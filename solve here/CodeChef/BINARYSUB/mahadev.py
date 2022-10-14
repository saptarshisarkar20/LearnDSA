mod = 998244353
for _ in range(int(input())):
    s = input()
    n = len(s)
    dp = [1]*(n+1)
    for i in range(1, n):
        dp[i+1] = dp[i]
        if s[i] != s[i-1]:
            dp[i+1] += dp[i-1]
        dp[i+1] %= mod
    print(dp[n])
