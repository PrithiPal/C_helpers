
FILENAME=slack
COMPILER=gcc
FLAGS=-g -O0 -W -Wall

all: single_file

single_file : $(FILENAME)
	
	$(COMPILER) $(FLAGS)  $(FILENAME).c -o $(FILENAME).o
	 
clean:
	rm *.o