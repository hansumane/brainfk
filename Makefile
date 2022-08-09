CC=cc
BIN=brainfk
FLAG=-std=gnu99 -O2

$(BIN): src/main.c src/lib.h
	env $(CC) $(FLAG) -o $@ src/main.c

release: src/main.c src/lib.h
	env sed 's/\/\/ #define RELEASE/#define RELEASE/g' -i src/main.c
	env $(CC) $(FLAG) -o $(BIN) src/main.c
	env sed 's/#define RELEASE/\/\/ #define RELEASE/g' -i src/main.c

install: $(BIN)
	env mkdir -p ~/.local/bin
	env mv -f $(BIN) ~/.local/bin

clean:
	env rm -f $(BIN)

uninstall:
	env rm -f ~/.local/bin/$(BIN)

help:
	@env echo "make            --  compile '$(BIN)' binary"
	@env echo "make install    --  install '$(BIN)' to ~/.local/bin"
	@env echo "make uninstall  --  remove '$(BIN)' from ~/.local/bin"
	@env echo "make clean      --  remove '$(BIN)' binary"
