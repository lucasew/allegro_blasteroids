cmake_minimum_required(VERSION 3.10)

project(blasteroids LANGUAGES C)

find_package(PkgConfig REQUIRED)

pkg_search_module(ALLEGRO5 REQUIRED allegro-5)

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
    -lm
    allegro
    allegro_primitives
    allegro_font
    allegro_ttf
)

# Mandar o arquivo de fonte junto para o target
add_custom_command(
    TARGET blasteroids
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/blasteroids_font.ttf ${CMAKE_CURRENT_BINARY_DIR}/blasteroids_font.ttf
)

install(TARGETS blasteroids DESTINATION bin)
