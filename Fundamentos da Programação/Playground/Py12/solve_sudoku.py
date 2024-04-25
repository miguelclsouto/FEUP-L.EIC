def solve_sudoku(board):
    
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                for k in range(1, 10):
                    if check(board, i, j, k):
                        board[i][j] = k
    
    return board

def clamp(start, value, end):
    return start if value < start else end if value > end else value

def check(board, line, col, num):
    
    # tenho que verificar na linha, na col e no quadrado pequeno
    
    #can = True
    
    # for i in range(len(board)):
        
    #     # if i != line:
        
    #     if board[i][col] == num:
    #         return False
    #         #can = False
    #         #break
            
    #     # if i != col:
        
    #     if board[line][i] == num:
    #         return False
    
    # if not can:
    #     return False
    
    # for j in range(len(board[0])):
    #     if j != col:
    #         if board[line][j] == num:
    #             #can = False
    #             return False
            
    # if not can:
    #     return False
    
    # agora vou verificar o quadrado maior
    minlin = 0
    maxlin = 0
    mincol = 0
    maxcol = 0
    
    # minlin = clamp(0, line - 1, 8)
    # mincol = clamp(0, col - 1, 8)
    # maxlin = clamp(0, line + 1, 8)
    # maxcol = clamp(0, line + 1, 8)
    
    minlin = mincol = 0
    
    maxlin = maxcol = 2
    
    nline = line // 3 
    
    ncol = col // 3 
    
    minlin = nline * 3
    
    mincol = ncol * 3
    
    maxlin = (nline + 1) * 3 - 1 # minlin + 2
    
    maxcol = (ncol + 1) * 3 - 1 # mincol + 2
    
    lines = [board[x][col] for x in range(0,9)]
    
    cols = [board[line][x] for x in range(0, 9)]
    
    cube = [board[x][y] for x in range(minlin, maxlin + 1) for y in range(mincol, maxcol + 1)]
    
    if num in cube or num in cols or num in lines:
        return False
    
    return True
    
    # if 0 <= line <= 2:
    #     minlin = 0
    #     maxlin = 2
    
    # elif 3 <= line <= 5:
    #     minlin = 3
    #     maxlin = 5
        
    # else:
    #     minlin = 6
    #     maxlin = 8
        
        
    # if 0 <= col <= 2:
    #     mincol = 0
    #     maxcol = 2
        
    # elif 3 <= col <= 5:
    #     mincol = 3
    #     maxcol = 5
        
    # else:
    #     mincol = 6
    #     maxcol = 8
    
    # for i in range(minlin, maxlin + 1):
    #     for j in range(mincol, maxcol+ 1):
            
    #         # if i != line or j != col: # ambos nao sao iguais ao original
            
    #         if board[i][j] == num:
    #             #can = False
    #             return False
    
    # return True