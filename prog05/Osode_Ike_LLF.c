/** 
 * Ike Osode
 * proj# 5
 * This file includes additional LinkedList functions: addFirst, removeFirst, 
 * swap, and change. The main function reads in a sequence of list operations
 * from stdin. The first char of the line indicates a specific list operation.
 * ‘a’ Add the given element to the end of the list (i.e., append)
 * ‘f’ Add the given element to the front of the list (i.e., position 0)
 * ‘d’ Delete the element from a specific position in the list
 * ‘r’ Remove the first element from the list
 * ‘o’ Output the list to stdout
 * ‘s’ Swaps the two elements in the specified positions in the list.
 * ’c’ Changes the data at the specified location in the list to the new data provided
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node { // represents one node in a Linked List

    void *data; // pointer to data associated with this node
    struct node *next; // pointer to next node in List
    struct node *prev; // pointer to previous node in List
} Node;
typedef struct { // represents a Linked List
    Node *header; // pointer to the "dummy header node" of
		  // the Linked List
    int size; // number of nodes in the Linked List
} LinkedList;
// function proto-types
void createList ( LinkedList *someList );
void addEnd( LinkedList *someList, void *newData );// this prototype was missing
void *delete( LinkedList *someList, int position );
void outputList( LinkedList *someList );
void addFirst( LinkedList *someList, void *newElement );
void *removeFirst( LinkedList *someList );
void swap( LinkedList *someList, unsigned int i, unsigned int j );
void *change( LinkedList *someList, int position, void *newElement );
#define MAX_NAME_LENGTH 20
int main() {
    LinkedList myList;
    LinkedList *roster = &myList;
    createList ( roster ); // initialize the fields of the list
    // process a sequence of List operations from stdin
    char input[30];
    char line[MAX_NAME_LENGTH];
    int pos = 0;
    int pos2 = 0;
    while(fgets(input, sizeof(input), stdin)){
        switch(input[0]){
            case 'a':{
                if (sscanf(input, "a %20s", line) != 1) exit(1);
		char *name = malloc(MAX_NAME_LENGTH);
		strcpy(name, line);
		addEnd(roster, name);
                break;
	    }
            case 'f':{
                if (sscanf(input, "f %20s", line) != 1) exit(1);
		char *name = malloc(MAX_NAME_LENGTH);
		strcpy(name, line);
                addFirst(roster,name);
                break;
	   }	
            case 'd':
                if (sscanf(input, "d %d", &pos) != 1) exit(1);
                delete(roster, pos);
                break;
            case 'r':
                removeFirst(roster);
                break;
            case 'o':
                outputList(roster);
                break;
            case 's':
                if (sscanf(input, "s %d %d", &pos, &pos2) != 2) exit(1);
                swap(roster,pos,pos2);
                break;
            case 'c':
                if (sscanf(input, "c %d %20s", &pos, line) != 2) exit(1);
                change(roster, pos, line);
        }
    }

}
/* ****** 
 * Initially the List is empty
 * We must create memory for the "dummy header node"
 * Parameters: LinkedList *someList
 * return void
****** */
void createList ( LinkedList *someList )
{
    someList->size = 0;
    someList->header = malloc ( sizeof (Node) );
    someList->header->data = NULL;
    someList->header->next = someList->header;
    someList->header->prev = someList->header;
}
/* ******
 * adds the new data element to the end of the List
 * Parameters: LinkedList *someList, void *newData
 * return void
****** */
void addEnd( LinkedList *someList, void *newData )
{
    //Node *lastNode = someList->header->prev;
    Node *newNode = malloc ( sizeof ( Node ) );
    newNode->data = newData; // set the fields of the new Node
    newNode->next = someList->header;
    newNode->prev = someList->header->prev;
    someList->header->prev->next = newNode; // splice-in the newNode
    someList->header->prev = newNode; // into the List
    someList->size++;
}
/* ******
 * removes the item in the given position in the List, and returns that data
 * Parameters: LinkedList *someList, int position
 * return removed data
****** */
void *delete ( LinkedList *someList, int position )
{
    if ( position < 0 || position >= someList->size )
        exit(2);
    // walk down the list until we reach the node to be removed
    Node *temp = someList->header;
    for ( int i=0; i <= position; i++ )
        temp = temp->next;
    void *removedData = temp->data;
    temp->prev->next = temp->next; // splice-out the Node
    temp->next->prev = temp->prev;
    someList->size--;
    free( temp ); // free-up the memory of the deleted Node
    return ( removedData );
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
/* ******
 * add the newElement to position 0 in the List
 * that is, the newElement precedes all other elements in the list
 * Parameters: LinkedList *someList, void *newElement
 * return void
****** */
void addFirst( LinkedList *someList, void *newElement )
{
    Node *fnode = malloc(sizeof(Node));
    fnode->data = newElement;
    fnode->next = someList->header->next; 
    fnode->prev = someList->header;
    someList->header->next->prev = fnode;
    someList->header->next = fnode;
    someList->size++;
}
/* ******
 * remove the first element in the list, and return a pointer to that data item.
 * if the list is empty, exit the program with status 2
 * Parameters: LinkedList *someList
 * returns pointer to the data of the removed first element
****** */
void *removeFirst( LinkedList *someList )
{
    if(someList->size == 0) {
        exit(2);
    }
    void *remove = someList->header->next->data;

    someList->header->next->next->prev = someList->header->next;
    someList->header->next = someList->header->next->next;
    someList->size--;
    return remove;
}
/* ******
 * swap the two elements in the list as indicated by their indices
 * if one or both of the positions/indices specified in the input
 * are not on the list, exit the program with status 2
 * Parameters: LinkedList *someList, unsigned int i, unsigned int j
 * return void
****** */
void swap(LinkedList *someList, unsigned int i, unsigned int j) {
	if (i >= someList->size || j >= someList->size || i<0 || j<0) exit(2);
	if (i == j) return;

	Node *node1 = someList->header->next;
	Node *node2 = someList->header->next;

	for (unsigned int k = 0; k < i; k++) node1 = node1->next;
	for (unsigned int k = 0; k < j; k++) node2 = node2->next;

	void *temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}

/* ******
 * modify the data in the given position in the List to be the newElement. 
 * Return a pointer to the data that was over-written and deleted from the list
 * if the position is illegal then exit the program with status 2
 * Parameters: LinkedList *someList, int position, void *newElement
 * return pointer to data that was over-written
****** */
void *change( LinkedList *someList, int position, void *newElement )
{
    if (position < 0 || position >= someList->size) {
        exit(2);
    }

    // Move to the node at the specified position
    Node *temp = someList->header;
    for (int i = 0; i <= position; i++) {
        temp = temp->next;
    }

     // Store old data, update with new, and return old data
    void *oldData = temp->data;
    temp->data = newElement;
    return oldData;
}
