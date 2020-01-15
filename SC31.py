
def  countSetBits(n): 
    count = 0
    while (n): 
        count += n & 1
        n >>= 1
    return count 

t = int(input())
while t:
    n = int(input())
    l = []
    ans = -1
    while n:
        k = int(input(),2)
        l.append(k)
        n -= 1
    for i in range(0,len(l)):
        for j in range(i+1,len(l)):
            temp = l[i]^l[j]
            ans = max(ans,countSetBits(temp))
    print(ans)
    t -= 1


