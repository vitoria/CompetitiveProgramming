#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'maximumOccurringCharacter' function below.
 *
 * The function is expected to return a CHARACTER.
 * The function accepts STRING text as parameter.
 */

int frequency[257];
char maximumOccurringCharacter(string text) {
  int max = 0;
  char result;

  for (int i = 0; i < text.size(); i++) {
    frequency[text[i]]++;
    if (frequency[text[i]] > max) {
      max = frequency[text[i]];
      result = text[i];
    }
  }

  return result;
}
