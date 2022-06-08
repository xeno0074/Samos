 cmake_minimum_required(VERSION 3.22)
 project(Samosc)

 set(CMAKE_CXX_STANDARD 17)

 add_subdirectory(SamosCLI)
 add_subdirectory(TestModule)
 add_subdirectory(CoreFunctionModule)
 # add_subdirectory(SupportFunction/ClockModule)
 add_subdirectory(SupportFunction/DataReaderModule)
 add_subdirectory(SupportFunction/DataWriterModule)
 add_subdirectory(DataModelModule)
 add_subdirectory(UtilityModule)