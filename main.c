#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct details{
    long acc_no;
    char *name;
    float balance;
} details;

float balance(int index,FILE *file_acc,FILE *file_bal){
    int i;
        long acc;
        float bal;
        for(i=0;i<index;i++){
            fscanf(file_bal,"%f\n",&bal);
            fscanf(file_acc,"%ld\n",&acc);
        }
        printf("\nAccount number : %ld",acc);
        return bal;
}


int main(){
    int choice,index=0,check=0;
    long temp;
    char name[100],pass[100];
    FILE *file_acc = fopen("C:\\Users\\student\\Desktop\\idk\\acc_no.txt","r");
    FILE *file_name = fopen("C:\\Users\\student\\Desktop\\idk\\name.txt","r");
    FILE *file_bal = fopen("C:\\Users\\student\\Desktop\\idk\\balance.txt","r");
    if(file_acc == NULL || file_name == NULL || file_bal == NULL){
        printf("\nFile not found!!!");
        return 0;
    }
    printf("\nEnter username : ");
    scanf("%s",&name);
    printf("\nEnter password : ");
    scanf("%s",&pass);
    while(file_name != EOF){
        index++;
        char temp_name[100],temp_pass[100];
        fscanf(file_name,"%s ",&temp_name);
        fscanf(file_name,"%s\n",&temp_pass);
        if(strcmp(name,temp_name) == 0){
            if(strcmp(pass,temp_pass) != 0){
                printf("\nWrong password!!!");
                return 0;
            }
            printf("\nLogin Successful!");
            check=1;
            break;
        }
    }
    if(check == 0){
        printf("\nUsername does not exist!!");
        return 0;
    }
    fclose(file_name);
    printf("\nEnter:\n1. For credit\n2. For debit\n3. Balance\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            printf("\nBalance : %.2f",balance(index,file_acc,file_bal));
            break;
        default:
            printf("\nWRONG INPUT, SUEING YOU TO THE IRS");
            return 0;
    }
    return 0;
}



/*
//BUBBLE SORT
int main()
{
    int i,j,n;
    printf("\nEnter number of terms : ");
    scanf("%d",&n);
    printf("\nEnter %d elements : ",n);
    int a[n];
    for(i = 0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
        printf("%d,",a[i]);
    return 0;
}
*/
