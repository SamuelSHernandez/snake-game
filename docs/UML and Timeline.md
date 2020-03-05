---
layout: page
title: /UML and Timeline
permalink: /UML/
---

# CPTR 142: Project #3

To see classes, flow diagram, challenges, and team management, click <a href="https://gitlab.cs.wallawalla.edu/irvilu/team-6---cptr142-project-3/raw/master/docs/project_planning.pdf">here</a>

## UML Diagrams
|Class Game   	|
|----------	|
|+Game()  	|
|+gameLoop()   	|
|+getMapWidth() const: int |
|+getMapHeight() const: int |
|+setGameDifficulty(choice: int) |
|+render() 	|
|+decrementArray(): void |
|-mapWidth |
|-mapHeight |
|-gameFruit: Fruit |
|-gameSnake: Snake |
|-gamePlayer: Player |
|-gameDifficulty: enum level |
|-board: char[][] |

-
-
-

|Class Fruit |
|----------- |
|+Fruit() |
|+getPosition() const: struct Point |
|+setPosition(&myGame: const Game) |
|+spawnFruit(&myGame: const Game) |
|+removeFruit(&myGame: const Game) |
|-position: struct Point |

-
-
-

|Class Player |
|------------ |
|+Player() |
|+getName() const: string |
|+setName(name: string) |
|+getAsciiChar(): char |
|+setAsciiChar(asciiChar: char) |
|+getHighScore() const: int |
|+setHighScore(score: int) |
|-name: string |
|-score: int |
|-asciiChar: char |
|-snake: Snake |

-
-
-

|Class Snake |
|----------- |
|+Snake() |
|+Snake(ascii: char, direction: enum Compass, position: structPoint) |
|+move() |
|+changeDirection(direction: enum Compass) |
|+lengthen() |
|+returnHead(): struct Point |
|+getLength(): int <br> - returns the snake's length member variable |
|-length: int |
|-direction: enum Compass |
|-headPosition: struct Point |
|-ascii: char |

-
-
-

# Timeline

Timeline:

Phase 1
- Due Feb 24
- Set up classes with function prototypes
- Assignments:
	- Luke: Set up basic tests for mutators and accessors
	- Hayden: Player prototypes 
	- Stefan: Game prototypes
	- Sam: Fruit and Snake prototypes

Phase 2
- Due Feb 28
- Build empty board
- Render (print) board
	- Start with terminal/txt file
		- Txt file if it updates dynamically
	- Move on to web 
- Get snake of fixed length moving across board
- Change direction of snake with keys
	- Have it wrap around
- Assignments:
	- Luke: more unit tests
		- Also game loop
	- Hayden: Directions
	- Stefan: Snake
	- Sam: Print Board

Phase 4
- Due March 2
- Add fruit
	- Generate randomly across board
- Make fruit change size of Snake

Phase 5
- Due March 6
- End game if snake hits walls or itself

Phase 6
- Due March 9
- Output score to file
- Read high score from file

Phase 7
- DEBUG/slush time
- Due March 16
