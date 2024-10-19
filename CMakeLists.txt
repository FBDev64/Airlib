cmake_minimum_required(VERSION 3.28)
project(Airlib C)

set(CMAKE_C_STANDARD 23)

# Option to compile the LaTex documentation
option(COMPILE_LATEX "Compile LaTeX documents" OFF)

if(COMPILE_LATEX)
    find_program(PDFLATEX_COMPILER NAMES pdflatex)

    if(NOT PDFLATEX_COMPILER)
        message(FATAL_ERROR "pdflatex not found! Please install a TeX distribution (MiKTeX or TeX Live).")
    endif()

    # Trouve tous les fichiers .tex dans le répertoire 'docs'
    file(GLOB_RECURSE LATEX_SOURCES "${CMAKE_SOURCE_DIR}/docs/*.tex")

    # Commande pour compiler chaque fichier .tex en PDF
    foreach(LATEX_SOURCE ${LATEX_SOURCES})
        get_filename_component(LATEX_FILENAME ${LATEX_SOURCE} NAME_WE)
        add_custom_command(
                OUTPUT ${CMAKE_BINARY_DIR}/docs/${LATEX_FILENAME}.pdf
                COMMAND ${PDFLATEX_COMPILER} -interaction=nonstopmode -output-directory ${CMAKE_BINARY_DIR}/docs ${LATEX_SOURCE}
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs
                DEPENDS ${LATEX_SOURCE}
                COMMENT "Compiling LaTeX file: ${LATEX_SOURCE}"
                VERBATIM
        )

        add_custom_target(${LATEX_FILENAME}_pdf ALL DEPENDS ${CMAKE_BINARY_DIR}/docs/${LATEX_FILENAME}.pdf)
    endforeach()
else()
    message(STATUS "LaTeX compilation is disabled. Enable it by setting COMPILE_LATEX=ON.")
endif()

add_library(Airlib SHARED src/old.c
        src/airlib.c
        src/audio.c
        src/graphics.c
)
