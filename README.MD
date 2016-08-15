Tote Betting Totalisator [![Build Status](https://travis-ci.org/ben-crowhurst/tote-betting-totalisator.svg?branch=master)](https://travis-ci.org/ben-crowhurst/tote-betting-totalisator)
========================================================================================================================================================================================

License
-------

The project is licensed under the terms of the MIT open source software license; See [LICENSE](LICENSE) for full details.

Build
-----

```bash
git clone --recursive https://github.com/ben-crowhurst/tote-betting-totalisator
mkdir tote-betting-totalisator/build
cd tote-betting-totalisator/build
cmake  ..
make install
make test
```

You will now find all required components installed in the distribution folder.

Please submit enhancements, proposals, and defects via the [issue](http://github.com/corvusoft/restbed/issues) tracker; Alternatively ask a question on [StackOverflow](http://stackoverflow.com/questions/ask) tagged [#restbed](http://stackoverflow.com/questions/tagged/restbed).

Example
-------

Here is sample data.txt file for a given race. This is what the program should receive on stdin:

```
Bet:W:1:3
Bet:W:2:4
Bet:W:3:5
Bet:W:4:5
Bet:W:1:16
Bet:W:2:8
Bet:W:3:22
Bet:W:4:57
Bet:W:1:42
Bet:W:2:98
Bet:W:3:63
Bet:W:4:15
Bet:P:1:31
Bet:P:2:89
Bet:P:3:28
Bet:P:4:72
Bet:P:1:40
Bet:P:2:16
Bet:P:3:82
Bet:P:4:52
Bet:P:1:18
Bet:P:2:74
Bet:P:3:39
Bet:P:4:105
Result:2:3:1
```

```
./totalisator < data.txt
```

And this is output on stdout showing the dividends for the supplied race data:

```
Win:2:$2.61
Place:2:$1.06
Place:3:$1.27
Place:1:$2.13
```

Minimum Requirements
--------------------

| Resource | Requirement                  |
|:--------:|:----------------------------:|
| Compiler |   C++11 compliant or above   |
|    OS    | BSD, Linux, Mac OSX, Windows |

Road Map
--------

| Milestone | Feature                  | Status   |
|:---------:|:------------------------:|:--------:|
|    1.0    | Funcationing Totalisator | complete |
