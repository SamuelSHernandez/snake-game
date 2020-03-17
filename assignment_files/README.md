# CPTR 142: Project III - ASCII Snake

This project is an ascii version of the classic Snake game. Click [here](https://www.google.com/search?q=snake+game&rlz=1C5CHFA_enUS726US726&oq=snake+game&aqs=chrome..69i57j0l7.2012j0j7&sourceid=chrome&ie=UTF-8) for a professional demo of the game.

Our game outputs an ascii game board to a .txt file that should be viewed while running the program (the program will prompt the user to open said text file part way through).

There are three difficulty levels that can be played - harder levels having a faster snake. Scores are then tracked for each level and a leaderboard with the 10 highest scores for the played level is displayed when the game is over.

## User Operation Instructions
* start by navigating the terminal to the src/main directory. 
* To start the program, run the command `g++ -pthread *.cpp && ./a.out` in the terminal.
    - The program will then prompt you to enter your name, which must be spelled the same way every time the user plays so scores can be properly tracked.
    - The user will then be prompted to enter a single ascii character to be used as the snake's "skin." If more than one character is entered, the first one is used as the snake's skin.
    - Lastly, the user is prompted to select a difficulty level. Easy is the slowest snake, Hard is the fastest snake.
* User should then open `Board.txt` in the src/main directory, which will have just been created.
* Navigate back to the terminal and press "enter".
* The snake is then moved by using the `w`, `a`, `s`, and `d` keys.
    - `w`: move snake up
    - `a`: move snake left
    - `s`: move snake down
    - `d`: move snake right
* The user should move the snake towards the fruit, which is displayed as a number.
    - the fruit's number is the score the player will achieve once their snake consumes it.
* The game is over once the snake hits a wall or its own body, and the score board will be displayed.

## Other Notes
* Score information is stored in .txt files in the storage directory. These files should not be edited manually as they are closely linked with one another. Editing one file without editing the corresponding piece in another file could result in segmentation faults.
* The name entered by the user at the beginning of the game can be a string of any length, but it is recommended that the user keep it to a single name rather than first name, last name. The string will be parsed, lowering all upper case letters and replacing spaces with under_scores. Periods and backwards slashes are not permitted in usernames.

## Known Bugs
* Every so often, the snake doesn't change directions when proper input is entered. The user will need to enter the desired input again to make the snake move. 
    - We believe this is a system problem and not caused by anything in our code. 
    - Occasionally this will cause a player to crash into a wall if they are trying to move right before a wall and the bug happens, but this is rare. Typically, this bug happesn towards the middle of the board.
