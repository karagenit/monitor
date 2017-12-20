INIT_OUT=bin/init
INIT_FILES=src/init.c
COMM_OUT=bin/comm

main: build

build: build_init build_comm

build_init: $(INIT_FILES)
	gcc -o $(INIT_OUT) $(INIT_FILES)

build_comm:
	
