build:
	@g++ src/app.cpp -o bin/pfc
install:
	@make build
	@sudo cp bin/* /bin/