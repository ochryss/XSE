file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h*"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c*"
)

add_library(XSE_SDK STATIC ${SOURCES})

#target_sources(XSE_SDK PRIVATE ${SOURCES})

target_include_directories(XSE_SDK
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(XSE_SDK
    PUBLIC
        SDL3::SDL3-static
)