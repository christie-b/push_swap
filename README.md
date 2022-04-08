# push_swap

[![cboutier's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl1f9y1k8000609jsc4a29jay/project/2267599)](https://github.com/JaeSeoKim/badge42)

Validated on August 14th, 2021

115/100 with bonus (checker to check if the instructions entered are sorting the stack properly.

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.  

We have 2 stacks, named A and B.  
At the beginning:
• The stack A contains a random amount of negative and/or positive numbers, which cannot be duplicated.
• The stack B is empty.
• The goal is to sort in ascending order numbers into stack A. To do so, we only could use the
following operations:  

Operations |  | Description
----------- | -- | ------------
**sa** | Swap A | Swap the first 2 elements at the top of stack A. </br> Do nothing if there is only one or no elements.  
**sb** | Swap B | Swap the first 2 elements at the top of stack B. </br> Do nothing if there is only one or no elements.  
**ss** | Swap A and B | sa and sb at the same time.
**pa** | Push A | Take the first element at the top of B and put it at the top of A. </br> Do nothing if B is empty.  
**pb** | Push B | Take the first element at the top of A and put it at the top of B. </br> Do nothing if A is empty.
**ra** | Rotate A | Shift up all elements of stack A by 1. </br> The first element becomes the last one.
**rb** | Rotate B | Shift up all elements of stack B by 1. </br> The first element becomes the last one.
**rr** | Rotate A and B | ra and rb at the same time.
**rra** | Reverse Rotate A | Shift down all elements of stack A by 1. </br> The last element becomes the first one.
**rrb** | Reverse Rotate B | Shift down all elements of stack B by 1. </br> The last element becomes the first one.
**rrr** | Reverse Rotate A and B | rra and rrb at the same time.  

## SORTING ALGORITHMS USED
The different algorithms I implemented were tested on different stack sizes, and the most optimized one is then used.  
</br> Whatever the numbers entered, the list of numbers will be simplified.  
</br> Meaning a list of numbers containing `10, 43, 1, 87, 72` will be simplified to `2, 3, 1, 5, 4`.  
- For stacks between 20 and 321 numbers :  
    - Use of chunks of 15, for example, if I have a list of 100 numbers, I will have 5 chunks as followed:  
       - Chunk 1: 0 - 14,  
       - Chunk 2: 15 - 29,  
       - Chunk 3: 30 - 44,  
       - Chunk 4: 45 - 59,  
       - Chunk 5: 60 - 74,  
       - Chunk 6: 75 - 89,  
       - Chunk 7: 90 - 99.  
    - Scan Stack A from the top to check if a number from the Chunk 1 is in there, if yes, save that value
    - Scan Stack A from the bottom to check if a number from the Chunk 1 is in there, if yes, save that value  
    - Compare how many moves it would take to get the first and second value to the top.  
    - Move the number which requires the least amount of moves to the top of Stack A.  
    - Scan Stack B to push the number on top of A to the right spot on Stack B.
    - Repeat the steps until all the numbers of Chunk 1 are no longer in Stack A.  
    - Repeat the same steps for the other Chunks until Stack A is empty.  
    - Find the biggest number in Stack B, and move it to the top to push it to Stack A.
    - Repeat the previous step until Stack B is empty.  
    - All the numbers in Stack A should be sorted in ascending order.  
- For stacks bigger than 322 numbers :  
    - A `Radix` Algorithm was used.  

Example:

$>./push_swap 2 1 3 6 5 8  
sa  
pb  
pb  
pb  
sa  
pa  
pa  
pa  
$>./push_swap 0 one 2 3  
Error  
$>  

Checker example:  
$>./checker 3 2 1 0  
rra  
pb  
sa  
rra  
pa  
OK  
$>./checker 3 2 1 0  
sa  
rra  
pb  
KO  
