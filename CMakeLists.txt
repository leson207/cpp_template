cmake_minimum_required(VERSION 3.31.6)
project(cpp_sample LANGUAGES C CXX)

message("Building with CMake version: ${CMAKE_VERSION}")

find_package(quill REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenSSL REQUIRED COMPONENTS SSL Crypto)

add_library(logger STATIC src/logger.cpp)
target_include_directories(logger PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(logger PUBLIC quill::quill)

add_executable(main app/main.cpp)

target_link_libraries(main PRIVATE
        logger
        Boost::system
        OpenSSL::SSL
        OpenSSL::Crypto
)