import sys
input = sys.stdin.readline
#Kadane's algo
def max_sum(a):
    maxnow = a[0]
    maximum = a[0]
    for i in range(1,len(a)):
        maxnow += a[i]
        if maxnow < a[i]:
            maxnow = a[i]

        maximum = max(maxnow, maximum)

    return maximum

n = int(input())
mat = []
for i in range(n):
    l = list(map(int,input().split()))
    mat.append(l)

ans = -10**18
for i in range(n):
    row = []
    for j in range(i,n):
        if i == j:
            for k in range(n):
                row.append(mat[k][j])

        else:
            for k in range(n):
                row[k] += mat[k][j]

        ans = max(ans,max_sum(row))

print(ans)