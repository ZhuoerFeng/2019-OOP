FLAGS = -std=c++11
main: main.o
	g++ -o main main.o $(FLAGS)
main.o: main.cpp AbstractCoffee.h CoffeeFactory.h MakeCoffee.h EasyMake.h Cup.h Coffee.h
	g++ -c $(FLAGS) main.cpp
clean:
	rm *.o main