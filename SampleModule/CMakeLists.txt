#SampleModule/CmakeList.txt

#file globbing
file(GLOB source "src/*.cpp")

#include library
include_directories(inc/)

#compile library
add_library(Sample STATIC ${source})