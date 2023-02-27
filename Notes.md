# Notes taken during the courses

## Contents

1. [Programming Fundamentals](#programming-fundamentals)

2. [Structured Programming](#structured-programming)


## 1. Programming Fundamentals

### Main topics
1. How to use the compiler (GCC and Vim);
2. Lexical elements (identifiers, constants, operators, punctuation, keywords,comments)
3. Fundamental data types (int, float, char)
4. Flow of control (compound statement, loops, decision)
5. Functions (call by value, definition, declaration, prototype, storage class {static})
6. Arrays, Pointers and Strings (call by ref)


### Comma operator
The comma operator is written as this;
```
    expression1, expression2
```
and its semantics are first expression1 gets evaluated. Only after that does expression2 get evaluated and the value of the overall expression is expression2.
```
    c = ( a = 0 , b = 1);
    printf("%d.", c);     //It will print 1
```

### Things to think about

A function largely should should do one thing well. This do one thing, they don't move multiple things.

Keep the function in one page. It should be like a paragraph. It is easy to test. A function is a unit you can manage and test efficiently (pre conditions and pos conditions)

## 2. Structured Programming

### Main topcis

1. Enumerations as ADT
2. The C preprocessor
### ADT

**Abstract Data Type** is a concept or model of a data type. An abstract data type is defined by its behavior (semantics) from the point of view of a user, of the data, specifically in terms of possible values, possible operations on data of this type, and the behavior of these operations. From [Wikipedia](https://en.wikipedia.org/wiki/Abstract_data_type).

### The C preprocessor

The C preprocessor does things before the actual code got compiled, like **link** in standard files (```#include <stdio.h>, #include <math.h>```, which means go and look it in a standard place and get one of the C standard header file), and it also does macro expansion (```#define C 123.56```).

Now in more modern languages, those are frequently just a component
of the overall compiler and there's frequently nothing to do with a preprocessor.

Tip to compile and expand macros:

```gcc -E -o file_expanded.c file.c```

### LIFO

Last in first out!
