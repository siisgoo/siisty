project(ServerGUI LANGUAGES CXX VERSION 0.9.2 DESCRIPTION "siisty Server GUI")

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/src/Ui
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ui/Pages
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ui/ControlPannel
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Ui/Users)

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

#########################
#  building executable  #
#########################

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${SRCS}
    )
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
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
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Network
        iiServer
        PagesManager
        Logger
        Widgets
        Network
        Database
        Crypto
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()

################################
#  setting project properties  #
################################

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME    "siisty-Server"
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

######################
#  installing files  #
######################

# install(
#     TARGETS ${PROJECT_NAME}
#     RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}
# )

# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     $<TARGET_FILE:Qt6::Core>
#     ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}
# )

# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     $<TARGET_FILE:Qt6::Widgets>
#     ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}
# )

# add_custom_command(
#     TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     $<TARGET_FILE:Qt6::Network>
#     ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}
# )
