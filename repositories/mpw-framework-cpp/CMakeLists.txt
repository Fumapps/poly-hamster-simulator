cmake_minimum_required(VERSION 3.17)
project(de_unistuttgart_iste_sqa_mpw_framework_cpp)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(core/src/generated)
add_subdirectory(core/src/impl)
add_subdirectory(core/src/framework)
set(SRCS ${GEN_SRCS} ${IMPL_SRCS} ${FRAMEWORK_SRCS})

include_directories(core/src/generated)
include_directories(core/src/impl)
include_directories(core/src/framework)
add_library(mpw_framework_core SHARED ${SRCS})
add_library(mpw_framework_core_lib STATIC ${SRCS})

# TODO: generate public include and use dynamic library
install(TARGETS mpw_framework_core DESTINATION lib)
install(
    DIRECTORY core/src 
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*")

## Setup GTEST

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(core/test)
