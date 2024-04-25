
a = int(input())
b = int(input()) 

print("Prime numbers between " + str(a) + " and " + str(b) + " are: ", end = "")

# max(lower, 2)

prime = False

#for i in range(a, b + 1):

    # prime = True
    
    #if i == 1:
    
        #continue
        
    #for j in range(2, i):
    
        #if i % j == 0:
        
            #continue
            
    #print(str(i), end = " ")

for i in range(a, b + 1):
    
        prime = True
        if i < 2:
            
            continue
        
        for j in range(2, i):
            
            if i % j == 0:
                
                prime = False
                break
            
        if prime:       
            print(str(i), end = " ")
    
#  "{" ".join(primes)}"
# primes = ' '.join(map(str, [x for x in range(lower, upper + 1) if is_prime(x)]))

#num1=int(input())
#num2=int(input())

#def primo(n):

    #p=list(filter(lambda i: n%i==0, range(1,n+1)))
    #return p
    
#def primos_entre(n1,n2):

    #final=list(filter(lambda i: len(primo(i))==2 , range(n1,n2+1)))
    #return final
    
#este=(map(str,primos_entre(num1,num2)))
#result=' '.join(este)
#print("Prime numbers between %i and %i are: %s" % (num1,num2,result))
