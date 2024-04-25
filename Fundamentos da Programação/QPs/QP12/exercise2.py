

def tic_tac_toe(board, player):
    
    board = board.split('\n')
    
    for i in range(len(board)):
        
        for j in range(len(board)):
            
            if board[i][j] == " " and check(board, i, j, player): # esta livre
                
                return chr(i + ord('A')) + str(j + 1) # this is to return the line and collumn of the win
    
    return None
    
def check(board, line, col, player):
    
    flag = False

    if line == col: # entao verifico as 2 diagonais
        
        flag = True # tenho que fzr isto se nao vai fzr return de True logo
        
        for i in range(len(board)):
            
            if i != line and board[i][i] != player: # line == col in this diagonal
                
                flag = False
        
        
        flag = True
        
        for i in range(len(board)):
            
            j = len(board) - 1 - i # the other diagonal
            
            if (i != line or j != col) and (board[i][j] != player):
                
                flag = False
                
                
    if flag:
        return True
    
    flag = True
        
    for j in range(len(board)): # check line
        
        if j != col and board[line][j] != player:  
             
            flag = False
    
    if flag:
        return True
    
    flag = True
        
    for i in range(len(board)): # check column
        
        if i != line and board[i][col] != player:
            
            flag = False
            
    if flag:
        return True
        
    return False
            