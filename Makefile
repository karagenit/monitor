D_OUT=bin/init
D_FILES=src/init.c src/monitor.c

U_OUT=bin/read
U_FILES=src/read.c

main: build

build: build_daemon build_user

build_daemon: $(D_FILES)
	gcc -o $(D_OUT) -g $(D_FILES)

build_user: $(U_FILES)
	gcc -o $(U_OUT) -g $(U_FILES)
	
