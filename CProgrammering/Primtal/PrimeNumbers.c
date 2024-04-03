#include <stdio.h>
#include <time.h>
//Lav et program som kan skrive de første 10.000 primtal


int isPrimeNumber(int num) { //"return 0" betyder at det ikke er prime, "return 1" betyder det er prime
    for (int i = 2; i*i <= num; i++) { //Stopper inden num
        if (num % i == 0)
            return 0;
    }
    // Hvis vi ikke har fanget det endnu, er det et primtal
    return 1;
}

int main() {
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  int num = 2;
  int counter = 1;
  while (counter <= 10000) {
        if (isPrimeNumber(num)) {
            printf("Primtal Nummer ");
            printf("%d; ", counter);
            printf("%d \n", num); 
            counter++;
        }
        num++;
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Det tog ");
  printf("%.30f", cpu_time_used);
  printf(", sekunder at regne de første 10.000 primtal ud! \n");
  return 0;
}

