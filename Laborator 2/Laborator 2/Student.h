#pragma once

#include <string>
using namespace std;

class Student
{
	string name;
	float mathsGrade;
	float englishGrade;
	float historyGrade;

public:
	void setName(string name);
	void setMathsGrade(float grade);
	void setEnglishGrade(float grade);
	void setHistoryGrade(float grade);

	string getName();
	float getMathsGrade();
	float getEnglishGrade();
	float getHistoryGrade();

	float getAvg();
};
