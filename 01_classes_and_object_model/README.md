---
title: "Лабораторная работа №1: классы и устройство объектов"
tags:
  - cpp
  - oop
  - cmake
type: laboratory-project
course: "C++ OOP"
---

# Лабораторная работа №1

Конспект: [классы и устройство объектов](01_oop_classes_and_object_model.md).

Исходники: [последовательные примеры](steps/README.md).

Корневой индекс: [все лабораторные](../README.md).

## Сборка и тесты

~~~bash
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
~~~

Запуск одного шага:

~~~bash
cmake --build --preset debug --target lab01_step_08_robot_v1
./build/debug/bin/lab01_step_08_robot_v1
~~~

Санитайзеры:

~~~bash
cmake --preset sanitizers
cmake --build --preset sanitizers
ctest --preset sanitizers
~~~
