#include "CalculatorProcessor.h"

CalculatorProcessor* CalculatorProcessor::_calculator = nullptr;

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	if (_calculator == nullptr)
	{
		_calculator = new CalculatorProcessor();
	}

	return _calculator;
}
void CalculatorProcessor::StackTokens(std::vector<std::string>& _tokens)
{
	mOperatorTokens.clear();
	mNewTokens.clear();

	for (int i = 0; i < _tokens.size(); i++)
	{
		if (IsDigit(_tokens[i]))
		{
			mNewTokens.push_back(_tokens[i]);
		}
		else
		{
			if (mOperatorTokens.size() != 0)
			{
				if (CurrPrecedence(_tokens[i]) == CurrPrecedence(mOperatorTokens[mOperatorTokens.size() - 1]))
				{
					mNewTokens.push_back(mOperatorTokens.back());
					mOperatorTokens.pop_back();
					mOperatorTokens.push_back(_tokens[i]);
				}
				else if (CurrPrecedence(_tokens[i]) < CurrPrecedence(mOperatorTokens.back()))
				{
					while (mOperatorTokens.size() != 0 && CurrPrecedence(_tokens[i]) < CurrPrecedence(mOperatorTokens.back()))
					{
						mNewTokens.push_back(mOperatorTokens.back());
						mOperatorTokens.pop_back();
					}
					mOperatorTokens.push_back(_tokens[i]);
				}
				else
				{
					mNewTokens.push_back(_tokens[i + 1]);
					mNewTokens.push_back(_tokens[i]);
					i++;
				}
			}
			else
			{
				mOperatorTokens.push_back(_tokens[i]);
			}
		}
	}

	if (mOperatorTokens.size() != 0)
	{
		for (int i = mOperatorTokens.size() - 1; i >= 0; i--)
		{
			mNewTokens.push_back(mOperatorTokens[i]);
		}
	}

	_tokens = mNewTokens;
}

double CalculatorProcessor::SolveEquation(std::vector<std::string>& _tokens)
{

	std::vector<double> operands;
	double operand1 = 0;
	double operand2 = 0;

	for (std::string t : _tokens) {

		if (t == "Sin")
		{
			operand1 = operands[0];
			operand1 *= acos(-1) / 180;
			operands.erase(operands.begin());
			operands.insert(operands.begin(), std::sin(operand1));
		}
		else if (t == "Cos")
		{
			operand1 = operands[0];
			operand1 *= acos(-1) / 180;
			operands.erase(operands.begin());
			operands.insert(operands.begin(), std::cos(operand1));
		}
		else if (t == "Tan")
		{
			operand1 = operands[0];
			operand1 *= acos(-1) / 180;
			operands.erase(operands.begin());
			operands.insert(operands.begin(), std::tan(operand1));
		}
		else if (IsDigit(t)) {
			operands.insert(operands.begin(), std::stod(t));
		}
		else
		{
			if (operands.size() >= 2)
			{
				operand2 = operands[0];
				operands.erase(operands.begin());
				operand1 = operands[0];
				operands.erase(operands.begin());
			}

			if (t == "+")
			{
				operands.insert(operands.begin(), (operand1 + operand2));
			}
			else if (t == "-")
			{
				operands.insert(operands.begin(), (operand1 - operand2));
			}
			else if (t == "x")
			{
				operands.insert(operands.begin(), (operand1 * operand2));
			}
			else if (t == "/")
			{
				operands.insert(operands.begin(), (operand1 / operand2));
			}
			else if (t == "%")
			{
				if (operand1 == 0 || operand2 == 0)
				{
					operand1 = 1;
					operand2 = 1;
					operands.insert(operands.begin(), ((int)operand1 % (int)operand2));
				}
				else
				{
					operands.insert(operands.begin(), ((int)operand1 % (int)operand2));
				}
			}
		}
	}
	double result = operands[0];
	return result;
}

bool CalculatorProcessor::IsDigit(std::string _stringToken)
{
	bool isDigit = false;

	try
	{
		std::stod(_stringToken);
		isDigit = true;
	}
	catch (const std::invalid_argument& ex)
	{
		isDigit = false;
	}
	return isDigit;
}

int CalculatorProcessor::CurrPrecedence(std::string _oper)
{
	int newPrec = 0;

	if (_oper == "+")
	{
		newPrec = 1;
	}
	else if (_oper == "-")
	{
		newPrec = 1;
	}
	else if (_oper == "x")
	{
		newPrec = 2;
	}
	else if (_oper == "/")
	{
		newPrec = 2;
	}
	else if (_oper == "%")
	{
		newPrec = 2;
	}
	else if (_oper == "Sin")
	{
		newPrec = 3;
	}
	else if (_oper == "Cos")
	{
		newPrec = 3;
	}
	else if (_oper == "Tan")
	{
		newPrec = 3;
	}

	return newPrec;
}