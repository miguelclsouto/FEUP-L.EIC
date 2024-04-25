hour = int(input())
min = int(input())

invalid = False
if hour < 0 or min < 0 or min >= 60:
    invalid = True
    
elif hour // 12 == 0:

    if hour == 0:

        hour = 12
        
    time = "am"

elif hour // 12 == 1:
    
    if hour != 12:
        hour = hour % 12

    time = "pm"

else:
    invalid = True

if invalid:
    print("INVALID DATE FORMAT")
    
elif min != 0:
   
    print(f"{hour}:{min:02} {time}")

else:
    
    print(f"{hour} {time}")

