#include <stdio.h>
void print_num(int a,int b){
    for(int i=0;i<=a;i++)printf("%d ",a+1);
    printf("\n");

    return ;
}
void print_sp(int a,int b){
    for(int i=a;i<b-1;i++) printf(" ");
    print_num(a,b);
    return ;
}

int main() {
    int n=6;
    for(int i=0;i<n;i++) print_sp(i,n);
    return 0;
}


