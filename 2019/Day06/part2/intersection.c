#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

char * findIntersection (planet *headA, planet *headB) {
    //take both lists
    //using intersection algorithm find intersection point

     planet *curr1 = headA, *curr2 = headB; 
     int counter = 0;
  
    // While both the pointers are not equal 
    while (strcmp(curr1->planet,curr2->planet)!=0) { 
        counter++;
  
        // If the first pointer is null then 
        // set it to point to the head of 
        // the second linked list 
        if (strcmp(curr1->planet,"COM")==0) { 
            curr1 = headB; 
        } 
  
        // Else point it to the next node 
        else { 
            curr1 = curr1->next; 
        } 
  
        // If the second pointer is null then 
        // set it to point to the head of 
        // the first linked list 
        if (strcmp(curr2->planet,"COM")==0) { 
            curr2 = headA; 
        } 
  
        // Else point it to the next node 
        else { 
            curr2 = curr2->next; 
        } 
    } 

    printf("ready to return intersection\n\n");
  
    // Return the intersection node 
    return curr1->planet; 

}