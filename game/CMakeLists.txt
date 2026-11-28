file(GLOB_RECURSE GAME_SOURCES
    CONFIGURE_DEPENDS
    LIST_DIRECTORIES false
    RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h*"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c*"
)

add_executable(TEST_GAME
    ${GAME_SOURCES}
)

target_include_directories(TEST_GAME
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(TEST_GAME
    PRIVATE
        XSE_SDK
)