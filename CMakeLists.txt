cmake_minimum_required (VERSION 3.13...3.21)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE
        "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

project(
        rogue_pyt_cpp
        LANGUAGES C CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")  # Keep all runtime files in one directory.
set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/uuid_v4)

if (WIN32)
    MESSAGE("Linking Windows BearLibTerminal library")
    INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/win64/blt)
    LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/win64/blt)
endif (WIN32)

if (UNIX)
    MESSAGE("Linking Unix BearLibTerminal library")
    INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/unix64/blt)
    LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/unix64/blt)
endif (UNIX)

FIND_PACKAGE(libtcod CONFIG REQUIRED)

INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

file(
    GLOB_RECURSE SOURCE_FILES
    CONFIGURE_DEPENDS  # Automatically reconfigure if source files are added/removed.
    ${PROJECT_SOURCE_DIR}/sources/*.cpp
    ${PROJECT_SOURCE_DIR}/sources/include/*.h
    ${PROJECT_SOURCE_DIR}/sources/include/*.hpp
    ${PROJECT_SOURCE_DIR}/sources/src/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Ensure the C++17 standard is available.
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

find_package(SDL2 CONFIG REQUIRED)
find_package(libtcod CONFIG REQUIRED)

if (WIN32)
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
            SDL2::SDL2
            SDL2::SDL2main
            libtcod::libtcod
            ${CMAKE_SOURCE_DIR}/extlib/win64/blt/BearLibTerminal.lib
    )
endif (WIN32)

if (UNIX)
    target_link_libraries(
            ${PROJECT_NAME}
            PRIVATE
            SDL2::SDL2
            SDL2::SDL2main
            libtcod::libtcod
            ${CMAKE_SOURCE_DIR}/extlib/unix64/blt/libBearLibTerminal.so
    )
endif (UNIX)