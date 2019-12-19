################################
# GTest
################################
project(googletest-git NONE)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

################################
# Tests
################################
project(oldknights_test LANGUAGES CXX)

add_executable(${PROJECT_NAME}
	test_combatantlist.cpp
)
target_link_libraries(${PROJECT_NAME}
    oldknights_lib
	gtest gtest_main
)

add_test(NAME UnitTests
	COMMAND ${PROJECT_NAME}
)
