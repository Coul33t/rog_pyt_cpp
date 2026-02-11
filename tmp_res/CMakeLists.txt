cmake_minimum_required(VERSION 3.14)

# Set the default toolchain to use a Vcpkg submodule.
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE
        "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

project(
    crogtcod  # Project name, change this as needed.
    LANGUAGES C CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")  # Save all runtime files to this directory.

# SDL3 & libtcod
IF (WIN32)
        MESSAGE("Linking SDL3, SDL3_Image and SDL3_ttf")
        SET(SDL3_DIR "${PROJECT_SOURCE_DIR}/extlib/SDL/Win/SDL3/cmake") 
        SET(SDL3_Image_DIR "${PROJECT_SOURCE_DIR}/extlib/SDL/Win/SDL3_image/cmake")
        SET(SDL3_ttf_DIR "${PROJECT_SOURCE_DIR}/extlib/SDL/Win/SDL3_ttf/cmake") 

        FIND_PACKAGE(SDL3 REQUIRED) 
        FIND_PACKAGE(SDL3_Image REQUIRED)
        FIND_PACKAGE(SDL3_ttf REQUIRED)

        INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/SDL/Win/SDL3/include)

        MESSAGE("Linking Windows BearLibTerminal library")
        INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/blt/Windows64/Include/C)
        LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/blt/Windows64/)
ENDIF (WIN32)

IF (UNIX)
        MESSAGE("Linking SDL3, SDL3_Image and SDL3_ttf")
        # For Unix, you might need to do as follow: https://stackoverflow.com/a/67678616
        #list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl3)
        FIND_PACKAGE(SDL3 REQUIRED)
        FIND_PACKAGE(SDL3_image REQUIRED)
        FIND_PACKAGE(SDL3_ttf REQUIRED)

        MESSAGE("Linking Unix BearLibTerminal library")
        INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/unix64/blt)
        LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/extlib/unix64/blt)
ENDIF (UNIX)

find_package(libtcod CONFIG REQUIRED)

file(
    GLOB_RECURSE SOURCE_FILES
    CONFIGURE_DEPENDS  # Automatically reconfigure if source files are added/removed.
    ${PROJECT_SOURCE_DIR}/crogtcod/*.cpp
    ${PROJECT_SOURCE_DIR}/crogtcod/*.hpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Enforce UTF-8 encoding on MSVC.
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()

# Enable warnings recommended for new projects.
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()

if (WIN32)
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
            ${CMAKE_SOURCE_DIR}/extlib/SDL/Win/SDL3/lib/x64/SDL3.lib
            SDL3::SDL3
            libtcod::libtcod
            ${CMAKE_SOURCE_DIR}/extlib/blt/Windows64/BearLibTerminal.lib
            
    )
endif (WIN32)

if (UNIX)
    target_link_libraries(
            ${PROJECT_NAME}
            PRIVATE
            SDL3
            libtcod::libtcod
            ${CMAKE_SOURCE_DIR}/extlib/unix64/blt/libBearLibTerminal.so
    )
endif (UNIX)
