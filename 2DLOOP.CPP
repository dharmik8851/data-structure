#include<stdio.h>
#include<conio.h>

int main(){
	int a[3][4] = {{1,2,3,4},{5,6,7,6},{12,3,3,22}};
	int r= sizeof(a)/sizeof(a[0]);
	int c= sizeof a[0]/ sizeof(int);
	for(int i=0,j=0; j<c && i<r; j++){
		printf("a[%d][%d] = %d \t",i,j,a[i][j]);
		if(j==c-1){j=-1;i++; printf("\n");}
	}
}