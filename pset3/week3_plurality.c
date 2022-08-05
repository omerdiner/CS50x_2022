#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Max number of candidates
#define MAX 9
#define N 100

// Candidates have name and vote count
typedef struct {
    char name[100];
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
int vote(char * name);
void print_winner(void);

int main() {
    int i = 0, j = 0;
    int voter_count, tmp=0;
    char candidatesInput[N];
    printf("Candidates: ");
    scanf("%99[^\n]", candidatesInput);

    while (candidatesInput[i] != '\n') {
        if (candidatesInput[i] == ' ') {
            candidate_count++;
        }
        i++;
    }
    candidate_count++;

    // Check for invalid usage
    if (candidate_count < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates

    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    
    i = 0;
    char tempName[N];
    while (candidatesInput[j] != '\0') {
        if (candidatesInput[j] == ' ') {
            strncpy(candidates[i].name, tempName, tmp);
            candidates[i].votes = 0;
            i++;
            j++;
            tmp = 0;

        } else {
            tempName[tmp] = candidatesInput[j];
            j++;
            tmp++;
        }

    }
    strncpy(candidates[i].name, tempName, tmp);
    candidates[i].votes = 0;

    printf("Number of voters: ");
    scanf("%d", & voter_count);

    // Loop over all voters
    for (i = 0; i < voter_count; i++) {
        char name[N];
        printf("Vote: ");
        scanf("%s", & name);

        // Check for invalid vote
        if (vote(name) == -1) {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();

    return 0;
}

// Update vote totals given a new vote
int vote(char * name) {
    int i = 0;
    for (i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return 1;
        }
    }
    return -1;
}

// Print the winner (or winners) of the election
void print_winner(void) {
    int max = INT_MIN;

    int i;

    for (i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > max) {
            max = candidates[i].votes;
        }
    }

    for (i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == max) {
            printf("%s\n", candidates[i].name);
        }
    }

}
