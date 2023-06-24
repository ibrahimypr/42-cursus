#include "RPN.hpp"

RPN::RPN()
{
	return;
}

RPN::~RPN()
{
	return;
}

RPN::RPN(std::stack<double> number)
{
	this->numbers = number;
}

RPN::RPN(const RPN &var)
{
	*this = var;
}

RPN &RPN::operator=(const RPN &var)
{
	this->numbers = var.numbers;
	return (*this);
}

void RPN::calculate(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];

		if (c == ' ')
		{
			// skip whitespace
			continue;
		}
		else if (isdigit(c))
		{
			int number = c - '0'; // int'e dönüştürüldü
			numbers.push(number);
		}
		else if (c == '+' && numbers.size() >= 2) // 4 4 + ifadesinde soldan sağa stack'e eklendi sonra + operatörüne ulaşıldığında 4 ve 4 stack'den çıkarıldı toplama işlemi yapılarak geri stack'e konuldu
		{
			double b = numbers.top(); // en üstteki eleman b ye atanıyor
			numbers.pop(); // en üstteki eleman çıkarılıyor
			double a = numbers.top(); // b çıkınca en üstte a kalıyor ona da aynı işlemler uygulanıyor
			numbers.pop();
			numbers.push(a + b); // toplanıp işlemin sonucu bulunyor
		}
		else if (c == '-' && numbers.size() >= 2)
		{
			double b = numbers.top();
			numbers.pop();
			double a = numbers.top();
			numbers.pop();
			numbers.push(a - b);
		}
		else if (c == '*' && numbers.size() >= 2)
		{
			double b = numbers.top();
			numbers.pop();
			double a = numbers.top();
			numbers.pop();
			numbers.push(a * b);
		}
		else if (c == '/' && numbers.size() >= 2)
		{
			double b = numbers.top();
			numbers.pop();
			double a = numbers.top();
			numbers.pop();
			numbers.push(a / b);
		}
		else
		{
			// invalid character or insufficient operands
			std::cout << "Invalid input." << std::endl;
			return;
		}
	}

	if (numbers.size() == 1)
	{
		double result = numbers.top();
		numbers.pop();
		std::cout << "Result: " << result << std::endl;
	}
	else
	{
		// insufficient operands
		std::cout << "Invalid input." << std::endl;
	}
}
