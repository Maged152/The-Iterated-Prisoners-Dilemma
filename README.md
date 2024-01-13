# The Prisoner's Dilemma Game

## Introduction
Welcome to the implementation of Axelrod's Iterated Prisoner's Dilemma Tournament! This repository contains the code (in C++) for simulating and participating in the famous Axelrod's Iterated Prisoner's Dilemma (IPD) Tournament. The tournament is a classic example in game theory, where participants (strategies) compete against each other in a series of repeated prisoner's dilemma games.

## Prerequisites and building
The only prerequisites for library are CMake 3.22+ and a C++20 (and MinGW if you are going to use makefile)
compiler.

Building:

    $ mkdir build
    $ cd build
    $ cmake .. -G"MinGW Makefiles" # or use ony generator you want
    $ make shakhbat_pd_lib

After a successful compilation The library should reside in `./lib` directory as `libshakhbat_pd_lib.a`. 

Use this command to copy the static library and include headers in the `package` folder.

    $ make install

In the `package` folder will be `libshakhbat_pd_lib.a` and `include` folder.

You need to include `include\shakhbat_pd.hpp` and static link `libshakhbat_pd_lib.a` into your project.

Running :

    $ make play

This will link (and build if not builded) the library with `play.cpp`, and produce `play.exe` which you can run

## Running the Tournament
To run the Axelrod's Iterated Prisoner's Dilemma Tournament

## Adding Your Strategy
To add your own strategy to compete in the tournament, follow these steps:

* Write your strategy as a class publicly internets from `Strategy` and place the declaration in `strategies.hpp`
* If you only need the constructor, `FirstAction`, and `Action` function to be written (most probably), then use this macro
    - DECLARE_STRATEGY(MyStrategy);
* In the constructor you initialize the information of your strategy : `name`, `info`, `properties`.
* The `FirstAction` will be called when your strategy starts first.
* The `Action` is your action function and will take the opponent action as input and you access the history of actions.
* you can use this function ` void UpdateHistory(const Choice my_play, const Choice opponent_play)` to update history inside `Action` function.
* Make CPP file with your class name `MyStrategy.cpp` inside `source/strategies` and write  the implementation there.

## Contributing
If you would like to contribute to this project, please fork the repository, make your changes, and submit a pull request. Contributions are welcome!

## Acknowledgments
Axelrod, r. (1980a). effective choice in the prisoner’s dilemma