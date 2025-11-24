cmake_minimum_required(VERSION 3.20)

# Project
project(MyCpp20WithCatch2
        VERSION 0.1.0
        LANGUAGES CXX)

# Global C++ standard settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(BUILD_TESTING "Build unit tests" ON)

# === Application target ===
add_executable(my_app
    src/main.cpp
)

# You can add include directories / libraries here for your app if needed:
# target_include_directories(my_app PRIVATE include)
# target_link_libraries(my_app PRIVATE some_lib)

# === Tests with Catch2 v3 ===
if(BUILD_TESTING)
  include(CTest)  # enables 'ctest' integration

  # Fetch Catch2 v3
  include(FetchContent)
  FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.0            # pick a specific tag; update when needed
    GIT_SHALLOW TRUE
  )
  FetchContent_MakeAvailable(catch2)

  # Test target
  add_executable(tests
    tests/test_example.cpp
  )

  # Link with Catch2's main (provides the test runner)
  target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

  # Ensure C++20 for tests too
  target_compile_features(tests PRIVATE cxx_std_20)

  # (Optional) Enable warnings for tests
  if(MSVC)
    target_compile_options(tests PRIVATE /W4 /permissive-)
  else()
    target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)
  endif()

  # Register tests with CTest by scanning Catch2's TEST_CASEs
  include(Catch)
  catch_discover_tests(tests)
endif()
