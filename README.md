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
layout it's Ctrl+Shift+2. It may not work on your terminal!

```
user@host:~/brainfk$ ./brainfk examples/bubble_sort.bf
CAB^@
ABC
```

If you need to input small values that can not be
presented as ASCII characters, then try using printf:

```
user@host:~/brainfk$ printf "\02\04" | ./brainfk examples/multiply.bf
```

## Issues

I am not sure if this program works 100% correctly, so
it may cause segfaults, other errors or even work improperly
(even though I've tried my best writing and debugging it).
And it definitely will do everything from above if you write
BrainF#ck programs with errors (it interprets the code as it is
without checking if it goes out of borders, for example).
