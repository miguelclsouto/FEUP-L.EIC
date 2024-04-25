
pe1 = int(input())
pe2 = int(input())
pe3 = int(input())

if pe3 < 40:
    
    pe4 = int(input())
    
    pe3 = max(pe3, pe4)


worst = min(pe1, pe2, pe3)


if worst == pe1:
    
    average = (pe2 + pe3) / 2
    
elif worst == pe2:
    
    average = (pe1 + pe3) / 2
    
else:
    
    average = (pe1 + pe2) / 2



if pe3 < 40:
    
    print("RFF")
    
else:
    
    print(round(average))
    


