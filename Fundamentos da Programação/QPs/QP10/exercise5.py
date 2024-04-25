

def transitive_closure(r):
    
    # ---> RECURSAO <---
    
    # criei oitra funcao composition que faz a transitive closure ate nao mudar nada,
    # pois precisava de ter uma funcao que tivesse 2 argumentos em que um deles fosse r
    
    return composition(r,r)


def composition(t, r):
    
    # set comprehension
    s = {(a, d) for a, b in list(r) for c, d in list(t) if b == c}
    
    s = s | r # UNION
    
    # NAO PODES ADICIONAR UM SET A UM SET
    # TENS QUE FAZER A UNIAO DOS SETS 
    
    # Nao posso iterar sobre sets tb. Apenas usar Iteradores.
    
    if s == t:
        return t
    
    return composition(s, r)
