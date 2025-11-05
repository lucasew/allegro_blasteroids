#include <signal.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_memfile.h>

#include "embedded_font.h"
#include <blasteroids/config.h>

#include <blasteroids/util_signal.h>
#include <blasteroids/util_log.h>

#include <blasteroids/context.h>
#include <blasteroids/event.h>
#include <blasteroids/collision.h>
#include <blasteroids/pos_fixer.h>

#include <blasteroids/asteroid_struct.h>
#include <blasteroids/asteroid_ops.h>
#include <blasteroids/bullet_struct.h>
#include <blasteroids/bullet_ops.h>
#include <blasteroids/spaceship_struct.h>


#include <blasteroids/main.h>

const char *WindowTitle = "BLASTEROIDS by Lucas59356";
bool running = true;
GameContext ctx;

int main() {
    srand(time(NULL));
    info("Iniciando...");
    // Signal handler
    if(catch_signal(SIGINT, stop) == -1 || catch_signal(SIGTERM, stop) == -1)
        error("Não foi possível setar o handler de interrupção");
    // Criando o contexto
    info("Inicializando...");
    if (!al_init())
        error("Não foi possível inicializar biblioteca de suporte!");
    if(!al_init_primitives_addon())
        error("Não foi possível inicializar a primitives addon");
    if(!al_init_font_addon())
        error("Não foi possível iniciar o módulo de fontes");
    if(!al_init_ttf_addon())
        error("Falha ao iniciar esquema de texto");
    // Queue
    ctx.event_queue = al_create_event_queue();
    // Timer
    ctx.timer = al_create_timer(1.0/FPS); // Tick a cada frame
    if (!ctx.timer)
        error("Não foi possível iniciar o timer");
    al_start_timer(ctx.timer);
    al_register_event_source(ctx.event_queue, al_get_timer_event_source(ctx.timer));
    // Teclado
    if(!al_install_keyboard())
        error("Não foi possível conectar-se ao teclado");
    al_register_event_source(ctx.event_queue, al_get_keyboard_event_source());
    // Display
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    ctx.display = al_create_display(600, 600);
    al_set_window_title(ctx.display, WindowTitle); // Título da janela
    al_register_event_source(ctx.event_queue, al_get_display_event_source(ctx.display));
    // Fonte (carregada da memória - embutida no binário)
    // Keep memfile open while font is in use - FreeType may need to access the data
    ctx.font_memfile = al_open_memfile((void*)embedded_font_data, embedded_font_size, "rb");
    if (!ctx.font_memfile)
        error("Não foi possível criar memfile para fonte embutida.");
    ctx.font = al_load_ttf_font_f(ctx.font_memfile, "embedded_font.ttf", 24, 0);
    if (ctx.font == NULL) {
        al_fclose(ctx.font_memfile);
        error("Não foi possível carregar fonte embutida.");
    }
    // Criando spaceship de exemplo
    Spaceship sp;
    sp.sx = 200;
    sp.sy = 200;
    sp.heading = 20;
    sp.speed = 10;
    sp.color = al_map_rgb(255, 255, 0);
    sp.health = 100;
    ctx.ship = sp;
    ctx.asteroids = malloc(sizeof(struct Asteroid*));
    *ctx.asteroids = NULL;
    blasteroids_asteroid__generate_and_append(&ctx);
    ctx.bullets = malloc(sizeof(struct Bullet*));
    *ctx.bullets = NULL;
    running = ctx.asteroids && ctx.bullets; // Se algum deles for falso/NULL, fechar o programa
    if (!running) handle_shutdown(SIGINT);
    // Event loop in main thread
    ALLEGRO_EVENT event; // Apenas para não ter de redeclarar a cada iteração
    while(running) {
        event_loop_once(&ctx, &event);
    }
    // ============= SAINDO ===========
    handle_shutdown(SIGINT);
}
void handle_shutdown() {
    info("Saindo....");
    /*debug("Destroy timer");
      al_destroy_timer(ctx->timer);*/
    debug("Destroy timer");
    al_destroy_timer(ctx.timer);
    // Queue
    debug("Destroy queue");
    al_destroy_event_queue(ctx.event_queue);
    debug("Free asteroids");
    blasteroids_asteroid__destroy(ctx.asteroids);
    debug("Free bullets");
    blasteroids_bullet__destroy(ctx.bullets);
    debug("Destroy display");
    al_destroy_display(ctx.display);
    debug("Destroy font");
    al_destroy_font(ctx.font);
    debug("Close font memfile");
    if (ctx.font_memfile)
        al_fclose(ctx.font_memfile);
    //raise(SIGKILL);
    free(ctx.asteroids);
    free(ctx.bullets);
    exit(1);
}

void stop(int sig) {
    running = false;
}
