#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

int main(void) {
  std::ifstream file;
  file.open("data.txt");
  if (!file.is_open()) {
    return 1;
  }
  std::string line;
  int safe_sum = 0;
  int counter = 1;
  while (std::getline(file, line)) {
    std::stringstream sline(line);
    std::string word;
    sline >> word;
    int previous = stoi(word);
    int increasing = 0;
    int safe = 0;
    while (sline >> word) {
      int diff = previous - stoi(word);
      if (increasing == 0)
        increasing = diff < 0 ? 1 : -1;
      if ((increasing == 1 && diff > 0) || (increasing == -1 && diff < 0))
        safe++;
      else if (abs(diff) > 3 || diff == 0)
        safe++;
      if (safe == 2)
        break;
      previous = stoi(word);
    }
    if (safe < 2)
      safe_sum++;
  }
  std::cout << safe_sum;
  return 0;
}
