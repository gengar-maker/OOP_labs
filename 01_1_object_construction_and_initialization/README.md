---
title: "Лабораторная №1.1 — проект по инициализации объектов"
aliases:
  - "Lab 01.1 Project"
tags:
  - cpp
  - cmake
  - vscode
  - initialization
type: laboratory-project
course: "C++ OOP"
---

# Лабораторная №1.1: конструирование и формы инициализации

Это автономный C++20-пакет. Он не зависит от исходников лабораторной №1.

## Содержимое

~~~text
01_1_object_construction_and_initialization/
├── .vscode/          настройки VS Code
├── steps/            пять последовательных примеров
├── tasks/            самостоятельное задание
├── solutions/        эталонное решение
├── 01_1_object_construction_and_initialization.md
├── CMakeLists.txt
├── CMakePresets.json
└── README.md
~~~

Конспект и задание: [лабораторная работа №1.1](01_1_object_construction_and_initialization.md).

[Все лабораторные](../README.md).
## Требования

- CMake 3.21 или новее;
- Ninja;
- компилятор с поддержкой C++20;
- VS Code и рекомендованные расширения — необязательно.

## Сборка и тестирование

~~~bash
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
~~~

Исполняемые файлы появятся в <code>build/debug/bin/</code>.

## Один демонстрационный шаг

~~~bash
cmake --build --preset debug --target lab011_step_04_designated_initializers
./build/debug/bin/lab011_step_04_designated_initializers
~~~

## Задание и решение

~~~bash
cmake --build --preset debug --target lab011_task_01_device_profile
./build/debug/bin/lab011_task_01_device_profile

cmake --build --preset debug --target lab011_solution_01_device_profile
./build/debug/bin/lab011_solution_01_device_profile
~~~

## Санитайзеры

~~~bash
cmake --preset sanitizers
cmake --build --preset sanitizers
ctest --preset sanitizers
~~~

## VS Code

Откройте именно этот каталог командой `code .`. Для файлов из `steps/` доступна конфигурация **Debug: current example**.
