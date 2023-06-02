# cparse


## Description

Human-readable command-line argument parser adhering to UNIX `getopt`.

C++ equivalent to my previous `rparse` and `lparse`.

**I'm working on making this C compatible.**

Written in C++.


## Compiling

N/A.


## Usage

```
#include "cparse.h"


int main(int argc, char **argv) {
    Argument one;
    one.init("foo", 'f', "lol");
    Argument two;
    two.init("bar", 'b', "bar");
    vector<Argument> arguments = {one, two};

    map<string, string> returned = parse_arguments(arguments, argc, argv);

    cout << "Foo: " << returned[one.arg_long] << "\n";
    cout << "Bar: " << returned[two.arg_long] << "\n";
    return 0;
}
```


## Alternative Implementation

`alt_cparse.h` is an alternative, non-OOP approach to parsing command-line
arguments, using a 2D vector.

Usage:

```
#include "alt_cparse.h"


int main(int argc, char **argv) {
    array2d_t arguments = {
        build_argument("foo", "f", "foo"),
        build_argument("bar", "b", "bar")
    };

    map<string, string> returned = parse_arguments(arguments, argc, argv);

    cout << "1: " << returned["foo"] << "\n";
    cout << "2: " << returned["bar"] << "\n";
}
```
