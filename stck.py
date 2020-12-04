def solve(arr):
    li = []
    for st in arr : 
        temp_st = st.split(' ')
        if temp_st[0] == 'push' :
            li.append([int(temp_st[1]),0]) 
            print(li[-1])
        elif temp_st[0] == 'inc':
            idx = int(temp_st[1])
            li[i] = [li[idx][0]+int(temp_st[2]),int(temp_st[2])]
            print(li[-1])
        
        else :
            if(len(li) == 0): 
                print('EMPTY')
            temp_pop = li.pop(-1)
            li[-1] = li[li[-1][0]+temp_pop[1],li[-1][0]+temp_pop[1]]
            print(temp_pop[0])

if __name__ == "__main__":
    solve()