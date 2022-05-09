#ClockModule/CMakeLists.txt

file(GLOB source "src/*.cpp")

include_directories(inc/)

add_library(Clock STATIC ${source})