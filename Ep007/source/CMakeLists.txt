cmake_minimum_required(VERSION 3.10)
# set(CXX_STANDARD_REQUIRED ON) # Default C++ standard for target
# set(CMAKE_CXX_STANDARD 20) #Make C++ 20 a hard requirement

project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "The leading Hellow World App"
        LANGUAGES CXX)

add_library(operations STATIC src/operations.cpp)
target_include_directories(operations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(operations PUBLIC cxx_std_20)

add_library(logger STATIC logger/src/log.cpp)
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logger/include)
target_compile_features(logger PUBLIC cxx_std_20)

add_executable(HelloAppBinary main.cpp 
                                src/dog.cpp)

target_include_directories(HelloAppBinary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(HelloAppBinary PRIVATE cxx_std_20)
target_link_libraries(HelloAppBinary PUBLIC operations logger)
