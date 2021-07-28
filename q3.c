#include <stdio.h>
#include <stdlib.h>

void display(int **m1,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=1;j<=cols;j++){
            printf("%d ",*(*(m1+i)+j));
        }
        printf("\n");
    }


}

void mult(int**m1, int** m2,int rows,int cols){
    int** res=(int**)calloc(rows+1,sizeof(int*));
    for(int i=0;i<rows;i++){
        res[i]=(int*)calloc(cols+1,sizeof(int));
        res[i][0]=cols;
    }

    for(int i=0;i<rows;i++){
        for(int j=1;j<=cols;j++){
            res[i][j]=m1[i][j]*m2[i][j];
        }
        printf("\n");
    }
    display(res,rows,cols);

}

int main(){
    int rows=3;
    int **m1;
    int **m2;
    int cols;

    m1=(int**)calloc(rows+1,sizeof(int*));
    m2=(int**)calloc(rows+1,sizeof(int*));

    for(int i=0;i<rows;i++){
        
        //can implement ragged using this
        printf("enter no. of cols for row %d",i+1);
        scanf("%d",&cols);
        m1[i]=(int*) calloc(cols+1,sizeof(int));
        m2[i]=(int*) calloc(cols+1,sizeof(int));
        printf("enter vals for m1 and m2 row %d",i+1);
       
        for(int j=1;j<=cols;j++){
            scanf("%d %d",(*(m1+i)+j),(*(m2+i)+j));
        }

        m1[i][0]=cols;
         m2[i][0]=cols;
         //storing size of each row in first col

    }

    display(m1,rows,cols);
    display(m2,rows,cols);

    mult(m1,m2,rows,cols);

    return 0;

}