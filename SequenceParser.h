// Sequence.h
// Contains definitions of methods for parsing the player's input.
//
// Author: Libor Vytlacil

#pragma once

#include <vector>
#include <string>

/// <summary>
/// Indicates a parsing error.
/// </summary>
class parse_error : public std::invalid_argument {
};

/// <summary>
/// Indicates an invalid input, e.g. correctly parsed one that did not meet requirements like length etc..
/// </summary>
class invalid_input : public std::domain_error {
};

/// <summary>
/// Parses the given string into a vector of numbers. The string is iterated character by character, mapping
/// '1' to number 1, '2' to number 2 etc. Spaces are ignored.
/// </summary>
/// <param name="input">input string to parse</param>
/// <returns>vector of parsed digits. Throws parse_error when encountering an invalid character.</returns>
std::vector<int> parseDigitSequence(const std::string& input);

/// <summary>
/// Verifies, that the given integer vector is a valid game input. The input vector is valid if and only if
/// the following holds:
/// <ul>
/// <li>All elements of the vector are unique integers.< / li>
/// <li>The length of the vector equals the expectedLength.< / li>
/// <li>Each element is greater than 0 and less or equal to expectedMax< / li>
/// <ul>
/// </summary>
/// <param name="digitSequence">sequence to validate</param>
/// <param name="expectedLength">expected length of the sequence.</param>
/// <param name="expectedMax">max number expected in the sequence.</param>
/// <returns>void with no side effects on succes, otherwise throws invalid_input.</returns>
void validateNumberSequence(const std::vector<int> &digitSequence, size_t expectedLength, int expectedMax);