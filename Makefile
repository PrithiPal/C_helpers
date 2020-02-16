

FILENAME=stack
ALL_FILES=stack linked_list double_linked_list
COMPILER=gcc
FLAGS=-g -W -Wall


%.o : %.c 
	$(COMPILER) $(FLAGS) $@ -o $<

all_files_named: $(ALL_FILES) 
	
stack: 
	$(COMPILER) $(FLAGS) stack.c -o stack.o
linked_list: 
	$(COMPILER) $(FLAGS) linked_list.c -o linked_list.o
double_linked_list: 
	$(COMPILER) $(FLAGS) double_linked_list.c -o double_linked_list.o

single_file : $(FILENAME)
	$(COMPILER) $(FLAGS)  $(FILENAME).c -o $(FILENAME).o

	 
clean:
	rm *.o
