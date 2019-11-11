run: compile
	@./avl.o

compile:
	@clang++ -o avl.o main.cpp

clean:
	@rm *.o
