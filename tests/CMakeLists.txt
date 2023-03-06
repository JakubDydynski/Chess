add_executable(StatisticsTests StatisticsTests.cpp)
target_link_libraries(StatisticsTests Statistics)
add_test(NAME StatisticsTests COMMAND StatisticsTests)

# Catch library
Include(FetchContent)
FetchContent_Declare(
Catch2
GIT_REPOSITORY https://github.com/catchorg/Catch2.git
GIT_TAG origin/devel)
# cmake > 3.15 FetchContent_MakeAvailable(Catch2)
FetchContent_GetProperties(Catch2)
if(NOT catch2_POPULATED)
FetchContent_Populate(Catch2)
add_subdirectory("${catch2_SOURCE_DIR}" "${catch2_BINARY_DIR}")
endif()

target_link_libraries(StatisticsTests Catch2::Catch2WithMain)
add_compile_options(-Wall -Wextra -pedantic -Werror)

# Clang Tidy
set(CMAKE_CXX_CLANG_TIDY 
        clang-tidy;
        -checks=*;
        -header-filter=.;
        -warnings-as-errors=*;
)