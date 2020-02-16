#include <stdlib.h>
#include <stdio.h>

#define MAX_STACK_SIZE 5 

struct stack{
    int size ; 
    int *ptr ; 
    int *head_ptr; 
    int max_size;
} ; 

void initializeStack(struct stack *my_stack ){
    // initializes the stack with the values 
    printf("initializeStack()\n") ; 
    my_stack->size = 0 ; 
    my_stack->max_size = MAX_STACK_SIZE ; 
    my_stack->ptr = (int *)malloc(MAX_STACK_SIZE*sizeof(int)); 
    my_stack->head_ptr = my_stack->ptr;  
}

void printStack(struct stack *my_stack){
    // print the reverse array becaue of LIFO structure
    printf("printStack()\n") ; 
    int current_size = my_stack->size; 
    for(int i = 0 ; i < my_stack->size; i ++){
        printf("%d ",my_stack->ptr[current_size-i-1]); 
    }
    
}

void pushStack(struct stack *my_stack, int value){
     printf("pushStack()\n") ; 
    int current_size = my_stack->size ; 
    
    if(current_size==MAX_STACK_SIZE-1){
        my_stack->ptr = (int *)realloc(my_stack->ptr,2*my_stack->max_size*sizeof(int)) ;
        my_stack->head_ptr=my_stack->ptr; 
        my_stack->head_ptr+=current_size;
        my_stack->max_size=2*my_stack->max_size;

    }
    
    *(my_stack->ptr + current_size) = value ; 
    my_stack->size++; 
    // move pointer to point to latest added entry 
    my_stack->head_ptr++; 
}

void popStack(struct stack *my_stack){
    *(my_stack->head_ptr-1) = 0 ; // reset to zero for later use. 
    my_stack->head_ptr--;
    my_stack->size--;
}

void peekStack(struct stack *my_stack){
    printf("peenStack()\n");
    printf("%d\n",*(my_stack->head_ptr-1)) ; 
}


int main(){

    struct stack s ; 
    initializeStack(&s);

    pushStack(&s,1);
    pushStack(&s,2);
    pushStack(&s,3);
    pushStack(&s,4);
    pushStack(&s,5);
    pushStack(&s,1);
    pushStack(&s,2);
    pushStack(&s,3);
    pushStack(&s,4);
    pushStack(&s,5);

    popStack(&s) ; 
    popStack(&s) ; 
    popStack(&s) ; 
    popStack(&s) ; 

    peekStack(&s);
    printStack(&s);
    //printf("%d \n",s.max_size);

}