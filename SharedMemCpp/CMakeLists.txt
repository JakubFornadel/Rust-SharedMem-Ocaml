cmake_minimum_required( VERSION 3.2 )
add_compile_options("-Wall" "-Werror")
set( CMAKE_CXX_STANDARD 17 )

add_library(SharedMemCpp SHARED src/SharedMem.cpp)
target_include_directories(SharedMemCpp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

install(TARGETS
   SharedMemCpp

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)


option(SHAREDMEMCPP_BUILD_EXAMPLES "Build examples." ON)
if (SHAREDMEMCPP_BUILD_EXAMPLES)
    # add the basic example executable
    add_executable(SharedMemExample examples/SharedMemExample.cpp)
    target_link_libraries(SharedMemExample SharedMemCpp)

else (SHAREDMEMCPP_BUILD_EXAMPLES)
    message(STATUS "SHAREDMEMCPP_BUILD_EXAMPLES OFF")
endif (SHAREDMEMCPP_BUILD_EXAMPLES)