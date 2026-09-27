# Array Length

## Example 3.2

### Question

Let Age[5] be an array of integers such that:

Age[0] = 2, Age[1] = 5, Age[2] = 3, Age[3] = 1, Age[4] = 7

Show the memory representation of the array and calculate its length.

### Solution

The memory representation of the array Age[5] is:

+-------+-------+-------+-------+-------+
|   2   |   5   |   3   |   1   |   7   |
+-------+-------+-------+-------+-------+
 Age[0]  Age[1]  Age[2]  Age[3]  Age[4]

The formula to calculate the length of an array is:

Length = upper_bound - lower_bound + 1

Here,

lower_bound = 0
upper_bound = 4

Therefore,

Length = 4 - 0 + 1
       = 5

### Answer

The length of the array is **5**.