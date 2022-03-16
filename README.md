## Credits

This repo is a refactor of lutrarutra's sfml\_sortingAlgs:
https://github.com/lutrarutra/sfml_sortingAlgs

It is my first exposure to SFML.

I refactored the project because I felt it was a good way to learn
SFML and at the same time practice incorporating modern C++ features
into an existing code base.

## Overview of changes I made

- RAII: Use modern C++ smart pointers instead of raw pointers with new and
  delete.
  - use std::unique\_ptr and std::move().
  - remove unnecessary destructors.
  - pass object by reference instead of pointers (when ownership is
    not the focus).

- Use std::random_device and random engine for shuffling.

- Mark class member functions "const" when possible.

- Use modern C++ features like member initializer list, auto trailing
  return type, and auto type deduction when possible.

- Change all C-style arrays to std::vectors and pass them by const reference.
  - (possible optimization: maybe use std::array instead?)

- Refactored header files under "/include", and separate utility
  functions and variables into their own namespaces.
  - generous usage of "inline constexpr" (C++17) for global constants.

- Variable name changes for better readability.

- Remove other sorting algorithms except mergesort.

- Center UI window to user screen (by getting desktop mode with SFML).
