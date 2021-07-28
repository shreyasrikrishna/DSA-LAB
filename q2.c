#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("enter value of n");
    int n;
    scanf("%d",&n);

    int *ptr=(int*)calloc(n,sizeof(int));
    if(!ptr){
        printf("terminiated");
        exit(100);
  
    }

    printf("enter values");
    for(int i=0;i<n;i++){
        scanf("%d",ptr+i);
    }

    printf("enter ele to be searched");
    int ele;
    scanf("%d",&ele);
    int flag=0;

    for(int i=0;i<n;i++){
        if(*(ptr+i)==ele){
            printf("ele found at pos %d",i+1);
            flag=1;
        }
    }
    if(flag==0){
        printf("ele not found");
    }

    }

