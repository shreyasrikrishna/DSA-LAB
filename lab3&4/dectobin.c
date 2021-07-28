#include <stdio.h>
#define max 10

typedef struct{
    int stck[max];
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
    printf("element popped is %d\n",s->stck[s->top--]);
}

void display(STACK s){
    if(isempty(s)){
        printf("stack is empty");
        return;
    }
     printf("BINARY EQUIVALENT:\n");
    for(int i=s.top;i>=0;i--){
        printf("%d\t",s.stck[i]);
    }
}

int main(){
    STACK s;
    s.top=-1;
    int num;
    printf("enter decimal number\n");
    scanf("%d",&num);
    while(num!=0){
        push(&s,num%2);
        num=num/2;
    }
    display(s);

}