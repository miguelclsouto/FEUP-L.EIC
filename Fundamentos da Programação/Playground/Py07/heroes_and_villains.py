def fight(heroes, villain):
    
    length = len(heroes)
    
    for i in range(length):
        if heroes[i]['category'] != villain['category']:
            
            continue
        
        elif villain['health'] <= heroes[i]['health']:
            
            name = heroes[i]['name']
            heroes[i]['score'] += 1
            
            score = heroes[i]['score']
            return f'{name} defeated the villain and now has a score of {score}'
        
        villain['health'] = villain['health'] - (heroes[i]['health'] / 2)
        
        name = villain['name']
        
        health = villain['health']
        
    return f'{name} prevailed with {health}HP left'