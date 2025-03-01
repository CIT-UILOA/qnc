# Queen Never Cry

> *Given a character array, see if any queen can capture the other queen...or something along those lines*

Given an 8x8 Board, this program checks to see if any queen
can capture another queen.

Input sample:

```txt
BQBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBQ
BBBBBBBB
BBBBBQBB
BBBBBBBB
```

Output:

```txt
0 BQBBBBBB
1 BBBBBBBB
2 BBBBBBBB
3 BBBBBBBB
4 BBBBBBBQ
5 BBBBBBBB
6 BBBBBQBB
7 BBBBBBBB
Safety status: WAR (Diagonal)
```

The queen on line 4 is in sight of the queen in ilne 6, which the checker sees as "war".

This code was made in response to a goofy CS problem for last year's UPC Programming competition, in order to prepare for this year's competition

## Building

This project requires CMake and some C compiler:
```sh
mkdir build
cd build
cmake ..
make
# Make sure that there's a file
# named `input` before running
# the binary
./queen
```
