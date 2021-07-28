#include <stdio.h>
#define max 10

typedef struct{
    char stck[max];
    int top;
}STACK;

int isfull(STACK s){
    if(s.top==max-1)
    return 1;
    else return 0;
}

int isempty(STACK s){
    if(s.top==-1)
    return 1;
    else return 0;
}

void push(STACK *s, char ele){
    if(isfull(*s)){
        printf("stack is full\n");
        return;
    }
    s->stck[++s->top]=ele;
}

void pop(STACK *s){
    if(isempty(*s)){
        printf("stack is empty");
        return;
    }
    printf("element popped is %c\n",s->stck[s->top--]);
}

void display(STACK s){
    if(isempty(s)){
        printf("stack is empty");
        return;
    }
     printf("STACK:\n");
    for(int i=s.top;i>=0;i--){
        printf("%c\n",s.stck[i]);
    }
}

int main() {
    STACK s;
    s.top=-1;
    char ele;
    int ch;
    printf("Stack max value is 10\n");

    do{
        printf("enter your choice\n\n1.Push\t\t2.Pop\t\t3.Display\t\t4.Exit\n\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("enter element to be pushed \n");
                
                scanf(" %c",&ele);
                push(&s,ele);
               
                break;
            }
            case 2:{
                pop(&s);
                break;
            }
            case 3:{
                display(s);
                break;
            }
        }

    }while(ch!=4);

    return 0;

}
