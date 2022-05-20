#DataModelModule/CmakeLists.txt

#file globbing
file(GLOB source "src/*.cpp")

#include header
include_directories(inc/)
include_directories(${CMAKE_SOURCE_DIR}/UtilityModule/inc/)

#compile module
add_library(DataModel STATIC ${source})
