// Implements a dictionary's functionality
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"
// TODO: Choose number of buckets in hash table
#define N 26
// Represents a node in a hash table
typedef struct node {
    char word[LENGTH + 1];
    struct node * next;
}
node;


// Hash table
node * table[N];

unsigned int word_count = 0;
unsigned int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char * word) {
    // TODO
    hash_value = hash(word);
    node * trav = table[hash_value];

    while (trav != NULL) {
        if (strcasecmp(word, trav -> word) == 0) {
            return true;
        }
        trav = trav -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char * word) {
    // TODO: Improve this hash function
    long sum = 0;
    int i;
    int length = strlen(word);
    for (i = 0; i < length; i++) {
        sum += tolower(word[i]);
    }

    return (unsigned int)sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char * dictionary) {
    // TODO
    FILE * file = fopen(dictionary, "r");
    if (file == NULL) {
        printf("Couldn't open the dictionary.");
        return false;
    }
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF) {
        node * tmp = malloc(sizeof(node));
        if (tmp == NULL) {
            return false;
        }
        strcpy(tmp->word, word);
        hash_value = hash(word);
        tmp->next = table[hash_value];
        table[hash_value] = tmp;
        word_count++;
    }
    
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void) {
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
    // TODO
    int i;
    for (i = 0; i < N; i++) {
        node * trav = table[i];

        while (trav != NULL) {
            node * tmp = trav;

            trav = trav -> next;

            free(tmp);
        }
        if (trav == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
