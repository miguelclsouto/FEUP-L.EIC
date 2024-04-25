
def generate(word):
    
    final = []
    new_word = ""
    
    if word.endswith('I'):
        new_word = word + 'U'
        final.append(new_word)
        # final += generate(new_word)
        
    if word.startswith('M'):
        new_word = word[0] + 2 * word[1:]
        final.append(new_word)
        # final += generate(new_word)
        
    
    for i in range(len(word) - 1):
        
        if word[i:i+2] == "UU":
            new_word = word[:i] + word[i+2:]
            final.append(new_word)
            # final += generate(new_word)

    for i in range(len(word) - 2):       
        if word[i: i + 3] == "III":
            new_word = word[:i] + "U" + word[i + 3:]
            final.append(new_word)
            #if word[i-1] or word[i+3] == 'U': # acho que nao da para verificar isto porque
                # word[i+3 pode passar do tamanho da palavra]
                # final += generate(new_word)
                
    final.sort() 
    
    return final # ou sorted(final)
