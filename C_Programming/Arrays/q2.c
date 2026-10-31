#include<stdio.h>
int main(){
    // max and min in 1d array
    int n;
    printf("enter array size: ");
    scanf("%d",&n);
    int arr[n];
    // taking input from user
    for(int i=0;i<n;i++){
        printf("enter a[%d] value: ",i);
        scanf("%d",&arr[i]);
    }
    // computing max and min
    int max = arr[0],min = arr[0];
     for(int i=0;i<n;i++){
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    printf("max  = %d \n min = %d",max,min);
}