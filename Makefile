CC=gcc
BIN=brainfk
FLAG=-std=gnu99 -O2

$(BIN): src/main.c src/lib.h
	env $(CC) $(FLAG) -o $@ src/main.c

help:
	@env echo "make        --  compile '$(BIN)' binary"
	@env echo "make clean  --  remove '$(BIN)' binary"

clean:
	env rm -f $(BIN)
