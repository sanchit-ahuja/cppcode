import requests
s="abcdefghijklmnopqrstuvwxyz1234567890"
c="https://www.hackerrank.com/tests/"
cnt=0
power = 1
def rec(s,c,i):
    global cnt
    global power
    if i==10:
        cnt+=1
        var=pow(10,power)
        if cnt%var==0:
            print(var)
            power+=1
        x=requests.get(c)
        if x.status_code == 200:
            print(c)
        return 0

    for k in s:
        d=c
        c+=k
        rec(s,c,i+1)
        c=d
    
    
rec(s,c,0)
        
    