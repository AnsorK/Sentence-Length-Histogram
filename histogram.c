/*
 * This program works for any text file
 * Spelling and capitalization isn't accounted for
 * Words can be of any length
 * Max sentence length that can be accounted for is 29
 * Acceptible characters are letters, numbers, -, ', and "
 * Any character sequence that starts with a letter or a number
 * and contains the allowed characters thereafter will count as a word
 * Sentences with only a ., ?, or ! count as empty sentences
 *
 * Author: Ansor Kasimov
 * Created: April 01 2022
 * Copyright (c) 2022 Ansor Kasimov
 */

#include <stdio.h>

void data();
int count();
void graph(int[]);

int main()
{
    data();
    return 0;
}

// Put data in an array
void data()
{
    int data[30];     // Max number of words that can be in a sentence is 29
    int i = 0;
    for (i = 0; i < 30; ++i)     // Initialize all data entries as 0
        data[i] = 0;
    int length = count();
    while (length != -1) {     // Increment the lengths of corresponding indices while the EOF isn't reached
        ++data[length];
        length = count();
    }
    graph(data);
}

// Count the number of words in a sentence
int count()
{
    int count = 0;
    char c = getchar();
    if (c == '.' || c == '?' || c == '!')     // A sentence with no words is empty
        return 0;
    while (c != '.' && c != '?' && c != '!') {     // Traverse characters before ., ?, !
        if (c == EOF)     // Break out of loop in data() if EOF has been reached
            return -1;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))     // Check if a sequence of characters starts with a letter or a number
            while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '-') || (c == '\'') || (c == '\"')) {     // Keep traversing the word if it contains the appropriate characters
                c = getchar();
                if (c == ' ' || c == ',' || c == ':' || c == ';' || c == '.' || c == '?' || c == '!')     // A word followed by ., ?, or ! is finished
                    ++count;
            }
        else
            c = getchar();
    }
    return count;
}

// Output the histogram
void graph(int arr[])
{
    printf("Number of sentences with 0-29 words in them\n\n");
    int i, j;
    for (i = 0; i < 30; ++i) {
        printf("%2d: ", i);
        for (j = 0; j < arr[i]; ++j)     // Print number of * corresponding with the number of sentences for that word count
            printf("*");
        if (arr[i] > 3)
            printf("\t\t");
        else
            printf("\t\t\t");
        printf("%d\n", arr[i]);     // Show sentence count for each word count
    }
}