#include<stdio.h>
#include<string.h>
#include<math.h>
int count;
int roll;
void administrator();
void student();
int roll_number();
typedef struct student
{
    char cnic[15];
    char name[100];
    int age;
    char gender;
    int rollno;

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
        scanf("%s",&a[count].cnic);
        printf("Enter your age: \n");
        scanf("%d",&a[count].age);
        printf("Enter your gender: (M,F) \n");
        scanf(" %c",&a[count].gender);
        a[count].rollno=0;
        roll_number(a,0);
        printf("Your roll number is %d\n",a[count].rollno);
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
int roll_number(std *a,int i){

    if(a[count].cnic[i]=='\0'){
        roll=0;
        return 0;
    }
    roll_number(a,i+1);
    if (roll<5)
    {
            
    a[count].rollno += ((int)(a[count].cnic[roll]-'0')* pow(10,roll));
    roll++;
    }
}