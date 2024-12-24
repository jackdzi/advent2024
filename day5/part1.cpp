#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using std::stringstream;

using namespace std;

int main(void) {
  ifstream file("data.txt");
  string line;
  unordered_map<int, set<int>> order;
  while (getline(file, line)) {
    if (line.empty())
      break;
    stringstream lines(line);
    int num1, num2;
    string temp;
    getline(lines, temp, '|');
    num1 = stoi(temp);
    getline(lines, temp);
    num2 = stoi(temp);
    order[num1].insert(num2);
  }
  int sum = 0;
  bool valid;
  while (getline(file, line)) {
    stringstream lines(line);
    string temp;
    set<int> seen;
    vector<int> numbers;
    valid = true;
    numbers = {};
    while (getline(lines, temp, ',')) {
      int num = stoi(temp);
      numbers.push_back(num);
      for (auto &val : seen) {
        if (order[num].find(val) != order[num].end()) {
          valid = false;
          break;
        }
      }
      seen.insert(num);
    }
    if (valid) {
      sum += numbers[(numbers.size() - 1) / 2];
    }
  }
  cout << sum;
}
