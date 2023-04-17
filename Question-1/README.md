### Problem:
There is a queue where people get their tasks assigned called Task Queue. In this queue, the same person can be repeated multiple times. The queue has a current index value, essentially the index of the queue member who will get the next task. The member of the current index is called the Current Index Member. If a queue member becomes inactive, it is removed from the queue. As members are removed, the queue changes. You need to find the index of the Current Index Member in the newly changed queue.
## Example: 
## Task Queue: [A B C D E F A* B C D A B C A B A]
## Current Index: 7
## Current Index Member: 2nd A (marked as A*)
So in the above example, the task queue has A B C D E F members. The members are repeating themselves multiple times in the task queue.
The current index value is 7, which means the 2nd A in the queue is the Current Index Member (marked as A*).
In case when members A and D become inactive, they are removed from the task queue and
## the Task Queue becomes: 
[B C E F B C B C B]
Now if we compare the: 
## Old Queue		[A B C D E F A* B C D A B C A B A]
## New Queue		[A B C D E F A* B C D A B C A B A]

We need to find the new index of the Current Index Member in the New Queue. If the Current Index Member in the Old Queue has become inactive, find the index of the next available member to the Current Index Member.
In this case, the new array 
The Current Index Member (2nd A)  is now inactive in the new array.
The next available member to the Current Index Member is 2nd B, at index 5 of the new queue. 
	
	Given: Old Task Queue, Current Index of Old Task Queue, New Task Queue.
	To Find: Find the index of the Current Index Member in the New Task Queue.
