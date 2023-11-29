CC=g++ #Name of compiler
FLAGS=-std=c++20 -w #Compiler flags (the s makes it silent)
TARGET=Assignment2 #Executable name
OBJECTS=Assignment_2.o FiniteFunctions.o
LIBS=-I ../../GNUplot/ -lboost_iostreams

#First target in Makefile is default
${TARGET}:${OBJECTS} #Make target from objects
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} ${LIBS} -o ${TARGET}
	@make clean

Assignment_2.o : Assignment_2.cpp FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c Assignment_2.cpp

FiniteFunctions.o : FiniteFunctions.cxx FiniteFunctions.h
	${CC} ${FLAGS} ${LIBS} -c FiniteFunctions.cxx

clean: #No targets just run shell command to rm object files and emacs backups
	@rm -f *.o *~

cleantarget: #Delete the exectuable
	@rm -f ${TARGET}
