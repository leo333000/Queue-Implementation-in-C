#include "Queue.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

Node_t* Queue_new(){
    return NULL;
}

bool Queue_isEmpty(Node_t* iHead_ptr){
    return (iHead_ptr == NULL);
}

// Before:
// iHead_ptr -> A -> B -> NULL
// push C
// After:
// iHead_ptr -> C -> A -> B -> NULL
Node_t* Queue_push(Node_t* iHead_ptr, Customer_t iCustomer){
    Node_t * newNode_ptr;
    newNode_ptr = (Node_t *) malloc(sizeof(Node_t));

    newNode_ptr->value = iCustomer;
    newNode_ptr->next_ptr = iHead_ptr;
    return newNode_ptr;
}

void Queue_print(Node_t* iHead_ptr){
    Node_t * aCurrent_ptr = iHead_ptr;

    while (aCurrent_ptr != NULL) {
        printf("->%d", aCurrent_ptr->value);
        aCurrent_ptr = aCurrent_ptr->next_ptr;
    }
    printf("->NULL \n");
}

int Queue_size(Node_t* iHead_ptr){
    Node_t * aCurrent_ptr = iHead_ptr;
    int i=0;
    while (aCurrent_ptr != NULL) {
        i++;
        aCurrent_ptr = aCurrent_ptr->next_ptr;
    }
    return i;
}


// Before:
// -> iHead_ptr -> A -> B -> NULL
// pop
// After:
// -> iHead_ptr -> A -> Null
Customer_t Queue_pop(Node_t** ioAddress_Head_ptr){
    Node_t * aHead_ptr = *ioAddress_Head_ptr;

    if(Queue_isEmpty(aHead_ptr)){
        Customer_t aNoCustomer;
        aNoCustomer.waiting_time = -1;
        return aNoCustomer;
    }

    if(Queue_size(aHead_ptr) == 1){
        Customer_t aPoppedCustomer;
        aPoppedCustomer = aHead_ptr->value;
        free(aHead_ptr);
        *ioAddress_Head_ptr = NULL;
        return aPoppedCustomer;
    }

    Node_t * aCurrent_ptr = aHead_ptr;
    while (aCurrent_ptr->next_ptr->next_ptr != NULL) {
        aCurrent_ptr = aCurrent_ptr->next_ptr;
    }
    
    Customer_t aPoppedCustomer;
    aPoppedCustomer = aCurrent_ptr->next_ptr->value;
    free(aCurrent_ptr->next_ptr);
    aCurrent_ptr->next_ptr = NULL;
    return aPoppedCustomer;
}

// Before:
// -> iHead_ptr -> A0 -> B1 -> NULL
// RemoveExpired
// After:
// -> iHead_ptr -> B0 -> Null
Node_t* Queue_RemoveExpired(Node_t* ioHead_ptr){
    

    if(Queue_isEmpty(ioHead_ptr)){
        return NULL;
    }

     Node_t * aCurrent_ptr = ioHead_ptr;
     while (aCurrent_ptr->next_ptr != NULL) {
         

         if (aCurrent_ptr->next_ptr->value.waiting_time == 0)
         {
             
             if (aCurrent_ptr->next_ptr->next_ptr == NULL){
                 
                 free(aCurrent_ptr->next_ptr);
                 aCurrent_ptr->next_ptr = NULL;
             }
             else{
                 
                Node_t * aTemporary_ptr = aCurrent_ptr->next_ptr;
                aCurrent_ptr->next_ptr = aCurrent_ptr->next_ptr->next_ptr; 
                free(aTemporary_ptr);
             }
         }else{
             
             aCurrent_ptr->next_ptr->value.waiting_time--;
             aCurrent_ptr = aCurrent_ptr->next_ptr;
         }
    }

    if(ioHead_ptr->value.waiting_time == 0){
        Node_t * aTemporary_ptr = ioHead_ptr->next_ptr;
        ioHead_ptr = aTemporary_ptr;
        free(aTemporary_ptr);
        return ioHead_ptr;
    }else{
        ioHead_ptr->value.waiting_time--;
        return ioHead_ptr;
    }

}