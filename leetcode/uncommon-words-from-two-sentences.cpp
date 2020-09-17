#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s) {
  vector<string> splited;
  string temp = "";

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      if (temp.size() > 0) splited.push_back(temp);
        temp = "";
    } else {
      temp += s[i];
    }
  }

  if (temp.size() > 0) splited.push_back(temp);

  return splited;

}

vector<string> uncommonFromSentences(string A, string B) {
  map<string, int> wordFreq;
  vector<string> uncommon;
  vector<string> splitedA = split(A), splitedB = split(B);

  for (int i = 0; i < max(splitedA.size(), splitedB.size()); i++) {
    if (i < splitedA.size()) wordFreq[splitedA[i]]++;
    if (i < splitedB.size()) wordFreq[splitedB[i]]++;
  }

  for (auto elem : wordFreq) {
    if (elem.second == 1) {
      uncommon.push_back(elem.first);
    }
  }
  return uncommon;
}

int main() {

  return 0;
}