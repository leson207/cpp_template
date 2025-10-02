add_executable(main main.cpp)

find_package(nlohmann_json REQUIRED)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)