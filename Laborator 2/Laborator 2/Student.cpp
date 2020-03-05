#include "Student.h"
#include <string>

void Student::setName(string name)
{
	this->name = name;
}

string Student::getName()
{
	return this->name;
}

void Student::setMathsGrade(float grade)
{
	this->mathsGrade = grade;
}

float Student::getMathsGrade()
{
	return this->mathsGrade;
}

void Student::setEnglishGrade(float grade)
{
	this->englishGrade = grade;
}

float Student::getEnglishGrade()
{
	return this->englishGrade;
}

void Student::setHistoryGrade(float grade)
{
	this->historyGrade = grade;
}

float Student::getHistoryGrade()
{
	return this->historyGrade;
}

float Student::getAvg()
{
	return (this->mathsGrade + this->englishGrade + this->historyGrade)/3;
}