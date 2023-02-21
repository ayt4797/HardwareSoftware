#include<stdio.h>
#include <math.h>
#include<stdlib.h>

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
    // perror("No inverse found");
    // exit(0);
    // return -99;

}

int division(int r0, int r1){
    int a = r0>r1 ? r0 : r1;
    int b = r0<r1 ? r1 : r1;
    int temp =b;
    int temp2 = 1;
    int res =0;
    int remainder =0;
    while(a>b){
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
    return res;
}

int power(int a,int b){
    for(int i=0;i<b;i++){
        
    }
}
int main(){
    // inverse();
    int a[256]; //temp
    int generators[128];
    int fx = 0b100011011;
    short fail =0;
    int c =0;
    for(int i=2;i<256;i++){
        fail =0;
        for(int j=1;j<256;j++){
                a[0] = i;
                a[j]= mult(i,a[j-1],283);
        }
           //check
        int co =0;
        for(int k=1;k<256;k++){
            if(i==a[k]){
                co++;
                if(co==2){
                    fail =1;
                    break;
                }
            }
        }
        if(!fail)
            generators[c++]=i;
        if(c==128){
            break;
        }
    }
    for(int i=0;i<128;i++){
        printf("%x ", generators[i]);
    }
    printf("count: %d",c);
    return 0;
}