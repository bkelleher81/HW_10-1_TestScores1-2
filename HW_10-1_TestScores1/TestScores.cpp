#include "TestScores.h"
#include<fstream>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

TestScores::TestScores()
{
	cout << "Constructor called" << endl;
}

TestScores::~TestScores() // Destructor deletes the memory allocated for the array
{
	cout << "Destructor called" << endl;
	if (testScore != nullptr) // Deallocate memory if it was allocated
		delete[] testScore;
}

void TestScores::readTestScores()
{
	cout << "Enter number of scores : \n";
	cin >> scoreCount;
	ifstream inFile;
	inFile.open("scores.txt");
	if (!inFile)
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		testScore = new string[scoreCount][3]; // Dynamically allocate memory for the 2D array
		for (int i = 0; i < scoreCount; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				inFile >> testScore[i][j];
			}
		}
	}
	inFile.close();
	sortScores();
	calcAverage();

}

void TestScores::sortScores()
{
	string temp;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (testScore[i][2] < testScore[j][2])
			{
				for (int k = 0; k < 3; k++)
				{
					temp = testScore[i][k];
					testScore[i][k] = testScore[j][k];
					testScore[j][k] = temp;
				}
			}
		}
	}
	displayScores();
}

void TestScores::displayScores()
{
	cout<< "List sorted by scores: \n";
	for (int i = 0; i < scoreCount; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << testScore[i][j] << " ";
		}
		cout << endl;
	}
}

void TestScores::calcAverage()
{
	double sum = 0;
	for (int i = 0; i < scoreCount; i++)
	{
		sum += stod(testScore[i][2]); // stod() used to convert a string to a double. It stands for "string to double". 
									  //It takes a string as an argument and returns its double representation.
	}
	average = sum / scoreCount;
	cout << "Average score is : " << average << endl;
}
