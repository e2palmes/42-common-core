*This project has been created as part of the 42 curriculum by ediba-de*

## Description
ft_printf is a project that aims to reproduce the behavior of the printf() function from libc.

This function handles the following conversions: cspdiuxX%

A `libftprintf.a` is generated at the root of the repository. There is also the ft_printf.h file that contains the prototype of ft_printf() function

## Instructions
#### step by step compilation

- clone the repository
- compile with `make` command
- the `libftprintf.a` should have been generated at the root of repository

if you have a main.c file using the library, compile it as follows:
`cc main.c libftprintf.a -o prog`
with prog being your program compiled output 

### How to use the library
You can embed the library to another one by copying the `libftprintf.a` file
or use it directly on your code with sources by including the `ft_printf.h` file header

## Resources

This project depands on the `libft` library included (sources on `libft` folder)
AI has been used here to compact the code, to meet the norm requirements.

- other references:

variadic functions: https://www.geeksforgeeks.org/c/variadic-functions-in-c/
printf man pages: http://manpagesfr.free.fr/man/man3/printf.3.html
Difference between %d and %i format specifier in C language: https://www.geeksforgeeks.org/c/difference-d-format-specifier-c-language/

## algorithm and data structure
The algorith used here is simply going througt the string passed as parameter, checking character by character.
- _If a % flag is found we check for conversion._
if the char is a % we check for the following char and convert to the corresponding element is necessary. (if a space comes after, for example, we don't do anything)

- _else we just write the current char_