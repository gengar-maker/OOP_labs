---
title: "Лабораторные работы по ООП на C++"
aliases:
  - "C++ OOP Labs"
tags:
  - cpp
  - oop
  - cmake
  - vscode
type: course-index
course: "C++ OOP"
---

# Лабораторные работы по ООП на C++

Репозиторий содержит конспекты, последовательные примеры, задания и CMake-проекты. Лабораторные изучаются по порядку.

## Быстрые ссылки

| № | Тема | Конспект | Проект и сборка |
|---:|---|---|---|
| 1 | Классы и устройство объектов | [Открыть конспект](01_classes_and_object_model/01_oop_classes_and_object_model.md) | [README](01_classes_and_object_model/README.md) |
| 1.1 | Конструирование и инициализация | [Открыть конспект](01_1_object_construction_and_initialization/01_1_object_construction_and_initialization.md) | [README](01_1_object_construction_and_initialization/README.md) |
| 2 | RAII, исключения, `noexcept` и операторы | [Открыть конспект](02_raii_constructor_exceptions_noexcept/02_raii_constructor_exceptions_noexcept.md) | [README](02_raii_constructor_exceptions_noexcept/README.md) |

## Структура

Каждая лабораторная находится в своей директории и является самостоятельным CMake-проектом:

~~~text
OOP_labs/
├── 01_classes_and_object_model/
├── 01_1_object_construction_and_initialization/
├── 02_raii_constructor_exceptions_noexcept/
└── README.md
~~~

## Требования

- CMake 3.21 или новее;
- Ninja;
- компилятор с поддержкой C++20;
- VS Code с рекомендуемыми расширениями — необязательно, но удобно.

## Сборка лабораторной №1

Из корня репозитория:

~~~bash
cd 01_classes_and_object_model
cmake --preset debug
cmake --build --preset debug
~~~

Исполняемые файлы появятся в <code>build/debug/bin/</code>.

## Сборка и запуск одного шага

~~~bash
cmake --build --preset debug --target lab01_step_08_robot_v1
./build/debug/bin/lab01_step_08_robot_v1
~~~

Имя цели строится так:

~~~text
steps/08_robot_v1.cpp
        ↓
lab01_step_08_robot_v1
~~~

## Автоматическая проверка

Каждый шаг зарегистрирован как отдельный CTest-тест:

~~~bash
ctest --preset debug
~~~

## Санитайзеры

~~~bash
cmake --preset sanitizers
cmake --build --preset sanitizers
ctest --preset sanitizers
~~~

## VS Code

Откройте директорию нужной лабораторной:

~~~bash
cd 02_raii_constructor_exceptions_noexcept
code .
~~~

Доступные действия:

- <code>Cmd+Shift+B</code> — собрать все шаги;
- открыть нужный <code>steps/*.cpp</code> и нажать F5 — собрать и отладить текущий шаг;
- задача **CTest: run all steps** — запустить весь набор проверок;
- команда **CMake: Select Configure Preset** — выбрать Debug, Release или Sanitizers.

Для подготовленного <code>launch.json</code> используется расширение CodeLLDB.

## Сборка других лабораторных

Каждый подпроект собирается из своего каталога:

~~~bash
cd 01_1_object_construction_and_initialization
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
~~~

Для другой работы замените имя каталога на `01_classes_and_object_model` или `02_raii_constructor_exceptions_noexcept`. Все команды выполняются внутри директории выбранной лабораторной.
