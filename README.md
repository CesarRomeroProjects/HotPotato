# Project 4: Hot Potato

# Overview
This project involves building a queue data structure and implementing a game of Hot Potato using the queue. In the first part, you will implement a queue as a linked list to store std::string objects. In the second part, you will simulate rounds of the Hot Potato game using the implemented queue.

# Part One: Building a Queue
Implement a queue data structure using a linked list to store std::string objects. The queue must follow specific rules and functions, including a default constructor, destructor, copy constructor, assignment operator, enqueue, front, and dequeue. Make sure to manage memory properly.

# QueueOfStrings Functions to Implement
1. Default constructor: Create an empty queue.
2. Destructor: Properly free memory.
3. Copy constructor and assignment operator: Implement deep copies.
4. enqueue(const std::string &item): Add the given std::string to the end of the queue.
5. front(): Two versions, depending on whether the queue can be modified or not. If the queue is empty, throw a QueueEmptyException.
6. dequeue(): Remove the front element from the queue. If the queue is empty, throw a QueueEmptyException.

# Restrictions on QueueOfStrings
- The queue must be implemented as a linked list.
- Do not use standard library container classes, including std::queue. Any attempt to use them will be treated as academic dishonesty.

# Part Two: Playing Hot Potato
Implement the playHotPotato function in HotPotato.cpp. This function simulates the game of Hot Potato with given participants and the order in which they are lined up. Participants pass the "potato" based on the specified number of passes in each round.

# Restrictions
- Use only your QueueOfStrings for solving this problem.
- Do not use any standard library container classes, except for QueueOfStrings.
- You may use std::vector only for the purpose of the second parameter.