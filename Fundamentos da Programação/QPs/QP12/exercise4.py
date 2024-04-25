    
def move_ball(board):
    
    # x = 0
    # y = 0
    
    # dir = (0, 0) # tb podia usar 2 dicionarios: um dirx e um diry
    # # para obter a dir e usava o dictionary method .get
    # p = [dir]
    # a direcao inicial nao e (0, 0)
    
    # directions = ['E', 'N', 'W', 'S']
    # dirx = {'E': 1, 'W': -1}
    # diry = {'N': 1, 'S': -1}
    
    # dir = board[0][0]
    
    
    double_bar = {'N': 'W', 'W': 'N', 'S': 'E', 'E': 'S'}
    
    single_bar = {'N': 'E', 'W': 'S', 'S': 'W', 'E': 'N'}
    
    directions = {'E': (0, 1), 'S': (1, 0), 'N': (-1, 0), 'W': (0, -1)}
    
    # tenho que verificar a posicao do X tb
    
    for i in range(len(board)):
        for j in range(len(board[i])):
            
            if board[i][j] in single_bar.keys():
                pos = [(i, j)]
                dir = directions[board[i][j]]
                tile = board[i][j]
                break
                
    
    x = dir[0]
    y = dir[1]
    
    while board[pos[-1][0]][pos[-1][1]] != 'X':
        
        pos = pos + [(pos[-1][0] + dir[0], pos[-1][1] + dir[1])] # tou a acrescentar / fzr append a este valor a lista
        x = dir[0]
        y = dir[1]
        
        if board[pos[-1][0]][pos[-1][1]] != ' ':
            if board[pos[-1][0]][pos[-1][1]] == '\\' :
                
                tile = double_bar[tile]
                dir = directions[tile]
            elif board[pos[-1][0]][pos[-1][1]] == '/':
                
                tile = single_bar[tile]
                dir = directions[tile]
    
    return pos
