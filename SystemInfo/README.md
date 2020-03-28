# System Information

This program is used to check the system-dependent parameters that
are used in the floating point arithmetics such as data models,
endianess, rounding mode, etc.

## Data Models

Depending on the system the sizes of the `int`, `long` or `pointer`
can change. Table presented in
[cppreference](https://en.cppreference.com/w/cpp/language/types) shows
that:

| Type Specifier  | LP32 | ILP32 | LLP64 | LP64 |
|:---------------:|:----:|:-----:|:-----:|:----:|
|    short int    |  16  |  16   |  16   |  16  |
|       int       |  16  |  32   |  32   |  32  |
|    long int     |  32  |  32   |  32   |  64  |
| long long int   |  64  |  64   |  64   |  64  |

## Endianess

Suppose that a floating point number is represented with 0x02A4410F
then in memory this number can be represented with:

Big Endian format
-----------------

    0x02  (A) position in memory
    0xA4  (A) + 1
    0x41  (A) + 2
    0x0F  (A) + 3

Big Endian format
-----------------

    0x0F  (A) position in memory
    0x41  (A) + 1
    0xA4  (A) + 2
    0x02  (A) + 3

## Rounding Mode

The rounding mode determines how the floating point arithmetic results
are rounded. The default in the IEEE standard is the _rounding to the
nearest_ mode.

## Testing
----------

The test to check which data model is your system using can be
compiled and run with:

    make
    ./SystemInfo

On my system:

    int_size           :4
    long_int_size      :8
    pointer_size       :8
    long_long_int_size :8
    It seems you have a LP64 or 4/8/8 system (64 bits)-> Unix or Unix-like.


