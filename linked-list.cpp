#include<stdio.h>
#include<iostream>
using namespace std;

//this is the class of each node in a list
class list{
	public:
	int data;
	list *next;
};

void createList();
void showList();
void insertAt(int no);
list* ptrAt(int pos);
list* search(int ele);



list *node,*start,*endptr;

int main(){
	
	int choice;
	while(1){
		printf("\n1.Create\t\t 2.Insert at beginning\n3.Insert at end \t 4.Insert\n\n5.Delete\n9.Display\t\t 10.Exit");
		printf("\nEnter Your Choice -> ");
		scanf("%d",&choice);
		switch(choice){
			case 1:createList();break;
			case 2:insertAt(2);break;
			case 3:insertAt(3);break;
			case 4:insertAt(4);break;
			case 9:showList();break;
			case 10: exit(0);
			default: printf("Enter valid Choice");break;
		}	
	}
	
}

//creating new node in list
void createList(){
	char ch='y';
    while(ch=='y' || ch=='Y'){
    	if(node == NULL){node = new list;//(struct list*)malloc(sizeof(struct list));
    		start = node;
			printf("Enter Element -> ");
    		cin>>node->data;goto here;
		}
    	node->next=new list;//(struct list*)malloc(sizeof(struct list));
    	node=node->next;
    	printf("Enter Element -> ");
    	cin>>node->data;
    	node->next=NULL;
    	here:
    	printf("Continue to create linked list (y / n) -> ");
    	cin>>ch;
	}
	endptr = node;
	showList();
	return;
}

//showing all elements of list
void showList(){
	system("cls");
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

void insertAt(int no){
	if(start==NULL) {
	cout<<"Please first create list...";return;}
	list *temp = new list;//(struct list*)malloc(sizeof(struct list));
	switch(no){
		case 2:
			temp->next=start;
			start=temp;
			printf("Enter Element -> ");
    		cin>>temp->data;
		break;
		case 3:
			endptr->next=temp;
			temp->next=NULL;
			printf("Enter Element -> ");
    		cin>>temp->data;
		break;
		case 4:
			int choice;
			struct list *ptrEle;
			printf("1. Insert after element\n2. Insert after position");
    		printf("\nEnter your choice for insert->");	
    		cin>>choice;
    		switch(choice){
    			case 1:
    				int ele;
    				cout<<"\nafter which element you want to insert->";cin>>ele;
					ptrEle = search(ele);
					if(ptrEle!=NULL){
						printf("\nEnter Element -> ");
    					cin>>temp->data;
    					node=ptrEle->next;
    					ptrEle->next=temp;
    					temp->next=node;						
					}else return;
				break;
    			case 2:
					int pos;
    				cout<<"\nafter which position you want to insert->";cin>>pos;
					ptrEle = ptrAt(pos);
					if(ptrEle!=NULL){
						printf("\nEnter Element -> ");
    					cin>>temp->data;
    					node=ptrEle->next;
    					ptrEle->next=temp;
    					temp->next=node;
					}else{return;}
				break;
			}
		break;
	}
	showList();
}

//this function will search the element and return address of that element
list* search(int ele){
	node=start;
	while(node!=NULL){
		if(node->data==ele){
			return node;
		}
		node=node->next;
	}
	cout<<"Element Not found...";
	return NULL;
}

//return address of position
list* ptrAt(int pos)
{   int ct=0;
    node=start;
    while(node!=NULL)
    {
	ct++;
	if(pos==ct){
		return node;
	}
	node=node->next;
    }
	cout<<"invalid position...";
	return NULL;
}