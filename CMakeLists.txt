cmake_minimum_required(VERSION 3.10)

project(Programm)


# Выбор таски
set(number_of_task 5)



set(name_add_project "Task_${number_of_task}")
add_subdirectory(${name_add_project})
