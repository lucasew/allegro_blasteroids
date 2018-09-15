cmake_minimum_required(VERSION 3.10)

project(blasteroids LANGUAGES C)

include_directories(include/)

add_executable(game
    main.c
    src/asteroid.c
    src/bullet.c
    src/collision.c
    src/context.c
    src/event.c
    src/spaceship.c
    src/pos_fixer.c
    src/text.c
    src/utils/draw.c
    src/utils/signal.c
)
#SET(BUILD_SHARED_LIBS OFF)

# Mandar o arquivo de fonte junto para o target
add_custom_command(
    TARGET game
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/font.ttf ${CMAKE_CURRENT_BINARY_DIR}/font.ttf
)
#SET(CMAKE_EXE_LINK_FLAGS "-static")
#target_link_libraries(game -lallegro -lallegro_ttf -lallegro_font -lallegro_primitives -lm)
target_link_libraries(game allegro allegro_primitives allegro_font allegro_ttf -lm)
#target_link_libraries(game allegro_monolith -lm)

