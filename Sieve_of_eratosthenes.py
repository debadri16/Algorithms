#sieve of erastotheses
def soe(n):
    prime = [True for _ in range(n+1)]
    p = 2
    
    while (p * p <= n): 
         
        if prime[p] is True: 
           
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
    
    for i in range(2,n):
        if prime[i]:
            print(i)

N = int(input())
soe(N)
