cmake_minimum_required(VERSION 3.21)
project(Client LANGUAGES CXX VERSION 0.0.1 DESCRIPTION "siisty Client")

set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ui
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ui/Pages)

#####################
#  finding sources  #
#####################

set(SRCS "")

# Sources
file(GLOB_RECURSE SRCS_G "src/*.cpp")
POCO_SOURCES_AUTO(SRCS ${SRCS_G})

# Headers
file(GLOB_RECURSE HDRS_G "include/*.hpp")
POCO_HEADERS_AUTO(SRCS ${HDRS_G})

qt6_add_resources(SRCS ${GLOBAL_RESOURCES})

#########################
#  building executable  #
#########################

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        ${SRCS}
    )
else()
    if(ANDROID)
        add_executable(${PROJECT_NAME}
            ${SRCS}
        )
    else()
        add_executable(${PROJECT_NAME}
            ${SRCS}
        )
    endif()
endif()

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Network
        General
)

if(QT_VERSION_MAJOR EQUAL 6)
    # qt_finalize_executable(${PROJECT_NAME})
endif()

################################
#  setting project properties  #
################################

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME    "${PROJECT_NAME}"
    SUFFIX         ""
    PREFIX         ""
    VERSION        "${PROJECT_VERSION}"
    PUBLIC_HEADER  "${HDRS_G}"
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
)
