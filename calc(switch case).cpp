#include <iostream>
using namespace std;

int main()
{
	float num1, num2;
    char operation;
	cin >> num1>>num2;
	cin >> operation;
	switch (operation) {
	case '+':
		cout << num1 + num2;
		break;
	case '-':
		cout << num1 - num2;
		break;
	case '*':
		cout << num1 * num2;
		break;
	case '/':
		cout << num1 / num2;
		break;
	default:
		cout << "Nevernoe";

		if (num1 == 0)
			cout << "Oshibka";
		else
			cout << "Oshibka";









	}


}
