# Array Address Calculation – Example 3.1

## Question

Given an array:

`int marks[] = {99, 67, 78, 56, 88, 90, 34, 85}`

Calculate the address of `marks[4]` if the base address is `1000`.

## Solution

The formula to calculate the address of an array element is:

**Address of A[k] = BA(A) + w × (k − lower_bound)**

Where:

- **BA(A)** = Base address of the array
- **k** = Index of the required element
- **w** = Size of one element in memory
- **lower_bound** = Index of the first element

Here:

- Base address = `1000`
- Required index = `4`
- Lower bound = `0`
- Size of `int` = `2 bytes` (as assumed in this textbook)

Therefore,

```text
Address of marks[4]
= 1000 + 2 × (4 − 0)
= 1000 + 2 × 4
= 1000 + 8
= 1008