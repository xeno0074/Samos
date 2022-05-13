#CoreFunctionModule/CmakeLists.txt

#file globbing
file(GLOB source "src/*.cpp")
file(GLOB test_files "test/*")

#include header
include_directories(inc/)
include_directories(../UtilityModule/inc/)
include_directories(../DataModelModule/inc/)
include_directories(../TestModule/)

#compile module
add_library(CoreFunction STATIC ${source})
add_library(CoreFunctionTest STATIC ${test_files})