#include <stdio.h>
#include <stdlib.h>

double add(double *ptr,int n){
    double sum=0;
    for(int i=0;i<n;i++){
        sum+= *(ptr+i);
    }
    return sum;
}

int main(){
    printf("enter value of n");
    int n;
    scanf("%d",&n);
    
    double *ptr=(double*)calloc(n,sizeof(double));
    if(!ptr){
        printf("terminiated");
        exit(100);
  
    }
    
    printf("enter values");
    for(int i=0;i<n;i++){
        scanf("%lf",ptr+i);
    }

    double ans=add(ptr,n);
    printf("sum is %lf",ans);

}