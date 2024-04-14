#pragma once
#include<string>
using namespace std;

class TestScores
{
private:
	int scoreCount = 0;
	string (*testScore)[3] = nullptr; // Pointer to a 2D array of strings
	double average = 0;
public:
	TestScores();
	~TestScores();
	void readTestScores();
	void sortScores();
	void displayScores();
	void calcAverage();
};
