// Logik.h
// Contains definitions of methods for generating and comparing number sequences.
//
// Author: Libor Vytlacil

#pragma once

#include <iostream>
#include <vector>
#include <functional>

enum class MatchIndicator {
	NO_MATCH,
	OCCURENCE_MATCH,
	FULL_MATCH
};

/// <summary>
/// Creates a vector of size 'count' consisting of unique integers from the set {1, 2, ..., max}.
/// </summary>
/// <param name="count">size of the vector</param>
/// <param name="max">max number that can appear in the vector</param>
/// <param name="getRand">function that should return a non-negative integer
/// from a uniform distribution.</param>
/// <returns>created vector</returns>
std::vector<int> createRandSeuqnce(int count, int max, const std::function<int()>& getRand);

/// <summary>
/// Compares the given 'guess' vector with the given 'reference' vector.
/// </summary>
/// <param name="guess">guess vector</param>
/// <param name="reference">eference vector</param>
/// <returns>Vector of the same length as the input, where i th element is:
/// <ul>
/// <li>FULL_MATCH if guess[i] == reference[i]</li>
/// <li>OCCURENCE_MATCH if guess[i] != reference[i] and guess[i] == reference[j] for some i != j.</li>
/// </ul>
/// </returns>
std::vector<MatchIndicator> compareSequences(std::vector<int> guess, std::vector<int> reference);
