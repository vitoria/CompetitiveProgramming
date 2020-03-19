#include <bits/stdc++.h>

using namespace std;

void show(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int* sliceArray(int arr[], int start, int end) {
  int* slice = new int[end - start];

  for (int i = 0; i < end - start; i++) {
    slice[i] = arr[start + i];
  }

  return slice;
}

void merge(int* arr, int start, int middle, int end) {
  int* left = sliceArray(arr, start, middle);
  int* right = sliceArray(arr, middle, end);

  int i = 0, j = 0;

  for (int index = start; index < end; index++) {
    if (i >= (middle - start)) {
      arr[index] = right[j]; j++;
    } else if (j >= (end - middle)) {
      arr[index] = left[i]; i++;
    } else if (left[i] < right[j]) {
      arr[index] = left[i]; i++;
    } else {
      arr[index] = right[j]; j++;
    }
  }
}

void mergeSort(int arr[], int start, int end) {
  int middle = (start + end) / 2;

  if (end - start > 1) {
    mergeSort(arr, start, middle);
    mergeSort(arr, middle, end);
    merge(arr, start, middle, end);
  }
}

int main() {

  int arr[] = {3, 1, 5, 4};

  mergeSort(arr, 0, 4);

  show(arr, 4);

  return 0;
}