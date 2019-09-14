
arr = [int(x) for x in raw_input().split()] 
a, b, c, d = arr
# a = input()
# b = input()
# c = input()
# d = input()

k = [a, b, c]
k.sort()
a, b, c = k

print(max(0, d - abs(a-b) + max(0, d - abs(b - c))))