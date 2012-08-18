import sys

def merge(arr, lt, rt):
    if lt + 1 >= rt:
        return 0
    mid = (lt + rt) / 2
    cnt = merge(arr, lt, mid) + merge(arr, mid, rt)
    i = lt
    j = mid
    a = []
    k = 0
    while i < mid and j < rt:
        if arr[j] < arr[i]:
            a.append(arr[j])
            cnt += j - (lt+k)
            j += 1
        else:
            a.append(arr[i])
            i += 1
        k += 1
    
    if i < mid:
        a.extend(arr[i:mid])
        #a += arr[i:mid]
    if j < rt:
        a.extend(arr[j:rt])
    
    arr[lt:rt] = a
    
    return cnt

T = int(sys.stdin.readline())
for case in range(0, T):
    N = int(sys.stdin.readline())
    a = [ int(i) for i in sys.stdin.readline().split() ]
    ans = merge(a, 0, len(a))
    '''
    ans = 0
    for i in range(1, N):
        j = i
        tmp = a[i]
        while j > 0 and tmp < a[j-1]:
            a[j] = a[j-1]
            ans += 1
            j -= 1
        a[j] = tmp
    '''
    print(ans)
    
