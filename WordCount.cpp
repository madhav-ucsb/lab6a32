// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(const std::string& word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	// STUB - your solution from Lab 5 goes here
	return -1;
}

int WordCount::getNumUniqueWords() const {
	// STUB - your solution from Lab 5 goes here
	return -1;
}

int WordCount::getWordCount(const std::string& word) const {
	// STUB - your solution from Lab 5 goes here
	return -1;
}
	
int WordCount::incrWordCount(const std::string& word) {
	// STUB - your solution from Lab 5 goes here
	return -1;
}

int WordCount::decrWordCount(const std::string& word) {
	// STUB - your solution from Lab 5 goes here
	return -2;
}


bool WordCount::isWordChar(char c) {
	// STUB - your solution from Lab 5 goes here
	return false;
}

std::string WordCount::makeValidWord(const std::string& word) {
	// STUB - your solution from Lab 5 goes here
	return "";
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	// STUB
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	// STUB
}

void WordCount::addAllWords(const std::string& text) {
	// STUB
}
