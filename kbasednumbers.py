def rec(prev,i,n,k):
    if i == n+1:
        return 1

    if dp[i][prev] != -1:
        return dp[i][prev]

    cnt = 0
    for j in range(k):
        if j == 0 and prev == 0:
            continue

        else:
            cnt = cnt+rec(j,i+1,n,k)

    dp[i][prev] = cnt
    return cnt

n = int(input())
k = int(input())
dp = []
for i in range(n+1):
    o = []
    for j in range(k):
        o.append(-1)

    dp.append(o)

print(rec(0,1,n,k))