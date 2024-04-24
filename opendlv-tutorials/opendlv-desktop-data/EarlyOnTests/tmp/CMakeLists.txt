# Copyright (C) 2024 OpenDLV

cmake_minimum_required(VERSION 3.10)

project(opendlv-template-microservice)

set(OPENDLV_MESSAGE_STANDARD opendlv-message-standard-1.0.odvd)
set(CLUON_COMPLETE cluon-complete-v0.0.145.hpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} \
    -D_FORTIFY_SOURCE=2 -O3 -s")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} \
    -g -fsanitize=thread")
    # -fsanitize=address 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -D_XOPEN_SOURCE=700 -fstack-protector \
    -fomit-frame-pointer -pipe -pedantic -pedantic-errors -Werror -Weffc++ \
    -Wall -Wextra -Wshadow -Wdeprecated -Wdiv-by-zero -Wfloat-equal \
    -Wfloat-conversion -Wsign-compare -Wpointer-arith -Wuninitialized \
    -Wunreachable-code -Wunused -Wunused-function -Wunused-label \
    -Wunused-parameter -Wunused-but-set-parameter -Wunused-but-set-variable \
    -Wunused-value -Wunused-variable -Wunused-result \
    -Wmissing-field-initializers -Wmissing-format-attribute \
    -Wmissing-include-dirs -Wmissing-noreturn")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}")
find_package(CluonMsc)

if (NOT CLUONMSC_FOUND)
  add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/cluon-msc
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/cluon-complete.hpp
      ${CMAKE_BINARY_DIR}/cluon-complete.cpp
      COMMAND ${CMAKE_CXX_COMPILER} -o ${CMAKE_BINARY_DIR}/cluon-msc
      ${CMAKE_BINARY_DIR}/cluon-complete.cpp -std=c++20 -pthread
      -D HAVE_CLUON_MSC
      DEPENDS ${CMAKE_BINARY_DIR}/cluon-complete.hpp)
else (NOT CLUONMSC_FOUND)
  add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/cluon-msc
      COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CLUONMSC_PATH} ${CMAKE_BINARY_DIR}/cluon-msc
      DEPENDS ${CMAKE_BINARY_DIR}/cluon-complete.hpp)
endif (NOT CLUONMSC_FOUND)

add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/cluon-complete.hpp
    COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_CURRENT_SOURCE_DIR}/src/${CLUON_COMPLETE}
    ${CMAKE_BINARY_DIR}/cluon-complete.hpp
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/${CLUON_COMPLETE})

add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/opendlv-message-standard.hpp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_BINARY_DIR}/cluon-msc --cpp
    --out=${CMAKE_BINARY_DIR}/opendlv-message-standard.hpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/${OPENDLV_MESSAGE_STANDARD}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/${OPENDLV_MESSAGE_STANDARD}
    ${CMAKE_BINARY_DIR}/cluon-msc)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories(SYSTEM ${CMAKE_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}.cpp
  ${CMAKE_BINARY_DIR}/opendlv-message-standard.hpp)

target_link_libraries(${PROJECT_NAME}
    Threads::Threads)

install(TARGETS ${PROJECT_NAME} DESTINATION bin COMPONENT ${PROJECT_NAME})
