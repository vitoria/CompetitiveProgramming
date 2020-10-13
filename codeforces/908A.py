alphabet = ['a', 'e', 'i', 'o', 'u']
even = ['1', '3', '5', '7', '9']
input_str = input()

ans = 0
for s in input_str:
    if (s in alphabet or s in even):
        ans += 1

print(ans)