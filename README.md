# The Prisoner's Dilemma Game

## Introduction
Welcome to the implementation of Axelrod's Iterated Prisoner's Dilemma Tournament! This repository contains the code (in C++) for simulating and participating in the famous Axelrod's Iterated Prisoner's Dilemma (IPD) Tournament. The tournament is a classic example in game theory, where participants (strategies) compete against each other in a series of repeated prisoner's dilemma games.

## Prerequisites and building
The only prerequisites for library are CMake 3.22+ and a C++20
compiler.

Building:

    $ mkdir build
    $ cd build
    $ cmake .. -G"MinGW Makefiles" # or use ony generator you want
    $ make -j

After a successful compilation The library should reside in `./lib` directory as `libshakhbat_pd_lib.a`. 

Use this command to copy the static library and include headers in the `package` folder.

    $ make install

In the `package` folder will be `libshakhbat_pd_lib.a` and `include` folder.

You need to include `include\shakhbat_pd.hpp` and static link `libshakhbat_pd_lib.a` into your project.


## Running the Tournament
To run the Axelrod's Iterated Prisoner's Dilemma Tournament

## Adding Your Strategy

## Contributing
If you would like to contribute to this project, please fork the repository, make your changes, and submit a pull request. Contributions are welcome!

## Acknowledgments
Axelrod, r. (1980a). effective choice in the prisoner’s dilemma