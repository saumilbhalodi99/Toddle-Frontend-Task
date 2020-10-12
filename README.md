# Toddle-Frontend-Task

Date: 12/10/2020
Name: Saumil Bhalodi
Student ID: 201701051
College: DA-IICT
Programming Language used: C++ (For Code) & HTML, CSS and JavaScript (For developement)
*********************************************************************************************************
 



After seeing the design requirement, I had initially thought of using tree data structure for implementing given design. I completely built up the logic on how my tree structure would work with all given functionalities of adding, indenting, outdenting, deleting and moving. I spent more than one and half days thinking on how I can implement such structure in Javascript. Unfortunately, I couldn’t figure out any. So, on the last day, I came up with another logic and was successful in achieving many functionalities. I have attached a cpp code which describes more of the logic I used for creating the project. Please go through that code also. 

The main idea I used was to make an array of Entries, each entry would have its corresponding text and level. By level, I mean the amount of padding/space before the text which shows parent child relation. For example, assume following array (I have added text and its corresponding level) :

Eg:

Arr[0]: Chapter A, 0
Arr[1]: Chapter B, 0
Arr[2]: 		Chapter C, 1
Arr[3]: 			Chapter D, 2
Arr[4]: 				Chapter E, 3
Arr[5]: 			Chapter F, 2
Arr[6]: Chapter G, 0
Arr[7]: 		Chapter H, 1


This way, I store every new element in the array. For every functionality, I have some constraints added which checks the corner cases. Here is list of few things to be taken care of while

1)Adding new element:
New entry is always appended last in the array.
A new entry must be added with the same paging/space as the last element in the list has.

2)Indent element:
Indent is not possible for the first element in the list.
Indent is possible only if the element above it has a level greater than or equal to current element.
While indenting a particular element, we must also indent its children. Now all elements, below current element to move, till element with level number less than or equal to level number of current element are its children and all of them will move along with it. For example, in above given array, if we want to indent Chapter B, than all elements till Chapter G will move along with it. 

3)Outdent element:
Outdent is possible only if level is greater than zero. 
Every child will also move along with current Element.

4)Delete element:
Any element can be deleted
While deleting element, we must also delete its children.  
		
