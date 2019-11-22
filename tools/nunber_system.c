#include<stdio.h>
void showbit(int n)
{
if(n>1){
showbit(n/2);
printf(" ");
}
printf("%d",n%2);
}

void showInputbit(){
    int a;
    printf("input a num:");
    scanf("%d",&a);
    showbit(a);
    printf("\n");
}
