#include <stdio.h>

int main(){
    FILE* fp;
    fp=fopen("a.bin","wb+");
    int a[]={1,2,3};
    char b[]="ABC";
    float c[]={1.1,1.2,1.3};
    int ra[10];
    char rb[10];
    float rc[10];
    fwrite(a,sizeof(a),1,fp);
    fwrite(b,sizeof(char),3,fp);
    fwrite(c,sizeof(c),1,fp);
    fseek(fp,0,SEEK_SET);
    fread(ra,sizeof(a),1,fp);
    fread(rb,sizeof(char),3,fp);
    fread(rc,sizeof(c),1,fp);
    for(int i=0;i<3;i++)printf("%d ",ra[i]);
    printf("\n");
    for(int i=0;i<3;i++)printf("%c ",rb[i]);
    printf("\n");
    for(int i=0;i<3;i++)printf("%f ",rc[i]);
    printf("\n");
    return 0;
}
