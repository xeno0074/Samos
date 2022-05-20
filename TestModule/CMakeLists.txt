#TestModule/CmakeLists.txt

#set variables
set(modules CoreFunction)
list(APPEND modules DataModel)
list(APPEND modules Utility)
#list(APPEND modules Clock)
list(APPEND modules DataReader)

set(test_libs CoreFunctionTest)
#list(APPEND test_lib DataModelTest)
#list(APPEND test_lib UtilityTest)

set(header_paths ${CMAKE_SOURCE_DIR}/CoreFunctionModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/DataModelModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/UtilityModule/inc/)
#list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/ClockModule/inc/)
list(APPEND header_paths ${CMAKE_SOURCE_DIR}/SupportFunction/DataReaderModule/inc/)

#include library
include_directories(${header_paths})

#compile target
add_executable(SampleTest SampleTest.cpp)
add_executable(FunctionTest FunctionTest.cpp)

#link libraries
target_link_libraries(SampleTest ${modules})
target_link_libraries(FunctionTest ${modules} ${test_libs})