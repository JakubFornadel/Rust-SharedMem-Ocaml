cmake_minimum_required( VERSION 3.2 )
add_compile_options("-Wall" "-Werror")
set( CMAKE_CXX_STANDARD 17 )

add_library(SharedMemCpp SHARED src/SharedMem.cpp src/SharedMemCWrapper.cpp)
target_link_libraries(SharedMemCpp rt pthread)
target_include_directories(SharedMemCpp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include")

add_library(SharedMemCpp_static STATIC src/SharedMem.cpp src/SharedMemCWrapper.cpp)
target_link_libraries(SharedMemCpp_static rt pthread)
target_include_directories(SharedMemCpp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include")
set_target_properties(SharedMemCpp_static PROPERTIES OUTPUT_NAME SharedMemCpp)


install(TARGETS
   SharedMemCpp

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

install(TARGETS
   SharedMemCpp_static

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/src/include/*")
install(FILES ${headers} DESTINATION include)


option(SHAREDMEMCPP_BUILD_EXAMPLES "Build examples." OFF)
if (SHAREDMEMCPP_BUILD_EXAMPLES)
    # builds C++ example
    add_executable(Cpp_SharedMemExample examples/Cpp_SharedMemExample.cpp)
    target_link_libraries(Cpp_SharedMemExample SharedMemCpp)

    # builds C example
    add_executable(C_SharedMemExample examples/C_SharedMemExample.c)
    target_link_libraries(C_SharedMemExample SharedMemCpp)

else (SHAREDMEMCPP_BUILD_EXAMPLES)
    message(STATUS "SHAREDMEMCPP_BUILD_EXAMPLES OFF")
endif (SHAREDMEMCPP_BUILD_EXAMPLES)