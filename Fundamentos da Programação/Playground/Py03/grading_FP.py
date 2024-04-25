
le = int(input())
re = int(input())
pe = int(input())
te = int(input())

grade = (le + re + 13 * pe + 5 * te) / 100

if not ((0 <= le <= 100) and (0 <= pe <= 100) and (0 <= te <= 100) and (0 <= re <= 100)):
    
    print("Input error")
    
elif pe < 40 or te < 40:
    
    print("RFF")
    
else:
    
    print(round(grade))