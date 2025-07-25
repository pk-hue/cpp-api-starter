cmake_minimum_required(VERSION 3.16)
project(cnx_com_db)

set(CMAKE_CXX_STANDARD 17)


find_package(libpqxx CONFIG REQUIRED)
find_package(Crow CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(cnx_com_db src/main.cpp)

target_link_libraries(cnx_com_db PRIVATE
        libpqxx::pqxx
        Crow::Crow
        nlohmann_json::nlohmann_json
)
