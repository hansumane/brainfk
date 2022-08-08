# BrainF#ck interpreter in C

## How to build

Compile with *compiler*, *flags* and **make**,
"gcc" is default compiler, and "-std=gnu99 -O2"
are default flags.

```
user@host:~/brainfk$ make CC=<compiler> FLAG=<flags>
```

## Usage

Provide filename with BrainF#ck source code,
and the program will interpret it.

```
user@host:~/brainfk$ ./brainfk examples/hello.bf
Hello World!
```

If your program requires input, you should
probably append null-terminator at the end of input,
as almost all of brainf#ck programs read the input this way:

```
user@host:~/brainfk$ echo -n "CAB\0" | ./brainfk examples/bubble_sort.bf
ABC
```

Or you can actually input Ctrl+@ to insert 0 to stdin. On US
keyboard it's Ctrl+Shift+2

```
user@host:~/brainfk$ ./brainfk examples/bubble_sort.bf
CAB^@
ABC
```

## Issues

I am not sure if this program works 100% correctly, so
it may cause segfaults, other errors or even work improperly
(even though I've tried my best writing and debugging it).
And it definitely will do everything from above if you write
BrainF#ck programs with errors (it interprets the code as it is
without checking if it goes out of borders, for example).
