#include <cstdio>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>

int main() {
  std::ifstream file;
  file.open("data.txt");
  if (!file.is_open()){
    return 1;
  }
  std::vector<int> vec1;
  std::vector<int> vec2;
  while (file) {
    std::string buffer;
    if (!(file >> buffer))
      break;
    vec1.push_back(stoi(buffer));
    file >> buffer;
    vec2.push_back(stoi(buffer));
  }
  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());
  int sum = 0;
  for (int i = 0; i < vec1.size(); i++) {
    sum += std::abs(vec1[i]-vec2[i]);
  }
  std::cout << "Answer: " << sum;
  return 0;
}
