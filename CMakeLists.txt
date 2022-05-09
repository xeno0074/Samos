# cmake_minimum_required(VERSION <specify CMake version here>)
project(Vladis)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Build)
add_subdirectory(SampleModule)
add_subdirectory(CoreFunction/AluModule)
add_subdirectory(SupportFunction/ClockModule)
add_subdirectory(DataModelModule)
add_subdirectory(UtilityModule)