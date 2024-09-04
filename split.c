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
    int s,n,i,j=0,k,init=0;
    printf("\nEnter number of indices for splitting : ");
    scanf("%d",&s);
    int split[s+1];
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int arr[n];
    split[s] = n;
    printf("\nEnter %d elements :\n",n);
    input(arr,n);
    printf("\nEnter %d indices to split :\n",s);
    input(split,s);
    printf("\nArray before splitting : ");
    output(arr,n);
    printf("\nArray after splitting : ");
    for(i=0;i<=n;i++){
        if(i==split[j]){
            printf("\nArray %d : ",j+1);
            for(k=init;k<split[j];k++)
                printf("%d,",arr[k]);
            j++;
            init = split[j-1];0
        }
    }
    return 0;
}
