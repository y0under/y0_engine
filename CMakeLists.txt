cmake_minimum_required(VERSION 3.20)
project(y0_engine CXX)

set(CMAKE_CXX_STANDARD 20)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long --pedantic-errors")
endif()

# add_subdirectory(src/y0_engine/object)
# add_subdirectory(src/y0_engine/shader)

set(BIN_NAME y0_engine)
set(TARGET_DIR_OBJECT object)
set(TARGET_DIR_COMPONENTS object/components)
set(TARGET_DIR_MESH mesh)
set(TARGET_DIR_TEXTURE texture)
set(TARGET_DIR_RENDERING rendering)
set(TARGET_DIR_SHADER shader)
set(TARGET_DIR_WINDOW window)
set(TARGET_DIR_Log Log)
set(TARGET_DIR_MATH math)

set(OBJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/y0_engine/${TARGET_DIR_OBJECT})
set(COMPONENTS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/y0_engine/${TARGET_DIR_COMPONENTS})
set(MESH_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/y0_engine/${TARGET_DIR_MESH})
set(TEXTURE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/y0_engine/${TARGET_DIR_TEXTURE})
set(RENDERING_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/y0_engine/${TARGET_DIR_RENDERING})
set(SHADER_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/y0_engine/${TARGET_DIR_SHADER})
set(WINDOW_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/y0_engine/${TARGET_DIR_WINDOW})
set(Log_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/y0_core/${TARGET_DIR_LOG})
set(MATH_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/y0_core/${TARGET_DIR_MATH})

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(COMPONENTS_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/y0_engine/${TARGET_DIR_COMPONENTS})
set(OBJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/y0_engine/${TARGET_DIR_OBJECT})
set(MESH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/y0_engine/${TARGET_DIR_MESH})
set(TEXTURE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/y0_engine/${TARGET_DIR_TEXTURE})
set(RENDERING_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/y0_engine/${TARGET_DIR_RENDERING})
set(SHADER_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/y0_engine/${TARGET_DIR_SHADER})
set(WINDOW_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/y0_engine/${TARGET_DIR_WINDOW})
set(LOG_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/y0_core/${TARGET_DIR_LOG})
set(MATH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/y0_core/${TARGET_DIR_MATH})

file(GLOB OBJECT_SOURCES "${OBJECT_SOURCE_DIR}/*.cc")
file(GLOB COMPONENTS_SOURCES "${COMPONENTS_SOURCE_DIR}/*.cc")
file(GLOB MESH_SOURCES "${MESH_SOURCE_DIR}/*.cc")
file(GLOB TEXTURE_SOURCES "${TEXTURE_SOURCE_DIR}/*.cc")
file(GLOB RENDERING_SOURCES "${RENDERING_SOURCE_DIR}/*.cc")
file(GLOB SHADER_SOURCES "${SHADER_SOURCE_DIR}/*.cc")
file(GLOB WINDOW_SOURCES "${WINDOW_SOURCE_DIR}/*.cc")
file(GLOB LOG_SOURCES "${LOG_SOURCE_DIR}/*.cc")
file(GLOB MATH_SOURCES "${MATH_SOURCE_DIR}/*.cc")
set(SOURCES ${OBJECT_SOURCES} ${COMPONENTS_SOURCES} ${MESH_SOURCES} ${RENDERING_SOURCES} ${SHADER_SOURCES}
            ${LOG_SOURCES} ${MATH_SOURCES} ${WINDOW_SOURCES} ${TEXTURE_SOURCES})

add_library(${BIN_NAME} SHARED ${SOURCES})

find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(Boost REQUIRED)

# find_package(Boost COMPONENTS thread system log log_setup filesystem system REQUIRED)
find_package(Boost REQUIRED COMPONENTS log log_setup thread filesystem system)
# find_package(Threads)


target_include_directories(
  ${BIN_NAME} PUBLIC
  ${INCLUDE_DIR}
  ${OBJECT_INCLUDE_DIR}
  ${COMPONENTS_INCLUDE_DIR}
  ${MESH_INCLUDE_DIR}
  ${TEXTURE_INCLUDE_DIR}
  ${RENDERING_INCLUDE_DIR}
  ${SHADER_INCLUDE_DIR}
  ${LOG_INCLUDE_DIR}
  ${WINDOW_INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS})

add_definitions("-DBOOST_LOG_DYN_LINK")

target_link_libraries(${BIN_NAME}
                      ${OpenCV_LIBS}
                      OpenGL::GL
                      glfw
                      GLEW
                      ${Boost_LIBRARIES}
                      ${CMAKE_THREAD_LIBS_INIT})
                      # Boost::boost)

# test code
add_subdirectory(test)

# set(BIN_NAME y0_engine)

# set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
# set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
# 
# file(GLOB SOURCES "${SOURCE_DIR}/*.cc")
# add_library(${BIN_NAME} ${SOURCES})

# target_include_directories(${BIN_NAME} PUBLIC ${INCLUDE_DIR})
