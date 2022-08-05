#include <stdio.h>

int main(void) {
  int n;
  int i, j;

  do {
    printf("Height: ");
    scanf("%d", & n);
  } while (n < 1 || n > 8);

  int spaces = n - 1;

  for (i = 0; i < n; i++) {
    for (j = 0; j < spaces; j++) {
      printf(" ");
    }
    for (j = 0; j < n - spaces; j++) {
      printf("#");
    }

    spaces--;
    printf("\n");
  }

  return 0;

}
