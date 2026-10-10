---
title: "Лабораторная №2 — последовательные примеры"
tags:
  - cpp
  - raii
  - examples
type: example-index
up: "../02_raii_constructor_exceptions_noexcept.md"
---

# Последовательные примеры

Изучайте файлы по порядку. Перед каждым запуском сначала предскажите результат.

| Шаг | Файл | Тема |
|---:|---|---|
| 01 | [01_manual_resource_management.cpp](01_manual_resource_management.cpp) | Почему ручное освобождение хрупко |
| 02 | [02_raii_owner.cpp](02_raii_owner.cpp) | RAII-владелец и инварианты |
| 03 | [03_stack_unwinding.cpp](03_stack_unwinding.cpp) | Раскрутка стека |
| 04 | [04_constructor_failure.cpp](04_constructor_failure.cpp) | Ошибка поля и ошибка тела конструктора |
| 05 | [05_exception_safe_resize.cpp](05_exception_safe_resize.cpp) | Базовая, строгая и невыбрасывающая гарантии; безопасный `resize()` |
| 06 | [06_noexcept_contracts.cpp](06_noexcept_contracts.cpp) | Спецификатор и оператор `noexcept` |
| 07 | [07_operator_overloading_basics.cpp](07_operator_overloading_basics.cpp) | Унарные и бинарные операторы, `++`, симметрия операндов, `operator()` |
| 08 | [08_array_operators.cpp](08_array_operators.cpp) | `operator[]`, `at()`, сравнение и вывод |

Для каждого шага:

1. прочитайте связанный раздел конспекта;
2. предскажите результат или порядок событий;
3. соберите и запустите пример;
4. объясните каждую строку, влияющую на время жизни или инвариант;
5. выполните эксперимент, предложенный в конспекте.
