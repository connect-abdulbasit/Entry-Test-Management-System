#include<stdio.h>
#include<string.h>
int count;
void administrator();
void student();
typedef struct student
{
    int cnic;
    char name[100];
    int age;
    char gender;
} std;

int main()
{
    int flag=0;
    std a[100];

    do
    {

    int interface;

    printf("\tWELCOME\n\n1:Administrator Interface\n2:Student Interface\n0:Exit\n");
    scanf("%d", &interface);
    switch (interface)
    {
    case 1:
        
        break;
    case 2:
        student(a);
        break;
    case 0:
        flag=1;
        break;
        
    }
    } while (flag==0);
    printf("%d",a[0].age);
    return 0;
}
void student(std *a){
int FLAG=0,option;
do
{
    printf("1: Regisration\n2:Take test\n3:Result\n0: Exit\n");
    scanf("%d",&option);

    switch (option)
    {
    case 1:
        printf("Enter your name: \n");
        scanf("%s",a[count].name);
        printf("Enter your cnic: \n");
        scanf("%d",&a[count].cnic);
        printf("Enter your age: \n");
        scanf("%d",&a[count].age);
        printf("Enter your gender: (M,F) \n");
        scanf(" %c",&a[count].gender);

        count++;
        break;
    case 2:
        
        break;

    case 3:
    break;
    case 0:
        FLAG=1;
        break;
    default:
    printf("Invalid Input\n\n");
        break;
    }
} while (FLAG==0);

}