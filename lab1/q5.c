#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    int rollno;
    float cgpa

} STU;

void read(STU *s1){
    printf("enter name rollno and cgpa\n");
    char n[50];
    int r;
    float c;
    scanf("%s %d %f",&(s1->name),&(s1->rollno),&(s1->cgpa));

}

void display(STU *s1){
    printf("details of the student are:\n");
    printf("Name: %s \n",s1->name);
    printf("roll no: %d \n",s1->rollno);
    printf("cgpa: %f \n",s1->cgpa);

}

void sort(STU arr[],int n){
    STU temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j].rollno>arr[j+1].rollno){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        STU *temp=&arr[i];
        display(temp);
    }

}

int main(){
    int capacity=3;
    int top=0;
    STU s;
    STU *ptr=&s;
    read(ptr);
    display(ptr);

    STU *arrptr=(STU*)calloc(capacity,sizeof(STU));
    int ch;
    
    do{
        printf("enter choice\n");
        printf("1.enter details for new student\n2.display details\n3.sort by rollno\n4.exit\n");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:{
                if(top==capacity-1){
                    arrptr=(STU*)realloc(arrptr,capacity*2*sizeof(STU));
                    capacity*=2;
                }
                
                read(&(arrptr[top]));
                top++;
                break;

            }
            case 2:{
                printf("enter number of student whose details you want displayed\n");
                int nameno;
                for(int i=0;i<=top;i++){
                    printf("%d. %s\n",i+1,arrptr[i].name);

                }
                scanf("%d",&nameno);
                display(&arrptr[nameno-1]);
                break;
            }
            case 3:{
                sort(arrptr,top+1);
                
                break;
            }

        }
        
    }while(ch!=4);

    printf("\nthank you!\n");
    return 0;
    
    
}