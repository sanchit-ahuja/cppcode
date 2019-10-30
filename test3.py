import math
x=int(input())
while x:
    flag=0
    n=int(input())
    k=int(math.log(n)/(math.log(2)))
    a=int(math.pow(2,k))
    b=n-int(math.pow(2,k))
    if b==0:
        flag=1
    elif b%2==0:
        b=int(math.log(n)/math.log(2))
    elif b%2:
        b=int(math.log(n)/math.log(2))+1
    if(flag==0):
        print(max(b,k))
    else:
        print(k-1)
    x-=1
