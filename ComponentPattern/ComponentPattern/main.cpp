#include <iostream>

using namespace std;

class ComputerFull
{
public :
	void ComputeAndPrint()
	{
		cin >> number1;
		cin >> operation;
		cin >> number2;

		int result = 0;

		switch (operation)
		{
		case '+':
			result = number1 + number2;
			break;
		case '-':
			result = number1 - number2;
			break;
		case '*':
			result = number1 * number2;
			break;
		case '/':
			result = number1 / number2;
			break;
		default:
			break;
		}


		cout << number1 << operation << number2 << " = " << result;
	}

private :
	int number1;
	int number2;
	char operation;
};

class Memory
{
private :
	int number1;
	int number2;
	char operation;

public :
	int result;

public:
	void SetData(int inputNumber1, int inputNumber2, char inputOperation)
	{
		number1 = inputNumber1;
		number2 = inputNumber2;
		operation = inputOperation;
	}

	int GetNumber1()
	{
		return number1;
	}

	int GetNumber2()
	{
		return number2;
	}

	char GetOperation()
	{
		return operation;
	}
};

class Keyboard
{
public:
	void Input(Memory& memory)
	{
		int number1, number2;
		char operation;
		cin >> number1;
		cin >> operation;
		cin >> number2;

		memory.SetData(number1, number2, operation);
	}
};

class CPU
{
public:
	void Compute(Memory& memory)
	{
		int number1 = memory.GetNumber1();
		int number2 = memory.GetNumber2();
		int result = 0;
		switch (memory.GetOperation())
		{
		case '+':
			result = number1 + number2;
			break;
		case '-':
			result = number1 - number2;
			break;
		case '*':
			result = number1 * number2;
			break;
		case '/':
			result = number1 / number2;
			break;
		default:
			result = -1;
			break;
		}

		memory.result = result;
	}
};

class Monitor
{
public :
	void Print(Memory& memory)
	{
		cout << memory.GetNumber1() << memory.GetOperation() << memory.GetNumber2() << "=" << memory.result;

	}
};

class Computer
{
private :
	Memory memory;
	Keyboard keyboard;
	CPU cpu;
	Monitor monitor;

public :
	void ComputeAndPrint()
	{
		keyboard.Input(memory);
		cpu.Compute(memory);
		monitor.Print(memory);
	}
};

int main()
{
	Computer compute;
	compute.ComputeAndPrint();

	return 0;
}