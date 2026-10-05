---
title: "Лабораторная работа №1: классы и устройство объектов"
aliases:
  - "Lab 01 Project"
tags:
  - cpp
  - oop
  - cmake
  - vscode
type: laboratory-project
course: "C++ OOP"
---

# Лабораторная работа №1: классы и устройство объектов

Папка является самостоятельным учебным пакетом. Для работы не нужны файлы из других каталогов хранилища.

## Содержимое

~~~text
01_classes_and_object_model/
├── .vscode/                           настройки сборки и отладки
├── steps/                             16 последовательных программ
├── 01_oop_classes_and_object_model.md конспект и задания
├── CMakeLists.txt                     конфигурация проекта
├── CMakePresets.json                  Debug, Release и Sanitizers
└── README.md                          эта инструкция
~~~

Конспект: [[01_oop_classes_and_object_model|Основы ООП в C++: классы и устройство объектов]].

## Требования

- CMake 3.21 или новее;
- Ninja;
- компилятор с поддержкой C++17;
- VS Code с рекомендуемыми расширениями — необязательно, но удобно.

## Сборка всех шагов

Откройте терминал в этой папке:

~~~bash
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

Откройте именно эту папку:

~~~bash
code .
~~~

Доступные действия:

- <code>Cmd+Shift+B</code> — собрать все шаги;
- открыть нужный <code>steps/*.cpp</code> и нажать F5 — собрать и отладить текущий шаг;
- задача **CTest: run all steps** — запустить весь набор проверок;
- команда **CMake: Select Configure Preset** — выбрать Debug, Release или Sanitizers.

Для подготовленного <code>launch.json</code> используется расширение CodeLLDB.
