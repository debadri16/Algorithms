dp = {};
#pascal's triangle
def nCr(n, r):

    dp[n] = {}
    if n==r:
       dp[n][r] = 1
       return 1
    if(r==0):
       dp[n][r] = 1
       return 1
    if(r==1):
       dp[n][r] = n
       return n
    if r in dp[n]:
       return dp[n][r]
       
    dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1)
    return dp[n][r]

def main():
    n,r = map(int,raw_input().split());
    
    
    print(nCr(n,r))

main()
