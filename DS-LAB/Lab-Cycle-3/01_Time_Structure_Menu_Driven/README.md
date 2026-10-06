# ⏱️ III LAB CYCLE — PROGRAM 01

## Time Structure — Menu Driven Program

---

# 📌 Question

Define a structure called `Time` containing 3 integer members (`hour`, `minute`, `second`). Develop a menu driven program to perform the following by writing separate function for each operation.

**a) Read (T):** To read time
**b) Display (T):** To display time
**c) Update (T):** To update time
**d) Add (T1, T2):** Add two times

Update function increments the time by one second and returns the new time. If the increment results in 60 seconds, the second member is set to zero and the minute member is incremented by one. If the result is 60 minutes, the minute member is set to zero and the hour member is incremented by one. Finally, when the hour becomes 24, Time should be reset to zero.

While adding two time variables, normalize the resultant time value as in the case of update function.

> **Note:** Illustrate the use of pointer to pass time variable to different functions.

---

# 💻 Code

```c
#include <stdio.h>

struct Time
{
    int hour;
    int minute;
    int second;
};

void Read(struct Time *T)
{
    printf("Enter hour, minute and second: ");
    scanf("%d %d %d", &T->hour, &T->minute, &T->second);
}

void Display(struct Time *T)
{
    printf("%02d:%02d:%02d\n", T->hour, T->minute, T->second);
}

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
                T->hour = 0;
        }
    }
}

void Add(struct Time *T1, struct Time *T2, struct Time *T3)
{
    T3->second = T1->second + T2->second;
    T3->minute = T1->minute + T2->minute;
    T3->hour = T1->hour + T2->hour;

    if (T3->second >= 60)
    {
        T3->second -= 60;
        T3->minute++;
    }

    if (T3->minute >= 60)
    {
        T3->minute -= 60;
        T3->hour++;
    }

    if (T3->hour >= 24)
        T3->hour %= 24;
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
}
```

---

# 🖥️ Output

## 🔹 Output 1 — Update Time

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

## 🔹 Output 2 — Add Two Times

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

# 🎤 Important Viva Questions

### 01. What is a structure?

A structure is a user-defined data type that groups different data types under one name.

### 02. Why is `struct Time` used here?

To store hour, minute, and second together as a single time variable.

### 03. Why is a pointer used in the functions?

To pass the address of the structure and directly modify its members.

### 04. What does `T->hour` mean?

It accesses the `hour` member of the structure pointed to by `T`.

### 05. What is the difference between `.` and `->`?

`.` is used with a structure variable, while `->` is used with a pointer to a structure.

### 06. Why do we use `&T` while calling `Read(&T)`?

`&T` passes the address of structure variable `T`.

### 07. What happens when seconds become 60?

Seconds become `0` and minutes are incremented by `1`.

### 08. What happens when hours become 24?

The time is reset to `00:00:00`.

### 09. What is normalization?

Converting the result into a valid time format where seconds and minutes are below 60 and hours are below 24.

### 10. Why is `%02d` used in `Display()`?

It displays each time component using at least two digits, such as `09:05:07`.
