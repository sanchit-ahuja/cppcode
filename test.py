def fact(n):
    arr=[]
    arr.append(1)
    for i in range(1,n+1):
        arr.append(i*arr[i-1])
    return arr[n]

n=int(input())
k=fact(n)
odd=0
for i in range(1,n+1,2):
    odd-=k/(fact(i))

even=0
for i in range(2,n+1,2):
    even+=k/(fact(i))

total = k+odd+even
print(int(total))