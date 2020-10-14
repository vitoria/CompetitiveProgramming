#include <bits/stdc++.h>

using namespace std;

string compressWord(string word, int k) {
  deque<pair<char, int>> letters;
  pair<char, int> temp;
  string ansReversed = "", ans = "";

  for (int i = 0; i < word.size(); i++) {
    if (!letters.empty() && letters.back().second == k) {
      temp = letters.back();

      while (!letters.empty() && letters.back().first == temp.first) {
        letters.pop_back();
      }
    }

    if (!letters.empty() && letters.back().first == word[i]) {
        temp = letters.back();
        letters.push_back({ word[i], temp.second + 1 });
    } else {
      letters.push_back({ word[i], 1 });
    }
  }

  if (!letters.empty() && letters.back().second == k) {
    temp = letters.back();

    while (!letters.empty() && letters.back().first == temp.first) {
      letters.pop_back();
    }
  }

  while (!letters.empty()) {
    pair<int, int> aux = letters.back();
    letters.pop_back();
    ansReversed += aux.first;
  }

  for (int i = ansReversed.size() - 1; i >= 0; i--) {
    ans += ansReversed[i];
  }

  return ans;
}

int main() {

  string s;
  int k;

  cin >> k >> s;

  cout << compressWord(s, k) << endl;

  return 0;
}