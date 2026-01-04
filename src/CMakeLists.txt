find_package(quill REQUIRED)

# -----------------------------------------------------------------------

add_library(logger SHARED logger.cpp)
add_library(${PROJECT_NAME}::logger ALIAS logger)
target_include_directories(logger PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(logger PUBLIC quill::quill)

add_library(calc SHARED calc.cpp)
add_library(${PROJECT_NAME}::calc ALIAS calc)
target_include_directories(calc PUBLIC ${PROJECT_SOURCE_DIR}/include)
