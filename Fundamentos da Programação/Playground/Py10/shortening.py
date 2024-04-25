def shorten(suffixes, base):

    suf = enumerate(suffixes) 
    
    suf = map(lambda x : base ** x[0], suf) # [0, 1000, 1000000]

    suf = zip(suf, suffixes) # [(0, ''), (1000, 'K')]
    

    def inner(num):
        
        if type(num) is not str or not num.isdigit():

            return str(num)
        
        num = int(num)

        s = list(filter(lambda x: x[0] <= num, suf)) # so fica com os que sao menores ou iguais
        
        ind = s.index(s[-1])
        if s[ind][0] != 0:
            num //= s[ind][0] # ou podia usar o pop ou o len()

            final = str(num) + " " + s[ind][1]
        else:
            final = str(num)
        
        return final
        
    return inner
