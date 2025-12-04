# 42_CPP_Module_06

## Global goal

Introduction to type casting in C++.

---

## ex00 : Conversion of scalar types

## Objective

We need to write a ScalarConverter class that contains one static method called `convert` that will take as parameter a string representation of a C++ literal in its most common form (const char* literal) and output its value in the following series of scalar types:

- char ( for example 'a' 'c' etc. no special character are treated) If a conversion to char is not a displayable, we need to print an informative message.
- int (0, -42, 42...) 
- float (0.0f, -4.2f, 4.2f,... and some pseudo literals such as -inff and +inff)
- double (0.0, -4.2, 4.2 and +inf and -inf)

The class does not store anything, and it should not be instantiable by users (probably meaning it is abstract).

First I have to detect the type of literal passed as a param, convert it from string to its actual type, then convert it explicitly to the three other data types. I have to display the results as shown below:

```bash
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

---

## Recap on Literals because apparently I forgot. *sigh*

Literals are fundemental elements used to represent fixed values. They can include numbers, characters, strings, and more.

There are 5 types of literals:
- Integer literals --> in this excercise, we use decimal representation and not another base like hexadecimal etc.
- Floating-point literals
- Character literals
- String literals (I guess this is the one I will use)
- Boolean literals 