D_OUT=bin/init
D_FILES=src/daemon/init.c src/daemon/monitor.c

U_OUT=bin/read
U_FILES=src/user/read.c

main: build

build: build_daemon build_user

build_daemon: $(D_FILES)
	gcc -o $(D_OUT) $(D_FILES)

build_user: $(U_FILES)
	gcc -o $(U_OUT) $(U_FILES)
	
