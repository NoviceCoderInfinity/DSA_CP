# Daily LeetCode Challenge

The repo contains the description and link to solutions to LeetCode Daily Challenge.

## September 2024

| Number | Title                                                                                                     | Difficulty | Code                                                              | LC Website  | Video Solution |
| ------ | --------------------------------------------------------------------------------------------------------- | ---------- | ----------------------------------------------------------------- | ----------- | -------------- |
| 2022   | [Convert 1D Array Into 2D Array](#2022-convert-1d-array-into-2d-array)                                    | Easy       | [Solution](2022.Convert_1D_Array_Into_2D_Array.cpp)               | Coming Soon | Coming Soon    |
| 1894   | [Find the Student that Will Replace the Chalk](#1894-find-the-student-that-will-replace-the-chalk-solved) | Medium     | [Solution](1894.Find_the_Student_that_Will_Replace_the_Chalk.cpp) | Coming Soon | Coming Soon    |

---

## Problem Solutions

## Problem Solutions

### 2022. Convert 1D Array Into 2D Array

**Difficulty:** Easy  
**Topics:** Array, Matrix, Simulation  
**Companies:** Google, Amazon, Meta

### Problem Description

You are given a 0-indexed 1-dimensional (1D) integer array `original`, and two integers, `m` and `n`. You are tasked with creating a 2-dimensional (2D) array with `m` rows and `n` columns using all the elements from `original`.

The elements from indices `0` to `n - 1` (inclusive) of `original` should form the first row of the constructed 2D array, the elements from indices `n` to `2 * n - 1` (inclusive) should form the second row of the constructed 2D array, and so on.

Return an `m x n` 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

#### Examples

**Example 1:**

```text
Input: original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]
Explanation: The constructed 2D array should contain 2 rows and 2 columns.
The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.
```

**Example 2:**

```text
Input: original = [1,2,3], m = 1, n = 3
Output: [[1,2,3]]
Explanation: The constructed 2D array should contain 1 row and 3 columns.Put all three elements in original into the first row of the constructed 2D array.
```

**Example 3:**

```text
Input: original = [1,2], m = 1, n = 1
Output: []
Explanation: There are 2 elements in original.It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D array.
```

### Constraints

- `1 <= original.length <= 5 * 10^4`
- `1 <= original[i] <= 10^5`
- `1 <= m, n <= 4 * 10^4`

### 1894. Find the Student that Will Replace the Chalk Solved

**Difficulty:** Medium  
**Topics:**  
**Hint:**

### Problem Description

There are n students in a class numbered from 0 to n - 1. The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. After that, the teacher will restart the process, starting with the student number 0 again. You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk. Return the index of the student that will replace the chalk pieces.

#### Examples

**Example 1:**

```text
Input: chalk = [5,1,5], k = 22
Output: 0
Explanation:
    The students go in turns as follows:
        - Student number 0 uses 5 chalk, so k = 17.
        - Student number 1 uses 1 chalk, so k = 16.
        - Student number 2 uses 5 chalk, so k = 11.
        - Student number 0 uses 5 chalk, so k = 6.
        - Student number 1 uses 1 chalk, so k = 5.
        - Student number 2 uses 5 chalk, so k = 0.

        Student number 0 does not have enough chalk, so they will have to replace it.
```

**Example 2:**

```text
Input: chalk = [3,4,1,2], k = 25
Output: 1
Explanation:
    The students go in turns as follows:
        - Student number 0 uses 3 chalk so k = 22.
        - Student number 1 uses 4 chalk so k = 18.
        - Student number 2 uses 1 chalk so k = 17.
        - Student number 3 uses 2 chalk so k = 15.
        - Student number 0 uses 3 chalk so k = 12.
        - Student number 1 uses 4 chalk so k = 8.
        - Student number 2 uses 1 chalk so k = 7.
        - Student number 3 uses 2 chalk so k = 5.
        - Student number 0 uses 3 chalk so k = 2.

        Student number 1 does not have enough chalk, so they will have to replace it.
```

### Constraints

- `chalk.length == n`
- `1 <= n <= 105`
- `1 <= chalk[i] <= 105`
- `1 <= k <= 109`
