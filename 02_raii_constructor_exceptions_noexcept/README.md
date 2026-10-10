---
title: "Лабораторная №2 — проект RAII, исключения и noexcept"
aliases:
  - "Lab 02 Project"
tags:
  - cpp
  - cmake
  - vscode
  - raii
  - exceptions
  - noexcept
type: laboratory-project
course: "C++ OOP"
---

# Лабораторная №2: RAII, исключения, `noexcept` и операторы

Это автономный C++20-пакет для самостоятельного изучения. Материал идёт от проблемы ручного освобождения ресурса к собственному классу `IntArray`.

## Содержимое

~~~text
02_raii_constructor_exceptions_noexcept/
├── .vscode/          настройки VS Code
├── steps/            восемь последовательных экспериментов
├── tasks/            заготовка IntArray
├── solutions/        решение для самопроверки
├── 02_raii_constructor_exceptions_noexcept.md
├── CMakeLists.txt
├── CMakePresets.json
└── README.md
~~~

Конспект, маршрут и задание: [лабораторная работа №2](02_raii_constructor_exceptions_noexcept.md).

[Все лабораторные](../README.md).
## Требования

- CMake 3.21 или новее;
- Ninja;
- компилятор с поддержкой C++20;
- VS Code и рекомендованные расширения — необязательно.

## Сборка и проверка

~~~bash
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
~~~

Исполняемые файлы появятся в <code>build/debug/bin/</code>.

## Один учебный шаг

~~~bash
cmake --build --preset debug --target lab02_step_04_constructor_failure
./build/debug/bin/lab02_step_04_constructor_failure
~~~

## Задание и решение

~~~bash
cmake --build --preset debug --target lab02_task_01_int_array
./build/debug/bin/lab02_task_01_int_array

cmake --build --preset debug --target lab02_solution_01_int_array
./build/debug/bin/lab02_solution_01_int_array
~~~

## Санитайзеры

~~~bash
cmake --preset sanitizers
cmake --build --preset sanitizers
ctest --preset sanitizers
~~~

AddressSanitizer и UndefinedBehaviorSanitizer помогают найти утечки, двойное освобождение и обращения за границами массива.

## VS Code

Из корня репозитория откройте этот каталог как отдельный проект:

~~~bash
code 02_raii_constructor_exceptions_noexcept
~~~

`Ctrl+Shift+B` собирает лабораторную. Для запуска примера откройте файл из `steps/`, перейдите в **Run and Debug**, выберите конфигурацию **LLDB** для Linux/macOS или **MSVC** для Windows и нажмите F5.

Открытие сразу всего курса и общие задачи описаны в [корневой инструкции](../README.md#vs-code).
