cmake_minimum_required(VERSION 3.27)
project(lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 main.c
        line.c
        line.h
        tests.c
        tests.h
        pictures.c
        pictures.h
        symbolpicture.c
        symbolpicture.h
        char.c
        char.h
        field_info.h
        stb_image.h
)
