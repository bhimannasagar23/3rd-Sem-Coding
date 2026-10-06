#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char Name[50];
    int Reg_no;
    float marks[3];
    float average_marks;
};

/* Function to read information of N students */
void Read(struct Student *S, int N)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Name: ");
        scanf(" %[^\n]", S[i].Name);

        printf("Enter Register Number: ");
        scanf("%d", &S[i].Reg_no);

        printf("Enter marks in 3 tests: ");
        for (j = 0; j < 3; j++)
        {
            scanf("%f", &S[i].marks[j]);
        }

        S[i].average_marks = 0;
    }
}

/* Function to calculate average of best two test marks */
void CalculateAverage(struct Student *S, int N)
{
    int i;
    float sum, lowest;

    for (i = 0; i < N; i++)
    {
        lowest = S[i].marks[0];

        if (S[i].marks[1] < lowest)
            lowest = S[i].marks[1];

        if (S[i].marks[2] < lowest)
            lowest = S[i].marks[2];

        sum = S[i].marks[0] + S[i].marks[1] + S[i].marks[2];

        S[i].average_marks = (sum - lowest) / 2.0;
    }
}

/* Function to display student information */
void Display(struct Student *S, int N)
{
    int i;

    printf("\n========== STUDENT INFORMATION ==========\n");

    for (i = 0; i < N; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Name           : %s\n", S[i].Name);
        printf("Register Number: %d\n", S[i].Reg_no);
        printf("Test 1 Marks   : %.2f\n", S[i].marks[0]);
        printf("Test 2 Marks   : %.2f\n", S[i].marks[1]);
        printf("Test 3 Marks   : %.2f\n", S[i].marks[2]);
        printf("Average (Best 2): %.2f\n", S[i].average_marks);
    }

    printf("\n=========================================\n");
}

int main()
{
    struct Student *S = NULL;
    int N;
    int choice;

    printf("Enter number of students: ");
    scanf("%d", &N);

    S = (struct Student *)malloc(N * sizeof(struct Student));

    if (S == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1)
    {
        printf("\n========== STUDENT MENU ==========\n");
        printf("1. Read Student Information\n");
        printf("2. Display Student Information\n");
        printf("3. Calculate Average of Best Two Tests\n");
        printf("4. Exit\n");
        printf("==================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                Read(S, N);
                break;

            case 2:
                Display(S, N);
                break;

            case 3:
                CalculateAverage(S, N);
                printf("\nAverage of best two test marks calculated successfully.\n");
                break;

            case 4:
                free(S);
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
