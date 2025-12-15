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

Convertimg from floating point to int means that there is a possible truncation of the value, meaning what is after the decimal is not kept. 

If the conversion is from int to int and float to float, it can not work in certain cases due to the OS and is implementation specific(not portable).

If some of the data is lost, the compiler can issue a warning. This warning can be avoided if we cast using explicit casts. 

## Ex00

In ex00, we are asked to convert a literal (const char *) through a static method "convert" into the four types: char, int, double, and float where possible. 
We also need to treat the following cases:
- +inf, -inf
- +nan, -nan
- +nanf, -nanf

We had to convert it first to it's actual type (done through parsing) and then convert it explicitly to the three other data types.

My strategy 


## Ex01

In this excercise, we were asked to use another type of casting operator:

**reinterpret_cast<type>(data)**

We had to write two static methods:
```cpp
uintptr_t serialize(Data* ptr);
```

It takes a pointer and converts it to the unsigned integer type uintptr_t.

```cpp
Data* deserialize(uintptr_t raw):
```

It takes an unsigned integer parameter and converts it to a pointer to Data.

