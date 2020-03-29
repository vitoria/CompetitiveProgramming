#include <iostream>
using namespace std;

void swap(int arr[], int index1, int index2) {
  int aux = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = aux;
}

int partition(int arr[], int start, int end) {
  int pivot = arr[end];
  int i = start;
  int aux;
  
  for (int j = start; j < end; j++) {
    if (arr[j] < pivot) {
      swap(i, j);
      i++;
    }
  }
  
  aux = arr[end];
  arr[end] = arr[i];
  arr[i] = aux;
  
  return i;
}

void quickSort(int arr[], int start, int end) {
  if (start < end) {
    int position = partition(arr, start, end);
    quickSort(arr, start, position - 1);
    quickSort(arr, position + 1, end);
  }
}

// To execute C++, please define "int main()"
int main() {
  int numbers[] = {5, 4, 3, 2, 1};
  quickSort(numbers, 0, 4);;
  for (int i = 0; i < 5; i++) {
    cout << words[i] << " ";
  }
  cout << endl;
  return 0;
}
