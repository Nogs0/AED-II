#include<stdio.h>

int main(){
	int a,b;

	scanf("%d %d", &a, &b);
	if(&a > &b) printf("&a > &b\n\n");
	else printf("&b > &a\n\n");
}
