#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9
#define N 200
// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct {
    char name[N];
    int votes;
    int eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count = 0;
int candidate_count = 0;

// Function prototypes
int vote(int voter, int rank, char * name);
void tabulate(void);
int print_winner(void);
int find_min(void);
int is_tie(int min);
void eliminate(int min);

int main() {
    int i = 0, j = 0, tmp = 0;
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
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates

    if (candidate_count > MAX_CANDIDATES) {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    i = 0;
    char tempName[N];
    while (candidatesInput[j] != '\0') {
        if (candidatesInput[j] == ' ') {
            strncpy(candidates[i].name, tempName, tmp);
            candidates[i].votes = 0;
            candidates[i].eliminated = -1; // -1 mean false
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
    candidates[i].eliminated = -1;

 

    printf("Number of voters: ");
    scanf("%d", & voter_count);

    if (voter_count > MAX_VOTERS) {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (i = 0; i < voter_count; i++) {

        // Query for each rank
        for (j = 0; j < candidate_count; j++) {
            char name[N];
            printf("Rank %i: ", j + 1);
            scanf("%s", & name);

            // Record vote, unless it's invalid
            if (vote(i, j, name) == -1) {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (1) {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        int won = print_winner();
        if (won == 1) {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        int tie = is_tie(min);

        // If tie, everyone wins
        if (tie == 1) {
            for (i = 0; i < candidate_count; i++) {
                if (candidates[i].eliminated == -1) {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (i = 0; i < candidate_count; i++) {
            candidates[i].votes = 0;
        }
    }

    return 0;
}

// Record preference if vote is valid
int vote(int voter, int rank, char * name) {
    int i;
    for (i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            preferences[voter][rank] = i;
            return 1;
        }
    }

    // TODO
    return -1;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void) {
    int i, j;
    for (i = 0; i < voter_count; i++) {
        for (j = 0; j < candidate_count; j++) {
            if (candidates[preferences[i][j]].eliminated == -1) {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
   
}

// Print the winner of the election, if there is one
int print_winner(void) {
    int total_votes = 0;
    int i;

    for (i = 0; i < voter_count; i++) {
        total_votes += candidates[i].votes;
    }

    for (i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > total_votes / 2 && candidates[i].eliminated == -1) {
            printf("%s\n", candidates[i].name);
            return 1;
        }
    }
    return -1;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void) {
    int min = INT_MAX;
    int i;
    for (i = 0; i < candidate_count; i++) {
        if (candidates[i].eliminated == -1 && candidates[i].votes < min) {
            min = candidates[i].votes;

        }
    }
    // TODO
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
int is_tie(int min) {
    // TODO
    int i;
    for (i = 0; i < candidate_count; i++) {
        if (candidates[i].eliminated == -1 && candidates[i].votes != min) {
            return -1;
        }
    }
    return 1;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min) {
    int i;
    for (i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == min && candidates[i].eliminated == -1) {
            candidates[i].eliminated = 1;
        }
    }

}
