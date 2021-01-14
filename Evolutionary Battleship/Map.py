import pygame
import numpy as np
import Battleship

# Creates and runs the visual display, to increase or decrease the speed
# Change the FPS in line 36 or the wait in line 158
# To increase or decrease the amount of gamers displayed change the variable
# on line 12

pygame.init()
pygame.font.init()
DISPLAY_GAMERS = 1  # Increase to change the amount of gamers displayed on board

BLACK = (0, 0, 0, 250)
WHITE = (255, 255, 255)  # Color of misses
BLUE = (0, 0, 255)  # Initial board
RED = (255, 0, 0)  # Color of hits

# colors of ships
S2 = (32, 32, 32)
S3 = (64, 64, 64)
S32 = (96, 96, 96)
S4 = (128, 128, 128)
S5 = (160, 160, 160)

# This sets the WIDTH and HEIGHT of each grid location, and space between grids
GRIDX = 40
GRIDY = 40
gridCount = 10
RADIUS = 10

WINDOWX = 455
WINDOWY = 550
SPACING = 5

FPS = 100
WINDOW = [WINDOWX, WINDOWY]
screen = pygame.display.set_mode(WINDOW)

grid = []
board = np.full((10, 10), 0)
#set = Battleship.Gamer()


def initGrid():
    for row in range(gridCount):
        # Add an empty array that will hold each cell
        # in this row
        grid.append([])
        for column in range(gridCount):
            grid[row].append(0)  # Append a cell


def set_board2(boards):
    for row in range(0,10):
        for column in range(0, 10):
            board[row][column] = boards[row][column]


def print_board():
    for row in range(0, 10):
        for column in range(0, 10):
            print(board[row][column]),
        print


def is_ship(row, column):
    if board[row][column] != 0:
        return board[row][column]
    return board[row][column]


def draw_hits(gamer):
    circle_surface = pygame.Surface((50,50), pygame.SRCALPHA)
    pygame.draw.rect(circle_surface, BLACK, circle_surface.get_rect(), 10)
    for gamer_column in range(0, 17):
        x = gamer.hits[gamer_column].coordinate[0]
        y = gamer.hits[gamer_column].coordinate[1]
        if board[x][y] != 0:
            gridColor = RED
        else:
            gridColor = WHITE
        pygame.draw.circle(screen, gridColor,
                           [(SPACING + GRIDX) * y + SPACING * 5,
                            (SPACING + GRIDY) * x + SPACING * 5],
                           RADIUS)


def drawGrid():
    test_val = 0
    for row in range(0, 10):
        for column in range(0, 10):
            test_val = is_ship(row, column)
            if test_val == 1:
                gridColor = S32
            elif test_val == 2:
                gridColor = S2
            elif test_val == 3:
                gridColor = S3
            elif test_val == 4:
                gridColor = S4
            elif test_val == 5:
                gridColor = S5
            else:
                gridColor = BLUE
            pygame.draw.rect(screen, gridColor,
                             [(SPACING + GRIDX) * column + SPACING,
                              (SPACING + GRIDY) * row + SPACING,
                              GRIDX,
                              GRIDY])


def drawGen(num):
    myfont = pygame.font.SysFont('sitkasmallsitkatextbolditalicsitkasubheadingbolditalicsitkaheadingbolditalicsitkadisplaybolditalicsitkabannerbolditalic', 45)
    textsurface = myfont.render('Generations: ' + str(num), True, (255, 255, 255))
    screen.blit(textsurface, (0,450))


def drawGamer(num):
    myfont = pygame.font.SysFont('sitkasmallsitkatextbolditalicsitkasubheadingbolditalicsitkaheadingbolditalicsitkadisplaybolditalicsitkabannerbolditalic', 40)
    textsurface = myfont.render('Completed: ' + str(num) + ' / ' + str(Battleship.POP_SIZE), True, (255, 255, 255))
    screen.blit(textsurface, (0 ,500))


pygame.display.set_caption('Battleship')
temp = Battleship.init_gamers()
Battleship.print_gamers(temp)
Battleship.set_board()
set_board2(Battleship.get_board())
drawGrid()


# Loop until the user clicks the close button.
done = False
check = False
check_all = False
counter = 0
complete = 0

#for adjusting FPS
clock = pygame.time.Clock()

while not done:
    clock.tick(FPS)
    pygame.display.flip()
    for event in pygame.event.get():  # User did something
        if event.type == pygame.QUIT:  # If user clicked close
            done = True  # Flag that we are done so we exit this loop
    for i in range(0, DISPLAY_GAMERS):
        draw_hits(temp[i])
        pygame.display.flip()
    temp = Battleship.do_gen(temp)
    counter += 1
    screen.fill(BLACK)
    drawGrid()
    drawGen(counter)
    drawGamer(Battleship.check_completed(temp))
    #pygame.time.wait(100)
    if not check:
        check = Battleship.check_first(temp)
        if check:
            print("The first generation to complete is " + str(counter))
    check_all = Battleship.check_all(temp)
    if check_all:
        print("All gamers completed on generation " + str(counter))
        Battleship.print_gamers(temp)
        while not done:
            for i in range(0, DISPLAY_GAMERS):
                draw_hits(temp[i])
                pygame.display.flip()
            for event in pygame.event.get():  # User did something
                if event.type == pygame.QUIT:  # If user clicked close
                    done = True  # Flag that we are done so we exit this loop

