/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>



struct node {
  int value ; 
  struct node  *next_ptr ; 
};


// returns pointer to the first node.
// input is size s 
void createLinkedListFromArray(int *arr, struct node *startNode, int size){
    
    startNode->value = *arr ; // first elem
    
    struct node *prevNode ; 
    
    for(int i = 0 ; i < size-1 ; i ++ ){
        
        struct node *my_node = (struct node *)malloc(sizeof(struct node)) ; 
        my_node->value = *(arr+i+1) ; 
        
        // second node 
        if(i==0){
            startNode->next_ptr = my_node; 
        }// >2 node 
        else{
            prevNode->next_ptr = my_node ; 
        }
        
        prevNode = my_node ; 
        
    }
    prevNode->next_ptr=NULL;
    
}

void printLinkedList(struct node *startNode, int size){
    
    struct node *ptr = startNode ;   
    
    while(ptr!=NULL){
        printf("%d -> ",ptr->value);
        ptr = ptr->next_ptr ; 
    }
    
    printf("NULL \n");
    
}

void insertNode(struct node *firstNode, int value){
    
    struct node *ptr = firstNode ; 
    while(ptr->next_ptr!=NULL){
        ptr = ptr->next_ptr; 
    }
    
    struct node *new_node = (struct node *)malloc(sizeof(struct node *));  
    ptr->next_ptr = new_node ; 
    new_node->next_ptr = NULL;
    new_node->value = value ; 
    
}

void createGreaterLinkedList(struct node *ll, struct node *ll1, struct node *ll2){
    int firstElem = ll1->value ; 
    int secondElem  = ll2->value ;  
    struct node *prev; 
    int i = 0 ; 
    
    // first node configurations.
    if(firstElem > secondElem){
        ll->value = firstElem;
    }
    else{
        ll->value = secondElem ; 
    }
    prev = ll ; 
    ll1 = ll1->next_ptr ; 
    ll2 = ll2->next_ptr ;

    // remaining nodes configurations
    while(ll1!=NULL){
        
        // create a new node.
        
        struct node *new_node = (struct node *)malloc(sizeof(struct node )) ; 
        prev->next_ptr=new_node;
        

        firstElem = ll1->value ; 
        secondElem = ll2->value ; 
        
        if(firstElem > secondElem){
            new_node->value = firstElem;
        }
        else{
            new_node->value = secondElem ; 
        }

        prev = new_node ; 
        ll1 = ll1->next_ptr ; 
        ll2 = ll2->next_ptr ;  
        i++; 
    }
    
    prev->next_ptr=NULL; 

}

int main(){

    // linked list #1
    struct node firstNode ; 
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    createLinkedListFromArray(arr,&firstNode,10);
    printLinkedList(&firstNode,10);
    
    //insertNode(&firstNode,11);
    //printLinkedList(&firstNode,11);
    
    // linkedlist #2
    struct node anotherNode;  
    int arr2[10] = {10,20,30,40,50,60,70,80,90,100} ; 
    createLinkedListFromArray(arr2,&anotherNode,10);
    printLinkedList(&anotherNode,10);

    // additive linkedlist #3
    struct node combinedNode; 
    createGreaterLinkedList(&combinedNode,&firstNode,&anotherNode);
    printLinkedList(&combinedNode,10);
    return 0 ; 
}