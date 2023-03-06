add_executable(App main.cpp)
target_link_libraries(App Statistics)
add_compile_options(-Wall -Wextra -pedantic -Werror)

set(CMAKE_CXX_CLANG_TIDY 
        clang-tidy;
        -checks=*;
        -header-filter=.;
        -warnings-as-errors=*;
)