set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)

target_compile_features(main PRIVATE cxx_std_17)