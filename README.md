# Minesweeper Project

<img width="636" alt="image" src="https://github.com/Poiixen/Minesweeper/assets/120151400/1aabc65e-5ff2-4be3-bfe2-d48ef4005063">


## Description

This is a Minesweeper project implemented using TypeScript and the SFML (Simple Fast Multimedia Library) bindings. Minesweeper is a classic single-player puzzle game where the player attempts to clear a board containing hidden mines without detonating any of them. The game involves revealing grid spaces and using numerical clues to determine the locations of mines.

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

## Using TypeScript with SFML Bindings

This project utilizes TypeScript with SFML bindings for graphics and multimedia functionalities. Compiling an application with SFML bindings may require initial setup but simplifies multimedia development once configured.

**Note**: Detailed instructions on setting up TypeScript with SFML bindings are beyond the scope of this README but can be found in SFML's official documentation.

Enjoy playing Minesweeper!
