# Counting FLOPs with `perf`

For counting FLOPs with `perf` the counter codes for floating point should be
given as input:

    perf -e <counter> executable

For this the program [`libpfm4`](https://github.com/wcohen/libpfm4) is used to get the counter code. Clone the repo and compile:

    git clone git@github.com:wcohen/libpfm4.git
    cd libpfm4
    make

In my machine with an Intel Core i5-9300H processor:
    
    cd examples
    ./showevtinfo 

    [...]
    IDX  : 419430469
    PMU name : skl (Intel Skylake)
    Name     : FP_ARITH
    Equiv  : FP_ARITH_INST_RETIRED
    Flags    : None
    Desc     : Floating-point instructions retired
    Code     : 0xc7
    Umask-00 : 0x01 : PMU : [SCALAR_DOUBLE] : None : Number of scalar double precision ...
    Umask-01 : 0x02 : PMU : [SCALAR_SINGLE] : None : Number of scalar single precision ...
    [...]

then do:

    ./check_events FP_ARITH:SCALAR_DOUBLE

    [...]
    Requested Event: FP_ARITH:SCALAR_DOUBLE
    Actual    Event: skl::FP_ARITH_INST_RETIRED:SCALAR_DOUBLE:k=1:u=1:e=0:i=0:c=0:t=0:intx=0:intxcp=0
    PMU            : Intel Skylake
    IDX            : 419430470
    Codes          : 0x5301c7
    Requested Event: FP_ARITH:SCALAR_SINGLE
    Actual    Event: skl::FP_ARITH_INST_RETIRED:SCALAR_SINGLE:k=1:u=1:e=0:i=0:c=0:t=0:intx=0:intxcp=0
    PMU            : Intel Skylake
    IDX            : 419430470
    Codes          : 0x5302c7

run the programs with `perf` now:

    perf -e r5301c7 -e r5302c7 main_1
    
    main_1: This program does 1 single FPO and 1 double FPO

    Performance counter stats for './main_1':

                 2      r5301c7:u                                                   
                 0      r5302c7:u                                                   

    0.002051261 seconds time elapsed

    0.002057000 seconds user
    0.000000000 seconds sys

In the example above there is an error but until know was not possible to
recognize the causes.

--------------------

    perf -e r5301c7 -e r5302c7 main_2

    main_2: This program does 20 double FPOs

    Performance counter stats for './main_2':

                20      r5301c7:u                                                   
                 0      r5302c7:u                                                   

    0.001650988 seconds time elapsed

    0.001661000 seconds user
    0.000000000 seconds sys

--------------------

    perf -e r5301c7 -e r5302c7 main_3

    main_3: This program does 20 single FPOs and 20 double FPOs

    Performance counter stats for './main_3':

                20      r5301c7:u                                                   
                20      r5302c7:u                                                   

    0.001369726 seconds time elapsed

    0.001400000 seconds user
    0.000000000 seconds sys
