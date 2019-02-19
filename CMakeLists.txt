cmake_minimum_required(VERSION 3.10)

project(blasteroids LANGUAGES C)

include(CheckIncludeFiles)

check_include_files("allegro5/allegro.h" HAVE_ALLEGRO)
if(NOT HAVE_ALLEGRO)
    message(FATAL_ERROR "Allegro5 not installed")
endif()

include_directories(include/)

file(GLOB_RECURSE PROJECT_FILES
    "src/*.c"
)

add_executable(blasteroids 
    main.c
    ${PROJECT_FILES}
)

#Libs externas
target_link_libraries(blasteroids
    allegro
    allegro_primitives
    allegro_font
    allegro_ttf
    -lm
)

# Mandar o arquivo de fonte junto para o target
add_custom_command(
    TARGET blasteroids
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/blasteroids_font.ttf ${CMAKE_CURRENT_BINARY_DIR}/blasteroids_font.ttf
)

install(TARGETS blasteroids DESTINATION bin)
