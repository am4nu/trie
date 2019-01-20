// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 27

#define hash(c) (tolower(c) - (int)'a')
// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
typedef struct trie{
    bool isEndOfWord;
    struct trie* children[SIZE];
}trie;
// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
trie* newNode();
void insert(const char* str);
trie* getroot();

#endif // DICTIONARY_H
