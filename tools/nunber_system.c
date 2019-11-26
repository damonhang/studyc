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

typedef unsigned char *byte_pointer;

//չʾ���ֵ�16�����ֽڱ�ʾ
void show_bytes(byte_pointer start ,size_t len){
    size_t i;
    for(i=0;i<len;i++){
        printf("%.2x",start[i]);
    }
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer)&x,sizeof(int));
}

void show_float(float x){
    show_bytes((byte_pointer)&x,sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer)&x,sizeof(void *));
}
