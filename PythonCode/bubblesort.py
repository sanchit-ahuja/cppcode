def bubblesort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0,n-i-1):
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1] = arr[j+1],arr[j]
    return arr

if __name__ == "__main__":
    arr = [1,4,5,2,1,8,3]
    arr = [-1*i for i in arr]
    (bubblesort(arr))
    arr = [-1*i for i in arr]
    print(arr)