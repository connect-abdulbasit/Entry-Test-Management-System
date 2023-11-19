#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int count = 0;
int roll;
void administrator();
void student();
int roll_number();
int sat();
void military();
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
        printf("Insufficient memory\n");
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

    free(ptr);
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
            float result;

            switch (choice)
            {
            case 1:

                sat(&result);

                break;
            case 2:

                break;
            case 3:

                military(&result);

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
int sat(float *result)
{
    FILE *sat_file;
    FILE *sat_key;
    sat_file = fopen("SAT.txt", "r");
    sat_key = fopen("sat_key.txt", "r");
    if (sat_file == NULL)
    {
        printf("Error\n");
        return 0;
    }

    printf("\t\tSAT TEST\n");
    char question[100];
    char user_answer, correct_answer;
    int num_of_question = 0;
    int right_answer = 0;
    do
    {
        fscanf(sat_file, "%[^\n]\n", question);
        printf("%s\n", question);
        fscanf(sat_file, "%[^\n]\n", question);
        printf("%s\n", question);
        fscanf(sat_file, "%[^\n]\n", question);
        printf("%s\n", question);
        fscanf(sat_file, "%[^\n]\n", question);
        printf("%s\n", question);
        fscanf(sat_file, "%[^\n]\n", question);
        printf("%s\n", question);
        fscanf(sat_key, "%c", &correct_answer);
        scanf(" %c", &user_answer);
        if (user_answer == correct_answer)
        {
            right_answer++;
        }
        num_of_question++;
    } while (num_of_question != 5);
    *result = right_answer * 100.00 / num_of_question;
    printf("You score %f\n\n", *result);
    return 1;
}
void military(float *result)
{
    FILE *military1_file;
    FILE *military1_key;
    military1_file = fopen("military_iq.txt", "r");
    military1_key = fopen("militarykey1.txt", "r");
    if (military1_file == NULL)
    {
        printf("Error\n");
    }   
        printf("\t\tMILITARY TEST\n");
        char ques1[100];
        char user_answer1, correct_answer1;
        int num_of_question1 = 0;
        int right_answer1 = 0;
        do
        {
            fscanf(military1_file, "%[^\n]\n", ques1);
            printf("%s\n", ques1);
            fscanf(military1_file, "%[^\n]\n", ques1);
            printf("%s\n", ques1);
            fscanf(military1_file, "%[^\n]\n", ques1);
            printf("%s\n", ques1);
            fscanf(military1_file, "%[^\n]\n", ques1);
            printf("%s\n", ques1);
            fscanf(military1_file, "%[^\n]\n", ques1);
            printf("%s\n", ques1);
            fscanf(military1_key, "%c", &correct_answer1);
            scanf(" %c", &user_answer1);
            if (user_answer1 == correct_answer1)
            {
                right_answer1++;
            }
            num_of_question1++;
        } while (num_of_question1 != 5);
        *result = right_answer1 * 100.00 / num_of_question1;
        printf("You score %f\n\n", *result);
        if (*result >= 50.0)
        {
            printf("Congratulations! You have sucessfully cleared IQ test.\n\n");
            float result2;
            FILE *military_file;
            FILE *military_key;
            military_file = fopen("Military.txt", "r");
            military_key = fopen("militarykey.txt", "r");
            if (military_file == NULL)
            {
                printf("Error\n");
            }
                printf("\t\tMILITARY TEST (Round #2)\n");
                char ques[100];
                char user_answer2, correct_answer2;
                int num_of_question2 = 0;
                int right_answer2 = 0;
                do
                {
                    fscanf(military_file, "%[^\n]\n", ques);
                    printf("%s\n", ques);
                    fscanf(military_file, "%[^\n]\n", ques);
                    printf("%s\n", ques);
                    fscanf(military_file, "%[^\n]\n", ques1);
                    printf("%s\n", ques);
                    fscanf(military_file, "%[^\n]\n", ques);
                    printf("%s\n", ques);
                    fscanf(military_file, "%[^\n]\n", ques);
                    printf("%s\n", ques);
                    fscanf(military_key, "%c", &correct_answer2);
                    scanf(" %c", &user_answer2);
                    if (user_answer2 == correct_answer2)
                    {
                        right_answer2++;
                    }
                    num_of_question2++;
                } while (num_of_question2 != 5);
                result2 = right_answer2 * 100.00 / num_of_question2;
                printf("You score %f\n\n", result2);
                if (result2>=50.0)
                {
                    printf("Congratulations! You have sucessfully cleared Military test.\n");
                }
                else
                {
                    printf("You have not cleared Military test. Better luck next time :(\n");
                }
            }
            else
            {
                printf("You have not cleared IQ test. Better luck next time :( \n");
            }
            
        }
    