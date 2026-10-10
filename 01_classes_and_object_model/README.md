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

## VS Code

Из корня репозитория откройте этот каталог как отдельный проект:

~~~bash
code 01_classes_and_object_model
~~~

`Ctrl+Shift+B` собирает лабораторную. Для запуска примера откройте файл из `steps/`, перейдите в **Run and Debug**, выберите конфигурацию **LLDB** для Linux/macOS или **MSVC** для Windows и нажмите F5.

Открытие сразу всего курса и общие задачи описаны в [корневой инструкции](../README.md#vs-code).
