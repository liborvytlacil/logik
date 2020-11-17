#include "SequenceParser.h"
#include <stdexcept>

std::vector<int> parseDigitSequence(const std::string& input) {
	std::vector<int> result;
	for (int i = 0; i < input.length(); ++i) {
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
			throw std::invalid_argument("Cannot parse a character: " + input[i]);
		}

		result.push_back(digit);
	}

	return result;
}