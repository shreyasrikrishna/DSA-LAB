#include <stdio.h>
#include <string.h>
#define max 10

typedef struct{
    int arr[max];
    int f1,r1,f2,r2;
}Q;

int isfull(Q q,int qno){
    if(qno==1){
        if(((q.r1+1)%(max/2))==q.f1)
        return 1;
        return 0;
    }
    if(qno==2){
        if((q.r2==max-1&&(q.r2+1)%max+max/2)==q.f2)
        return 1;
        if(((q.r2+1)%(max))==q.f1)
        return 1;
        return 0;
    }
}

int isempty(Q q,int qno){
    switch(qno){
        case 1:{
            if((q.f1==-1&&q.r1==-1))
            return 1;
            return 0;
        }
        case 2:{
            if(q.f2==-1&&q.r2==-1)
            return 1;
            return 0;
        }
    }
       
}

void insert(Q *q, int ele, int qno){
    switch(qno){
        case 1:{
            if(isfull(*q,1)){
        printf("queue 1 is full!!\n");
        return;
        }
        if(q->r1==-1&&q->f1==-1){
            q->r1=q->f1=0;
            q->arr[q->r1]=ele;
            return;
        }
     q->r1=(q->r1+1)%(max/2);
     q->arr[q->r1]=ele;
    
        }

        case 2:{
            if(isfull(*q,2)){
                printf("queue 2 is full!!\n");
                return;
            }
            if(q->r2==-1&&q->f2==-1){
            q->r1=q->f1=max/2;
            q->arr[q->r1]=ele;
            return;
        }
            if(q->r2==max-1){
                q->r2=(q->r2 +1)%max+max/2;
            }
            else q->r2=(q->r2 +1)%max;
            q->arr[q->r2]=ele;
        }
    }
}

int delete(Q *q, int qno){
    switch(qno){
        case 1:{
            if(isempty(*q,1)){
        printf("queue 1 is empty!!\n");
        return 0;
        }
            q->f1=(q->f1+1)%(max/2);
            return q->arr[q->f1];
    
        }

        case 2:{
            if(isfull(*q,2)){
                printf("queue 2 is full!!\n");
                return 0;
            }
            if(q->f2==max-1){
                q->f2=(q->f2 +1)%max+max/2;
            }
            else q->f2=(q->f2 +1)%max;
            return q->arr[q->f2];
        }
    }
}

void display(Q q,int qno){
    switch(qno){
        case 1:{
            int i;
            for( i=q.f1;i!=q.r1;i=(i+1)%(max/2)){
                printf("%d\t",q.arr[i]);
            }    
            printf("%d",q.arr[i]);
        }

        case 2:{
           int i=q.f2;
            while(i!=q.r2){
                printf("%d",q.arr[i]);
                if(i==max-1){
                  i=(i +1)%max+max/2;
                }
                else i=(i+1)%max;

            }
            printf("%d",q.arr[i]);

        }
    }
}

int main(){
    Q q;
    q.f1=-1;
    q.r1=-1;
    q.f2=-1;
    q.r2=-1;
    int choice,ele;

    do{
        printf("enter choice\n");
        printf("1.insert q1\t\t2.insert q2\t\t3.delete q1\t\t4.delete q2\t\t5.display q1\t\t6. display q2\t\t7.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("enter ele to be inserted");
                scanf("%d",&ele);
                insert(&q,ele,1);
                break;
            }
            case 2:{
                printf("enter ele to be inserted");
                scanf("%d",&ele);
                insert(&q,ele,2);
                break;
            }
            case 3:{
                int temp=delete(&q,1);
            }
            case 4:{
                int temp=delete(&q,2);
            }
            case 5:{
                display(q,1);
            }
            case 6:{
                display(q,2);
            }
        }
    }while(choice!=7);

    return 0;
}