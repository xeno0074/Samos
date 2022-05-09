#DataModelModule/CmakeLists.txt

#file globbing
file(GLOB source "src/*.cpp")

#include header
include_directories(inc/)
include_directories(../UtilityModule/inc/)

#compile module
add_library(DataModel STATIC ${source})
