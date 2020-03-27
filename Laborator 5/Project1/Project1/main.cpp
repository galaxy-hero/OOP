#include "Number.h"
#include <iostream>

using namespace std;

int main()
{
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("FFA", 16);

	cout<< "n1 has" << n1.GetDigitsCount() << "digits and it is written in base " << n1.GetBase()<< endl;
	for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
	{
		cout<<"n1["<< tr << "]=" << n1[tr]<<endl;
	}
	n1.Print();
	n2.Print();
	//n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16
	n1 = n2.operator+(n3).operator+(n2);
	n1.Print();
	n3.Print();

	n3.SwitchBase(2);
	n3.Print();

	Number a("100", 2);
	Number b("200", 2);
	if (a < b) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");

	/*Number n4 = 12345; // n4 will be in base 10
	n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
	n4 += n1;
	n4.Print();

	n4 = "13579"; // n4 mentains its base (10) and will be 13579
	n4.Print();
	--n4; // the first digit from n4 will be remove ==> n4 becomes 3579
	n4.Print();
	n4--; // the last digit from n4 will be remove ==> n4 becomes 357
	n4.Print();*/

	int x;
	cin >> x;

	return 0;
}