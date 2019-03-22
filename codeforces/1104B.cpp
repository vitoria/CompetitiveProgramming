#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int count_remotions = 0;
    vector<char> to_process_letters;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && s[i] == s[i+1]) {
            i += 1;
            count_remotions++;
        } else if (to_process_letters.size() > 0 && s[i] == to_process_letters.back()) {
            to_process_letters.pop_back();
            count_remotions++;
        } else {
            to_process_letters.push_back(s[i]);
        }
    }

    if (count_remotions % 2 == 0) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}