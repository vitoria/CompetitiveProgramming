input()
list_number = list(map(int, input().split()))
list_number.sort()
print(' '.join(map(str, list_number)))