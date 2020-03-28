# Handling FP Exceptions in C++

There are five kind of exceptions:

      1) Invalid Operation: Set result to NaN. Eg. 0 / 0 operation.

      2) Division by zero: Set the result to -Inf or +Inf. Eg. a / 0
      a != 0.

      3) Overflow: Set result to +Nmax, +Inf, -Nmax or -Inf.

      4) Underflow: Set result to +Nmin, +0, -Nmin or -0.

      5) Inexact: Set result to correctly rounded value.

