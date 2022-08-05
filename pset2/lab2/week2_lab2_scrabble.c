#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define N 100
// Points assigned to each letter of the alphabet
int POINTS[] = {
  1,
  3,
  3,
  2,
  1,
  4,
  2,
  4,
  1,
  8,
  5,
  1,
  3,
  1,
  1,
  3,
  10,
  1,
  1,
  1,
  1,
  4,
  4,
  8,
  4,
  10
};

int compute_score(char * word);

int main(void) {
  // Get input words from both players
  char word1[N];
  char word2[N];
  printf("Player 1:");
  gets(word1);
  printf("Player 2:");
  gets(word2);

  // Score both words
  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  // TODO: Print the winner

  if (score1 > score2) {
    printf("Player 1 wins!");
  } else if (score2 > score1) {
    printf("Player 2 wins!");
  } else {
    printf("Tie!");
  }

  return 0;
}

int compute_score(char * word) {
  // TODO: Compute and return score for string
  int length = strlen(word);
  int totalScore = 0;
  int i;

  for (i = 0; i < length; i++) {
    if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
      totalScore += POINTS[tolower(word[i]) - 'a'];
    }

  }

  return totalScore;
}
