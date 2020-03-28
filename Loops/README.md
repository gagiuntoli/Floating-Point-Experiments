# Loop-1

This example initializes a simple precision floating point variable
`x` in `1 = 2^0` and divides it successively until reaching
`2^-126`. If the compiler does not support gradual underflow then the
next result would be `0`, if not, it will print `2^-127 - 2^-149` and
`0`.


