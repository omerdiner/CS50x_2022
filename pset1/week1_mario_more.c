#include <stdio.h>

int main(void) {

  int n, i, j, spaces;

  do {
    printf("Height?:\n");
    scanf("%d", & n);
  } while (n < 1 || n > 8);

  spaces = n - 1;

  for (i = 0; i < n; i++) {
    for (j = 0; j < spaces; j++) {
      printf(" ");
    }
    for (j = 0; j < n - spaces; j++) {
      printf("#");
    }
    printf("  ");

    for (j = 0; j < n - spaces; j++) {
      printf("#");
    }

    spaces--;

    printf("\n");
  }

  return 0;
}
