objects = main.o Control.o Airline.o Part.o Date.o Aircraft.o View.o

a4: $(objects)
	g++ -o a4 $(objects)

main.o: main.cc
	g++ -c -g main.cc

Control.o: Control.h Control.cc
	g++ -c -g Control.cc

View.o: View.cc View.h
	g++ -c -g View.cc

Airline.o: Airline.cc Airline.h
	g++ -c -g Airline.cc

Aircraft.o: Aircraft.cc Aircraft.h
	g++ -c -g Aircraft.cc

Date.o: Date.cc Date.h
	g++ -c -g Date.cc

Part.o: Part.cc Part.h
	g++ -c -g Part.cc


clean:
	rm -f a4 *.o *.gch
