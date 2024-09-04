#include <stdio.h>

void input(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

void output(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d,",arr[i]);
}

int main()
{
    int n,i,target,index;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    printf("\nEnter %d elements :\n",n);
    int arr[n+1];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the element to be inserted and its index, separated by commas : ");
    scanf("%d,%d",&target,&index);
    printf("\nArray before insertion : ");
    output(arr,n);
    for(i=n;i>index;i--)
        arr[i] = arr[i-1];
    arr[index] = target;
    printf("\nArray after insertion : ");
    output(arr,n+1);
    return 0;
}
