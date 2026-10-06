# LAB CYCLE 2 - STUDENT STRUCTURE

## Student Structure - Dynamic Memory Allocation

### Question

Define a structure called `Student` with the members: `Name`, `Reg_no`, marks in 3 tests and `average_marks`.

Develop a menu driven program to perform the following by writing separate function for each operation:

1. Read information of N students
2. Display student's information
3. Calculate the average of best two test marks of each student

**Note:** Allocate memory dynamically and illustrate the use of pointer to an array of structure.

---

## Program

```c
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
        printf("Name            : %s\n", S[i].Name);
        printf("Register Number : %d\n", S[i].Reg_no);
        printf("Test 1 Marks    : %.2f\n", S[i].marks[0]);
        printf("Test 2 Marks    : %.2f\n", S[i].marks[1]);
        printf("Test 3 Marks    : %.2f\n", S[i].marks[2]);
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

Enter number of students: 2

========== STUDENT MENU ==========
1. Read Student Information
2. Display Student Information
3. Calculate Average of Best Two Tests
4. Exit
==================================
Enter your choice: 1

Enter details of Student 1
Enter Name: Rahul
Enter Register Number: 101
Enter marks in 3 tests: 80 70 90

Enter details of Student 2
Enter Name: Anjali
Enter Register Number: 102
Enter marks in 3 tests: 85 95 75

========== STUDENT MENU ==========
1. Read Student Information
2. Display Student Information
3. Calculate Average of Best Two Tests
4. Exit
==================================
Enter your choice: 3

Average of best two test marks calculated successfully.

========== STUDENT MENU ==========
1. Read Student Information
2. Display Student Information
3. Calculate Average of Best Two Tests
4. Exit
==================================
Enter your choice: 4
Program terminated.

Enter number of students: 2

========== STUDENT MENU ==========
1. Read Student Information
2. Display Student Information
3. Calculate Average of Best Two Tests
4. Exit
==================================
Enter your choice: 1

Enter details of Student 1
Enter Name: Rahul
Enter Register Number: 101
Enter marks in 3 tests: 80 70 90

Enter details of Student 2
Enter Name: Anjali
Enter Register Number: 102
Enter marks in 3 tests: 85 95 75

========== STUDENT MENU ==========
1. Read Student Information
2. Display Student Information
3. Calculate Average of Best Two Tests
4. Exit
==================================
Enter your choice: 3

Average of best two test marks calculated successfully.

========== STUDENT MENU ==========
1. Read Student Information
2. Display Student Information
3. Calculate Average of Best Two Tests
4. Exit
==================================
Enter your choice: 2

========== STUDENT INFORMATION ==========

Student 1
Name            : Rahul
Register Number : 101
Test 1 Marks    : 80.00
Test 2 Marks    : 70.00
Test 3 Marks    : 90.00
Average (Best 2): 85.00

Student 2
Name            : Anjali
Register Number : 102
Test 1 Marks    : 85.00
Test 2 Marks    : 95.00
Test 3 Marks    : 75.00
Average (Best 2): 90.00

=========================================

========== STUDENT MENU ==========
1. Read Student Information
2. Display Student Information
3. Calculate Average of Best Two Tests
4. Exit
==================================
Enter your choice: 4
Program terminated.

````markdown
## Important Concepts

### 1. Structure

A structure is used to group different types of data under one name.

```c
struct Student
{
    char Name[50];
    int Reg_no;
    float marks[3];
    float average_marks;
};
````

### 2. Array of Structures

An array of structures stores information of multiple students.

```c
struct Student *S;
```

Here, `S` points to the dynamically allocated array of student structures.

### 3. Pointer to Structure

A pointer to a structure is used to access and modify structure members.

```c
S[i].Name
S[i].Reg_no
S[i].marks[j]
```

The pointer `S` is passed to functions so that the same student data can be accessed by different functions.

### 4. Dynamic Memory Allocation

Memory is allocated at runtime using `malloc()` based on the number of students entered by the user.

```c
S = (struct Student *)malloc(N * sizeof(struct Student));
```

This allocates memory for `N` student structures.

### 5. Memory Deallocation

Dynamically allocated memory must be released using `free()`.

```c
free(S);
```

This prevents unnecessary memory usage.

### 6. Passing Pointer to Functions

The pointer to the structure array is passed to functions.

```c
Read(S, N);
Display(S, N);
CalculateAverage(S, N);
```

This allows functions to directly access the dynamically allocated student records.

### 7. Finding the Lowest Mark

To calculate the average of the best two tests, the lowest of the three marks is identified.

```c
lowest = S[i].marks[0];

if (S[i].marks[1] < lowest)
    lowest = S[i].marks[1];

if (S[i].marks[2] < lowest)
    lowest = S[i].marks[2];
```

### 8. Average of Best Two Marks

The lowest mark is removed from the total of three marks.

```text
Average = (Mark1 + Mark2 + Mark3 - Lowest Mark) / 2
```

Example:

```text
Marks = 80, 70, 90
Lowest = 70

Average = (80 + 70 + 90 - 70) / 2
        = 85
```

### 9. Menu Driven Program

A `switch` statement is used to perform different operations according to the user's choice.

```c
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
        break;

    case 4:
        free(S);
        return 0;
}
```

### 10. Separate Functions

Each operation is implemented using a separate function:

* `Read()` → Reads student information
* `Display()` → Displays student information
* `CalculateAverage()` → Calculates the average of the best two tests

This improves code organization, readability, and reusability.

```
```
