#include <stdio.h>

int main(){
    int n,i,index;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    printf("\nEnter %d elements :\n",n);
    int arr[n];
    input(arr,n);
    printf("\nEnter the index to be deleted : ");
    scanf("%d",&index);
    printf("\nArray before deletion : ");
    output(arr,n);
    for(i=index;i<n-1;i++)
        arr[i] = arr[i+1];
    printf("\nArray after deletion : ");
    output(arr,n-1);
    return 0;
}
