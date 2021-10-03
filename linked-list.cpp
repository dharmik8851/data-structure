#include<stdio.h>
#include<iostream>
using namespace std;
void createList();
void showList();
struct list{
	int data;
	struct list *next;
};
struct list *node,*start;

int main(){
	int choice;
	while(1){
		printf("\n1.Create\t\t 2.Insert at beginning\n3.Insert at end \t 4.Insert\n\n5.Delete\t\t 6.Search\n7.Sort\t\t\t 8.Count\n\n9.Display\t\t 10.Exit");
		printf("\nEnter Your Choice -> ");
		scanf("%d",&choice);
		switch(choice){
			case 1:createList();break;
			case 10: exit(0);
			default: printf("Enter valid Choice");break;
		}	
	}
	
}

//creating new node in list
void createList(){
	char ch='y';
	//start = (struct list*)malloc(sizeof(struct list));
	//node=start;
    while(ch=='y' || ch=='Y'){
    	if(node == NULL){node = (struct list*)malloc(sizeof(struct list));
    		start = node;
			printf("Enter Element -> ");
    		cin>>node->data;goto here;
		}
    	node->next=(struct list*)malloc(sizeof(struct list));
    	node=node->next;
    	printf("Enter Element -> ");
    	cin>>node->data;
    	node->next=NULL;
    	here:
    	printf("Continue to create linked list (y / n) -> ");
    	cin>>ch;
	}
	showList();
	return;
}

void showList(){
	node=start;
	if(node==NULL){
		printf("List is empty...");
	}else{
		while(node!=NULL){
			printf("%d  ",node->data);
			node=node->next;
		}
	}
}