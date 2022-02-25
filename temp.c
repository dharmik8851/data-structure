
#include <stdio.h>

int main()
{
    int lower=-1,upper=-1;
    char c;
    
    printf("enter the alphabet-> ");
    scanf("%c",&c);
    lower = (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    upper = (c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    
    printf("%d\n", lower);
    printf("%d\n", upper);

	if(!isalpha(c)){
		printf("not alphabet");
	}
	else if(lower || upper ){
		printf("vowel");
	}
	else{
		printf("not vowel")	;
	}
	
    return 0;
}
