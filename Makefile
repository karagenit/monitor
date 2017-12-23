D_OUT=bin/init
D_FILES=src/init.c src/monitor.c

U_OUT=bin/read
U_FILES=src/read.c

main: build

build: clean
	gcc -o $(D_OUT) -g $(D_FILES)
	gcc -o $(U_OUT) -g $(U_FILES)

test: build
	$(D_OUT)
	sleep 1
	$(U_OUT)

check: build
	valgrind --tool=memcheck --leak-check=yes $(D_OUT)

debug: build
	gdb $(D_OUT) -ex "set follow-fork-mode child"

clean:
	rm -f socket
	rm bin/*

docs:
	doxygen Doxyfile
