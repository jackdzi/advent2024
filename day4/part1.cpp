#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
  ifstream file;
  file.open("data.txt");
  string line;
  vector<vector<char>> data;
  while (getline(file, line)) {
    vector<char> temp;
    for (char &c : line)
      temp.push_back(c);
    data.push_back(temp);
  }
  string xmas = "XMAS";
  int rows, cols;
  rows = data.size();
  cols = data[0].size();
  int sum = 0;
  int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};  // directions: right, down-right, down, down-left, left, up-left, up, up-right
  int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      for (int d = 0; d < 8; d++) {
        int k;
        for (k = 0; k < 4; k++) {
          int ni = i + k * dx[d];
          int nj = j + k * dy[d];
          if (ni < 0 || ni >= rows || nj < 0 || nj >= cols || data[ni][nj] != xmas[k]) {
            break;
          }
        }
        if (k == 4) {
          sum++;
        }
      }
    }
  }
  cout << sum;

  return 0;
}
