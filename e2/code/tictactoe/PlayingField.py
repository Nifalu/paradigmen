import re

 
# Initializes a new PlayingField with the Field and its win conditions
field = "         "
x_win = re.compile(r"^(X..X..X..)$|^(.X..X..X.)$|^(..X..X..X)$|^(XXX......)$|^(...XXX...)$|^(......XXX)$|^(X...X...X)$|^(..X.X.X..)$")
o_win = re.compile(r"^(O..O..O..)$|^(.O..O..O.)$|^(..O..O..O)$|^(OOO......)$|^(...OOO...)$|^(......OOO)$|^(O...O...O)$|^(..O.O.O..)$")
tie = re.compile(r"^([XO][XO][XO][XO][XO][XO][XO][XO][XO])$")

# Checks if field matches with a win conditon.
def isFinished():
    if bool(x_win.match(field)):
        return [True, 0] # player 0 wins
    elif bool(o_win.match(field)):
        return [True, 1] # player 1 wins
    elif bool(tie.match(field)):
        return [True, 2] # tie
    return[False, 0]

# Marks the cell i on the playing field with character c
def mark(i, c):
    global field
    field = field[:i] + c + field[i+1:]
    if c != " ":
        printcurrent()

# Checks if a cell is free
def isFree(i):
    return field[i] == " "

# empties the playing Field
def reset():
    global field
    field = "         " # <-- nine spaces

# prints the current playing field to the console
def printcurrent():
    print("\n" + field[0] + " | " + field[1] + " | " + field[2] + "\n--+---+--\n" +
        field[3] + " | " + field[4] + " | " + field[5] + "\n--+---+--\n"+
        field[6] + " | " + field[7] + " | " + field[8] + "\n")
    
