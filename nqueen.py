def print_board(board, n):
    for i in range(n):
        for j in range(n):
            if board[i] == j:
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print()
    print()

def is_safe(board, row, col):
    for i in range(row):
        # check column and diagonal conflicts
        if board[i] == col or abs(board[i] - col) == abs(i - row):
            return False
    return True

def solve(board, row, n):
    if row == n:
        print_board(board, n)
        return True  # found at least one solution

    res = False
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            res = solve(board, row + 1, n) or res
            board[row] = -1  # backtrack
    return res

def n_queens(n):
    board = [-1] * n
    if not solve(board, 0, n):
        print("No solution exists")

# 🟢 Run program
n = int(input("Enter number of queens: "))
n_queens(n)
