def merge(arr, start, middle, end):
  left = arr[start:middle]
  right = arr[middle:end]
  i = 0
  j = 0

  for x in range(start, end):
    if i < len(left) and j < len(right):
      if left[i] < right[j]:
        arr[x] = left[i]
        i = i + 1
      else:
        arr[x] = right[j]
        j = j + 1
    else:
      if i < len(left):
        arr[x] = left[i]
        i = i + 1
      else:
        arr[x] = right[j]
        j = j + 1


def mergesort(arr, start, end):
  middle = (start + end) // 2
  if (end - start > 1):
    mergesort(arr, start, middle)
    mergesort(arr, middle, end)
    merge(arr, start, middle, end)

  
arr = [3, 1, 5, 4]

mergesort(arr, 0, 4)

print arr