## Build instructions
You can build the project using Cmake version >=3.8. The build tested with with the following compilers and environments.
* msvc 19.27.29112 on Windows 10.
* gcc 9.3.0 on Ubuntu 20.04.1 LTS.

### Steps
* Navigate to the project root and run `cmake .`.
* Run `make`.
* `./Logik` is the executable of the game, while `test/LogikTest` runs unit tests.

## Game rules
Logik is a simple logic game. The computer generates a pseudo random sequence of 5 unique integers
from the set {1, 2, ..., 6}, e.g. '45312'.

Your goal is to guess the sequence. Each of your guesses is followed by a hint that informs you, which
numbers you guessed right. The hint is formed of the following symbols:
* M - You guessed a correct number at a correct position.
* O - You guessed a correct number, but at an incorrect position.
* X - You guessed an incorect number.

### Example
If the answer is '16423' and your guess is '15432', then the hint is 'MXMOO', because:
* You correctly guessed numbers 1 and 4 at correct position.
* You guessed number 5 incorrectly.
* You guessed 2 and 3 correctly, but at incorrect positions.
