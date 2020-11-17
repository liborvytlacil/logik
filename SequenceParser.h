#pragma once

#include <vector>
#include <string>

/**
* Parses the given string into a vector of numbers. The string is iterated character by character, mapping
* '1' to number 1, '2' to number 2, etc. Spaces between digits are skipped.
* 
* For example, the string "1231" is parsed to a vector [1, 2, 3, 1] and "1 3  4  5" to [1, 3, 4, 5]
*/
std::vector<int> parseDigitSequence(const std::string& input);

/**
* Verifies, that the given integer vector is a valid game input. The input vector is valid
* if and only if the following holds:
* <ul>
*	<li>All elements of the vector are unique integers.</li>
*	<li>The length of the vector equals the expectedLength.</li>
*	<li>Each element is greater than 0 and less or equal to expectedMax</li>
* </ul>
* If the validation fails, the method throws an exception.
*/
void validateNumberSequence(const std::vector<int> &digitSequence, int expectedLength, int expectedMax);