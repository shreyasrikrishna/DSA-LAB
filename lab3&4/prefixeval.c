#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
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

void push(STACK *s, int ele){
    if(isfull(*s)){
        printf("stack is full\n");
        return;
    }
    s->stck[++s->top]=ele;
}

int pop(STACK *s){
    if(isempty(*s)){
        printf("stack is empty");
        return '0';
    }
    return s->stck[s->top--];
}

int eval(int op1,int op2,char ch){
    switch(ch){
        case '+':{ 
            return op1+op2;
            break;
        }
        case '-':{ 
            return op1-op2;
            break;
        }
        case '*':{ 
            return op1*op2;
            break;
        }
        case '/':{ 
            return op1/op2;
            break;
        }
        case '^':{ 
            return pow(op1,op2);
            break;
        }

    }
}

void display(STACK s){
    if(isempty(s)){
        printf("stack is empty");
        return;
    }
     printf("STACK:\n");
    for(int i=s.top;i>=0;i--){
        printf(" %d\n",s.stck[i]);
    }
}

int main(){
    STACK s;
    s.top=-1;
    int i=0;
    int op1,op2;
    char* pref,ch;
    pref=(char*)calloc(15,sizeof(char));
    printf("enter prefix expr\n");
    scanf("%s",pref);
    pref=strrev(pref);

    while((ch=pref[i++])!='\0'){
        if(isdigit(ch)){
            push(&s,ch-'0');
            //display(s);
        }
        else{
            op1=pop(&s);
            op2=pop(&s);
            push(&s,eval(op1,op2,ch));
        }
        
    }
    int res=pop(&s);
    printf("the result is :\t %d \n",res);
}
