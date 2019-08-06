def display(a):
    for row in a:
        for ele in row:
            disp=''
            if ele==1:
                disp='X'
            elif ele==0:
                disp='N'
            else:
                disp='O'
            print(disp,end=' ')
        print('')
def game_over(a,moves):
    for row in range(3):
        if a[row][0]==a[row][1] and a[row][1]==a[row][2]:
            if a[row][0]==1:
                return True,1 #player with x has 1 
            if a[row][0]==-1:
                return True,2 #player with y has 2
    for i in range(3):
        if a[0][i]==a[1][i] and a[2][i]==a[1][i]:
            if a[0][i]==1:
                return True,1 #player with x has 1 
            if a[0][i]==-1:
                return True,2 #player with y has 2
    if (a[0][0]==a[1][1] and a[1][1]==a[2][2]) or (a[0][2]==a[1][1] and a[1][1]==a[2][0]):
        if a[1][1]==1:
            return True,1
        if a[1][1]==-1:
            return True,2
    if moves==9:
        return True,0#draw match
    return False,0#match continues
board=[[0,0,0],[0,0,0],[0,0,0]]#New board created 1s are x and -1s are o 0s are empty
mov_count=0#if 9 moves are done game is over
flag=True #game not over
invalid=True
while flag:
    display(board) 
    while invalid:
        r=int(input('Enter row number : '))
        c=int(input('Enter column number : '))
        if r>3 or c>3 or board[r-1][c-1]!=0:
            print('Invalid Move!')
            continue
        if mov_count%2==0:
            board[r-1][c-1]=1
        else:
            board[r-1][c-1]=-1
        mov_count=mov_count+1
        break
    winflag,win=game_over(board,mov_count)
    if winflag:
        if win==0:
            print("Draw Match")
        elif win==1:
            print("Player 1 Wins!")
        else:
            print("Player 2 Wins!")
        #display(board)
        break
print('Thank You For Playing!!')