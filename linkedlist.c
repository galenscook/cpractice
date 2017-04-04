#include <stdio.h>
#include <stdlib.h>

//* List *new(): creates a new linked list (use a struct def)
//* void add(List *list, void *value)
//* void *head(List *list): returns the first element of the list (“car” in lisp)
//* List *tail(List *list): returns a new list without the head (“cdr” in lisp)
//* int len(List *list): returns the length of the list

struct List {
	int value;
	struct List *next;
};
typedef struct List List;

List *newList(int value) {

	List *first = NULL;

	// UGH I KNOW I NEED TO USE THIS HERE BUT WHERE DO I FREE IT??
	first = calloc(1, sizeof(List));
	first->value = value;
	first->next = NULL;

	return first;
}

void add(List *list, int value) {
	List *current = list;
	List *newNode = newList(value);

	while (current->next != NULL) {
		current = current->next;
	}

	current->next = newNode;
}

// returns the first element of the list (“car” in lisp)
int *head(List *list) {
	return &list->value;
}

// returns a new list without the head (“cdr” in lisp)
List *tail(List *list) {
	List *newList = list->next;
	return newList;
}

// returns the length of the list
int len(List *list) {
	List *current = list;
	int length = 1;
	while (current->next != NULL) {
		length++;
		current = current->next;
	}
	return length;
}

void cleanUp(List *list) {
	List *current = list;
	while (current->next != NULL) {
		List *temp = current;
		current = current->next;
		free(temp);
	}
}

int main(int argc, char *argv[]) {

	List *myList = newList(5);
	printf("This is the length of my list : %d\n", len(myList));
	add(myList, 4);
	printf("This is the length of my list : %d\n", len(myList));
	add(myList, 17);
	printf("This is the length of my list : %d\n", len(myList));
	List *tailOfList = tail(myList);

	printf("This is the length of my list : %d\n", len(myList));
	printf("This is the length of the tail of list : %d\n", len(tailOfList));

	cleanUp(myList);
	return 0;
}

