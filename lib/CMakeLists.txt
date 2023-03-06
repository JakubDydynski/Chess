add_library(Statistics Statistics.cpp Statistics.h)
add_compile_options(-Wall -Wextra -pedantic -Werror)

set(CMAKE_CXX_CLANG_TIDY 
        clang-tidy;
        -checks=*;
        -header-filter=.;
        -warnings-as-errors=*;
)