#include<stdio.h>
void main(){
    // read n array elements and calculate their sum and average.
    int n;
    printf("enter array size: ");
    scanf("%d",&n);
    int arr[n];
    // taking input from user
    for(int i=0;i<n;i++){
        printf("enter a[%d] value: ",i);
        scanf("%d",&arr[i]);
    }
    // print array
     for(int i=0;i<n;i++){
        printf("%d  ",arr[i]); 
    }
    printf("\n");
      // print  reverse ofarray
     for(int i=n-1;i>=0;i--){
        printf("%d  ",arr[i]); 
    }
}