# 42_CPP_Module_06

## Global goal

Introduction to type casting in C++.

---

## Type conversion

---

## Implicit type conversions

Automatically performed when a value is copied to a compatible type where no data is lost. For example short to int. 

Converting from a int from a smaller integer type or from a double to a float is called a promotion, and it is garanteed not to truncate any value from the data.

Other conversions may not conserve all the value. Converting from a negative integer to an unsigned type results in the 2's complement bitwise representation (-1 becomes the largest value representable by the type, -2 the second largest etc (it loops around)).

Converting from floating point to int means that there is a possible truncation of the value, meaning what is after the decimal is not kept. 

If the conversion is from int to int and float to float, it can not work in certain cases due to the OS and is implementation specific(not portable).

If some of the data is lost, the compiler can issue a warning. the warning is issued if we use brace initialisation, making it a prefered way of initialising data so we avoid this type of error. This warning can be avoided if we cast using explicit casts, whereby the programmer takes full responsibility of the conversion.

This is the case of the static_cast.

```cpp
static_cast<int>(input)
```

if the input is a double, no warning will be issued. 

## Ex00

In ex00, we are asked to convert a literal (const char *) through a static method "convert" into the four types: char, int, double, and float where possible. 
We also need to treat the following cases:
- +inf, -inf
- +nan, -nan
- +nanf, -nanf

We had to convert it first to it's actual type (done through parsing) and then convert it explicitly to the three other data types.

My strategy: a structure containing an enum and a struct with the different types is used. 
1. First I identify the type using the strtof, strtod, strtol functions. If they do not manage to convert to the value, the endptr will not be on '\0' as it did not manage to convert until the end. I use the errno to analyse whether or not the function encountered an ERANGE or EINVAL error and I treat these errors accordingly.

If the conversion succeeded, then we set the type to the successful conversion and the corresponding value in the structure.
2. Then I perform a switch case on the type of the converted type and send to an overloaded function convert which behaves according to the type receicved (char, int, double, float). This is where we use a static_cast<type>(value).
3. Once the t_result structure is filled out, I send it to the overloaded operator who's behaviour is modified to output the converted types according to what the exercise wants.

```cpp
std::ostream& operator<<(std::ostream& os, t_result r);
```

## Ex01

In this excercise, we were asked to use another type of casting operator:

**data_type *var_name = reinterpret_cast<date_type>(pointer_variable);**

There is no return type, it simply converts to the pointer type and it only takes one parameter is the source pointer variable. 

A reinterpret_cast is a type of casting operator used in C++ used to convert a pointer of some type to a pointer of another data type, even if the data types before and after conversion are different.

```cpp
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
```

- The reinterpret cast is a dangerous type of casting operator.
- It can typecast a pointer into any other data type
- It is used whrn we want to work with bits

But the sentence which is the most important:

2) A pointer can be converted to any integral type large enough to hold all values of its type (e.g. to std::uintptr_t).


We had to write two static methods:
```cpp
uintptr_t serialize(Data* ptr);
```

It takes a pointer and converts it to the unsigned integer type uintptr_t.

```cpp
Data* deserialize(uintptr_t raw):
```

It takes an unsigned integer parameter and converts it to a pointer to Data.

