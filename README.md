# Sentence-Length-Histogram

Display how many sentences have x amount of words

## How it works
A txt file is read in character by character and will count how many sentences have n number of words
Then that data is outputted to the console in a histogram:  
0: *** 3  
1: ** 2  
...  
29 words: 0 sentences

## How to run it
To compile C code, make sure you have GCC on your machine, then run
```
~/user/destinationexample gcc filename.c && ./a.out < example.txt
```
to compile and execute the file with the example.txt being fed in
