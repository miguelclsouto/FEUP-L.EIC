def remove_leading(ip):
    
    ip = ip.split(".")
    final = []
    
    for i in ip:
        
        i = str(int(i))
        final.append(i)
        
    final = ".".join(final)
    
    return final

    # ip = ip.split('.')
    # return "%i.%i.%i.%i" % (int(ip[0]), int(ip[1]), int(ip[2]), int(ip[3]))