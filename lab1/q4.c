#include <stdio.h>
//find second largest


int secondlargest(int a[],int n){
    int l,sl;
    l=a[0];
    sl=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>l){
            sl=l;
            l=a[i];
        }
        else if(a[i]<l&&a[i]>sl){
            sl=a[i];
        }
    }
    return sl;
}

int main(){
    printf("enter number of integers");
    int n,arr[10];
    scanf("%d",&n);
    printf("enter elements");
    

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }

    printf("Second largest in array is %d",secondlargest(arr,n));
}