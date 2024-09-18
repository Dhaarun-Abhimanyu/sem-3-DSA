#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input(int arr[],int n){
    const k;
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
}
void output(int arr[],int n){
    int i;
    printf("\n\nSorted Array : ");
    for(i=0;i<n;i++)
        printf("%d,",arr[i]);
}

int linear(int arr[], int n, int target, int *iter){
    int i;
    for(i=0;i<n;i++){
        *iter = *iter + 1;
        if(arr[i] == target)
            return i;
    }
    return -1;
}

int binary(int arr[], int n, int target, int *iter){
    int left=0, right=n-1, mid = 0;
    while(left <= right){
        *iter = *iter + 1;
        mid = (left + right)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            right = mid-1;
        else
            left = mid+1;

    }
    return -1;
}

int bubble(int arr[], int n){
    int i,j,counter=0;
    for(i=0;i<n-1;i++){
        int check = 0;
        for(j=0;j<n-i-1;j++){
            counter++;
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                check = 1;
            }
        }
        if(!check)
            break;
    }
    return counter;
}
int selection(int arr[], int n){
    int i,j,counter=0;
    for(i=0;i<n;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            counter++;
            if(arr[min] > arr[j])
                min=j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    return counter;
}
int insertion(int arr[], int n){
    int i,j,counter=0;
    int key=0;
    for(i=0;i<n-1;i++){
        for(j=i+1;j>0;j--){
                counter++;
            if(arr[j] > arr[j-1]){
                break;
            }
            else{
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
    return counter;
}
int sort()
{
    int *arr = (int*)malloc(sizeof(int));
    int n;
    int choice;
    printf("\nEnter:\n(1)Bubble Sort\n(2)Selection Sort\n(3)Insertion sort\nYour choice : ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("\nEnter number of elements : ");
            scanf("%d",&n);
            arr = (int*)realloc(arr, n*sizeof(int));
            printf("\nEnter %d elements : ",n);
            input(arr,n);
        printf("\nBest case : %d iterations\nWorst case : %d iterations\nNumber of iterations for given array : %d",n-1,n*(n-1)/2,bubble(arr,n));
            break;
        case 2:
            printf("\nEnter number of elements : ");
            scanf("%d",&n);
            arr = (int*)realloc(arr, n*sizeof(int));
            printf("\nEnter %d elements : ",n);
            input(arr,n);
            printf("\nBest case : %d iterations\nWorst case : %d iterations\nNumber of iterations for given array : %d",n*(n-1)/2,n*(n-1)/2,selection(arr,n));
            break;
        case 3:
            printf("\nEnter number of elements : ");
            scanf("%d",&n);
            arr = (int*)realloc(arr, n*sizeof(int));
            printf("\nEnter %d elements : ",n);
            input(arr,n);
            printf("\nBest case : %d iterations\nWorst case : %d iterations\nNumber of iterations for given array : %d",n-1,n*(n-1)/2,insertion(arr,n));
            break;
        default:
            printf("\nINVALID CHOICE !!!");
            return;
    }
    output(arr,n);
    return 0;
}

int search()
{
    int choice,n,*iter,iterations=0,result,target,worst;
    iter = &iterations;
    int *arr = (int*)malloc(sizeof(int));
    printf("\nEnter:\n(1)Linear Search\n(2)Binary Search\nYour choice : ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("\nEnter number of elements : ");
            scanf("%d",&n);
            arr = (int*)realloc(arr, n*sizeof(int));
            printf("\nEnter %d elements : ",n);
            input(arr,n);
            printf("\nEnter the element to be searched : ");
            scanf("%d",&target);
            result = linear(arr,n,target,iter);
            printf("\nBest case : %d iterations\nWorst case : %d iterations\nCurrent number of iterations : %d",1,n,*iter);
            if(result != -1){
                printf("\nElement found at index %d",result);
                break;
            }
            else
                printf("\nElement not found!!!");
            break;

        case 2:
            printf("\nEnter number of elements : ");
            scanf("%d",&n);
            arr = (int*)realloc(arr, n*sizeof(int));
            printf("\nEnter %d sorted elements : ",n);
            input(arr,n);
            printf("\nEnter the element to be searched : ");
            scanf("%d",&target);
            result = binary(arr,n,target,iter);
            worst = ceil(log(n)/log(2.0));
            printf("\nBest case : %d iterations\nWorst case : %d iterations\nCurrent number of iterations : %d",1,worst,*iter);
            if(result != -1){
                printf("\nElement found at index %d",result);
                break;
            }
            else
                printf("\nElement not found!!!");
            break;
            break;

        default:
            printf("\nWrong Choice!!!");
    }
    return 0;
}

int main(){
    int choice;
    printf("\nEnter:\n(1)Searching\n(2)Sorting\nYour choice : ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        search();
        break;
    case 2:
        sort();
        break;
    default:
        printf("\nWrong choice!!!");
    }
    return 0;
}
