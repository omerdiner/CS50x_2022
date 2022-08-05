#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 1000

int count_sentences(char * str);
int count_words(char * str);
int count_letters(char * str);

int main(void) {

  char paragraph[N];
  printf("Text:");
  gets(paragraph);

  int sentences = count_sentences(paragraph);
  int words = count_words(paragraph);
  int letters = count_letters(paragraph);

  double L = (double) letters / (double) words * 100.0;
  double S = (double) sentences / (double) words * 100.0;

  int cl_index = round(0.0588 * L - 0.296 * S - 15.8);

  if (cl_index < 1) {
    printf("Before Grade 1");
  } else if (cl_index >= 16) {
    printf("Grade 16+");
  } else {
    printf("Grade %d", cl_index);
  }

  return 0;
}

int count_letters(char * str) {
  int length = strlen(str);

  int total = 0;
  int i;

  for (i = 0; i < length; i++) {
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
      total++;
    }
  }

  return total;
}
int count_words(char * str) {
  int length = strlen(str);

  int total = 0;
  int i;

  for (i = 0; i < length; i++) {
    if (str[i] == ' ') {
      total++;
    }
  }

  return total + 1;
}
int count_sentences(char * str) {
  int length = strlen(str);

  int total = 0;
  int i;

  for (i = 0; i < length; i++) {
    if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
      total++;
    }
  }

  return total;
}
