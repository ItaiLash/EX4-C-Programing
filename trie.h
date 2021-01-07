#ifndef trie_h
#define trie_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LETTERS ((int)26)

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
    char letter;
    long unsigned int count;
    struct node* children[NUM_LETTERS];
} node;


int char_to_index(const char c);
node* buildNode(void);
void insert(node *root, const char *key);
void fixWord(char* word);
void printReverseLex(node* root, char* word, int index);
void printLex(node* root, char* word, int index);
void freeTrie(node* root);
boolean noKids(node* n);


#endif /* trie_h */
