#include <stdio.h>

#include <math.h>

int basamakSayisiHesapla(long long int n);
int basamakCheck(long long int n);
int basamakSayisiHesapla(long long int n);
int basamakToplami(int n);

int main(void) {

  long long int cardNumber;

  printf("Credit card number:");
  scanf("%lli", & cardNumber);

  int basamakSayisi = basamakSayisiHesapla(cardNumber);

  if (basamakCheck(cardNumber)) {
    if (basamakSayisi == 15 && ((cardNumber / (long long int) pow(10, 13) == 34) || (cardNumber / (long long int) pow(10, 13) == 37))) {
      printf("AMERICAN EXPRESS");
    } else if (basamakSayisi == 13 && (cardNumber / (long long int) pow(10, 12) == 4)) {
      printf("VISA");
    } else if (basamakSayisi == 16) {
      if (cardNumber / (long long int) pow(10, 14) == 51 || cardNumber / (long long int) pow(10, 14) == 52 || cardNumber / (long long int) pow(10, 14) == 53 || cardNumber / (long long int) pow(10, 14) == 54) {
        printf("MASTERCARD");
      } else if (cardNumber / (long long int) pow(10, 15) == 4) {
        printf("VISA");
      }
    } else {
      printf("INVALID");
    }
  } else {
    printf("INVALID");
  }

  return 0;
}

int basamakSayisiHesapla(long long int n) {
  int basamak = 0;

  while (n > 0) {
    basamak++;
    n /= 10;
  }
  return basamak;
}

int basamakCheck(long long int n) {
  int total = 0;

  int x = 1;

  while (n > 0) {
    if (x % 2 == 1) {
      total += n % 10;
    } else {
      total += basamakToplami(2 * (n % 10));
    }
    x++;
    n /= 10;
  }

  if (total % 10 == 0) {
    return 1;
  } else {
    return -1;
  }
}

int basamakToplami(int n) {
  int toplam = 0;

  while (n > 0) {
    toplam += (n % 10);
    n /= 10;
  }

  return toplam;
}
