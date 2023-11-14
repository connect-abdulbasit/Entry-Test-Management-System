#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int count = 0;
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
    float ecat;
    float sat;
    float military;

} std;

int main()
{
    int flag = 0;
    std *ptr;

    ptr = (std *)calloc(count, sizeof(std));
    if (ptr == NULL)
    {
        print("Insufficient memory\n");
    }
    else
    {
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
                student(ptr);
                break;
            case 0:
                flag = 1;
                break;
            }
        } while (flag == 0);
    }
    return 0;
}
void student(std *a)
{
    int FLAG = 0, option, error = 0, exit = 3, choice;
    do
    {
        printf("1:Regisration\n2:Take test\n3:Result\n0: Exit\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            count++;
            a = realloc(a, count);
            if (a + count == NULL)
            {
                printf("Insufficient memory\n");
            }
            else
            {

                printf("Enter your name: \n");
                scanf("%s", a[count].name);
                do
                {
                    error = 0;
                    printf("Enter your cnic: \n");
                    scanf("%s", &a[count].cnic);

                    for (int i = 0; i < count; i++)
                    {
                        if (strcmp(a[i].cnic, a[count].cnic) == 0)
                        {
                            if (exit > 0)
                            {
                                printf("This cnic is already used\n");
                                error = 1;
                                exit--;
                                printf("%d attempt left:\n", exit);
                            }
                            else
                            {
                                printf("Maximum attempt reached\n");
                            }
                        }
                    }

                } while (error == 1 && exit != 0);
                if (exit == 0)
                {
                    break;
                }

                printf("Enter your age: \n");
                scanf("%d", &a[count].age);
                printf("Enter your gender: (M,F) \n");
                scanf(" %c", &a[count].gender);
                roll_number(a, 0);
                printf("Your roll number is %d\n", a[count].rollno);
            }
            break;
        case 2:
            printf("1: SAT\n2: ECAT\n3: Military\n");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            default:
                printf("Invalid Input\n");
                break;
            }
            break;
            break;

        case 3:
            printf("Enter your roll no\n");
            scanf("%d", &roll);
            for (int i = 0; i < count; i++)
            {
                if (a[i].rollno == roll)
                {
                    roll = i;
                    break;
                }
            }

            printf("1: SAT\n2: ECAT\n3: Military\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Your score is %f", a[roll].sat);
                break;
            case 2:
                printf("Your score is %f", a[roll].ecat);

                break;
            case 3:
                printf("Your score is %f", a[roll].military);

                break;
            default:
                break;
            }
            break;
        case 0:
            FLAG = 1;
            break;
        default:
            printf("Invalid Input\n\n");
            break;
        }
    } while (FLAG == 0);
}
int roll_number(std *a, int i)
{
    int error = 0;
    if (a[count].cnic[i] == '\0')
    {
        roll = 0;
        return 0;
    }
    roll_number(a, i + 1);
    if (roll < 5)
    {

        a[count].rollno += ((int)(a[count].cnic[roll] - '0') * pow(10, roll));
        roll++;
    }
    do
    {
        for (int i = 0; i < count; i++)
        {
            error = 0;
            if (a[i].rollno == a[count].rollno)
            {
                a[count].rollno++;
                error = 1;
            }
        }
    } while (error == 1);
}
