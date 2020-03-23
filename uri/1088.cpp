#include <bits/stdc++.h>
#define MAXN (int)1e5 + 1

using namespace std;

int ans = 0;
string players[] = {"Carlos", "Marcelo"};

int* sliceArray(int arr[], int start, int end) {
  int* slice = new int[end - start];

  for (int i = 0; i < end - start; i++) {
    slice[i] = arr[start + i];
  }

  return slice;
}

void merge(int arr[], int start, int middle, int end) {
  int* left = sliceArray(arr, start, middle);
  int* right = sliceArray(arr, middle, end);

  int i = 0, j = 0;

  for (int index = start; index < end; index++) {
    if (i >= (middle - start)) {
      arr[index] = right[j++];
    } else if (j >= (end - middle)) {
      arr[index] = left[i++];
    } else if (left[i] < right[j]) {
      arr[index] = left[i++];
    } else {
      arr[index] = right[j++];
      ans += middle - start - i;
    }
  }
}

void mergesort(int arr[], int start, int end) {
  int middle = (start + end) / 2;
  if (end - start > 1) {
    mergesort(arr, start, middle);
    mergesort(arr, middle, end);
    merge(arr, start, middle, end);
  }
}

int main() {

  int n, numbers[MAXN];

  while(cin >> n && n > 0) {
    ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> numbers[i];
    }

    mergesort(numbers, 0, n);

    cout << (ans % 2 == 0 ? "Carlos" : "Marcelo") << endl;
  }

  return 0;
}