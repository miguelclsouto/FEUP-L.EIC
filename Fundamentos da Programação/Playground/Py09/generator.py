def generator(intlist):
    l = map(lambda x: list(range(x[0], x[1] + 1)), intlist)
    k = []
    for i in l:
        #k += i
        for j in i:
            yield j

    #return (x for x in l)
  
# complexidade 2  
# from functools import reduce
# def generator(intlist):
#     l = reduce(lambda x, y: x + y, map(lambda x: list(range(x[0], x[1] + 1)), intlist))

#     return (x for x in l)