project(learn-stl-17-cookbook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_$<CONFIG> ${CMAKE_CURRENT_LIST_DIR}/bin)

add_subdirectory(ch1/2)
add_subdirectory(ch1/3)
add_subdirectory(ch1/4)
add_subdirectory(ch1/5)
add_subdirectory(ch1/6)
add_subdirectory(ch1/7)