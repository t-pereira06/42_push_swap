# push_swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## How To Compile and Execute:
To compile the project:
```bash
$ make
```
After compiling, execute the program, followed by numbers to order:
```bash
$ ./push_swap <number1> <number2> ...
```
After executing the program, the movements made by the program will appear in the terminal:
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
If you want to check how many moves the program did to organize the numbers, execute:
```bash
$ ./push_swap 3 2 1 4 5 | wc -l
10
```
After executing the program, if you want to clean the object files, execute:
```bash
$ make fclean
```

## push_swap rules:
The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

Moves:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

Evaluation:

* Sorting 3 values: no more than 3 moves.
* Sorting 5 values: no more than 12 moves.
* Sorting 100 values: rating from 1 to 5 points depending on the number of moves:

  * 5 points for less than 700
  * 4 points for less than 900
  * 3 points for less than 1100
  * 2 points for less than 1300
  * 1 point for less than 1500

* Sorting 500 values: rating from 1 to 5 points depending on the number of moves:

  * 5 points for less than 5500
  * 4 points for less than 7000
  * 3 points for less than 8500
  * 2 points for less than 10000
  * 1 point for less than 11500

# Example of the program running:
![simplescreenrecorder-2023-04-17_15 22 57](https://user-images.githubusercontent.com/118270669/232516232-9a0f1bf9-aa0d-4760-8414-104d42bc6a2e.gif)

# Grade:
![Screenshot from 2023-03-02 17-55-44](https://user-images.githubusercontent.com/118270669/222511939-fc694fa7-f182-4641-8bbe-e8aabab90526.png)
