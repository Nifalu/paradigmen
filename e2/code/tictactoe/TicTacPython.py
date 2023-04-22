import sys
import random
import re
from tkinter import Tk, Label, Frame, Button
import PlayingField as field


mode = 0 # 0 = p2, 1 = AI
turn = 0 # 0 = p0, 1 = p1
chars = ["X", "O"]
blocked = False


def nextTurn(i):
    global turn
    if field.isFree(i) and not blocked:
        markButton(i, chars[(turn % 2)])
        turn = 1 if turn == 0 else 0
        if whoWon(): return
        player = str(object=turn+1)
        ai_turn() if mode else announce("It's Player " + player + "'s turn!")
        if whoWon(): return


def ai_turn():
    global turn
    turn = 0
    corners = [0,2,6,8]
    if field.isFree(4): # try to get middle
        markButton(4, "O")
        announce("It's Player 1's turn!") 
    else: #if there is a free corner, try to get a (random) corner
        match = re.compile(r"^([XO].[XO]...[XO].[XO])$").match(field.field)
        while(not match) :
            r = random.randint(0,3)
            if field.isFree(corners[r]):
                markButton(corners[r], "O")
                announce("It's Player 1's turn!") 
                return
        # if no corner is free, take the first free field.
        for i in range(9):
            if field.isFree(i):
                markButton(i, "O")
                announce("It's Player 1's turn!") 
                return
    return

def whoWon():
    bol, val = field.isFinished()
    if bol:
        finish(val)
        return True


# finishes the current game.
# If there is a winner it's announced
# If it's a tie, a new game is started
def finish(i):
    global blocked
    if i == 2:
        print("--TIE--\n")
        restart(False)
        
    else:
        player = str(object=i+1)
        announce("Player " + player + " has won!")
        blocked = True

# Starting Player is chosen at random.
def shuffleStartingPlayer():
    global turn
    turn = random.randint(0,1)


# ------------------------------------------------------------ Feature 5 part 1:
# Game Conditions
def restart(shuffle):
    global blocked
    field.reset()
    for i in range(9):
        markButton(i," ")
    # ------------------------------------------------------------ Feature 1 and 2:
    # Random starting player with restart, other player with a tie 
    if shuffle: shuffleStartingPlayer()
    # ------------------------------------------------------------    
    player = str(object=turn+1)
    announce("Player " + player + " begins!")
    if turn == 1 and mode == 1:
        ai_turn()
        whoWon()
    blocked = False

def changeMode():
    global mode
    mode = 1 if mode == 0 else 0
    if mode == 0:
        bchangeMode.config(text="Mode: 2p")
        print("Mode is now: 2 Players")
    else: 
        bchangeMode.config(text="Mode: AI")
        print("Mode is now: 1 Player")
        if turn == 1 and mode == 1:
            ai_turn()
            whoWon()
    
# ------------------------------------------------------------


# ------------------------------------------------------------ Feature 6:
# Play the game with keyboard input.
def keyboardInput(event):
    try:
        nextTurn(int(event.char)-1)
    except:
        print("invalid input", event.char)
# ------------------------------------------------------------

def markButton(i, char):
    grid.grid_slaves()[8-i].config(text=char)
    field.mark(i, char)

def announce(msg):
    action.config(text=msg)
    print(msg)

# ---------------------------------------------------------------
# Gui starts here
# ---------------------------------------------------------------

# The root pane
root = Tk()
root.geometry('800x900')
root.title('TicTacPython')
root.bind('<KeyPress>', keyboardInput)


# The Heading
header = Label(root, 
               text="Tic Tac Python",
               font=("Papyrus", 75),
               padx=5,
               pady=5)
header.pack()

# Create 9 Labels (cells)
grid = Frame(root)
for x in range(3):
    for y in range(3):
        ind = x*3+y
        def unique_click(i=ind):
            nextTurn(i)
        cell = Button(grid, text="",
                      font=("Papyrus", 125),
                      width=2,
                      command=unique_click)
        cell.grid(row=x, column=y, sticky="NSEW", padx=5, pady=5)
grid.pack()


# Action Text:
action = Label(root, 
               text="",
               font=("Papyrus", 25))
action.pack()

# ---------------------------------------------------------------- Feature 5 part 2: Game Conditions
hbox = Frame(root)
brestart = Button(hbox,
                  text="Restart",
                  font=("Papyrus", 40),
                  command=lambda: restart(True))
brestart.grid(row=0, column=0)

bchangeMode = Button(hbox,
                     text="Mode: 2p",
                     font=("Papyrus", 40),
                     command=changeMode)
bchangeMode.grid(row=0, column=1)

bquit = Button(hbox,
               text="Quit",
               font=("Papyrus", 40),
               command=root.destroy)
bquit.grid(row=0, column=2)
# ----------------------------------------------------------------
hbox.configure(pady=20)
hbox.pack()


if __name__ == "__main__":
    announce("Welcome to Tic Tac Python! Player 1 begins!")


    # Allows playing the game in the terminal. (gui still updates)
    while(True):
        field.printcurrent()
        msg = input(" ")
        if msg == "mode":
            changeMode()
        elif msg == "restart":
            restart(True)
        elif msg == "quit":
            break
        else:
            try:
                nextTurn(int(msg)-1)
            except:
                print("not a valid command", msg)

