# 42_CPP_Module_06

## Global goal

Introduction to type casting in C++.

---

## Type conversion

type conversion of a value behaves much like a call to a function whose return type matches the target tye of the conversion. The data to be converted is passed as an arument and the converted result is returned (in a temporary object) returned to the caller.

```cpp
#include <iostream>

int main()
{
    int x { 10 };
    int y { 4 };

    std::cout << (double)x / y << '\n'; // C-style cast of x to double

    return 0;
}
```

Here, (double)x returns 10.0 as a temp obbject, and so y is automatically converted and a double floating point division is performed instead of an int division.

**Implicit type conversion warnings** are compile time warnings which will be thrown if ever the conversion results in a loss of data. For example whe you go from double 5.5 to 5 (loss of 0.5)

## Explicit type conversions

C++ upports a second method of type comversion called explicit tpe conversion. The programmer takes full responsibility of asking the compiler to convert a variable's type to another type.

The static_cast<new_type>(expresssion) is used and it returns the new value converted to the type specified by new_type. 

Because this is explicit, the compiler will not throw an error if we lose data.

## Casting vs initialising a temp object

If we have a variable x that we need to convert to an int, we have two options: direct initilaisation or static cast. 

If we use direct list initialisation int {x} which creates a temporary int object, list initialisation dissalows narrowing conversions, we will have an issue if we go from a 64 bit OS to a 32 bit OS with the conversion of int to double.

A duble uses 64 bts total, but only has 53 bits for storing the actual number. This means that it can represet all the 32 bit ints, but no the 64 bit ints. Here again, a compiler would throw an error.

To avoid this, we use static_cast<new_type>(value)