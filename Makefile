main:
	@mkdir -p build
	@cc -o build/main.o src/main.c src/cstring.c
	@./build/main.o