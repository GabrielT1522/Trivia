This program implement a Trivia game similar to the popular game show, Jeopardy.
This game will have 2-4 participants. The order the participants will answer will
depend on an initial “dice roll” using a random number generator. The participants will
answer from the largest to the least dice value which will be determined using the bubble sort
and placed in a deque. When a participant has answered, they will be placed in the rear of the
deque to form a cycle until a winner has been determined. The display board will be implemented
using a map data structure. The key will be a two-character string where the first character is
the category (column) and the second is the question number (row). The value associated with the
key will be a string that holds the question to be answered. The map initialization will be
determined on runtime by reading from a file. With each correct answer, the plate will collect
money. The first player to earn $1000 will win and will be determined with a priority queue.

File Contents Organization:
Key
Value
Answer 1
Answer 2
Answer 3
Answer 4
Correct Answer Index
Points Worth

