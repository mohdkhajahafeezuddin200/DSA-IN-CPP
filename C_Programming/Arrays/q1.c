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
    // computing sum and average
    int sum=0;
     for(int i=0;i<n;i++){
        sum += arr[i];
    }
    float avg = sum/n;
    printf("sum is %d \n average is %f",sum,avg);
}