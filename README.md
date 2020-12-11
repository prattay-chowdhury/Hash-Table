# Hash-Table

What does the program do?
1. The program will insert 20 words (strings) into a hash table read from a txt file (table_inputs.txt). Maximum string length is 8 and minimum is 3. 
2. The hash table has a initial size of 31 (which is a prime number), and use  open addressing - quadratic to handle collision. 
3. The hash function is to add up ASCII values of all characters in the string, then mod 101.
4. After 15 insertation, the hash table size will become 67 (prime number next to double of 31) and old words are re-inserted.
5. The final hash table is printed with indices and keys.
5. The number of total collisions will be printed out at the end.
