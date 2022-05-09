#UtilityModule/CmakeLists.txt

#file globbing
file(GLOB source "src/*.cpp")

#include header
include_directories(inc/)

#compile module
#add_library(Utility STATIC ${source})
