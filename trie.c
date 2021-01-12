#include "trie.h"

int char_to_index(const char c){
    return (c - 'a');
}

node* buildNode(){
    node* n = NULL;
    n = (node*)malloc(sizeof(node));
    if(n){
        n->count = 0;
        for(int i=0 ; i<NUM_LETTERS ; i++){
            n->children[i] = NULL;
        }
    }
    else{
        printf("ERR");
    }
    return n;
}

void insert(node *root, const char *key)
{
    int i;
    node *temp = root;
    for (int level = 0; level < strlen(key); level++)
    {
        i = char_to_index(key[level]);
        if (!temp->children[i]){
            temp->children[i] = buildNode();
        }
        temp = temp->children[i];
        temp->letter = key[level];

    }
    temp->count++;
}

void fixWord(char* word){
    int length = strlen(word);
    char c;
    int index = 0;
    for(int i=0 ; i<length ; i++){
        c = word[i];
        if(c>='A' && c<='Z'){
            word[index++] = (char)(c-'A'+'a');
        }
        else if(c>='a' && c<='z'){
            word[index++] = c;
        }
    }
    word[index] = '\0';
}

void printLex(node* root, char* word, int index){
    if(noKids(root)){
        word[index] = '\0';
        printf("%s %ld\n",word,root->count);
        return;
    }
    if(root->count>0){
        word[index] = '\0';
        printf("%s %ld\n",word,root->count);
    }
    for(int i=0 ; i<NUM_LETTERS ; i++){
        if(root->children[i]){
            word[index] = root->children[i]->letter;
            printLex(root->children[i], word, index+1);
        }
    }
}

void printReverseLex(node* root, char* word, int index){
    if(noKids(root)){
        word[index] = '\0';
        printf("%s %ld\n",word,root->count);
        return;
    }
    if(root->count>0){
        word[index] = '\0';
        printf("%s %ld\n",word,root->count);
    }
        for(int i=NUM_LETTERS-1 ; i>=0 ; i--){
        if(root->children[i]){
            word[index] = root->children[i]->letter;
            printReverseLex(root->children[i], word, index+1);
        }
    }
}

boolean noKids(node* n){
    boolean flag = TRUE;
    for(int i=0 ; i<NUM_LETTERS ; i++){
        if(n->children[i]){
            flag = FALSE;
            break;
        }
    }
    return flag;
}

void freeTrie(node* root){
    if(!root){
        return;
    }
    for(int i=0 ; i<NUM_LETTERS ; i++){
        freeTrie(root->children[i]);
    }
    free(root);
}
