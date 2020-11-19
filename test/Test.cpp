// Test.cpp
// A batch of unit tests with its own main() function that runs the tests.
//
// Author: Libor Vytlacil

#include "../SequenceParser.h"
#include "../Logik.h"
#include <iostream>
#include <algorithm>

using namespace std;

class test_assert_error {
private:
	string message;

public:
	test_assert_error(string message)
		:message(message) { }

	const string& getMessage() const {
		return message;
	}
};

// Gets a string represenation of a vector
template <typename T> string stringifyVector(const vector<T>& vec) {
	string result = "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		result += to_string((int)vec[i]);
		result += ", ";
	}
	result += "]";
	return result;
}

// Asserts an equality of two vectors
template <typename T> void assertEquals(const vector<T>& expected, const vector<T>& actual) {
	if (expected != actual) {
		throw test_assert_error("Vectors are not equal: " + stringifyVector(expected) +
			" != " + stringifyVector(actual));
	}
}

// Asserts that parsing throws an exception
void assertParseDigitThrows(const string& input) {
	try {
		parseDigitSequence(input);
	}
	catch (parse_error&) {
		return;
	}
	throw test_assert_error("Parsing did not throw an invalid argument exception: " + input);
}

// Asserts that sequence comparsion throws an exception
void assertSequenceComparisonThrows(const vector<int>& arg1, const vector<int>& arg2) {
	try {
		compareSequences(arg1, arg2);
	}
	catch (invalid_argument&) {
		return;
	}
	throw test_assert_error("Sequence comparison did not throw an invalid argument exception. Input: " +
		stringifyVector(arg1) + ", " + stringifyVector(arg2));
}

// Asserts that an input validation succeeds.
void assertSuccesfulInputValidation(const vector<int>& vec, int length, int max) {
	try {
		validateNumberSequence(vec, length, max);
	}
	catch (invalid_input&) {
		throw test_assert_error("Input was considered invalid: " + stringifyVector(vec) + ", length: " +
			to_string(length) + ", max:" + to_string(max));
	}
}

// Tests sequence parsing
void testSequenceParsing() {
	vector<int> expected = { 1, 1, 1, 1 };
	vector<int> actual = parseDigitSequence("1111");
	assertEquals(expected, actual);

	expected = {};
	actual = parseDigitSequence("");
	assertEquals(expected, actual);

	expected = { 1, 2, 3, 4, 3 };
	actual = parseDigitSequence("12343");
	assertEquals(expected, actual);

	expected = { 9, 8, 7, 6, 5, 9 };
	actual = parseDigitSequence(" 9 8  7    6 5 9  ");
	assertEquals(expected, actual);

	assertParseDigitThrows("x123");
	assertParseDigitThrows("1203");
}

// Tests seqence comparison
void testSequenceComparison() {
	vector<int> arg1 = { 1, 2, 4, 7 };
	vector<int> arg2 = { 1, 2, 4, 7 };
	vector<MatchIndicator> expected = { MatchIndicator::FULL_MATCH, MatchIndicator::FULL_MATCH,
		MatchIndicator::FULL_MATCH, MatchIndicator::FULL_MATCH };
	assertEquals(expected, compareSequences(arg1, arg2));

	arg1 = { 1, 2, 4, 7 };
	arg2 = { 2, 1, 4, 6 };
	expected = { MatchIndicator::OCCURENCE_MATCH, MatchIndicator::OCCURENCE_MATCH,
		MatchIndicator::FULL_MATCH, MatchIndicator::NO_MATCH };
	assertEquals(expected, compareSequences(arg1, arg2));

	arg1 = { 1, 2, 3, 4 };
	arg2 = { 1, 2, 3, 4, 5 };
	assertSequenceComparisonThrows(arg1, arg2);
	assertSequenceComparisonThrows(arg2, arg1);
}

// Test input validation
void testInputValidation() {
	vector<int> arg = { 1, 4, 2, 5 };
	assertSuccesfulInputValidation(arg, 4, 5);
	assertSuccesfulInputValidation(arg, 4, 8);
}

int main() {
	try {
		testSequenceParsing();
		testSequenceComparison();
		testInputValidation();
		cout << "PASS" << endl;
	}
	catch (test_assert_error& ex) {
		cout << "FAIL: " << endl;
		cout << ex.getMessage() << endl;
	}
	catch (exception&) {
		cout << "FAIL: Unexpected exception caught." << endl;
		return 1;
	}

	return 0;
}