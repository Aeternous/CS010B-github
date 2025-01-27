#include "IntList.h"
#include <algorithm>

bool IntList::bubbleUp(IntNode *curr) {
   if(!curr || !curr->next){
      return false;
   }
   bool swapped = bubbleUp(curr->next);

   if(curr->value > curr->next->value){
      swap(curr->value, curr->next->value);
      swapped = true;
   }

   return swapped;
}

bool IntList::bubbleUp() {
   if(!head || !head->next){
      return false;
   }
   
   return bubbleUp(head);
}
