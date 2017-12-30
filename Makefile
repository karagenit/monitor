EXE=bin/lsdev
FILES=src/init.c src/monitor.c src/directory.c src/read.c src/lsdev.c

main: build

build: clean
	gcc -o $(EXE) -g $(FILES)

test: build
	@echo "Running Test\n-----------"
	@$(EXE) init
	@sleep 1
	@./test/create.sh
	@sleep 2
	@$(EXE) read
	@sleep 1
	@./test/remove.sh
	@sleep 2
	@$(EXE) read

check: build
	valgrind --tool=memcheck --leak-check=yes $(EXE)

debug: build
	gdb $(EXE) -ex "set follow-fork-mode child"

clean:
	rm -f socket
	rm -f bin/*

docs:
	doxygen Doxyfile
