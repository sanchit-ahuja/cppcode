def knapsack(val,wt,i,W,lookup):
    if W == 0 or i == len(wt):
        return 0
    

    if lookup[i][W] != -1:
        return lookup[i][W]
    if wt[i] > W:
        return knapsack(val,wt,i+1,W,lookup)
    
    else:
        m = val[i] + knapsack(val,wt,i+1,W-wt[i],lookup)
        n = knapsack(val,wt,i+1,W,lookup)
        lookup[i][W] =  max(m,n)
        return lookup[i][W]


if __name__ == "__main__":
    val = [60,100,120]
    wt = [10,20,30]
    W = 50
    lookup = [[-1 for i in range(W+1)] for j in range(len(val)+1)]
    # print((lookup[0][50]))
    print(knapsack(val,wt,0,W,lookup))