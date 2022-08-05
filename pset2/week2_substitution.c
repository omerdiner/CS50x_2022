#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 100

char encrypt(char c, char k);
int checkKey(char * str);

int main(void) {

  char key[26];
  char ciphertext[N];
  char plaintext[N];
  int i, index, length;

  printf("key:");
  gets(key);

  if (checkKey(key) == -1) {
    return 1;
  }

  printf("plaintext: ");
  gets(plaintext);

  length = strlen(plaintext);

  for (i = 0; i < length; i++) {
    index = tolower(plaintext[i]) - 'a';
    ciphertext[i] = encrypt(plaintext[i], key[index]);
  }
  printf("ciphertext: %s\n", ciphertext);

  return 0;
}

int checkKey(char * str) {
  int i;

  for (i = 0; i < 26; i++) {
    if (!isalpha(str[i])) {
      printf("Key must contain 26 characters.");
      return -1;
    }
  }
  return 1;
}

char encrypt(char c, char k) {

  if (islower(c)) {
    return tolower(k);
  } else if (isupper(c)) {
    return toupper(k);
  }
  return c;
}


