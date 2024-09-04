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

int main(){
    int m,n,i;
    printf("\nEnter number of elements of both arrays : ");
    scanf("%d,%d",&m,&n);
    int a[m+n],b[n];
    printf("\nEnter %d elements for array 1 :\n",m);
    input(a,m);
    printf("\nEnter %d elements for array 2 :\n",n);
    input(b,n);
    printf("\nArray 1 : ");
    output(a,m);
    printf("\nArray 2 : ");
    output(b,n);
    printf("\nArrays after merging : ");
    output(a,m);output(b,n);
    return 0;
}
