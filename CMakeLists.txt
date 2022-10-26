cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/nirvik/vcpkg/installed/x64-linux/share")

project(demo)

add_subdirectory(calc)
add_executable(test main.cpp)

target_link_libraries(test PRIVATE calc)

find_package(oatpp CONFIG REQUIRED)
target_link_libraries(test PRIVATE oatpp::oatpp oatpp::oatpp-test)


find_package(jsoncpp CONFIG REQUIRED)
target_link_libraries(test PRIVATE jsoncpp_object jsoncpp_static JsonCpp::JsonCpp)

