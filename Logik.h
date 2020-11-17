// Logik.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>

enum class MatchIndicator {
	NO_MATCH,
	OCCURENCE_MATCH,
	FULL_MATCH
};

/**
* Creates a vector of size 'count' with unique integers from the set {1, 2, ..., max}.
*/
std::vector<int> createCombination(int count, int max);

/**
* Compares the given guess vector with the given reference vector.
* 
* @returns a vector of the same size as the input vectors, whose i-th element is:
* FULL_MATCH if guess[i] == reference[i]
* OCCURENCE_MATCH if guess[i] != reference[j] and guess[i] == reference[j] for some i != j
* NO_MATCH otherwise
*/
std::vector<MatchIndicator> compareCombinations(std::vector<int> guess, std::vector<int> reference);


class Sequence {
private:
	void set(int i);
public:
	int get(int i);

};

class ComparisonResult {

};

/**
* Represents 
*/
class GameDirector {
private:
	int linelength;
	int maxValue;

public:
	GameDirector(int linelength, int maxValue) :
		linelength(linelength), maxValue(maxValue) {}

	Sequence createLine() const;

	Sequence fromIntVector(const std::vector<int>& vec) const;

	ComparisonResult compareLines(Sequence& line, Sequence& otherLine) const;
};