# Typing Test Game (C language)
## Building the Project with CMake
## Project Description

This is a C project that includes multiple files and dependencies. This is a game that will allow you to check the typing speed. Installation and startup instructions are given below.

## Dependencies

To build the project, you need to install the following dependencies:
* CMake
* C Compiler (e.g. GCC)
* Library <windows.h> for C

## Cloning the Repository

Before starting the build process, you need to clone the repository to your local computer

``` git clone https://github.com/andreu5547/Typing_Test_Game_C.git ```

## Building the Project with CMake
1. Navigate to the root directory of the project:
```cd Typing_Test_Game_C```
2. Create a "build" directory:
```mkdir build```
3. Navigate to the "build" directory:
```cd build```
4. Generate the project files with CMake:
```cmake ..```
5. Build the project:
```cmake --build .```
6. Profit
## Run game
* Usage: ```typing-speed-test <difficulty> <time_limit> <error_limit>```
* Arguments:
  1. \<difficulty>: Difficulty level of the test. Can be 'easy', 'medium', or 'hard'.
  2. \<time_limit>: Time limit in seconds. Must be a positive integer.
  3. \<error_limit>: Error limit. Must be a positive integer.
* Example: ```typing-speed-test medium 60 5```