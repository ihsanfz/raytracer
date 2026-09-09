cmake_minimum_required(VERSION 3.10)

project(raytracer)

find_package(OpenMP REQUIRED)

set(SOURCES raytracer.cpp)

set(HEADERS camera.h commons.h hittableList.h material.h vec3.h color.h hittable.h interval.h ray.h sphere.h)

add_executable(raytracer ${SOURCES} ${HEADERS})

target_link_libraries(raytracer PRIVATE OpenMP::OpenMP_CXX)

target_include_directories(raytracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
