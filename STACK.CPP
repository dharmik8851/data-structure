#include<stdio.h>
#include<malloc.h>
#include<process.h>
#include<conio.h>
#define WINDOWS 1

int tos=-1,*stack;
void push(int size);
void pop();
void display();
void search();
void update();

int main(){
	int n,op;
	printf("\nEnter size of your own stack -> ");
	scanf("%d",&n);
	stack = (int*)calloc(n, sizeof(int));
	 while(1){
		printf("\nEnter your choice for stack operation");
		printf("\n1. Push\n2. POP\n3. Search\n4. Update\n5. Display\n6. Exit\n");
		printf("\nEnter your choice -> ");
		scanf("%d",&op);
//		clrscr();
		#ifdef WINDOWS
  		system("cls");
  		#endif
		switch(op)
		{
		    case 1: push(n);
		    break;

		    case 2: pop();
		    break;

		    case 3: search();
		    break;

		    case 4: update();
		    break;

		    case 5: display();
		    break;

		    case 6: exit(0);
		    break;

		    default: printf("Enter Valid Operation...");
		    break;
		}
	}
	return 0;
}

void push(int size){
	if(tos>=size-1){
		 printf("\nStack overflow...");
		 return;
	}
	tos++;
	printf("\nEnter element -> ");
	scanf("%d",&stack[tos]);
	display();
}

void pop(){
	if(tos<0)
	{
		printf("\nData underflow...");
		return;
	}
	printf("%d popped from stack...",stack[tos]);
	tos--;
	display();

}

void display(){
	if(tos==(-1))
	printf("\nStack is empty...");
	else
	 {
		printf("\nStack ->\n");
		for(int i=tos;i>=0;i--)
		printf("%16d\n",stack[i]);
	 }
}

void search(){
	if(tos==(-1))
	{
		printf("\nStack is empty...");
		return;
	}
	int sele;
	printf("\nEnter element do you want to search -> ");
	scanf("%d",&sele);
	for(int i=tos; i>=0; i--){
		if(stack[i]==sele){
			printf("\nValue %d found at position %d...",sele,i+1);
			return;
		}
	}
	printf("\nValue not found...");
}

void update(){
	int pos,val;

    if(tos==(-1))
    {
	printf("\nStack is empty...");
	return;
    }

    printf("\nAt which position do you want to update an element -> ");
    scanf("%d",&pos);
    if(pos<=tos && pos>0){
	printf("Enter new element -> ");
	scanf("%d",&val);
	stack[pos-1]=val;
	display();
    }
    else{
	printf("Enter valid position...");
	return;
    }
}

