#include "GlobalFunctons.h"

short compareName(Student s1, Student s2)
{
	if (s1.getName() == s2.getName())
		return 0;

	else if (s1.getName() > s2.getName())
		return 1;

	else if (s1.getName() < s2.getName())
		return -1;

	return 2;
}

short compareMathsGrade(Student s1, Student s2)
{
	if (s1.getMathsGrade() == s2.getMathsGrade())
		return 0;

	if (s1.getMathsGrade() > s2.getMathsGrade())
		return 1;

	if (s1.getMathsGrade() < s2.getMathsGrade())
		return -1;

	return 2;
}

short compareEnglishGrade(Student s1, Student s2)
{
	if (s1.getEnglishGrade() == s2.getEnglishGrade())
		return 0;

	if (s1.getEnglishGrade() > s2.getEnglishGrade())
		return 1;

	if (s1.getEnglishGrade() < s2.getEnglishGrade())
		return -1;

	return 2;
}

short compareHistoryGrade(Student s1, Student s2)
{
	if (s1.getHistoryGrade() == s2.getHistoryGrade())
		return 0;

	if (s1.getHistoryGrade() > s2.getHistoryGrade())
		return 1;

	if (s1.getHistoryGrade() < s2.getHistoryGrade())
		return -1;

	return 2;
}

short compareAvg(Student s1, Student s2)
{
	if (s1.getAvg() == s2.getAvg())
		return 0;

	if (s1.getAvg() > s2.getAvg())
		return 1;

	if (s1.getAvg() < s2.getAvg())
		return -1;

	return 2;
}