# CMakeList.txt: проект CMake для Task33_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Task33_2 "Task33_2.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Task33_2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
