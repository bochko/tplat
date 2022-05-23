cmake_minimum_required(VERSION 3.0.0)
project(tplat VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# dependencies
include(FetchContent)
FetchContent_Declare(
  "googletest"
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable("googletest")

add_library(tplat INTERFACE)
target_include_directories(tplat INTERFACE "include")

add_executable(tplat_test "test/test_array_as_string_view.cxx")
target_link_libraries(tplat_test tplat gtest_main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
