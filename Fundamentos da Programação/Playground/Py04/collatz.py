
def collatz(n):
    
    if n == 1:
        
        return '1'
    
    return str(n) + ',' + (collatz(n // 2) if n % 2 == 0 else collatz(3 * n + 1))