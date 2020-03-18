# Floating Point Experiments

Experiments to check the floating point and integer representation
your system is implementing. Notice that this depends on the
architecture, operating system and compiler.

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

The test to check which data model is your system using can be
compiled and run with:

    make DataModels
    ./Datamodels

On my system:

    int_size           :4
    long_int_size      :8
    pointer_size       :8
    long_long_int_size :8
    It seems you have a LP64 or 4/8/8 system (64 bits)-> Unix or Unix-like.


