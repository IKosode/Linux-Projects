#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct node *next;
    struct node *prev;
} Node;
typedef struct { // represents a Linked List
    Node *header; // pointer to the "dummy header node" of
// the Linked List
    int size; // number of nodes in the Linked List
} LinkedList;

// Function to concatenate two linked lists
void concatenate(LinkedList *someList, LinkedList *someList2) {
    if (someList == NULL || someList2 == NULL) {
        printf("One of the lists is NULL.\n");
        return;
    }

    if (someList->size == 0) {
        // If the first list is empty, just point it to the second list
        someList->header = someList2->header;
        someList->size = someList2->size;
        return;
    }

    if (someList2->size == 0) {
        // If the second list is empty, nothing to do
        return;
    }

    // Find the last node of the first list
    Node *tail1 = someList->header;
    while (tail1->next != NULL) {
        tail1 = tail1->next;
    }

    // Connect the last node of the first list to the first node of the second list
    tail1->next = someList2->header;
    someList2->header->prev = tail1;

    // Update the size of the first list
    someList->size += someList2->size;
}

/* ******
* output the contents of the List
* it is assumed that the elements in the list are strings
* Parameters: LinkedList *someList
* return void
****** */
void outputList( LinkedList *someList )
{
    if ( someList == NULL )
        return;
    if ( someList->size == 0 ) {
        printf ( "[]\n" );
        return;
    }
    printf ( "[" );
    Node *temp = someList->header->next;
    for ( int num = 0; num < someList->size; num++ ) {
        printf("%s%s", (char *) temp->data,
        (num < someList->size-1) ? " " : "" );
    temp = temp->next;
    }
    printf ( "]\n" );
}

void createList ( LinkedList *someList ) {
    someList->size = 0;
    someList->header = malloc ( sizeof (Node) );
    someList->header->data = NULL;
    someList->header->next = someList->header;
    someList->header->prev = someList->header;
}

void append(LinkedList *list, char data) {
    Node *newNode = createNode(data);
    if (list->header == NULL) {
        list->header = newNode;
    } else {
        Node *temp = list->header;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    list->size++;
}

// Main function
int main() {
    LinkedList list1, list2;
    createList(&list1);
    createList(&list2);

    // Append elements to the first list
    append(&list1, 'A');
    append(&list1, 'B');
    append(&list1, 'C');

    // Append elements to the second list
    append(&list2, 'X');
    append(&list2, 'Y');
    append(&list2, 'Z');

    printf("List 1: ");
    printList(&list1);

    printf("List 2: ");
    printList(&list2);

    // Concatenate the lists
    concatenate(&list1, &list2);

    printf("Concatenated List: ");
    outputList(&list1);    

    return 0;
}
