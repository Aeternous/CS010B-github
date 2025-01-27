// Name: (Score was 15/15)
// NetID: 

#include "List.h"

// Implement the private member function
void List::remove_after(Node *n) {
    if (n == nullptr) {
        if (head == nullptr) {
            return;
        }
        Node* to_remove = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete to_remove;
        return;
    }

    if (n->next == nullptr) {
        return;
    }

    Node* to_remove = n->next;
    n->next = to_remove->next;
    if (to_remove == tail) {
        tail = n;
    }
    delete to_remove;
}

/*
Alternate way of solving this:
To refrain from using the return function, we can use
a "if else" statement logic which would be slower in the
sense that the code logic won't easily leave the code
system as the return statement does but we can make use of 
the operation to get a similar result. I am writing
this section in comments to prove that I understand this 
code and how it works and that I want to bend in the more
logic efficient one which is the code that is written
above in black. Below I will write the other version I
believe is also correct, but don't want this commented.
*/
