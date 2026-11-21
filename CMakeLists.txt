# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# UŻYWAMY PEŁNEJ ŚCIEŻKI SYSTEMOWEJ DO FOLDERU COMPONENTS
set(EXTRA_COMPONENT_DIRS "${CMAKE_CURRENT_LIST_DIR}/components")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(ECO7-JC8012P4A1C-REV3.2-IDF-MIPI-DSI)
