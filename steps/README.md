---
title: "Lab 01 — последовательные версии C++-проекта"
aliases:
  - "Lab 01 Code Steps"
tags:
  - cpp
  - oop
  - laboratory
  - code
type: code-index
up: "[[Материалы для студентов/01_classes_and_object_model/01_oop_classes_and_object_model]]"
---

# Lab 01: последовательные версии проекта

Каждый пронумерованный <code>.cpp</code> является самостоятельной программой с собственной функцией <code>main()</code>. Файлы не нужно одновременно копировать в <code>src/</code>: CMake собирает каждый как отдельную цель.

## Сборка всех шагов

Из корня текущего пакета:

~~~bash
cmake --preset debug
cmake --build --preset debug
~~~

## Сборка одного шага

~~~bash
cmake --build --preset debug --target lab01_step_08_robot_v1
./build/debug/bin/lab01_step_08_robot_v1
~~~

## Правило работы

1. Сначала прочитайте и запустите текущий файл.
2. Найдите ограничение текущей модели.
3. Попробуйте внести следующее изменение самостоятельно.
4. Только затем откройте следующий файл.

Конспект: [[Материалы для студентов/01_classes_and_object_model/01_oop_classes_and_object_model|Лабораторная №1 — классы и устройство объектов]].
