#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>



class CalculatorProcessor
{
private:

	static CalculatorProcessor* _calculator;

	//Empty private default contructor 
	CalculatorProcessor() { }
	~CalculatorProcessor() { delete _calculator; }
	
	std::vector<std::string> mNewTokens;
	std::vector<std::string> mOperatorTokens;

public:
	CalculatorProcessor(CalculatorProcessor& _copy) = delete;
	CalculatorProcessor& operator=(const CalculatorProcessor& _assign) = delete;
    static CalculatorProcessor* GetInstance();
	void StackTokens(std::vector<std::string>& _tokens);
	double SolveEquation(std::vector<std::string>& _tokens);
	bool IsDigit(std::string _stringToken);
	int CurrPrecedence(std::string _oper);
};
