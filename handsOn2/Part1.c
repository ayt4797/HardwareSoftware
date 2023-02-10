#include<stdio.h>
#include <math.h>
#include<stdlib.h>

int add(int combo1,int combo2, int fx){
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
int inverse(int valueToInvert){
    for(int i=0;i<256;i++){
        int o=mult(i,valueToInvert,283);
        if(o==1){
            return i;
        }
    }
    perror("No inverse found");
    exit(0);
    return -99;

}
int divi(int value1, int value2){
    return mult(value1, inverse(value2),283);
}
// int eea(int* r0,int r1,int* s0,int* t0){
//     //r0 is going to be our gcd
//     int t1=1;
//     (*s0)=1;
//     int s1=0;
//     (*t0)=0;
//     int r2=0;
//     int q=0;
//     int s2=0;
//     int t2=0;
//     // (*r0)=(*r0)*(*r0);
//     while (1){
//         if (r1 ==0)
//             return (*r0);

//        r2=(*r0)%r1;
//     //    q=divi((*r0),r1);
//        q=*r0/r1;

//     //    s2=(*s0)-mult(q,(s1),283);
//     //    t2=(*t0)-mult(q,t1,283);
//         s2=(*s0)-q*s1;
//         t2=(*t0)-q*t1;
//         (*r0)=r1;
//         r1=r2;
//         (*s0)=s1;
//         s1=s2;
//         (*t0)=t1;
//         t1=t2;
//         }
// }
// //there 
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
        }
}

//2^1 mod 8 = 2
//2^2 mod 8 = 4
// 2^3 mod 8 = 0
//2 ^4 mod 8 = 0
//2 ^5 mod 8 = 0

//3^1=3 mod 7 = 3
//3^2= 9 mod 7 = 2
//3^3 =27 mod 7 = 6
//3^4 =81 mod 7 = 4
//3^5 =mod 7 = 5
//3^6 mod 7 = 1
//3^7 mod 7 = 3

//3^1 mod 5 = 3
//3^2 mod = 4 
//3*3 mod 5 = 4
//9*3 mod 5 = 2
//9*9 mod 5 =1
//9*9*3 mod 5 =3
// int primitives(int i, int fx){
//     int first = ((int)pow(i,1)%fx);
//     int next =first;
//     int arr[256];
//     arr[0] = next;
//     for(int j=2;j<256;j++){
//         next = (int)pow(next,j)%fx;
//         printf("next %d\n",next);
//         if (next == arr[j]){
//             return 0;
//         }
//     }
//     return i;

// }

//there is a better way to do this lol IK
int function(int x8,int x4,int x3, int x){
    return (int)pow(x8,8)+(int)pow(x4,4)+(int)pow(x3,3)+x+1;
}
// int findPrimitives(int* list){
//     //fx = x^8+x^4+x^3+x+1
//     int count =0;
//     for(int i=0;i<256;i++){
//         for(int j=0;j<256;j++){
//         // int out = function(i,i,i,i);
//             if(mult(i,j,283)){

//             }
//         }
       
//     }
//     return count;
// }


int main(){
    // inverse();
    int fx = 0b100011011;
    int combos[256];
    int addResult =0;
    int multResult=0;
    int val1, val2;
    int *generators;
    int listSize =0;
    int count=0;
    int s0=0,t0=0;
    printf("give two 8bit numbers:\n");
    scanf("%d %d", &val1,&val2);
    printf("You have given values: %d, %d\n ", val1,val2);
    for(int i=0;i<256;i++){
        combos[i] = i;
    }
    generators = (int*)calloc(1,sizeof(int)*128);
    if(generators==NULL){
        perror("err on malloc");
    }
    //add
    // for(int i=0;i<256;i++){
    //     for(int j=0;j<256;j++){
    addResult = add(val1,val2,fx);
    printf("Add result: %d\n",addResult);
    //     }
    // }
    //mult
    // for(int i=0;i<256;i++){
    multResult =mult(val1,val2,fx);
    printf("\nmult result: %d\n",multResult);
    // }
    //is a generator check:
    // count =findPrimitives(list);
    // for(int i=0;i<count;i++){
    //     printf("primitive_%d : %d\n",i,list[i]);
    // }
    printf("Generators: ");
    for(int i=2;i<=256;i++){
        int r0=i;
        
        // printf("\nr0 %d, s0 %d t0 %d\n",r0,s0,t0);
        if(1==eea(r0,256)){
            generators[listSize]= i;
            listSize++;
            // generators = (int*) realloc(generators,sizeof(int)*(128));
            printf("%x ",i);
        }
       
    }
    listSize++;
    //     for(int i=2;i<=256;i++){
    //         int p = primitives(11,fx);
    //         if(p)
    //         printf("%d \n",p);
    //     }
    printf("list size: %d\n\n\n", listSize);

    printf("val1 against all values: ");
    for(int i=0;i<255;i++){
        int addRes = add(val1,i,283);
        int multRes = mult(val1,i,283);
        printf("add res: %d, mult Res: %d\n", addRes, multRes);
    }
    free(generators);
    return 0;
}