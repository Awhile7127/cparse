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
    one.init("foo", 'f');
    Argument two;
    two.init("bar", 'b');
    vector<Argument> returned = {one, two};

    cout << "Foo: " << returned[one.arg_long] << "\n";
    cout << "Bar: " << returned[two.arg_long] << "\n";
    return 0;
}
```
