cmake_minimum_required(VERSION 3.10)

project(blasteroids LANGUAGES C)

find_package(PkgConfig REQUIRED)

pkg_search_module(ALLEGRO5 REQUIRED allegro-5)

include_directories(include/)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE PROJECT_FILES
    "src/*.c"
)

# Generate embedded font header
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/embedded_font.h
    COMMAND ${CMAKE_COMMAND} -E env python3 ${CMAKE_SOURCE_DIR}/embed_font.py ${CMAKE_SOURCE_DIR}/blasteroids_font.ttf ${CMAKE_CURRENT_BINARY_DIR}/embedded_font.h
    DEPENDS ${CMAKE_SOURCE_DIR}/blasteroids_font.ttf ${CMAKE_SOURCE_DIR}/embed_font.py
    COMMENT "Embedding font data into C header"
)

add_executable(blasteroids
    main.c
    ${PROJECT_FILES}
    ${CMAKE_CURRENT_BINARY_DIR}/embedded_font.h
)

#Libs externas
target_link_libraries(blasteroids
    -lm
    allegro
    allegro_primitives
    allegro_font
    allegro_ttf
)

install(TARGETS blasteroids DESTINATION bin)
