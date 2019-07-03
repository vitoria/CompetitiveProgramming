#include <bits/stdc++.h>

using namespace std;

int freq_arr[1000000];

int main() {

  string s;
  string u = "";
  stack<char> p;

  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    freq_arr[s[i]]++;
  }

  int index = 0;
  for (char i = 'a'; i <= 'z' && index < s.size(); i++) {
    while(!p.empty() && p.top() <= i) {
      u += p.top();
      p.pop();
    }
    while(freq_arr[i] > 0) {
      if (s[index] == i) {
        u += i;
      } else {
        p.push(s[index]);
      }
      freq_arr[s[index]]--;
      index++;
    }
  }

  while (!p.empty())  {
		u += p.top();
		p.pop();
	}

	cout << u << endl;

  return 0;
}