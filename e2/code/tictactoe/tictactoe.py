import re
import sys
import random
from tkinter import Tk, Label, Frame, Button

'''
The playing field is defines as a string of 9 spaces for the 9 cells of the game.
Since there are only 8 winning patterns, they can easily be represented as regex.
This way the state of the game be checked by matching the win_pattern with the field.
'''

field = " " * 9     # string of 9 spaces where every space represents one cell
win_pattern = re.compile(r"((?P<X>XXX......|...XXX...|......XXX|X..X..X..|.X..X..X.|..X..X..X|X...X...X|..X.X.X..)|"
                         r"((?P<O>OOO......|...OOO...|......OOO|O..O..O..|.O..O..O.|..O..O..O|O...O...O|..O.O.O..)))")
numpad_converter = [6, 7, 8, 3, 4, 5, 0, 1, 2] # so the top left is 6 instead of 1 etc

def is_finished():
    '''Checks if the field matches a win condition or is in a tie.'''
    global blocked
    match = win_pattern.search(field)

    if match:
        winning_player = 1 if match.group('X') else 2
        announce(f"Player {winning_player} has won!")
        shuffle_turn()
        blocked = True
        return True
    elif field.find(' ') == -1: # if there are no spaces left, it's a tie
        announce(f"It's a TIE!")
        reset(False)
        return True
    return False


def mark(i, char):
    '''Writes the 'char' on position 'i' on the field'''
    global field
    field = field[:i] + char + field[i+1:]
    grid.grid_slaves()[8-i].config(text=char)

def is_free(i):
    '''Returns true when cell i is empty (free)'''
    return field[i] == " "

def reset(do_shuffle):
    '''Empties the field string back to 9 spaces and clears the gui'''
    global blocked
    global field
    blocked = False
    field = " " * 9
    for i in range(9):
        grid.grid_slaves()[i].config(text=" ")
    
    '''Shuffle players if needed and let AI play if she's supposed to start'''
    if do_shuffle:
        shuffle_turn()
    announce_next_move()
    if turn == 1 and against_ai:
        ai_turn()
    



'''
Mechanics:
There are some flags that determine which Players turn it is, if AI is turned on or if the field is blocked.
Each turn is started by a button click or keyboard input and advances until the next keyboard input is needed.

On the first game Player 1 starts, after that the starting player is randomized except if there was a tie in
which case the starting player changes compared to the last round.

The AI (when turned on) priorizes the center cell over the corners and the corners over the border cells.
The Mode can be changed at all times.

When the game finishes, no field is frozen (blocked) until the restart button is pressed.
'''

against_ai = False
turn = 0
char = ['X', 'O']
blocked = False

def next_turn(i):
    '''Advances one turn (or two when against AI).'''
    global turn
    if is_free(i) and not blocked: # when the game is finished, all cells are blocked
        mark(i, char[turn])             # mark selected cell
        turn = 1 if turn == 0 else 0    # swap whos turn it is

        if is_finished(): return         # check for a winner after first move

        ai_turn() if against_ai else announce_next_move() # AI move or announce next Player

        if is_finished(): return         # check for a winner after second move
    else:
        print(i, "is already taken.")

def ai_turn():
    global blocked
    blocked = True
    '''Plays one turn. Prio: Center > Corner > Border'''
    global turn
    turn = 0
    corners = [0, 2, 6, 8]
    if is_free(4):
        mark(4, "O")
    else:
        free_corners = [corner for corner in corners if is_free(corner)]
        if free_corners:
            mark(random.choice(free_corners), "O")
        else:
            for i in range(9):
                if is_free(i):
                    mark(i, "O")
                    break
    blocked = False
    if is_finished():
        return
    announce_next_move()
    


def shuffle_turn():
    '''Randomizes who can play the next turn'''
    global turn
    turn = random.choice([0,1])

def announce_next_move():
    '''Announces the next Player and prints the current playing field'''
    announce(f"It's Player {str(turn+1)}'s turn!")
    print("\n" + field[0] + " | " + field[1] + " | " + field[2] + "\n--+---+--\n" +
        field[3] + " | " + field[4] + " | " + field[5] + "\n--+---+--\n"+
        field[6] + " | " + field[7] + " | " + field[8] + "\n")
    

def announce(msg):
    '''Only does an announcement without printing the playing field'''
    action.config(text=msg)
    print(msg)


def change_mode():
    '''if game_mode was against_ai, it changes to 2 player mode and vice versa'''
    global against_ai
    if against_ai:
        change_mode_button.config(text="Mode: 2p")
        against_ai = False
        announce("You're now playing two player mode!")
    else:
        change_mode_button.config(text="Mode: AI")
        against_ai = True
        announce("You're now playing against me!")
        if turn == 1 and not blocked:
            ai_turn()

def quit():
    root.destroy()
    sys.exit()


def keyboard_in(event):
    '''Input preferred cell via keyboard'''
    try:
        next_turn(numpad_converter[int(event.char) -1])
    except:
        print(event.char, "is not a valid field number.")





''' 
The Game's GUI is split into 4 parts held together by the root pane.
The header Label shows the games title (logo), in the middle is the playing field (grid)
The action bar which always displays the next move or current action.
and in the bottom is a horizontal box (hbox) containing the different buttons.
'''

root = Tk()
root.geometry("800x900")
root.title('TicTacPython')
root.bind('<KeyPress>', keyboard_in)

header = Label(root, text="Tic Tac Python", font=("Papyrus", 75), padx=5, pady=5)
header.pack()

grid = Frame(root)
for x in range(3):
    for y in range(3):
        index = x*3+y
        def unique_click(i=index):
            next_turn(i)
        cell = Button(grid, text="", font=("Papyrus", 125), width=2, command=unique_click)
        cell.grid(row=x, column=y, sticky="NSEW", padx=5, pady=5)
grid.pack()

action = Label(root, text="Welcome! Click a cell or press 1-9 to play", font=("Papyrus", 25))
action.pack()

hbox = Frame(root)

restart_button = Button(hbox, text="Restart", font=("Papyrus", 40), command=lambda: reset(True))
restart_button.grid(row=0, column=0)

change_mode_button = Button(hbox, text="Mode: 2p", font=("Papyrus", 40), command=change_mode)
change_mode_button.grid(row=0, column=1)

quit_button = Button(hbox, text="Quit", font=("Papyrus", 40), command=quit)
quit_button.grid(row=0, column=2)

hbox.configure(pady=20)
hbox.pack()

if __name__ == "__main__":
    announce("Welcome! Click a cell or press 1-9 to play")
    announce_next_move()
    # Allows playing the game in the terminal. (gui still updates)
    while(True):
        msg = input(" ")
        if msg == "mode":
            change_mode()
        elif msg == "restart":
            reset(True)
        elif msg == "quit":
            quit()
        else:
            try:
                next_turn(numpad_converter[int(msg)-1])
            except:
                print(msg, "is not a valid field number or command.")