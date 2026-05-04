# Contact Book in C

A command-line contact manager built in C, demonstrating dynamic memory management, structs, pointers, and file persistence.

## Features
- Add, list, search, and delete contacts
- Dynamic array that grows automatically using malloc and realloc
- Contacts persist between sessions via file storage
- Memory safe — null checks on all allocations, freed on exit
- Supports full names with spaces

## Build
gcc contact_book.c -o contact_book

## Run
./contact_book

## Concepts Demonstrated
- Dynamic memory allocation (malloc, realloc, free)
- Pointers and structs
- File I/O (fopen, fprintf, fscanf)
- Defensive programming with null checks
