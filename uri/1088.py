def merge(arr, start, middle, end):
  ans = 0
  left = arr[start:middle]
  right = arr[middle:end]

  i = 0
  j = 0

  for k in range(start, end):
    if i >= middle:
      arr[k] = right[j]
      j = j + 1
    elif j >= end:
      arr[k] = left[i]
      i = i + 1
    elif left[i] < right[j]:
      arr[k] = left[i]
      i = i + 1
    else:
      arr[k] = right[j]
      j = j + 1
      ans += len(left) - i
  return ans
  
def mergesort(arr, start, end):
  middle = (start + end) // 2

  if end - start > 1:
    mergesort(arr, start, middle)
    mergesort(arr, middle, end)
    merge(arr, start, middle, end)
  return 0

player = ['Carlos', 'Marcelo']

while True:
  ans = 0
  n = [int(x) for x in raw_input().split(' ')]
  arr = n[1:len(n)]
  if n[0] == 0:
    break
  mergesort(arr, 0, len(arr))
  print player[ans % 2]