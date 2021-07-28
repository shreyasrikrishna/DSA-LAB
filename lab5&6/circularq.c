#include <stdio.h>
#include <string.h>
#define max 5
#define size 25
//circular queue
//front points to already deleted

typedef struct{
    char que[max][size];
    int front,rear;
}Q;

int isfull(Q q){
    if((q.rear+1)%max==q.front)
    return 1;
    return 0;
}

int isempty(Q q){
    if(q.rear==q.front)
    return 1;
    return 0;
}

void insertq(Q *q, char str[]){
    if(isfull(*q)){
        printf("queue is full!!\n");
        return;
    }
    q->rear=(q->rear+1)%max;
    strcpy(q->que[q->rear],str);//IMPORTANT: cant assign as string are unmodifiable
}

char* deleteq(Q *q){
    (q->front)++;
    return q->que[q->front];
}

void display(Q q){
    int i;
    for(i=q.front+1;i!=q.rear;i=(i+1)%max){
        printf("%s\n",q.que[i]);

    }
    printf("%s\n",q.que[i]);

}

int main(){
    Q q;
    q.rear=0;
    q.front=0;
    int choice;
    char str[size];
    

    do{
        printf("enter your choice\n");
        printf("1.insert\t\t2.delete\t\t3.display\t\t4.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("enter string to be inserted\n");
                scanf("%s",str);
                insertq(&q,str);
                break;
            }
            case 2:{
                char *temp=deleteq(&q);
                printf("deleted : %s\n",temp);
                break;
            }
            case 3:{
                display(q);
                break;
            }
            
            
        }
    }while(choice!=4);
}