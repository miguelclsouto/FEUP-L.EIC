def map(pos, steps):
    
    way = steps.split("-")
    x = pos[0]
    y = pos[1]
    
    # tuples are immutable
    
    for i in way:
        
        if i == "up":
            
            y += 1
            
        elif i == "down":
            
            y -= 1
            
        elif i == "right":
            
            x += 1
            
        else:
            x -= 1
    
    return (x, y)

# return (pos[0] + way.count("right") - way.count("left"), pos[1] + way.count("up") - way.count("down"))