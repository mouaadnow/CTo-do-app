#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variables and structur

typedef struct Task { 
	char title[100];
	char description[500];
        struct Task *next;  
} Task;
Task *head= NULL; // the head for the linked list.
Task *content = NULL; //for displaying the Tasks.

// functions 
// add function :
void add_Task() {
	Task *Todo = (Task*)malloc(sizeof(Task));
	printf("enter your title:");
	fgets(Todo->title, 100, stdin);
	printf("enter your description:");
	fgets(Todo->description, 500, stdin);
       	if (head!=NULL){
	       Todo->next = head;
	       head = Todo;
       	}else {
	Todo->next =NULL;
	head = Todo ; // the case for the  first element on the likendlist 
       }
}
// view function 
void view_Task() {
	int i=1;
	while (content != NULL) {
		printf("\tTASK %d:\n",i);
		printf("title: %s",content->title);
		printf("description: %s", content->description);
	   	content = content->next;	
		i++;
		}
}


int main() {
	int chioce=0, c;
	enum {add=1,view,exit};
	

// the loop for check the state of choice	
	do {
        mainmenu:
	printf("\n========================================================\n");	
	printf("   _____   _______                        _ \n");        
	printf("  / ____| |__   __|                      | | \n");        
	printf(" | |         | |      ___    ______    __| |   ___ \n");  
	printf(" | |         | |     / _ \\  |______|  / _  |  / _ \\ \n"); 
	printf(" | |____     | |    | (_) |          | (_| | | (_) | \n");
	printf("  \\_____|    |_|     \\___/            \\__,_|  \\___/ \n");
        printf("===========================================================\n");                                                                                                 
	printf("\nchose your option\n");
	printf("1)Add a new task.\n2)view tasks.\n3)exit.\n");
	scanf("%d",&chioce);
	while ( ((c = getchar())) != '\n') {} // this line is use it to clear the buffer for the next input from the user .
	switch (chioce) {
		case 1:
			add_Task();
			goto mainmenu;
		case 2:
			content = head;
			view_Task();
			goto mainmenu;
		case 3:
			break;
		default:
			printf("please,verify your choice !!\n");
			}
	}while (chioce != 1 && chioce != 2 && chioce !=3); 
	return 0;
}
