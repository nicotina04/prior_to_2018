import copy
import queue

def take_input():
    """Accepts the size of the chess board"""
    while True:
        try:
            size = int(input('What is the size of the chessboard? n = \n'))
            if size == 1:
                print("Trivial solution, choose a board size of at least 4")
            if size <= 3:
                print("Enter a value such that size>=4")
                continue
            return size
        except ValueError:
            print("Invalid value entered. Enter again")

def get_board(size):
    """Returns an n by n board that filled zeros"""
    #Return n size row.
    board = []
    #Duplicate rows by size.
    for ix in range(size):
        board.append([0]*size)
    return board

def print_solutions(solutions, size):
    #print(solutions.qsize())
    """Prints all the solutions in user friendly way"""
    while not solutions.empty():
        printer = solutions.get()
        for i in printer:
            print(i)
        print()

def deploy(board, row, size):
    global boards

    if row == size:
        return

    if row == 0:
        for i in range(size):
            pushtarget = copy.deepcopy(board)
            pushtarget[0][i] = 1
            boards.put(pushtarget)
        deploy(board, row + 1, size)
    else:
        tmpque = queue.Queue()
        while not boards.empty():
            temp = boards.get()
            for k in range(size):
                test = copy.deepcopy(temp)
                test[row][k] = 1
                if safe(test, row, k):
                    tmpque.put(test)
        boards = tmpque
        deploy(board, row + 1, size)


def safe(target, row, col):
    for j in range(row + 1):
        if j == row:
            continue
        if target[j][col] == 1:
            return False

    ix, iy = row, col
    while ix >= 0 and iy >= 0:
        if ix == row and iy == col:
            ix -= 1
            iy -= 1
            continue
        #Check the diagonal line
        if target[ix][iy] == 1:
            return False
        #Move to up and left side.
        ix -= 1
        iy -= 1

    ix, iy = row, col
    while ix >= 0 and iy < size:
        if ix == row and iy == col:
            ix -= 1
            iy += 1
            continue
        #Check the diagonal line
        if target[ix][iy] == 1:
            return False
        #Move to up and right side.
        ix -= 1
        iy += 1

    #If not False, return True. (Solution found)
    return True

if __name__ == "__main__":

    size = take_input()
    board = get_board(size)
    boards = queue.Queue()
    deploy(board, 0, size)
    sols = boards.qsize()
    print_solutions(boards, size)
    print("Total solutions = {}".format(sols))