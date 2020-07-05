# The Working Saturday

## CS 224 Object Oriented Programming and Design Methodologies: Final Project

## Team Members

- Maheen Anees (Group Leader)
- Muhammad Salman Abid
- Sara Mahmood
- Uzair Khoso

## About

### Game Description:
Habib University is attacked by some enemies on a Saturday afternoon. You are required to save the university by defeating all the enemies located at Central Street and the Fire Courtyard. You lose HP on collision with enemy so you have to be careful.If you are able to defeat all the enemies before you run out of health, you win the game. Otherwise, you lose. 

### Game Controls:
- Arrow key for moving the player in four directions.
- Press P for pause and unpause.
- Press A to attack the enemy.

### Project Playlist Link:
https://www.youtube.com/playlist?list=PLMtDE6PfhEO7V0w16MwKFzBdHd1cbgkPK

### Additional packages:
 - Additional packages needed are SDL_Image and SDL_TTF.


### Total time spent:
 -75 hours.

## Requirements
### Technical Requirements
- __Polymorphism__:
  - The GameObject class is the base class for all objects. It has attributes catering to rendering on the screen and SDL_Rects for          source and destination. 

- __Design Patterns__:
  - Singleton:
     -Game class satisfies the singleton design pattern. A static instance is created initially , and the game object can only be             accessed through a get_instance() function. The constructor for the Game class is private.
  - Factory:
    -The IngameScreen class is used to create seperate rooms. A factory provides a functional room pointer, and only takes in a room          type.
    -The Enemy Factory also provides a relevant enemy pointer, and takes in only a string containing enemy type.
    
  - Template:
    -The template pattern is used when the Player and Enemy (hence also its 2 child classes) override methods for the Character class.        Each child class has its own movement method implemented and overrides the methods provided in parent classes. The Player class           also implements its additional deconstructor for attacking frames.     
  
  - Strategy:
    -The strategy pattern is used when only the direction attribute of the Player is changed upon user input. The function for                movement() is called every iteration without any parameters and internally implements different movement depending on what              direction is specified.  
  
      
- __Menu with Buttons__:
  - Start Screen with new game and quit button.

- __File I/O__:
  - Each time the player plays the game, its score is compared with the highscore saved in `scorefile.txt`. If the current score is         greater than the previously saved highscore, it is replaced and a corresponding screen is shown.
  - Score file is used to print highscore on the start screen.

- __Operator Overloading__:
  - The IngameScreen class (for each room in-game) has overloaded the '<<' operator to output the screen name whenever required for         identification and output to console for debugging.

## Contributions
__Maheen Anees__:
  - Apart from the leader responsibilities, she worked mainly on the startScreen, endMenu and pause classes as highlighted in the UML.
  - She also worked on the screen transitioning from the start to the ingame screen and file i/o along with Sara and Salman.
  - She also worked on designing the buttons and screens.
  
__Sara Mehmood__:
  - Sara Implemented score, file I/O and SDL_ttf rendering on screen.
  - She also worked on designing the buttons adding appropriate score figures from file to the screen and updating them each loop.
  - Worked on pause functionality, end game screen and worked on final UML on code integration along with leader.
  
__Muhammad Salman Abid__:
  - Salman worked on the Character class as well as player and enemy class inheriting from it. Added player health, attack, movement as     well as enemy pre-set movement pattern.
  - He desgined the game.cpp file to create a temporary container to hold each screen from the screens vector and render on screen for      in-game room transitions and to move player from one screen to another.
  - Worked on GameObject Class to enable rendering for each in-game object.
  

__Uzair Khoso__:
  - Worked on game design, as well as creating sprites and animation sprites for rooms, obstacles and enemies.


## Acknowledgments
 - https://www.youtube.com/playlist?list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx
