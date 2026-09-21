# 42 / 1337 — C++ Modules (00 - 09)

![C++](https://img.shields.io/badge/Language-C%2B%2B98-blue.svg)
![42](https://img.shields.io/badge/School-1337%20%2F%2042%20Network-black.svg)
![Score](https://img.shields.io/badge/Result-100%2F100-brightgreen.svg)

A comprehensive series of exercises designed to introduce and master Object-Oriented Programming (OOP) in C++ conforming strictly to the **C++98 standard**, as part of the 42 / 1337 common core curriculum.

---

## Table of Contents

- [Overview](#overview)
- [General Rules & Constraints](#general-rules--constraints)
- [Orthodox Canonical Form](#orthodox-canonical-form)
- [Modules Breakdown](#modules-breakdown)
  - [Module 00: Namespaces, Classes, Streams](#module-00-namespaces-classes-streams)
  - [Module 01: Memory Allocation, Pointers to Members, References](#module-01-memory-allocation-pointers-to-members-references)
  - [Module 02: Ad-hoc Polymorphism, Operator Overloading, OCF](#module-02-ad-hoc-polymorphism-operator-overloading-ocf)
  - [Module 03: Inheritance](#module-03-inheritance)
  - [Module 04: Subtype Polymorphism, Abstract Classes, Interfaces](#module-04-subtype-polymorphism-abstract-classes-interfaces)
  - [Module 05: Repetition and Exceptions](#module-05-repetition-and-exceptions)
  - [Module 06: C++ Type Casts](#module-06-c-type-casts)
  - [Module 07: C++ Templates](#module-07-c-templates)
  - [Module 08: Templated Containers, Iterators, Algorithms](#module-08-templated-containers-iterators-algorithms)
  - [Module 09: STL Containers](#module-09-stl-containers)
- [Compilation & Execution](#compilation--execution)

---

## Overview

The C++ modules transition developers from procedural programming in C to Object-Oriented Programming in C++. The curriculum progressively covers encapsulation, memory management, inheritance, polymorphism, exceptions, type casting, templates, and the Standard Template Library (STL).

---

## General Rules & Constraints

- **Standard**: Strictly compiled using `c++` with the flags `-Wall -Wextra -Werror -std=c++98`.
- **Prohibited**:
  - Usage of external libraries (Boost, etc.) or modern C++ features (`auto`, `nullptr`, C++11 ranged for-loops, lambda expressions, etc.).
  - Standard C functions (`printf`, `malloc`, `free`) unless explicitly authorized.
  - Memory leaks: All allocated memory must be properly freed without leaks or double frees.
  - Header guards (`#ifndef`, `#define`, `#endif`) must be present on every header file.

---

## Orthodox Canonical Form

Starting from Module 02, classes must conform to the **Orthodox Canonical Form (OCF)** unless specified otherwise:

```cpp
class Sample {
    public:
        Sample(void);                               // Default constructor
        Sample(const Sample &src);                  // Copy constructor
        Sample &operator=(const Sample &rhs);       // Assignment operator
        ~Sample(void);                              // Destructor
};
```

---

## Modules Breakdown

| Module | Core Concepts | Key Exercises |
| :--- | :--- | :--- |
| **CPP 00** | Namespaces, classes, member functions, `iostream`, static attributes | Megaphone, PhoneBook, Account log recreation |
| **CPP 01** | `new`/`delete`, heap vs stack, references, pointers to members, file streams | Zombie, Weapon/Human, File string replacement (sed), Harl |
| **CPP 02** | Fixed-point numbers, operator overloading, Orthodox Canonical Form | Fixed-point representation, BSP (Point in Triangle) |
| **CPP 03** | Single and diamond inheritance, construction/destruction chains | ClapTrap, ScavTrap, FragTrap, DiamondTrap |
| **CPP 04** | Subtype polymorphism, virtual functions, abstract classes, interfaces | Animal/Dog/Cat, Brain (deep copying), AMateria |
| **CPP 05** | Nested exceptions, `try`/`catch`, structured forms | Bureaucrat, Form/AForm execution, Intern factory |
| **CPP 06** | `static_cast`, `reinterpret_cast`, `dynamic_cast`, scalar conversions | Scalar conversion, Pointer serialization, Type identification |
| **CPP 07** | Function templates, class templates | `swap`/`min`/`max`, `iter`, custom `Array<T>` |
| **CPP 08** | Templated containers, iterators, standard algorithms | `easyfind`, `Span`, iterable `MutantStack` |
| **CPP 09** | STL containers, algorithmic complexity, sorting | Bitcoin Exchange (`map`), RPN (`stack`), PmergeMe (`vector`/`deque`) |

---

### Module 00: Namespaces, Classes, Streams
- **ex00 - Megaphone**: Command line argument manipulation and standard output formatting using `std::cout`.
- **ex01 - My Awesome PhoneBook**: Implementing basic classes, member functions, field truncation, and input validation without dynamic memory.
- **ex02 - The Job of Your Dreams**: Reverse-engineering an `Account` class implementation by matching target timestamped log outputs and managing static variables.

### Module 01: Memory Allocation, Pointers to Members, References
- **ex00 & ex01 - Zombie / Moar brainz!**: Stack vs heap memory allocation with `new` and `delete[]`.
- **ex02 - HI THIS IS BRAIN**: Demystifying pointers vs references in memory.
- **ex03 - Unnecessary violence**: Designing classes containing references vs pointers according to lifetime and nullability.
- **ex04 - Sed is for losers**: Reading and writing files using `std::ifstream` and `std::ofstream`, replacing target substrings without forbidden methods.
- **ex05 & ex06 - Harl 2.0 / Harl filter**: Dispatching member functions via pointers-to-member-functions and `switch-case` level filtering.

### Module 02: Ad-hoc Polymorphism, Operator Overloading, OCF
- **ex00 to ex02 - Fixed Point Class**: Implementing fixed-point arithmetic, raw bit conversions, comparison, arithmetic, and increment/decrement operators.
- **ex03 - BSP**: Implementing Binary Space Partitioning algorithm to check if a point lies strictly within a 2D triangle.

### Module 03: Inheritance
- **ex00 to ex02 - ClapTrap, ScavTrap, FragTrap**: Basic inheritance, attribute overriding, and observing base/derived constructor and destructor execution order.
- **ex03 - DiamondTrap**: Resolving the diamond inheritance problem using `virtual` inheritance.

### Module 04: Subtype Polymorphism, Abstract Classes, Interfaces
- **ex00 - Polymorphism**: Virtual member functions, dynamic dispatch, and virtual destructors.
- **ex01 - I don’t want to set the world on fire**: Avoiding shallow copies by implementing strict deep-copy logic for dynamically allocated class members (`Brain`).
- **ex02 - Abstract class**: Pure virtual functions preventing instantiation of incomplete base classes (`AAnimal`).
- **ex03 - Interface & recap**: Pure abstract interfaces (`IMateriaSource`, `ICharacter`) and concrete resource management.

### Module 05: Repetition and Exceptions
- **ex00 - Bureaucrat**: Creating custom exception classes inheriting from `std::exception` with `gradeTooHighException` and `gradeTooLowException`.
- **ex01 - Form**: Applying exceptions to state verification.
- **ex02 - Concrete Forms**: Concrete form execution (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`).
- **ex03 - Intern**: Factory pattern implementation returning concrete forms via function pointers matching form names.

### Module 06: C++ Type Casts
- **ex00 - ScalarConverter**: Parsing literal strings (char, int, float, double) and detecting edge cases (`nan`, `+inf`, `-inf`) using `static_cast`.
- **ex01 - Serializer**: Serializing data pointers to `uintptr_t` and restoring them using `reinterpret_cast`.
- **ex02 - Identify real type**: Detecting underlying polymorphic types at runtime using `dynamic_cast` with pointers and references (handling `std::bad_cast`).

### Module 07: C++ Templates
- **ex00 - Start with a few functions**: Writing generic function templates for `swap`, `min`, and `max`.
- **ex01 - Iter**: Writing a function template that executes a callback function across array elements.
- **ex02 - Array**: Developing a generic `Array<T>` template class with bounds-checked `operator[]` and dynamic allocation.

### Module 08: Templated Containers, Iterators, Algorithms
- **ex00 - Easy find**: Writing a template function searching across standard sequence containers using STL iterators.
- **ex01 - Span**: Class storing numbers that computes the shortest and longest spans between any stored elements, with range-iterator filling.
- **ex02 - MutantStack**: Making `std::stack` iterable by inheriting from the container adapter and exposing the underlying container's iterators.

### Module 09: STL Containers
- **ex00 - Bitcoin Exchange**: Database rate matching using `std::map` and `std::map::lower_bound` for date comparisons.
- **ex01 - Reverse Polish Notation**: Evaluating postfix mathematical expressions using `std::stack`.
- **ex02 - PmergeMe**: Implementing the **Ford-Johnson algorithm** (merge-insertion sort) with two distinct containers (`std::vector` and `std::deque`), profiling and comparing execution times.

---

## Compilation & Execution

Each exercise directory contains a standalone `Makefile`.

```bash
# Navigate to any exercise directory
cd cpp04/ex00

# Compile using the default rule
make

# Execute the resulting binary
./polymorphism

# Clean object files and binary
make fclean
```

### Memory Leak Checking

Verify execution clean of leaks using `valgrind` (Linux) or `leaks` (macOS):

```bash
# Linux
valgrind --leak-check=full --show-leak-kinds=all ./binary

# macOS
leaks --atExit -- ./binary
```
