#include<stdio.h>
#include <stdint.h>
int add(int combo1,int combo2){
    return combo1^combo2;
}
//the concept is that multiplication is a serious of additions
int mult(int val1, int val2, int fx){
    int res=0;
    for(int i=0; i<8;i++){
        // printf("res1: %d\t", res);
        res<<=1;
        //keep shifting left until we've reached a unique value to add against the  
        if(val2 & 128){
            res=res^val1;
        }
        val2<<=1;
        if(res & 256){
            //if we've reached the left most bit get rid of it.
            res=res^fx;
        }


     
        // printf("res2: %d\n", res);

    }
    return res;

}
int inverseTest(int valueToInvert){
    for(int i=0;i<283;i++){
        int o=mult(i,valueToInvert,283);
        if(o==1){
            return i;
        }
    }
    perror("No inverse found");
    // exit(0);
    // return -99;

}
int division(int r0, int r1, int* r){
    int a = r0>r1 ? r0 : r1;
    int b = r0<r1 ? r1 : r1;
    int temp =b;
    int temp2 = 1;
    int res =0;
    int remainder =0;
    while(a>=b){
        while(!((a^b)<=(a&b))){
            temp2 <<=1;
            b<<=1;
        }
        res=res ^temp2;
        temp2 =1;
       
        remainder = add(a,b);
        a=remainder;
        b=temp;
    }
    r=remainder;
    return res;
}
int eea(int r0,int r1){
    int s0=1;
    int s1=0;
    int r2=0;
    int s2=0;
    int q =0;
    while (1){
        r2=(r1)%r0;
        q=division(r0,r1);
        s2 = add(s0,mult(q,s1,283));
        // s2=(s0)-(r1/r0)*s1;
        s0=s1;  //0
        s1=s2;//25eea 
        r0=r1;//255
        r1=r2;//10
        }
}
int eea1(int r0,int r1){
  //r1 = r0*a+r
  int r=1;
  while(r!=0){
    int a = division(r1,r0,&r);
    r1=r0
    r0=r;
  }
}

int main(){
    int a =eea(256,70);
    int out,x,y;

    printf("val: %d",a);
    printf("val2: %d",out);
    int t =0;
    t=t<<1;
    printf("\n%d\n",t);
    printf("Division: %d",division(127,30));

}