#include <stdio.h>

int fizz(int n) {
    return ((n + 4) % 43) == 0;
}

int buzz(int n) {
    return ((n + 6) % 52) == 0;
}

int count_numbers_between_fizz_and_fizzbuzz(int from, int to) {
    int count = 0;
    int fizz_encountered = 0;
    
    for (int i = from; i < to; ++i) {
        if (fizz(i)) {
            fizz_encountered = 1;
        }
        else if (fizz_encountered && buzz(i)) {
            return count;
        }
        else if (fizz_encountered) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int from = 587;
    int to = 5587;
    
    int numbers_between = count_numbers_between_fizz_and_fizzbuzz(from, to);
    
    printf("Quantos números são impressos entre a primeira linha do tipo Fizz e a linha do tipo FizzBuzz que se lhe segue? %d\n", numbers_between);
    
    return 0;
}