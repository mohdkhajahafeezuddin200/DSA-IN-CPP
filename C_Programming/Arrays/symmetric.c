#include<stdio.h>
void main(){
    int m,n;
    printf("enter rows & cols: ");
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("enter a[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    // transpose
    int b[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            b[i][j] = arr[j][i];
        }
    }
    // checking
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++ ){
            
        }
    }
}