// SequenceParser.cpp
// Implementation of SequencecParser.h
//
// Author: Libor Vytlacil

#include "SequenceParser.h"
#include <stdexcept>
#include <set>

std::vector<int> parseDigitSequence(const std::string& input) {
	std::vector<int> result;
	for (size_t i = 0; i < input.length(); ++i) {
		int digit = 0;

		switch (input[i]) {
		case '1':
			digit = 1;
			break;
		case '2':
			digit = 2;
			break;
		case '3':
			digit = 3;
			break;
		case '4':
			digit = 4;
			break;
		case '5':
			digit = 5;
			break;
		case '6':
			digit = 6;
			break;
		case '7':
			digit = 7;
			break;
		case '8':
			digit = 8;
			break;
		case '9':
			digit = 9;
			break;
		case ' ':
			continue;
		default:
			throw parse_error{};
		}

		result.push_back(digit);
	}

	return result;
}

void validateNumberSequence(const std::vector<int>& digitSequence, size_t expectedLength, int expectedMax) {
	if (expectedLength < 0 || expectedMax < 0 || expectedLength > (size_t) expectedMax) {
		throw std::invalid_argument("Invalid arguments passed. Both expected length and max must be "
			"positive with the length smaller than the max");
	}

	if (digitSequence.size() != expectedLength) {
		throw invalid_input{};
	}

	std::set<int> encounteredNumbers;
	for (int number : digitSequence) {
		if (number <= 0 || number > expectedMax) {
			throw invalid_input{};
		}
		if (encounteredNumbers.find(number) != encounteredNumbers.cend()) {
			throw invalid_input{};
		}
		encounteredNumbers.insert(number);
	}
}