#include "Number.h"
#include <iostream>

using namespace std;

int main()
{
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("FFA", 16);

	cout << "n1 din bin in dec:"<<endl;
	n1.SwitchBase(10);
	n1.Print();
	cout << endl;

	cout << "n1 din dec in bin:" << endl;
	n1.SwitchBase(2);
	n1.Print();
	cout << endl;
	
	cout<< "n1 has " << n1.GetDigitsCount() << " digits and it is written in base " << n1.GetBase()<< endl;
	for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
	{
		cout<<"n1["<< tr << "]=" << n1[tr]<<endl;
	}
	cout << endl;

	cout << "printam n1: " << endl;
	n1.Print();
	cout << "printam n2: " << endl;
	n2.Print();
	cout << endl;

	cout << "n1 = n1 + n3 adica 10110010 + FFA adica in dec 178 + 4090 = 4268 sau 10AC in hex" << endl;
	n1 = n1 + n3;
	n1.Print();
	cout << endl;

	cout << "n1 = (n2 + n3 - n1) + n1 " << endl;
	n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16
	n1.Print();
	cout << endl;

	cout << "n3" << endl;
	n3.Print();
	cout << endl;

	cout << "n3 switchbase 2" << endl;
	n3.SwitchBase(2);
	n3.Print();
	cout << endl;

	if (n1 < n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");
	cout << endl;

	cout << "Number n4 = 12345, n1 = 255, n4+=n1 = 12600" << endl;
	Number n4 = 12345; // n4 will be in base 10
	n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
	n4 += n1;
	n4.Print();
	cout << endl;

	cout << "n4 = 13579" << endl;
	n4 = "13579"; // n4 mentains its base (10) and will be 13579
	n4.Print();
	cout << endl;

	cout << "operator --" << endl;
	--n4; // the first digit from n4 will be remove ==> n4 becomes 3579
	n4.Print();
	n4--; // the last digit from n4 will be remove ==> n4 becomes 357
	n4.Print();

	int x;
	cin >> x;

	return 0;
}