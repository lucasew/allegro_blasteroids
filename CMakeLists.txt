cmake_minimum_required(VERSION 3.10)

project(blasteroids LANGUAGES C)

include_directories(include/)

add_library(blasteroids_utils
    src/utils/draw.c
    src/utils/signal.c
    src/utils/rand.c
)

add_library(blasteroids_core
    src/asteroid.c
    src/bullet.c
    src/spaceship.c
    src/collision.c
    src/context.c
    src/event.c
    src/pos_fixer.c
    src/text.c
)

add_executable(blasteroids main.c)

target_link_libraries(blasteroids blasteroids_core blasteroids_utils)
target_link_libraries(blasteroids allegro allegro_primitives allegro_font allegro_ttf -lm)
#SET(BUILD_SHARED_LIBS OFF)

# Mandar o arquivo de fonte junto para o target
add_custom_command(
    TARGET blasteroids
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/blasteroids_font.ttf ${CMAKE_CURRENT_BINARY_DIR}/blasteroids_font.ttf
)

install(TARGETS blasteroids DESTINATION bin)
