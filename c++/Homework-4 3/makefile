prog: main.o flights.o flight.o crewMember.o crewMembers.o plane.o planes.o
	g++ -o prog main.o flights.o flight.o crewMember.o crewMembers.o plane.o planes.o

main.o: flights.h main.cpp
	g++ -c main.cpp
	
flights.o: flight.h flights.cpp
	g++ -c flights.cpp

flight.o: crewMembers.h planes.h flight.cpp
	g++ -c flight.cpp
	
crewMembers.o: crewMembers.cpp crewMember.h
	g++ -c crewMembers.cpp

crewMember.o: crewMember.cpp
	g++ -c crewMember.cpp

planes.o: planes.cpp plane.h
	g++ -c planes.cpp

plane.o: plane.cpp
	g++ -c plane.cpp
clean:
	rm prog main.o flights.o flight.o crewMember.o crewMembers.o plane.o planes.o
run:
	./prog
