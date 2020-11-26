// Logik.cpp
// Implementation of Logik.h
//
// Author: Libor Vytlacil

#include "Logik.h"
#include <algorithm>
#include <functional>

using namespace std;

std::vector<int> createRandSeuqnce(int count, int max, const std::function<int()> &getRand) {
	if (count < 1 || max < 1 || count > max) {
		throw std::invalid_argument("Both count and max must be positive and count <= max");
	}

	// initialize result to [1, 2, ..., max]
	std::vector<int> result;
	for (int i = 0; i < max; ++i) {
		result.push_back(i + 1);
	}

	// make a permutation of the vector
	for (int i = 0; i < max; ++i) {
		// getRand() % (max - i) generates a pseudorandom number from 0 to max - i - 1.
		// This simple approach might introduce a slight bias.
		int swapIndex = i + (getRand() % (max - i));
		int temp = result[i];
		result[i] = result[swapIndex];
		result[swapIndex] = temp;
	}

	// max - count = the number of elements we need to remove to match the expected size of the result
	for (int i = 0; i < max - count; ++i) {
		result.pop_back();
	}
	return result;
}

std::vector<MatchIndicator> compareSequences(std::vector<int> guess, std::vector<int> reference) {
	if (guess.size() != reference.size()) {
		throw std::invalid_argument("Both input vectors must be of the same size.");
	}

	std::vector<MatchIndicator> result;
	for (size_t i = 0; i < guess.size(); ++i) {
		if (guess[i] == reference[i]) {
			result.push_back(MatchIndicator::FULL_MATCH);
		}
		else if (std::find(reference.cbegin(), reference.cend(), guess[i]) != reference.cend()) {
			result.push_back(MatchIndicator::OCCURENCE_MATCH);
		}
		else {
			result.push_back(MatchIndicator::NO_MATCH);
		}
	}
	return result;
}
