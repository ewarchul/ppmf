
set(SOURCES main.cc)

add_executable(basic_experiments ${SOURCES})
target_compile_features(basic_experiments PRIVATE cxx_std_23)
target_compile_options(basic_experiments PRIVATE -Wall -Wextra)
target_link_libraries(basic_experiments PRIVATE cmaes)
