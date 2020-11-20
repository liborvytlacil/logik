// Main.h
// Contains the game loop code.
//
// Author: Libor Vytlacil

#include <iostream>
#include <ctime>
#include "SequenceParser.h"
#include "Logik.h"

using namespace std;

char matchIndicatorToChar(MatchIndicator matchIndicator) {
	switch (matchIndicator) {
	case MatchIndicator::FULL_MATCH:
		return 'M';
	case MatchIndicator::OCCURENCE_MATCH:
		return 'O';
	default:
		return 'X';
	}
}

int main() {
	// constants that basically controls the difficulty
	const int max = 6;
	const int length = 5;

	// print intro message and instructions
	cout << "Welcome to Logik!" << endl;
	cout << "You need to guess a random sequence of " << length << " unique numbers out of the set "
		"{1, 2, ..., " << max << "}, e.g. 12345" << endl;
	cout << "Each guess is followed by a hint showing you how you guessed each number: " << endl;
	cout << "\t" << matchIndicatorToChar(MatchIndicator::FULL_MATCH) <<
		" - You guessed a correct number at a correct position." << endl;
	cout << "\t" << matchIndicatorToChar(MatchIndicator::OCCURENCE_MATCH) <<
		" - You guessed a correct number but at a wrong position." << endl;
	cout << "\t" << matchIndicatorToChar(MatchIndicator::NO_MATCH) <<
		" - You guessed an incorrect number." << endl;
	cout << "Example: " << endl << "Guess: " << "63125"<< endl << "Hint: XOOOM" << endl;
	cout << "**********************************************************" << endl << endl;


	// create a sequence to be guessed
	srand(time(nullptr));
	auto getRand = []() {return rand(); };
	std::vector<int> answer = createRandSeuqnce(length, max, getRand);

	// game-loop logic
	bool win = false;
	while (!win) {
		string input;
		cout << "Enter your guess: ";
		cin >> input;

		// parse, validate and evaluate the input, print a hint
		try {
			vector<int> guess = parseDigitSequence(input);
			validateNumberSequence(guess, length, max);
			vector<MatchIndicator> result = compareSequences(guess, answer);

			cout << "Hint: ";
			win = true;
			for (const MatchIndicator val : result) {
				if (val != MatchIndicator::FULL_MATCH) {
					win = false;
				}
				cout << matchIndicatorToChar(val);
			}
			cout << endl;
		}
		catch (parse_error&) {
			cout << "Cannot parse your input. Only enter a sequence of digits optionally "
				"separated by spaces." << endl;
		}
		catch (invalid_input&) {
			cout << "Invalid game input. Please provide a sequence of " << length << " unique digits "
				"from the range [1 .. " << max << "]" << endl;
		}
		catch (invalid_argument& ex) {
			cerr << "Internal error: " << ex.what() << endl;
			return 1;
		}
		cout << endl;
	}


	cout << "Congratulations, you have guessed the seqence!" << endl;
	return 0;
}