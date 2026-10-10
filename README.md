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

## Сборка любой лабораторной

Каждая лабораторная — самостоятельный CMake-проект, но имена presets и порядок сборки у всех одинаковые: `debug`, `release` и `sanitizers`. Команды нужно выполнять внутри директории выбранной работы.

### Linux

Нужны CMake, Ninja и GCC либо Clang. Например, в Ubuntu или Debian зависимости можно установить так:

~~~bash
sudo apt update
sudo apt install cmake ninja-build g++
~~~

Сборка и проверка из корня репозитория:

~~~bash
cd 01_classes_and_object_model
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
~~~

Запуск одного из примеров:

~~~bash
./build/debug/bin/lab01_step_08_robot_v1
~~~

### Windows

Нужны CMake, Ninja и MSVC из комплекта **Visual Studio 2022 Build Tools** с компонентом **Desktop development with C++**. Команды следует выполнять в **Developer PowerShell for VS 2022**, чтобы компилятор `cl.exe` был доступен CMake.

Сборка и проверка из корня репозитория:

~~~powershell
cd .\01_classes_and_object_model
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
~~~

Запуск одного из примеров:

~~~powershell
.\build\debug\bin\lab01_step_08_robot_v1.exe
~~~

В обоих случаях исполняемые файлы появятся в `build/debug/bin/`. Вместо `01_classes_and_object_model` можно указать директорию любой другой лабораторной.

## Сборка одного шага

~~~bash
cmake --build --preset debug --target lab01_step_08_robot_v1
~~~

Имена целей перечислены в `README.md` и `steps/README.md` выбранной лабораторной. Например, в работе №1 имя цели строится так:

~~~text
steps/08_robot_v1.cpp
        ↓
lab01_step_08_robot_v1
~~~

## Санитайзеры

Preset `sanitizers` предназначен для GCC и Clang и рекомендуется для Linux. При сборке MSVC используйте presets `debug` и `release`.

~~~bash
cmake --preset sanitizers
cmake --build --preset sanitizers
ctest --preset sanitizers
~~~

## VS Code

### Рекомендуемые расширения

При первом открытии VS Code предложит установить расширения из рекомендаций проекта:

- **C/C++** — поддержка C++ и отладчик MSVC в Windows;
- **CMake Tools** — работа с CMake presets;
- **CodeLLDB** — отладка в Linux и macOS.

### Открыть весь курс

Из корня репозитория выполните одну и ту же команду в Linux или Windows:

~~~bash
code OOP_labs.code-workspace
~~~

Если команда `code` недоступна, выберите в VS Code **File → Open Workspace from File...** и откройте файл `OOP_labs.code-workspace`.

В workspace доступны общие задачи:

- `Ctrl+Shift+B` — настроить и собрать сразу все лабораторные;
- **Terminal → Run Task... → Course: build all labs** — то же действие через меню;
- **Terminal → Run Task... → Course: test all labs** — собрать и проверить все лабораторные;
- задачи `Course: build lab ...` и `Course: test lab ...` — собрать или проверить только выбранную работу.

Все общие задачи работают и в Linux, и в Windows. Они вызывают одинаковые CMake presets из соответствующих директорий.

### Открыть одну лабораторную

В Linux:

~~~bash
code 02_raii_constructor_exceptions_noexcept
~~~

В Windows PowerShell:

~~~powershell
code .\02_raii_constructor_exceptions_noexcept
~~~

При таком способе доступны настройки из `.vscode` выбранной лабораторной:

- `Ctrl+Shift+B` в Windows/Linux или `Cmd+Shift+B` в macOS — собрать все шаги;
- **Terminal → Run Task... → CTest: run all...** — собрать и запустить все проверки лабораторной;
- **CMake: Select Configure Preset** — выбрать Debug, Release или Sanitizers;
- открыть нужный `steps/*.cpp`, перейти в **Run and Debug**, выбрать конфигурацию своей ОС и нажать F5 — собрать и запустить текущий пример под отладчиком.

Для Linux и macOS выбирайте конфигурацию с пометкой **LLDB**, для Windows с MSVC — конфигурацию с пометкой **MSVC**.

Конфигурация текущего примера формирует имя цели из имени открытого файла. Поэтому запуск через F5 предназначен для файлов из `steps/`. Задания из `tasks/` и решения из `solutions/` можно собирать общей задачей лабораторной и запускать из терминала.
