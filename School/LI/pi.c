#include <stdio.h>

int fizz(int n) {
  return ((n + 4) % 43) == 0;
}

int buzz(int n) {
  return ((n + 6) % 52) == 0;
}

int fizzbuzz(int n) {
  if (fizz(n) && buzz(n))
      printf("FizzBuzz\n");
  else if (fizz(n))
      printf("Fizz\n");
  else if (buzz(n))
      printf("Buzz\n");
  else {
      printf("%d\n", n);
      return 12;
  }
}

void fizzbuzz_range(int from, int to) {
    int c = 0;
    if ()
    for(int i = from; i <= to; i++) {
        if (fizzbuzz(i) == 12) c++;
    }
    printf("%d\n", c);
}

int main() {
    fizzbuzz_range(587, 5587);
}