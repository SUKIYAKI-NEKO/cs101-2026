#include <stdio.h>

void multi(int i,int j){
    if(j==1){
        printf("%d*%d=%d\n",i,j,i*j);
        return ;
    }
    else {
        multi(i,j-1);
        printf("%d*%d=%d\n",i,j,i*j);
    }
    return ;
}
int main(){
    multi(1,9);
    return 0;
}
