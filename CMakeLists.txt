cmake_minimum_required(VERSION 3.20)
project(exams)
set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig)
find_package(Threads)
find_package(ZLIB)
find_package(OpenSSL)

if(OPENSSL_FOUND)
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

#find_package(Crow)
#pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

add_definitions(-DCROW_ENABLE_DEBUG -DCROW_ENABLE_COMPRESSION -DCROW_ENABLE_SSL)
add_executable(exams mainCrow.cpp)
#target_precompile_headers(exams PUBLIC <string> <zlib.h> <crow_all.h>)
target_link_libraries(exams PUBLIC pthread z ssl crypto)
