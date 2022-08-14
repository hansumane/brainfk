# BrainF#ck interpreter in C

## How to build & install

Compile with *compiler*, *flags* and **make**,
"cc" is default compiler, and "-std=gnu99 -O2"
are default flags. Programs are installed to
**~./local/bin/**, so please add this folder
to your PATH

```
user@host:~/brainfk$ make install CC=<compiler> FLAG=<flags>
```

## Usage

### Flags

The program supports two flags for now: **-d*n*** for *debug*
and **-n** for *no newline*. The debug flag prints 16 * n first
bytes to stdout after program has finished. The no-newline flag
prevents printing newline character after program has finished
if the last printed character is not newline character.
Default n value for **-d*n*** is 1

```
user@host:~/brainfk$ ./brainfk examples/hello.bf -d5  # or
user@host:~/brainfk$ ./brainfk -d5 examples/hello.bf
Hello World!
  0,  33,  72,  87, 100,   0,   0 . . .
```

### Main usage

Provide filename with BrainF#ck source code,
and the program will interpret it.

```
user@host:~/brainfk$ ./brainfk examples/hello.bf
Hello World!
```

If your program requires input, you should
probably append null-terminator at the end of input,
as almost all of BrainF#ck programs read the input this way:

```
user@host:~/brainfk$ echo -n "CAB\0" | ./brainfk examples/bubble_sort.bf
ABC
```

Or you can actually input Ctrl+@ to insert 0 to stdin. On US
layout it's Ctrl+Shift+2. It may not work on your terminal!

```
user@host:~/brainfk$ ./brainfk examples/bubble_sort.bf
CAB^@
ABC
```

If you need to input some small values that can not be
presented as ASCII characters, then try using printf:

```
user@host:~/brainfk$ printf "\2\4" | ./brainfk examples/multiply.bf -d  # or
user@host:~/brainfk$ printf "\x2\x4" | ./brainfk examples/multiply.bf -d
```

## Issues

I am not sure if this program works 100% correctly, so
it may cause segfaults, other errors or even work improperly
(even though I've tried my best writing and debugging it).
And it definitely will do everything from above if you write
BrainF#ck programs with errors (it interprets the code as it is
without checking if it goes out of borders, for example).
