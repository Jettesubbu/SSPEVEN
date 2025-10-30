import math

# Initialize board
board = [' ' for _ in range(9)]  # 3x3 board

def print_board(board):
    for row in [board[i*3:(i+1)*3] for i in range(3)]:
        print('| ' + ' | '.join(row) + ' |')

def is_winner(board, player):     
    win_cond = [
        [0,1,2], [3,4,5], [6,7,8],  # rows
        [0,3,6], [1,4,7], [2,5,8],  # columns
        [0,4,8], [2,4,6]            # diagonals
    ]
    return any(all(board[pos] == player for pos in line) for line in win_cond)

def is_draw(board):
    return ' ' not in board

def get_available_moves(board):
    return [i for i, spot in enumerate(board) if spot == ' ']

# Minimax algorithm
def minimax(board, depth, is_maximizing):
    if is_winner(board, 'X'):
        return 1
    elif is_winner(board, 'O'):
        return -1
    elif is_draw(board):
        return 0

    if is_maximizing:
        best_score = -math.inf
        for move in get_available_moves(board):
            board[move] = 'X'
            score = minimax(board, depth + 1, False)
            board[move] = ' '
            best_score = max(score, best_score)
        return best_score
    else:
        best_score = math.inf
        for move in get_available_moves(board):
            board[move] = 'O'
            score = minimax(board, depth + 1, True)
            board[move] = ' '
            best_score = min(score, best_score)
        return best_score

def best_move_easy(board):
    best_score = -math.inf
    move = None
    for i in get_available_moves(board):
        board[i] = 'X'
        score = minimax(board, 0, False)
        board[i] = ' '
        if score > best_score:
            best_score = score
            move = i
    return move

# Game Loop
def play_game():
    print("Tic Tac Toe: You (O) vs AI (X)")
    print_board(board)

    while True:
        # Human move
        try:
            move = int(input("Enter your move (0-8): "))
            if board[move] != ' ':
                print("Invalid move! Try again.")
                continue
            board[move] = 'O'
        except (ValueError, IndexError):
            print("Invalid input! Enter a number from 0 to 8.")
            continue

        print_board(board)

        if is_winner(board, 'O'):
            print("You win!")
            break
        if is_draw(board):
            print("It's a draw!")
            break

        # AI move
        ai_move = best_move_easy(board)
        board[ai_move] = 'X'
        print("AI played at position", ai_move)
        print_board(board)

        if is_winner(board, 'X'):
            print("AI wins!")
            break
        if is_draw(board):
            print("It's a draw!")
            break

# Run the game
play_game()
