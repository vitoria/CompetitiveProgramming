s1 = input()
s2 = input()

s1_1 = s1[:len(s1)//2]
s1_2 = s1[len(s1)//2:]
s2_1 = s2[:len(s2)//2]
s2_2 = s2[len(s2)//2:]

if s1 == s2 or (len(s1) % 2 == 0 and len(s1) == len(s2) and ((s1_1 == s2_1 and s1_2 == s2_2) or (s1_1 == s2_2 and s1_2 == s2_1))):
  print('YES')
else:
  print('NO')