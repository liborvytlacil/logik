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

template <typename T> string stringifyVector(const vector<T>& vec) {
	string result = "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		result += to_string((int)vec[i]);
		result += ", ";
	}
	result += "]";
	return result;
}

void assertEquals(const vector<int>& expected, const vector<int>& actual) {
	if (expected != actual) {
		throw test_assert_error("Vectors are not equal: " + stringifyVector(expected) +
			" != " + stringifyVector(actual));
	}
}

void assertEquals(const vector<MatchIndicator>& expected, const vector<MatchIndicator>& actual) {
	if (expected != actual) {
		throw test_assert_error("Vectors are not equal: " + stringifyVector(expected) +
			" != " + stringifyVector(actual));
	}
}

void assertParseDigitThrows(const string& input) {
	try {
		parseDigitSequence(input);
	}
	catch (invalid_argument&) {
		return;
	}
	throw test_assert_error("Parsing did not throw an invalid argument exception: " + input);
}

void assertSequenceComparisonThrows(const vector<int>& arg1, const vector<int>& arg2) {
	try {
		compareCombinations(arg1, arg2);
	}
	catch (invalid_argument&) {
		return;
	}
	throw test_assert_error("Sequence comparison did not throw an invalid argument exception. Input: " +
		stringifyVector(arg1) + ", " + stringifyVector(arg2));
}

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

void testSequenceComparison() {
	vector<int> arg1 = { 1, 2, 4, 7 };
	vector<int> arg2 = { 1, 2, 4, 7 };
	vector<MatchIndicator> expected = { MatchIndicator::FULL_MATCH, MatchIndicator::FULL_MATCH,
		MatchIndicator::FULL_MATCH, MatchIndicator::FULL_MATCH };
	assertEquals(expected, compareCombinations(arg1, arg2));

	arg1 = { 1, 2, 4, 7 };
	arg2 = { 2, 1, 4, 6 };
	expected = { MatchIndicator::OCCURENCE_MATCH, MatchIndicator::OCCURENCE_MATCH,
		MatchIndicator::FULL_MATCH, MatchIndicator::NO_MATCH };
	assertEquals(expected, compareCombinations(arg1, arg2));

	arg1 = { 1, 2, 3, 4 };
	arg2 = { 1, 2, 3, 4, 5 };
	assertSequenceComparisonThrows(arg1, arg2);
	assertSequenceComparisonThrows(arg2, arg1);
}

int main() {
	// TODO
	try {
		testSequenceParsing();
		testSequenceComparison();
		cout << "PASS";
	}
	catch (test_assert_error& ex) {
		cout << "FAIL: " << endl;
		cout << ex.getMessage() << endl;
	}
}