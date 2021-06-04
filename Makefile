build:
	g++ -fpermissive -Wwrite-strings -Wreturn-type src/app.cpp -o bin/ppf
install:
	make build
	sudo cp bin/* /bin/
br:
	make build
	./bin/*
cmp-app:
	cpp src/app.cpp > cmp/cmp-app.cpp