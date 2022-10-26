

set(CMAKE_PREFIX_PATH "/home/nirvik/vcpkg/installed/x64-linux/share/jsoncpp")
find_package(jsoncpp CONFIG REQUIRED)

add_library(calc STATIC Calc.cpp)
target_include_directories(calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(calc PRIVATE jsoncpp_object jsoncpp_static JsonCpp::JsonCpp)
