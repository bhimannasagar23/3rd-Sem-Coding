````markdown
# III LAB CYCLE - PROGRAM 01

## Time Structure - Menu Driven Program

### Question

Define a structure called Time containing 3 integer members (hour, minute, second). Develop a menu driven program to perform the following by writing separate function for each operation.

a) Read (T): To read time  
b) Display (T): To display time  
c) update(T): To Update time  
d) Add (T1, T2): Add two times.

Update function increments the time by one second and returns the new time (if the increment results in 60 seconds, then the second member is set to zero and minute member is incremented by one. If the result is 60 minutes, the minute member is set to zero and the hour member is incremented by one. Finally, when the hour becomes 24, Time should be reset to zero.

While adding two time variable, normalize the resultant time value as in the case of update function.

**Note:** Illustrate the use of pointer to pass time variable to different functions.

---

## Program

```c
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
````

---

## Output 1 - Update Time

```text
========== TIME MENU ==========
1. Read Time
2. Display Time
3. Update Time
4. Add Two Times
5. Exit
===============================
Enter your choice: 1
Enter hour, minute and second: 23 59 59

========== TIME MENU ==========
1. Read Time
2. Display Time
3. Update Time
4. Add Two Times
5. Exit
===============================
Enter your choice: 3
Updated Time = 00:00:00

========== TIME MENU ==========
1. Read Time
2. Display Time
3. Update Time
4. Add Two Times
5. Exit
===============================
Enter your choice: 5
Program terminated.
```

---

## Output 2 - Add Two Times

```text
========== TIME MENU ==========
1. Read Time
2. Display Time
3. Update Time
4. Add Two Times
5. Exit
===============================
Enter your choice: 4

Enter first time:
Enter hour, minute and second: 12 45 50

Enter second time:
Enter hour, minute and second: 11 20 30

Sum of two times = 00:06:20

========== TIME MENU ==========
1. Read Time
2. Display Time
3. Update Time
4. Add Two Times
5. Exit
===============================
Enter your choice: 5
Program terminated.
```

---

## Important Concepts

### 1. Structure

```c
struct Time
{
    int hour;
    int minute;
    int second;
};
```

The structure stores hour, minute and second as one variable.

### 2. Pointer to Structure

The functions receive the address of the structure.

```c
void Update(struct Time *T)
```

The function is called using:

```c
Update(&T);
```

Here, `&T` passes the address of `T`.

Structure members are accessed using the arrow operator:

```c
T->hour
T->minute
T->second
```

### 3. Update Logic

When seconds become 60:

```text
seconds = 0
minutes = minutes + 1
```

When minutes become 60:

```text
minutes = 0
hours = hours + 1
```

When hours become 24:

```text
hours = 0
```

### 4. Addition

Two time values are added and then normalized so that:

```text
seconds < 60
minutes < 60
hours < 24
```

---

## File Structure

```text
01_Time_Structure_Menu_Driven/
│
├── README.md
└── time.c
```

**README.md** → Question + Program + Outputs + Important Concepts for revision.

**time.c** → Separate source file used for compilation and execution.

```
```
