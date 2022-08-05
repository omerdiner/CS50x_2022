#include <stdio.h>
#include <string.h>

#define N 100

int checkKey(char * str);
char rotate(char c, int k);

int main(void) {
  int key;
  char keyString[N];
  char plain_text[N];
  char cipher_text[N];
  int i;

  printf("text:");
  gets(plain_text);

  int length = strlen(plain_text);

  printf("Key:");
  scanf("%s", & keyString);

  if (checkKey(keyString) == -1) {
    printf("Error!");
    return 1;
  } else {
    key = atoi(keyString);
  }

  key = key % 26;

  for (i = 0; i < length; i++) {
    cipher_text[i] = rotate(plain_text[i], key);
  }

  printf("plaintext: %s\n", plain_text);
  printf("ciphertext: %s\n", cipher_text);

  return 0;
}

char rotate(char c, int k) {

  if (isupper(c)) {
    int i = (c + k - 65) % 26 + 65;
    c = toupper((char) i);
  } else if (islower(c)) {
    int i = (c + k - 97) % 26 + 97;
    c = tolower((char) i);
  }

  return c;
}

int checkKey(char * str) {

  int length = strlen(str);
  int i;

  if (!(str[0] >= '1' && str[0] <= '9')) {
    return -1;
  }

  for (i = 0; i < length; i++) {
    if (!(str[i] >= '0' && str[i] <= '9')) {
      return -1;
    }
  }

  return 1;
}
