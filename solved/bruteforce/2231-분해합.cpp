//
// Created by heechan on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <numeric>

int sum_digit(int);

int main() {
  long long n;
  std::cin >> n;

  for (int i = 1; i <= 1000000; i++) {
    if (sum_digit(i)==n) {
      std::cout << i;
      return 0;
    }
  }

  std::cout << 0;

  return 0;
}

// 자리수를 모두 더하는 함수
int sum_digit(int n) {
  int sum = n;
  while (n > 0) {
    sum += n%10;
    n /= 10;
  }
  return sum;
}
