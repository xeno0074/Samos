#AluModule/CMakeList.txt

file(GLOB source "src/*.cpp")

include_directories(inc/)

add_library(Alu STATIC ${source})