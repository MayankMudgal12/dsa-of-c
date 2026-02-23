#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[100], i=0 , j,n,value,pos,m,s;
    
    printf("enter the number of element in array");
    scanf("%d",&n);
    printf("enter the elements");
    while(i<n){
        scanf("%d",&arr[i]);
        printf("\n");
        i++;
    }

    printf("enter the element you want to enter");
    scanf("%d",value);
    printf("at what position");
    scanf("%d",pos);
    
    for(i=n;i>=pos-1;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    n++;
    for(s=1;s<=n;s++){
        printf("%d",arr[i]);
    }
      
 




}