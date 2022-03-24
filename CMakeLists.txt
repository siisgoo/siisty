cmake_minimum_required(VERSION 3.5)

project(siisty VERSION 0.2 LANGUAGES CXX)

# set(default_build_type "Release")
# if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
set(DEFAULT_BUILD_TYPE "Debug")
set(CMAKE_BUILD_TYPE "Debug")
# endif()

#########################
#  YCM export commands  #
#########################

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json"  )
    EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
ENDIF()

include(PocoMacros.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT
    NAMES Qt6
    COMPONENTS Core Widgets Network Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS Core Widgets Network Sql REQUIRED)

set(GLOBAL_RESOURCES ${CMAKE_SOURCE_DIR}/resources.qrc)

set(BINARY_DIR ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

add_subdirectory(Widgets)
add_subdirectory(Logger)
add_subdirectory(Math)
add_subdirectory(Crypto)
add_subdirectory(PagesManager)
add_subdirectory(Database)
add_subdirectory(Network)
add_subdirectory(iiServer)

add_subdirectory(UserInterface/Server)
# add_subdirectory(UserInterface/Client)
