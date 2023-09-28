cmake_minimum_required(VERSION 3.5)

project(puzzle LANGUAGES CXX)

IF (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.5.2 COMPONENTS graphics audio REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(puzzle main.cpp)

set(ASSETS
    "assets/puzzle.png"
    "assets/tr.png"
)

foreach(RESOURCE ${ASSETS})
    configure_file(${CMAKE_SOURCE_DIR}/${RESOURCE} ${CMAKE_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach()

include(GNUInstallDirs)
install(TARGETS puzzle
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(puzzle sfml-graphics sfml-audio)
