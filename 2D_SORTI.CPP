#include<stdio.h>
#include<conio.h>
int main(){
	int a[3][4] = {12,110,1000,-9,8,7,6,-5,0,3,2,1},max;
	int r = sizeof a/sizeof a[0];
	int c = sizeof a[0]/sizeof a[0][0];
	printf("row = %d and column = %d\n",r,c);
	printf("\nbefore sorting\n");
		for(int i=0; i<r*c; i++){
		printf("a[%d][%d] = %d\t",i/c,i%c,a[i/c][i%c]);
		if(i%c==c-1){printf("\n");}
	}
	for(int i=0; i<r*c; i++){
		for(int j=i+1; j<r*c; j++){
			if(a[i/c][i%c] > a[j/c][j%c]){
				max=a[i/c][i%c];
				a[i/c][i%c]=a[j/c][j%c];
				a[j/c][j%c]=max;
			}
		}
	}

		printf("\nafter sorting\n");
	for(int i=0; i<r*c; i++){
		printf("a[%d][%d] = %d\t",i/c,i%c,a[i/c][i%c]);
		if(i%c==c-1){printf("\n");}
	}
}
