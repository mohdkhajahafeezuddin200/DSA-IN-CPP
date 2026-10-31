#include<stdio.h>
int main(){
// find the second-largest distinct array element and report if it does not exist. 
    int n;
    printf("enter array size: ");
    scanf("%d",&n);
    int arr[n];
    // taking input from user
    for(int i=0;i<n;i++){
        printf("enter a[%d] value: ",i);
        scanf("%d",&arr[i]);
    }
    // computing second max
    int max = arr[0],smax = arr[0];
     for(int i=0;i<n;i++){
        if (max < arr[i]) max = arr[i];
    }
      for(int i=0;i<n;i++){
        if (smax < arr[i] && arr[i] != max) smax = arr[i];
    }
    printf("max = %d \n second max = %d",max,smax);
}