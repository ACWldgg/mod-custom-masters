cmake_minimum_required(VERSION 3.8)

set(MODULE_NAME "mod_custom_masters")

project(${MODULE_NAME})

global_collect_src_directory_list(
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

add_definitions(-DMODULE_NAME=${MODULE_NAME})
