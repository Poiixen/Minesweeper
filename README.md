# Minesweeper Project
Must be cloned or installed locally to run!  

<img width="636" alt="image" src="https://github.com/Poiixen/Minesweeper/assets/120151400/1aabc65e-5ff2-4be3-bfe2-d48ef4005063">


## Description

This is a Minesweeper project implemented using the SFML (Simple Fast Multimedia Library) bindings. Minesweeper is a classic single-player puzzle game where the player attempts to clear a board containing hidden mines without detonating any of them. The game involves revealing grid spaces and using numerical clues to determine the locations of mines.

## Rules Overview

The rules of the game are as follows:

- The game board consists of a grid of spaces, some of which contain mines.
- Clicking on a space reveals its content.
- If a revealed space contains a mine, the game ends.
- If a revealed space does not contain a mine, it displays the number of mines adjacent to it (ranging from 0 to 8).
- If a space has no adjacent mines, all adjacent non-mine spaces are also revealed.
- The objective is to reveal all non-mine spaces without detonating any mines.
- Right-clicking on a hidden space marks it as a possible mine with a flag. Flagged spaces cannot be revealed.
- The game provides a mine counter to track the number of mines on the board.
- The mine counter decreases when a flag is placed and increases when a flag is removed. It can go negative.
- The game includes a restart button to generate a new board with randomized mines.

## Non-standard Features

In addition to the standard Minesweeper features, this project includes some non-standard features:

- **Debug Button**: Toggles the visibility of mines on the board for testing and debugging purposes.
- **Test Buttons #1-3**: Load predefined board layouts for testing specific scenarios.

## Using SFML 

This project utilizes SFML bindings for graphics and multimedia functionalities. Compiling an application with SFML bindings may require initial setup but simplifies multimedia development once configured.

**Note**: Detailed instructions on setting up SFML bindings are beyond the scope of this README but can be found in SFML's official documentation, https://www.sfml-dev.org/ 

## How to run

In the terminal, using powershell (I believe bash works as well, not tested), compile the make file:  

>**mingw32-make**

After compiling, you should now see "main.exe", so to execute this file type the following into terminal:  

>**Cmd.exe /c main.exe**

NOTE: This program only works on Windows 10. (Windows 11 seems to show incompatibility issues)

## Credits

This project was created by Jorge Garcia.

## License

This project is licensed under the [MIT License](LICENSE).


### Enjoy playing Minesweeper!
