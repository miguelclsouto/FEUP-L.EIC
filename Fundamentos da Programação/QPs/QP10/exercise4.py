
def union_with(combine, dict1, dict2):
    
    keys1 = set(dict1.keys())
    keys2 = set(dict2.keys())
    
    keys = keys1 | keys2 # union
    ikeys = keys1 & keys2 # intersection
    
    #[combine(dict1[x], dict2[x]) for x in keys if x in dict1.keys() and x in dict2.keys() else dict1[x] if x not in dict2.keys() else dict2[x]]
    
    difkeys1 = keys1 - keys2 # apenas do dict1 # difference
    difkeys2 = keys2 - keys1 # apenas do dict2 # difference
    
    
    k1 = zip(difkeys1, map(lambda x: dict1[x], difkeys1))
    
    k2 = zip(difkeys2, map(lambda x: dict2[x], difkeys2))
    
    
    k3 = zip(ikeys, map(lambda x: combine(dict1[x], dict2[x]), ikeys))
    
    
    dict3 = list(k1) + list(k2) + list(k3)
    
    
    #dictionary comprehension
    dict3 = {k:v for k, v in dict3}
    
    
    return dict3
    
    
    
    
    