cmake_minimum_required(VERSION 3.5)

project(siisty VERSION 0.1 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

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

find_package(QT NAMES Qt6 COMPONENTS Core Widgets Network Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Network Sql REQUIRED)
find_package(Threads REQUIRED)
find_package(siigix COMPONENTS Data REQUIRED)

add_subdirectory(General)
add_subdirectory(Client)
add_subdirectory(Server)

# set_target_properties(shelly PROPERTIES
#     MACOSX_BUNDLE_GUI_IDENTIFIER github.com/siisgoo/shelly
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )
