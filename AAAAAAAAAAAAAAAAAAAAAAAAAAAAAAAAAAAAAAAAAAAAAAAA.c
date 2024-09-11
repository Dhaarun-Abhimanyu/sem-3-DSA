#include <stdio.h>
#include <stdlib.h>

int n=0,check = 0,l=0;

void input(int *arr){
    printf("\nEnter %d elements : ",n);
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

void output(int *arr){
    int i;
    for(i=0;i<n;i++)
        printf("%d,",arr[i]);
}

void bubble_asc(int *arr){
    int i,j;
    for(i=0;i<n-1;i++){
        int check = 0;
        for(j=0;j<n-i-1;j++){
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
}

void bubble_des(int *arr){
    int i,j;
    for(i=0;i<n-1;i++){
        int check = 0;
        for(j=0;j<n-i-1;j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                check = 1;
            }
        }
        if(!check)
            break;
    }
}

void search(int arr[], int target){
    int i;
    for(i=0;i<n;i++){
        if(arr[i] == target){
            printf("\nTarget found at index %d",i);
            return;
        }
    }
    printf("\nElement not found!!");
}

void splitting(int *arr,int *split){
    int index,i;
    printf("\nEnter the index to split : ");
    scanf("%d",&index);
    printf("\nArray before splitting : ");
    output(arr);
    printf("\nArray after splitting :");
    l = n-index;
    split = (int*)realloc(split,l*sizeof(int));
    for(i=index;i<n;i++)
        split[i-index] = arr[i];
    n = index;
    printf("\nArray 1 : ");
    output(arr);
    printf("\nArray 2 : ");
    for(i=0;i<l;i++)
        printf("%d,",split[i]);
    check = 1;
}

void merge(int *arr,int *split){
    int temp=0,i;
    int *arr_2;
    if(check == 0){
        printf("\nEnter length of array 2 : ");
        scanf("%d",&temp);
        printf("\nEnter %d elements for array 2 :\n",temp);
        arr_2 = (int*)malloc(temp*sizeof(int));
        for(i=0;i<temp;i++)
            scanf("%d",&arr_2[i]);
    }
    else{
        temp = l;
        arr_2 = split;
    }
    printf("\nArray 1 : ");
    output(arr);
    printf("\nArray 2 : ");
    for(i=0;i<temp;i++)
        printf("%d,",arr_2[i]);
    printf("\nArrays after merging : ");
    arr = (int*)realloc(arr,(n+temp)*sizeof(int));
    for(i=n;i<n+temp;i++)
        arr[i] = arr_2[i-n];
    n+=temp;
    output(arr);
    check = 0;
    l=0;
}

void insert(int *arr)
{
    int i,index,target;
    printf("\nEnter the element to be inserted and its index, separated by commas : ");
    scanf("%d,%d",&target,&index);
    printf("\nArray before insertion : ");
    output(arr);
    for(i=n;i>index;i--)
        arr[i] = arr[i-1];
    arr[index] = target;
    printf("\nArray after insertion : ");
    n+=1;
    output(arr);
}

void delete(int *arr){
    int i,index;
    printf("\nEnter the index to be deleted : ");
    scanf("%d",&index);
    printf("\nArray before deletion : ");
    output(arr);
    for(i=index;i<n-1;i++)
        arr[i] = arr[i+1];
    printf("\nArray after deletion : ");
    n-=1;
    output(arr);
    return 0;
}

int main()
{
    int choice,sort,a,b,index,element ,target,temp,rot,i;
    int *arr,*split;
    outer:
    printf("\n\nEnter\n0.Initialize\n1. Searching\n2. Sorting\n3.Merging\n4.Splitting\n5.Inserting\n6.Deleting\n7.Exchanging\n8.Rotating\n9.Traversing\n10.Displaying\n11.Copying\n12.Updating\n13.Exit\n\n");
    scanf("%d",&choice);
    switch(choice){
    case 0:
        printf("\nEnter number of elements : ");
        scanf("%d",&n);
        arr = (int*)malloc(n*sizeof(int));
        split = (int*)malloc(n*sizeof(int));
        input(arr);
        break;

    case 1:
        printf("\nEnter an element to be searched : ");
        scanf("%d",&target);
        search(arr,target);
        break;
    case 2:
        printf("\nEnter 1.Ascending\n2.Descending");
        scanf("%d",&sort);
        if(sort != 1 && sort != 2){
            printf("\nWrong choice!!!");
            break;
        }
        printf("\nArray before sorting : ");
        output(arr);
        printf("\nArray after sorting : ");
        if(sort == 1)
            bubble_asc(arr);
        else
            bubble_des(arr);
        output(arr);
        break;
    case 3:
        merge(arr,split);
        break;
    case 4:
        splitting(arr,split);
        break;
    case 5:
        insert(arr);
        break;
    case 6:
        delete(arr);
        break;
    case 7:
        printf("\nEnter two indices to be exchanged : ");
        scanf("%d,%d",&a,&b);
        printf("\nArray before exchanging : ");
        output(arr);
        printf("\nArray after exchanging : ");
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        output(arr);
        break;
    case 8:
        printf("\nEnter\n1.Right rotation\n2.Left rotation\n");
        scanf("%d",&rot);
        if(rot != 1 && rot != 2){
            printf("\nWrong choice!!!");
            break;
        }
        printf("\nEnter no. of times to rotate : ");
        int rotate;
        scanf("%d",&rotate);
        if(rot == 1){

        }
        break;
    case 9:
        printf("\nArray traversal : ");
        output(arr);
        break;
    case 10:
        printf("\nDisplaying array elements : ");
        output(arr);
        break;
    case 11:
        printf("\nOriginal array : ");
        output(arr);
        printf("\nCopied array : ");
        output(arr);
        break;
    case 12:
        printf("\nEnter the index and new element to be updated : ");
        scanf("%d,%d",&index,&element);
        printf("\nArray before updating : ");
        output(arr);
        printf("\nArray after updating : ");
        arr[index] = element;
        output(arr);
        break;
    case 13:
        printf("\nProgram terminated!!!");
        return;
    default:
        printf("\nWrong Choice!!!");
    }
    goto outer;
    return 0;
}
