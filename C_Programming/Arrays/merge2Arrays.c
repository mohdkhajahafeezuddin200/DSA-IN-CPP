#include<stdio.h>
void main(){
    // merge two one-dimensional arrays into a third array
    int n;
    printf("enter array1 size: ");
    scanf("%d",&n);
    int arr[n];
    // taking input from user
    for(int i=0;i<n;i++){
        printf("enter arr[%d] value: ",i);
        scanf("%d",&arr[i]);
    }
    int m;
    printf("enter array2 size: ");
    scanf("%d",&m);
    int a[m];
    // taking input from user
    for(int i=0;i<m;i++){
        printf("enter a[%d] value: ",i);
        scanf("%d",&a[i]);
    }
    int c[m+n];
    for(int i=0;i<n;i++){
        c[i] = arr[i];
    }
    for(int i=n;i<n+m;i++){
        c[i] = a[i-n];
    }
     // print array
     for(int i=0;i<m+n;i++){
        printf("%d  ",c[i]); 
    }
}