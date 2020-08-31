#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'countStudents' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY height as parameter.
 */

int countStudents(vector<int> height) {

  vector<int> ordedHeight;
  int result = 0;

  for (int i = 0; i < height.size(); i++) {
    ordedHeight.push_back(height[i]);
  }

  sort(ordedHeight.begin(), ordedHeight.end());

  for (int i = 0; i < height.size(); i++) {
    if (ordedHeight[i] != height[i]) {
      result++;
    }
  }

  return result;
}
