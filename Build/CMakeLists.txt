#Build/CmakeLists.txt

#set variables
set(modules Sample)
list(APPEND modules Alu)
list(APPEND modules DataModel)
#list(APPEND modules Utility)
#list(APPEND modules Clock)

set(header_paths ../SampleModule/inc/)
list(APPEND ../CoreFunction/AluModule/inc/)
list(APPEND ../DataModelModule/inc/)
list(APPEND ../UtilityModule/inc/)
list(APPEND ../SupportFunction/ClockModule/inc/)

#include library
include_directories(${header_paths})

#compile target
add_executable(nCpu main.cpp)

#link libraries
target_link_libraries(nCpu ${modules})