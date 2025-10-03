add_executable(main main.cpp)

find_package(nlohmann_json REQUIRED)
find_package(OpenSSL REQUIRED COMPONENTS SSL Crypto)
find_package(Boost REQUIRED COMPONENTS system thread)

target_link_libraries(main PRIVATE
        OpenSSL::SSL
        OpenSSL::Crypto
        Boost::system
        Boost::thread
        nlohmann_json::nlohmann_json
)