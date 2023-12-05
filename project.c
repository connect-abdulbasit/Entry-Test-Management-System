#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int count = 0;
char password[10] = "Fast123";

typedef struct student
{
    char cnic[15];
    char name[100];
    int age;
    char gender;
    int rollno;

} std;
int adminPass();
void admin(std *a);
int appendSat();
int appendEcat();
int appendMil();
int appendiq();
void student(std *a);
int sat(float *result);
int ecat(float *result);
int military(float *iq, float *theo);
int roll_number(std *a, int i);

int main()
{
    int interface, pass, flag = 0;
    std ptr[100];
    do
    {
        printf("\tWELCOME\n\n1:Administrator Interface\n2:Student Interface\n0:Exit\n");
        scanf("%d", &interface);
        switch (interface)
        {
            case 1:
            pass = adminPass();
            if (pass == 1)
            {
                printf("Sucessfully login:\n");
                admin(ptr);
            }
            else
            {
                printf("Maximum attempt reached try ater 30 min\n");
                break;
            case 2:
                student(ptr);
                break;
            case 0:
                flag = 1;
                break;
            default:
            	printf("Invalid Input\n");
            }
        }
    } while (flag == 0);
    free(ptr);
    return 0;
}
int adminPass()
{
    int flag, i = 3;
    char pass[10];

    do
    {
        flag = 1;
        printf("Enter password:");
        scanf("%s", pass);
        i--;
        if (strcmp(pass, password) == 0)
        {
            return 1;
        }
        else
        {
            printf("Invalid password\n%d attempt left\n", i);
            flag = 0;
        }
    } while (i != 0);
    return 0;
}
void admin(std *a)
{
    int option, flag, op, flag1, roll;
    flag1 = 1;
    flag = 0;
    do
    {
        printf("1: Student record\n2: Question append\n0: Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter roll number:\n");
            scanf("%d", &roll);
            for (int i = 0; i < count; i++)
            {
                if (a[i].rollno == roll)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                printf("REGISTERATION DONE\n");

                char R[50];
                float marks1, marks2;
                FILE *ptr;
                ptr = fopen("Sresult.txt", "r");
                if (ptr == NULL)
                {
                    printf("Error in sat file opening:");
                }
                while (fscanf(ptr, "%d %f", &flag, &marks1) != EOF)
                {
                    if (roll == flag)
                    {
                        printf("\tSAT\nRoll No:\tScore\n");

                        printf("%d\t\t%.2f\n\n", flag, marks1);
                        break;
                    }
                }
                fclose(ptr);
                printf("\n");
                ptr = fopen("Eresult.txt", "r");
                if (ptr == NULL)
                {
                    printf("Error in ecat file opening:");
                }
                while (fscanf(ptr, "%d %f", &flag, &marks1) != EOF)
                {
                    if (roll == flag)
                    {
                        printf("\tECAT\nRoll No:\tScore\n");

                        printf("%d\t\t%f\n\n", flag, marks1);
                        break;
                    }
                }
                fclose(ptr);
                printf("\n");
                ptr = fopen("Mresult.txt", "r");
                if (ptr == NULL)
                {
                    printf("Error in military file opening:");
                }
                while (fscanf(ptr, "%d%f%f\n\n", &flag, &marks1, &marks2) != EOF)
                {
                    if (roll == flag)
                    {
                        printf("\tMilitary\nRoll No:\tIQ\tTheory\n");

                        printf("%d\t\t%.2f\t%.2f\n\n", flag, marks1, marks2);
                        break;
                    }
                }
                fclose(ptr);
            }
            else
            {
                printf("No Record Found:\n");
            }
            printf("\n");
            break;
        case 2:
            printf("Which portion:\n1:SAT\n2:ECAT\n3:Military\n");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                appendSat();
                break;
            case 2:
                appendEcat();

                break;
            case 3:
                printf("\n1:IQ\n2:Theory\n");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                    appendMil();
                    break;
                case 2:
                    appendiq();
                    break;

                default:
                    printf("Invalid Input");
                    break;
                }
            }
            break;
        case 0:
            flag1 = 0;
            break;
        default:
            printf("Invalid Input:");
            break;
        }
    } while (flag1 == 1);
}
void student(std *a)
{
    int flag = 0, option, error = 0, exit = 3, choice;
    do
    {
        printf("1:Regisration\n2:Take test\n0: Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:

            count++;

            getchar();
            printf("Enter your name: \n");
            fgets(a[count - 1].name, 100, stdin);
            do
            {
                error = 0;
                printf("Enter your cnic: \n");
                scanf("%s", &a[count - 1].cnic);

                for (int i = 0; i < (count - 1); i++)
                {
                    if (strcmp(a[i].cnic, a[count - 1].cnic) == 0)
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
            scanf("%d", &a[count - 1].age);
            printf("Enter your gender: (M,F) \n");
            scanf(" %c", &a[count - 1].gender);
            a[count - 1].rollno = 0;
            roll_number(a, 0);
            printf("Your roll number is %d\n", a[count - 1].rollno);

            break;
        case 2:
            printf("1: SAT\n2: ECAT\n3: Military\n");
            scanf("%d", &choice);
            float result, theory;
            int id, checker = 0, check = 0;
            switch (choice)
            {
            case 1:
                printf("Enter your id: \n");
                scanf("%d", &id);
                for (int i = 0; i < count; i++)
                {
                    if (a[i].rollno == id)
                    {
                        checker = 1;
                    }
                }
                if (checker != 1)
                {
                    printf("You have not registered yet\nPlz register first\n\n");
                }
                else
                {
                    check = 0;
                    FILE *ptr;
                    ptr = fopen("Sresult.txt", "r");
                    if (ptr == NULL)
                    {
                        printf("Error in file opening\n");
                    }
                    else
                    {

                        int roll = 0;
                        float marks;
                        while (fscanf(ptr, "%d %f", &roll, &marks) != EOF)
                        {

                            if (id == roll)
                            {

                                check = 1;
                                break;
                            }
                        }

                        fclose(ptr);

                        if (check == 0)
                        {
                            sat(&result);
                            FILE *s_res = fopen("Sresult.txt", "a");
                            fprintf(s_res, "%d\t\t", id);
                            fprintf(s_res, "%.2f\n", result);
                            fclose(s_res);
                        }
                        else
                        {
                            printf("You have already taken test:\n");
                        }
                    }
                }
                break;
            case 2:
                printf("Enter your roll number:\n");
                scanf("%d", &id);
                for (int i = 0; i < count; i++)
                {
                    if (a[i].rollno == id)
                    {
                        checker = 1;
                    }
                }
                if (checker == 0)
                {
                    printf("You have not registered yet\nPlz register first\n\n");
                }
                else
                {
                    check = 0;
                    FILE *ptr;
                    ptr = fopen("Eresult.txt", "r");
                    if (ptr == NULL)
                    {
                        printf("Error in file opening\n");
                    }
                    else
                    {

                        int roll = 0;
                        float marks;
                        while (fscanf(ptr, "%d %f", &roll, &marks) != EOF)
                        {

                            if (id == roll)
                            {

                                check = 1;
                                break;
                            }
                        }

                        fclose(ptr);
                        if (check == 0)
                        {
                            ecat(&result);
                            FILE *e_res = fopen("Eresult.txt", "a");
                            fprintf(e_res, "%d\t\t", id);
                            fprintf(e_res, "%.2f\n", result);
                            fclose(e_res);
                        }
                        else
                        {
                            printf("You have already taken test:\n");
                        }
                    }
                }
                break;
            case 3:
                printf("Enter your roll number:\n");
                scanf("%d", &id);
                for (int i = 0; i < count; i++)
                {
                    if (a[i].rollno == id)
                    {
                        checker = 1;
                    }
                }
                if (checker == 0)
                {
                    printf("You have not registered yet\nPlz register first\n\n");
                }
                else
                {
                    check = 0;
                    FILE *ptr;
                    ptr = fopen("Mresult.txt", "r");
                    if (ptr == NULL)
                    {
                        printf("Error in file opening\n");
                    }
                    else
                    {

                        int roll = 0;
                        float marks;
                        while (fscanf(ptr, "%d %f", &roll, &marks) != EOF)
                        {

                            if (id == roll)
                            {

                                check = 1;
                                break;
                            }
                        }

                        fclose(ptr);
                        if (check == 0)
                        {
                            military(&result, &theory);
                            FILE *m_res = fopen("Mresult.txt", "a");
                            fprintf(m_res, "%d\t\t", id);
                            fprintf(m_res, "%.2f\t", result);
                            fprintf(m_res, "%.2f\n", theory);
                            fclose(m_res);
                        }
                        else
                        {
                            printf("You have already taken test:\n");
                        }
                    }
                }
                break;
            default:
                printf("Invalid Input\n");
            }
            break;

        case 0:
            flag = 1;
            break;
        default:
            printf("Invalid Input\n");

            break;
        }
    } while (flag == 0);
}
int sat(float *result)
{
    FILE *sat_file = fopen("SAT.txt", "r");
    FILE *sat_key = fopen("sat_key.txt", "r");
    int flag = 0;
    if (sat_file == NULL || sat_key == NULL)
    {
        printf("Error\n");
        return 0;
    }

    printf("\t\tSAT TEST\n");
    char question[1000];
    char user_answer, correct_answer;
    int num_of_question = 0;
    int right_answer = 0;

    while (fscanf(sat_file, "%[^\n]\n", question) != EOF)
    {
        printf("%s\n", question);
        for (int i = 0; i < 4; i++)
        {
            fscanf(sat_file, "%[^\n]\n", question);
            printf("%s\n", question);
        }
        fscanf(sat_key, " %c", &correct_answer);
        do
        {
            flag = 0;
            scanf(" %c", &user_answer);
            if ('A' > user_answer || user_answer > 'D')
            {
                printf("Invalid Input\n");
                flag = 1;
            }
        } while (flag == 1);
        if (user_answer == correct_answer)
        {
            right_answer++;
        }
        num_of_question++;
    }

    *result = right_answer * 100.00 / num_of_question;
    printf("You score %f\n\n", *result);
    fclose(sat_file);
    fclose(sat_key);
    return 1;
}

int ecat(float *result)
{
    FILE *ecat_file = fopen("ECAT.txt", "r");
    FILE *ecat_key = fopen("ecat_key.txt", "r");
    int flag = 0;
    if (ecat_file == NULL || ecat_key == NULL)
    {
        printf("Error\n");
        return 0;
    }

    printf("\t\tECAT TEST\n");
    char question[1000];
    char user_answer, correct_answer;
    int num_of_question = 0;
    int right_answer = 0;

    while (fscanf(ecat_file, "%[^\n]\n", question) != EOF)
    {
        printf("%s\n", question);
        for (int i = 0; i < 4; i++)
        {
            fscanf(ecat_file, "%[^\n]\n", question);
            printf("%s\n", question);
        }
        fscanf(ecat_key, " %c", &correct_answer);
        do
        {
            flag = 0;
            scanf(" %c", &user_answer);
            if ('A' > user_answer || user_answer > 'D')
            {
                printf("Invalid Input\n");
                flag = 1;
            }
        } while (flag == 1);
        if (user_answer == correct_answer)
        {
            right_answer++;
        }
        num_of_question++;
    }

    *result = right_answer * 100.00 / num_of_question;
    printf("You score %f\n\n", *result);
    fclose(ecat_file);
    fclose(ecat_key);
    return 1;
}

int military(float *iq, float *theo)
{
    FILE *military1_file;
    FILE *military1_key;
    military1_file = fopen("military_iq.txt", "r");
    military1_key = fopen("military_iq_key.txt", "r");
    if (military1_file == NULL || military1_key == NULL)
    {
        printf("Error\n");
        return 0;
    }
    printf("\t\tMILITARY TEST\n");
    char question[1000];
    char user_answer, correct_answer;
    int num_of_question1 = 0, flag = 0;
    int right_answer1 = 0;
    while (fscanf(military1_file, "%[^\n]\n", question) != EOF)
    {
        printf("%s\n", question);
        for (int i = 0; i < 4; i++)
        {
            fscanf(military1_file, "%[^\n]\n", question);
            printf("%s\n", question);
        }
        fscanf(military1_key, " %c", &correct_answer);
        do
        {
            flag = 0;
            scanf(" %c", &user_answer);
            if ('A' > user_answer || user_answer > 'D')
            {
                printf("Invalid Input\n");
                flag = 1;
            }
        } while (flag == 1);
        if (user_answer == correct_answer)
        {
            right_answer1++;
        }
        num_of_question1++;
    }
    *iq = right_answer1 * 100.00 / num_of_question1;
    printf("You score %f\n\n", *iq);
    fclose(military1_key);
    fclose(military1_file);
    if (*iq >= 50.0)
    {
        printf("Congratulations! You have sucessfully cleared IQ test.\n\n");

        FILE *military_file;
        FILE *military_key;
        military_file = fopen("Military.txt", "r");
        military_key = fopen("militarykey.txt", "r");
        if (military_file == NULL)
        {
            printf("Error\n");
            return 0;
        }
        printf("\t\tMILITARY TEST (Round #2)\n");
        char question[1000];
        int num_of_question2 = 0;
        int right_answer2 = 0;
        while (fscanf(military_file, "%[^\n]\n", question) != EOF)
        {
            printf("%s\n", question);
            for (int i = 0; i < 4; i++)
            {
                fscanf(military_file, "%[^\n]\n", question);
                printf("%s\n", question);
            }
            fscanf(military_key, " %c", &correct_answer);
            do
            {
                flag = 0;
                scanf(" %c", &user_answer);
                if ('A' > user_answer || user_answer > 'D')
                {
                    printf("Invalid Input\n");
                    flag = 1;
                }
            } while (flag == 1);
            if (user_answer == correct_answer)
            {
                right_answer2++;
            }
            num_of_question2++;
        }
        *theo = right_answer2 * 100.00 / num_of_question2;
        printf("You score %f\n\n", *theo);
        fclose(military_file);
        fclose(military_key);
        if (*theo >= 50.0)
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

int roll_number(std *a, int i)
{
    int error = 0;
    static int roll;
    if (a[count - 1].cnic[i] == '\0')
    {
        roll = 0;
        return 0;
    }
    roll_number(a, i + 1);
    if (roll < 5)
    {

        a[count - 1].rollno += (((int)(a[count - 1].cnic[i] - '0')) * pow(10, roll));
        roll++;
    }
    else
    {
        do
        {
            error = 0;
            for (int i = 0; i < (count - 1); i++)
            {
                if (a[i].rollno == a[count - 1].rollno)
                {
                    a[count - 1].rollno++;
                    error = 1;
                }
            }
        } while (error == 1);
    }
}

int appendSat()
{
    FILE *ptr = fopen("SAT.txt", "a");
    FILE *ptr1 = fopen("sat_key.txt", "a");
    if (ptr == NULL || ptr1 == NULL)
    {
        printf("Error\n");
        return 0;
    }

    char input[1000], key;
    printf("Enter a question:\n");
    for (int i = 0; i < 6; i++)
    {
        fgets(input, 1000, stdin);
        fprintf(ptr, "%s", input);
    }
    printf("Enter answer key\n");
    scanf(" %c", &key);
    fprintf(ptr1, "%c", key);

    fclose(ptr);
    fclose(ptr1);
}
int appendEcat()
{
    FILE *ptr = fopen("ECAT.txt", "a");
    FILE *ptr1 = fopen("ecat_key.txt", "a");
    if (ptr == NULL || ptr1 == NULL)
    {
        printf("Error\n");
        return 0;
    }

    char input[1000], key;
    printf("Enter a question:\n");
    for (int i = 0; i < 6; i++)
    {
        fgets(input, 1000, stdin);
        fprintf(ptr, "%s", input);
    }
    printf("Enter answer key\n");
    scanf(" %c", &key);
    fprintf(ptr1, "%c", key);

    fclose(ptr);
    fclose(ptr1);
}
int appendMil()
{
    char key;
    FILE *ptr = fopen("Military.txt", "a");
    FILE *ptr1 = fopen("militarykey.txt", "a");
    if (ptr == NULL || ptr1 == NULL)
    {
        printf("Error\n");
        return 0;
    }

    char input[1000];
    printf("Enter a question:\n");
    for (int i = 0; i < 6; i++)
    {
        fgets(input, 1000, stdin);
        fprintf(ptr, "%s", input);
    }
    printf("Enter answer key\n");
    scanf(" %c", &key);
    fprintf(ptr1, "%c", key);

    fclose(ptr);
    fclose(ptr1);
}
int appendiq()
{
    char key;
    FILE *ptr = fopen("military_iq.txt", "a");
    FILE *ptr1 = fopen("military_iq_key.txt", "a");
    if (ptr == NULL || ptr1 == NULL)
    {
        printf("Error\n");
        return 0;
    }

    char input[1000];
    printf("Enter a question:\n");
    for (int i = 0; i < 6; i++)
    {
        fgets(input, 1000, stdin);
        fprintf(ptr, "%s", input);
    }
    printf("Enter answer key\n");
    scanf(" %c", &key);
    fprintf(ptr1, "%c", key);

    fclose(ptr);
    fclose(ptr1);
}
