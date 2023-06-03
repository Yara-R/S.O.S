cmake_minimum_required(VERSION 3.25)
project(teste C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(teste
        login.c
        login.h
        avisos_residentes.c
        avisos_residentes.h
        main.c avisos_preceptores.c avisos_preceptores.h avaliacao_residente.c avaliacao_residente.h avaliacao_preceptor.c avaliacao_preceptor.h presenca.c presenca.h)
