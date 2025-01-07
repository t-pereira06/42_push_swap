# push_swap

This project challenges you to sort data on a stack using a limited set of instructions while minimizing the number of actions.
To succeed, you will need to understand and manipulate various algorithms and choose the most efficient solution for optimized data sorting.

---

## Table of Contents
- [How to Compile and Execute](#how-to-compile-and-execute)
- [Rules and Instructions](#rules-and-instructions)
- [Evaluation Criteria](#evaluation-criteria)
- [Examples](#examples)
- [Grade](#grade)

---

## How to Compile and Execute

### Compilation
To compile the project, simply run:
```bash
make
```

### Execution
After compiling, you can execute the program by providing a sequence of numbers to sort:
```bash
./push_swap <number1> <number2> ...
```

Example:
```bash
$ ./push_swap 3 2 1 4 5
pb
pb
pa
sa
rra
rra
pa
ra
ra
ra
```

### Counting Moves
If you want to see how many moves the program uses to sort the numbers, pipe the output into `wc -l`:
```bash
$ ./push_swap 3 2 1 4 5 | wc -l
10
```

### Cleaning Up
To clean up the object files after execution, run:
```bash
make fclean
```

---

## Rules and Instructions

The program operates on two stacks: **Stack A** and **Stack B**. Initially, all numbers are loaded into Stack A, while Stack B starts empty. The goal is to sort the numbers in Stack A.

### Moves
Here are the allowed moves:

- **`pa` (push A):** Move the top element of Stack B to the top of Stack A. Does nothing if Stack B is empty.
- **`pb` (push B):** Move the top element of Stack A to the top of Stack B. Does nothing if Stack A is empty.
- **`sa` (swap A):** Swap the first two elements of Stack A. Does nothing if there are fewer than two elements.
- **`sb` (swap B):** Swap the first two elements of Stack B. Does nothing if there are fewer than two elements.
- **`ss`:** Perform `sa` and `sb` simultaneously.
- **`ra` (rotate A):** Shift all elements of Stack A up by one. The first element becomes the last.
- **`rb` (rotate B):** Shift all elements of Stack B up by one. The first element becomes the last.
- **`rr`:** Perform `ra` and `rb` simultaneously.
- **`rra` (reverse rotate A):** Shift all elements of Stack A down by one. The last element becomes the first.
- **`rrb` (reverse rotate B):** Shift all elements of Stack B down by one. The last element becomes the first.
- **`rrr`:** Perform `rra` and `rrb` simultaneously.

---

## Evaluation Criteria

### Sorting 3 Values
- Maximum allowed moves: **3**

### Sorting 5 Values
- Maximum allowed moves: **12**

### Sorting 100 Values
Points are awarded based on the number of moves:
- **5 points:** Less than 700 moves
- **4 points:** Less than 900 moves
- **3 points:** Less than 1100 moves
- **2 points:** Less than 1300 moves
- **1 point:** Less than 1500 moves

### Sorting 500 Values
Points are awarded based on the number of moves:
- **5 points:** Less than 5500 moves
- **4 points:** Less than 7000 moves
- **3 points:** Less than 8500 moves
- **2 points:** Less than 10000 moves
- **1 point:** Less than 11500 moves

---

## Examples

### Demonstration
Here is an example of the program running:

[![Demo Video](https://user-images.githubusercontent.com/118270669/232516593-dee1d478-a425-4c28-bb57-00a83eafe9ec.webm)](https://user-images.githubusercontent.com/118270669/232516593-dee1d478-a425-4c28-bb57-00a83eafe9ec.webm)

---

## Grade

![Grading Screenshot](https://github.com/t-pereira06/42_push_swap/assets/118270669/c0f02287-6cad-4c10-8e35-0b77762779d4)
