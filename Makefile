D_OUT=bin/init
D_FILES=src/init.c src/monitor.c

U_OUT=bin/read
U_FILES=src/read.c

main: build

build:
	gcc -o $(D_OUT) -g $(D_FILES)
	gcc -o $(U_OUT) -g $(U_FILES)

test:
	valgrind --tool=memcheck --leak-check=yes bin/init

debug:
	gdb bin/init
