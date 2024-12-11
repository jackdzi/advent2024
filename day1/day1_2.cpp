#include <cstdio>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>

int main(void) {
  std::ifstream file;
  file.open("data.txt");
  if (!file.is_open()) {
    return 1;
  }
  std::unordered_map<int, int> map1;
  std::unordered_map<int, int> map2;
  while (file) {
    std::string buffer;
    if (!(file >> buffer))
      break;
    if (map1.find(stoi(buffer)) == map1.end())
      map1.insert(std::make_pair(stoi(buffer), 1));
    else
      map1[stoi(buffer)]++;
    file >> buffer;
    if (map2.find(stoi(buffer)) == map2.end())
      map2.insert(std::make_pair(stoi(buffer), 1));
    else
      map2[stoi(buffer)]++;
  }
  int sum = 0;
  for (auto& val: map1) {
    if (map2.find(val.first) != map2.end()) {
      sum += val.first * val.second * map2[val.first];
    }
  }
  std::cout << sum;
  return 0;
}
