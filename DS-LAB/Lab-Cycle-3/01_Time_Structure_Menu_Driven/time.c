/*
================================================================
                    III LAB CYCLE - PROGRAM 01
================================================================

QUESTION:

Define a structure called Time containing 3 integer members
(hour, minute, second). Develop a menu driven program to perform
the following by writing separate function for each operation.

a) Read (T): To read time
b) Display (T): To display time
c) update(T): To Update time
d) Add (T1, T2): Add two times.

Update function increments the time by one second and returns the
new time (if the increment results in 60 seconds, then the second
member is set to zero and minute member is incremented by one.
If the result is 60 minutes, the minute member is set to zero
and the hour member is incremented by one. Finally, when the hour
becomes 24, Time should be reset to zero.

While adding two time variable, normalize the resultant time
value as in the case of update function.

Note: Illustrate the use of pointer to pass time variable to
different functions.

================================================================
*/

#include <stdio.h>

struct Time
{
    int hour;
    int minute;
    int second;
};

/* Function to read time */
void Read(struct Time *T)
{
    printf("Enter hour, minute and second: ");
    scanf("%d %d %d", &T->hour, &T->minute, &T->second);
}

/* Function to display time */
void Display(struct Time *T)
{
    printf("%02d:%02d:%02d\n", T->hour, T->minute, T->second);
}

/* Function to update time by one second */
void Update(struct Time *T)
{
    T->second++;

    if (T->second == 60)
    {
        T->second = 0;
        T->minute++;

        if (T->minute == 60)
        {
            T->minute = 0;
            T->hour++;

            if (T->hour == 24)
            {
                T->hour = 0;
            }
        }
    }
}

/* Function to add two time values */
void Add(struct Time *T1, struct Time *T2, struct Time *T3)
{
    T3->second = T1->second + T2->second;
    T3->minute = T1->minute + T2->minute;
    T3->hour = T1->hour + T2->hour;

    /* Normalize seconds */
    if (T3->second >= 60)
    {
        T3->second -= 60;
        T3->minute++;
    }

    /* Normalize minutes */
    if (T3->minute >= 60)
    {
        T3->minute -= 60;
        T3->hour++;
    }

    /* Normalize hours */
    if (T3->hour >= 24)
    {
        T3->hour %= 24;
    }
}

int main()
{
    struct Time T, T1, T2, T3;
    int choice;

    while (1)
    {
        printf("\n========== TIME MENU ==========\n");
        printf("1. Read Time\n");
        printf("2. Display Time\n");
        printf("3. Update Time\n");
        printf("4. Add Two Times\n");
        printf("5. Exit\n");
        printf("===============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                Read(&T);
                break;

            case 2:
                printf("Time = ");
                Display(&T);
                break;

            case 3:
                Update(&T);
                printf("Updated Time = ");
                Display(&T);
                break;

            case 4:
                printf("\nEnter first time:\n");
                Read(&T1);

                printf("Enter second time:\n");
                Read(&T2);

                Add(&T1, &T2, &T3);

                printf("Sum of two times = ");
                Display(&T3);
                break;

            case 5:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}