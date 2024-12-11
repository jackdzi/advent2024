#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int main(void) {
  ifstream file;
  file.open("data.txt");
  char c;
  string test = "mul(";
  string do_ = "do()";
  string dont = "don't()";
  bool go = true;
  int i = 0;
  int j = 0;
  int sum = 0;
  bool mul = false;
  int num1 = 0;
  int num2 = 0;
  bool next = false;
  int counter = 0;
  while (!(file.get(c), file.eof())) {
    counter++;
    if (go) {
      if (mul) {
        try {
          int val = stoi(string(1, c));
          if (!next) {
            num1 *= 10;
            num1 += val;
          } else {
            num2 *= 10;
            num2 += val;
          }
          continue;
        } catch (const std::invalid_argument &_) {
          if (c == ',') {
            next = true;
            continue;
          } else if (c == ')') {
            sum += num1 * num2;
          }
        }
      } else {
        if (c == test[i]) {
          if (c == '(')
            mul = true;
          i++;
          continue;
        } else if (c == dont[j]) {
          if (c != ')') {
            j++;
            continue;
          }
          go = false;
        }
      }
      i = 0;
      j = 0;
      next = false;
      num1 = 0;
      num2 = 0;
      mul = false;
    } else {
      if (c == do_[j]) {
        if (c == ')') {
          go = true;
        }
        j++;
      } else {
        j = 0;
      }
    }
  }
  cout << sum;
  return 0;
}
