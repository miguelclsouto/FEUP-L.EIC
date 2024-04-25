def find_treasure(pos, steps):
    
    x = pos[0]
    y = pos[1]
    
    dx = {'right': 1, 'left': -1}
    dy = {'up': 1, 'down': -1}
    
    return aux(x, y, steps, dx, dy)
    

def aux(x, y, steps, dx, dy):
    
    if len(steps) == 0:
        return (x, y)
    
    x += dx.get(steps[0], 0)
    y += dy.get(steps[0], 0)
    
    return aux(x, y, steps[1:], dx, dy)