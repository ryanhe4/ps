//
// Created by heechan on 2022/02/20.
//

#include <iostream>
#include <vector>
#include <numeric>

int main() {
  std::vector<int> v;

  for (int i = 0; i < 9; i++) {
    int temp;
    std::cin >> temp;
    v.push_back(temp);
  }

  std::sort(v.begin(), v.end());
  int first, second = 0;
  bool find_pair = false;
  const int sum = std::accumulate(v.begin(), v.end(), 0);
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (sum - v[i] - v[j]==100) {
        first = v[i];
        second = v[j];
        find_pair = true;
        break;
      }
    }
    if (find_pair) {
      break;
    }
  }

  for(int el: v) {
    if(el == first || el == second) {
      continue;
    }
    std::cout << el << std::endl;
  }

  return 0;
}
