cmake_minimum_required(VERSION 3.12)
project(socket_cpp)

##############################################################################
# compiler settings
##############################################################################
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

##############################################################################
# Find ament packages and system dependencies
##############################################################################
# find_package(Eigen3 REQUIRED)
# find_package(Boost REQUIRED COMPONENTS system thread) # asio
# find_package(yaml-cpp REQUIRED COMPONENTS node)
##############################################################################
# Build
##############################################################################
include_directories(
    include()
    # ${EIGEN3_INCLUDE_DIRS}
    # ${Boost_INCLUDE_DIRS}
    # ${yaml-cpp_INCLUDE_DIRS}
)
add_library(
    ${PROJECT_NAME}_lib
    "src/socket_server.cpp"
)
target_link_libraries(
    ${PROJECT_NAME}_lib
    # ${EIGEN3_LIBRARIES}
    # ${Boost_LIBRARIES}
    # ${yaml-cpp_LIBRARIES}
)


add_executable(socket "src/main.cpp")
target_link_libraries(socket ${PROJECT_NAME}_lib)

add_executable(ntoh "src/ntoh.cpp")


##############################################################################
# install
##############################################################################
install(
    TARGETS ${PROJECT_NAME}_lib socket ntoh
    DESTINATION lib/${PROJECT_NAME}
)