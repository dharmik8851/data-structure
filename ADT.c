#include<stdio.h>
#include<stdlib.h>


struct myArray{
	int totalSize;
	int usedSize;
	int *ptr;
};

void createArray(struct myArray * a,int tsize,int usize){
	a->totalSize = tsize;
	a->usedSize=usize;
	a->ptr=(int*)malloc(tsize*sizeof(int));
}

void setArray(struct myArray *a){
	for(int i=0; i<a->usedSize; i++){
		printf("Enter element %d -> ",i+1);
		scanf("%d",&a->ptr[i]);
	}
}

void showArray(struct myArray *a){
	for(int i=0; i<a->usedSize; i++){
		printf("\nelement %d is %d",i+1,a->ptr[i]);
	}
	printf("\ntotal size -> %d\n",a->totalSize);
	printf("used size -> %d\n",a->usedSize);
}

void insertion(struct myArray *a){
	printf("At which position you want to insert element -> ");
	int pos;
	scanf("%d",&pos);
	if(pos>=0 && pos<=a->usedSize && a->usedSize<a->totalSize){
		int ele;
		printf("Enter new element -> ");
		scanf("%d",&ele);
		a->ptr[a->usedSize]=a->ptr[pos];
		a->ptr[pos]=ele;
		a->usedSize++;
		showArray(a);
	}
	else{
		printf("Enter Valid position...");
	}
}

void deletion(struct myArray *a){
	printf("At which position you want to delete element -> ");
	int pos;
	scanf("%d",&pos);
	if(pos==a->usedSize-1){
		a->ptr[a->usedSize-1]='\0';
		a->usedSize--;
	}
	else if(pos>=0 && pos<a->usedSize){
		a->ptr[pos]=a->ptr[a->usedSize-1];
		a->ptr[a->usedSize-1]='\0';
		a->usedSize--;
	}
	else{
		printf("Enter Valid position...");
	}
	showArray(a);
}

void searching(struct myArray *a){
	printf("Enter element for searching -> ");
	int ele;
	scanf("%d",&ele);
	for(int i=0; i<a->usedSize; i++){
		if(a->ptr[i] == ele){
			printf("%d was found at postion %d",ele,i);
			return;
		}
	}
	printf("element not found");
	
}

int main(){
	int size,usize;
	struct myArray marks;
	printf("Enter the total size of your array -> ");
	scanf("%d",&size);
	printf("how many element do you want to insert -> ");
	scanf("%d",&usize);
	if(usize>size){printf("array overflow...");exit(0);
	}else{
		createArray(&marks,size,usize);
	setArray(&marks);
	showArray(&marks);	
	}
	
	while(1){
		printf("\n 1.insertion \n 2.deletion \n 3.traversal  \n 4.searaching \n 5.exit");
	int op;
	printf("\nwhich operation do you want to perform -> ");
	scanf("%d",&op);
	system("cls");
	switch(op){
		case 1:insertion(&marks);break;
		case 2:deletion(&marks);break;
		case 3:showArray(&marks);break;
		case 4:searching(&marks);break;
		case 5:exit(0);
		default: printf("Enter valid choice");
	}	
	}
}