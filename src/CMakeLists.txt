cmake_minimum_required(VERSION 3.10)

project(raytracer)

find_package(OpenMP REQUIRED)
find_package(GTest CONFIG REQUIRED)

set(SOURCES raytracer.cpp)

set(HEADERS camera.h commons.h hittableList.h material.h vec3.h color.h hittable.h interval.h ray.h sphere.h)

add_executable(raytracer ${SOURCES} ${HEADERS})

target_link_libraries(raytracer PRIVATE OpenMP::OpenMP_CXX)

target_include_directories(raytracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()

add_executable(raytracertests tests/vec3test.cpp tests/raytest.cpp)

target_include_directories(raytracertests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(raytracertests PRIVATE GTest::gtest_main pthread)

include(GoogleTest)

gtest_discover_tests(raytracertests)
