#include <stdio.h>
#include "trie.h"
#define SIZE 10
#define INDEX 0


int main(int argc, const char * argv[]) {
    
    node* root = buildNode();
    boolean r = FALSE;
    if(argc == 2 && strcmp(argv[1],"r") == 0){
        r = TRUE;
    }
    int size = SIZE;
    char current;
    char* word = (char*)malloc(SIZE*sizeof(char));
    char* re_word = NULL;
    if(word == NULL){
        freeTrie(root);
        printf("ERR: allocate does not succed");
        return -1;
    }
    int index = 0;
    while((current = getc(stdin)) != EOF){
        if(current != ' ' && current != '\t' && current != '\n' && current != '\r'){
            if(index == size-1){
                re_word = (char*)realloc(word,size*2);
                size*=2;
                if(re_word == NULL){
                    freeTrie(root);
                    free(word);
                    printf("ERR: REallocate does not succed");
                    return -1;
                }
                word = (char*)malloc(size*sizeof(char));
                strcpy(word,re_word);
                free(re_word);
            }
            word[index++] = current;
        }
        else if(index!=0){
            word[index] = '\0';
            index=0;
            fixWord(word);
            insert(root, word);
        }
    }
    if(r){
        printReverseLex(root, word, INDEX);
    }
    else{
        printLex(root, word, INDEX);
    }
    free(word);
    freeTrie(root);
    return 0;
}
