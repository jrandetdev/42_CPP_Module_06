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

## Why conversions are needed and introduction to implicit conversion

The value of an object is stored as a sequence of bits. The data type of the object will tell the compiler how it should interpret those bits into meaningful values.

They are stored differently. For example, the integer value 3 might be stored as binary 0000 0000 0000 0000 0000 0000 0000 0011, whereas floating point value 3.0 might be stored as binary 0100 0000 0100 0000 0000 0000 0000 0000.

Explicit casts occur when the compiler converts from one data type to another without any data loss risk. For example I have an int and I want to convert it to a double: it is possible. 

We could want to be explicit and do 

```cpp
double value = 5.25;
int a = (int)value; // this will truncate the value (c style cast)
```

If the conversion cannot work, the compiler will produce a compile error. 

Narrowing conversions --> when the destination type could not hold the values of the source type (truncation)

ex: float to int, int to float, int to short, 

Narrowing conversions should be avoided but sometimes you still have to do an explicit conversion with a cast for function calls where the function parameters and argument may hve mistmatch tyoes. 

## Explicit casting

When we need to explicitly state that we are using a narrowing conversion, we use a static cast.

It doesn't do anything that C-style cast can't do. The conversion is a successful type conversion, but it adds synthax "sugar" to your code. 

It's a way to say that a static cast is actually a static cast, reinterpret cast is a type puning technique whereby you reinterpret the memory, const cast: I'm removing the constness of this value (making your actions explicit)

The different types of casts:
- static_cast : performs compile-time type conversions between related types
- dynamic_cast : Performs runtime type conversions on pointers or references in a polymorphism hierarchy (inheritance)
- const_cast : Adds or removes const
- C-style casts : performs a combination of all 3 listed above and is just not explicit.

C-style casting is done with the operator() and the name of the type used to convert is in the paranethesis. The issue is that it can perform a variety of different actions "under the hood", which can make the code more difficult to understand. 

It performs the following in order:
- const_cast
- static_cast
- static_cast, followed by const_cast
- reinterpret_cast
- reinterpret_cast, followed by const_cast


Casting an int into a char is potentially unsade (the compiler cannot tell whether the integer value will overflow the range of the char or not). To contour the error, we use static cast, which explicitly tells the compiler that this conversion is intended, and that we accept the responsibility for the consequences. 


---

## My strategy for the excercise 

I used a **discriminated union struct** as such:

```cpp
enum Type { CHAR, INT, DOUBLE, FLOAT, IMPOSSIBLE };

union Value
{
	char	c;
	int		i;
	double	d;
	float	f;
};

typedef struct	s_result
{
	Type	type;
	Value	value;
}				t_result;
```

The union will be of the size of the biggest data type (8 bits) and the Enum is with 4 ints, so 16 bytes total. 

The goal was to:
1. First parse the input, find the data type through getType function and store it in the Type part of the struct.
2. Then according to the Type found (CHAR, INT, DOUBLE, FLOAT, or IMPOSSIBLE), I use functions like atoi, atof, etc and convert it into its corresponding type.
3. Finally, I overloaded a function called convert_values and it's different versions will be called depending on what I send to the function.
4. Finally, I output it. 

This is the "cleanest" method I found, although I am not 100% satisfied with the if else chain.  