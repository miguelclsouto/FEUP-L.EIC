    
            
def number_of_collisions(objects):
    
    count = 0
    
    for i in range(len(objects)): # poderiamos ir ate len(objects) - 1, mas ele ja nao verifica a ultima linha
        
        for j in range(i + 1, len(objects)):
            
            if check_collision(objects[i], objects[j]):
                
                count += 1
                
    return count            

def check_collision(object1, object2):
    
    # if object1['x1'] > object2['x2'] or object1['x1'] > object2['x2'] or object1['y1'] < object2['y2'] or object2['y1'] < object1['y2']:
    #     return False
    # return True
    
    return not(object1['x1'] > object2['x2'] or object2['x1'] > object1['x2'] or object1['y1'] > object2['y2'] or object2['y1'] > object1['y2']) # isto acontece caso os 2 objetos nao colidem

    