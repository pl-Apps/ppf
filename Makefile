build:
	@g++ src/app.cpp -o bin/ppf
install:
	@make build
	@sudo cp bin/* /bin/
br:
	@make build
	@./bin/*