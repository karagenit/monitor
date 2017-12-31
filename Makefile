EXE=bin/monitor
FILES=src/init.c src/monitor.c src/directory.c src/read.c src/main.c
INSTALL=/usr/local/bin/monitor

main: build

build: clean
	gcc -o $(EXE) -g $(FILES)

test: build
	@echo "Running Test\n-----------"
	@$(EXE) init ./test 1
	@sleep 1
	@./test/create.sh
	@sleep 2
	@$(EXE) read ./test
	@sleep 1
	@./test/remove.sh
	@sleep 2
	@$(EXE) read ./test
	@$(EXE) kill ./test

check: build
	valgrind --tool=memcheck --leak-check=yes $(EXE)

debug: build
	gdb $(EXE) -ex "set follow-fork-mode child"

clean:
	rm -f test/socket
	rm -f bin/*

docs:
	doxygen Doxyfile

release: clean
	gcc -o $(EXE) -O2 $(FILES)

install: release
	cp $(EXE) $(INSTALL)
