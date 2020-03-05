#include <iostream>
#include "NumberList.h"
#include "Student.h"
#include "GlobalFunctons.h"

using namespace std;

int main()
{
	int n;

	NumberList list;
	                   
	list.Init();

	list.Add(5);
	list.Add(2);
	list.Add(4);
	list.Add(1);
	list.Add(9);

	list.Print();

	list.Sort();

	list.Print();

	//----- student

	Student stud1, stud2;

	stud1.setName("Gigi");
	stud1.setMathsGrade(10);
	stud1.setEnglishGrade(6);
	stud1.setHistoryGrade(8);

	stud2.setName("Dany");
	stud2.setMathsGrade(9);
	stud2.setEnglishGrade(8);
	stud2.setHistoryGrade(8);

	cout << stud1.getName() << " are notele: " << stud1.getMathsGrade() << " " << stud1.getEnglishGrade() << " " << stud1.getHistoryGrade() << " si media: " << stud1.getAvg() << endl;
	cout << stud2.getName() << " are notele: " << stud2.getMathsGrade() << " " << stud2.getEnglishGrade() << " " << stud2.getHistoryGrade() << " si media: " << stud2.getAvg() << endl;

	//------ compare functions

	cout << compareName(stud1, stud2) << endl; //1
	cout << compareMathsGrade(stud1, stud2) << endl; //1
	cout << compareEnglishGrade(stud1, stud2) << endl; //-1
	cout << compareHistoryGrade(stud1, stud2) << endl; //0
	cout << compareAvg(stud1, stud2) << endl; //-1
	cin >> n;
}
