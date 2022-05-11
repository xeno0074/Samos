#TestModule/CmakeLists.txt

#set variables
set(modules CoreFunction)
list(APPEND modules DataModel)
list(APPEND modules Utility)
#list(APPEND modules Clock)

set(test_libs CoreFunctionTest)
#list(APPEND test_lib DataModelTest)
#list(APPEND test_lib UtilityTest)

set(header_paths ../CoreFunctionModule/inc/)
list(APPEND header_paths ../DataModelModule/inc/)
list(APPEND header_paths ../UtilityModule/inc/)
#list(APPEND ../SupportFunction/ClockModule/inc/)

#include library
include_directories(${header_paths})

#compile target
add_executable(SampleTest SampleTest.cpp)
add_executable(FunctionTest FunctionTest.cpp)

#link libraries
target_link_libraries(SampleTest ${modules})
target_link_libraries(FunctionTest ${modules} ${test_libs})