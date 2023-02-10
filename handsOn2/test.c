#include<stdio.h>
int eea(int r0,int r1){
    //r0 is going to be our gcd
    //s2 =x
    int s0=1;
    int s1=0;
    int r2=0;
    int s2=0;
    while (1){
        if (r1 ==0)
            return (r0);

        r2=(r0)%r1;
        s2=(s0)-(r0/r1)*s1;
        s0=s1;  //0
        s1=s2;//25
        r0=r1;//255
        r1=r2;//10

        // printf("r0 %d, r1 %d, r2 %d, s0 %d, s1 %d, s2 %d\n",
        // r0,r1,r2,s0,s1,s2;
        }
}
int main(){
    int x =eea(256,70);
    printf("val: %d",x);
}