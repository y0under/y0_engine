# test code
option(TEST_BUILD "Build the test executable" OFF)

add_custom_target(test_build
    COMMAND ${CMAKE_COMMAND} -DTEST_BUILD=ON ..
    COMMAND ${CMAKE_COMMAND} --build .
)

set(TEST_BIN y0_engine_test)
if(TEST_BUILD)
  add_executable(${TEST_BIN} test.cc)
  target_link_libraries(y0_engine_test ${BIN_NAME})
  add_custom_target(run
    COMMAND ${TEST_BIN}
    DEPENDS ${TEST_BIN}
    # wORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Running test")
endif()
