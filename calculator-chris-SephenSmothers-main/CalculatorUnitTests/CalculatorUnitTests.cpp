#include "wx/wx.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/CalculatorProcessor.h"
#include "../SWE_App/MainWindow.h"
#include "../SWE_App/ButtonFactory.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTests
{
	TEST_CLASS(CalculatorUnitTests)
	{
	public:

		CalculatorProcessor* testCalc = CalculatorProcessor::GetInstance();
		MainWindow windowRef;
		double result = 0;
		std::vector<std::string> tokens;
		wxString input;
		wxWindow* testWindow = new wxWindow();
		ButtonFactory testButton;

		TEST_METHOD(AddNum)
		{
			input = "2 + 8";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(10.0, result);
		}

		TEST_METHOD(SubNum)
		{
			input = "2 - 8";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(-6.0, result);
		}

		TEST_METHOD(MultNum)
		{
			input = "12 x 12";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(144.0, result);
		}

		TEST_METHOD(DivNum)
		{
			input = "100 / 10";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(10.0, result);
		}

		TEST_METHOD(ModNum)
		{
			input = "10 % 4";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(2.0, result);
		}

		TEST_METHOD(SinNum)
		{
			input = "30 Sin ";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(std::to_string(0.5), std::to_string(result));
		}

		TEST_METHOD(CosNum)
		{
			input = "Cos 90";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(std::to_string(0.0), std::to_string(result));
		}

		TEST_METHOD(TanNum)
		{
			input = " Tan 45";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(std::to_string(1.0), std::to_string(result));
		}

		TEST_METHOD(Pemdas)
		{
			input = "20 + 2 - 3 x 4 / 2";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(16.0, result);
		}

		TEST_METHOD(TrigPemdas)
		{
			input = "Sin 90 + Cos 0";
			result = 0;
			tokens = windowRef.TokenizeText(input);
			testCalc->StackTokens(tokens);
			result = testCalc->SolveEquation(tokens);
			Assert::AreEqual(2.0, result);
		}

		TEST_METHOD(Number1Id)
		{
			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests");
			wxButton* number1 = testButton.CreateButton(testWindow, 20001, "1", wxPoint(10, 130), wxSize(50, 50));

			Assert::AreEqual(20001, number1->GetId());
		}

		TEST_METHOD(Number2)
		{
			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests", wxPoint(400, 200), wxSize(400, 500));
			wxButton* number2 = testButton.CreateButton(testFrame, 20002, "2", wxPoint(10, 130), wxSize(50, 50));

			Assert::AreEqual("2", number2->GetLabel());
		}

		TEST_METHOD(Number3XPosit)
		{
			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests", wxPoint(400, 200), wxSize(400, 500));
			wxButton* number3 = testButton.CreateButton(testFrame, 20003, "3", wxPoint(130, 130), wxSize(50, 50));

			Assert::AreEqual(130, number3->GetPosition().x);
		}

		TEST_METHOD(Number3YPosit)
		{
			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests", wxPoint(400, 200), wxSize(400, 500));
			wxButton* number3 = testButton.CreateButton(testFrame, 20004, "3", wxPoint(130, 130), wxSize(50, 50));

			Assert::AreEqual(130, number3->GetPosition().y);
		}

		TEST_METHOD(Number4XSize)
		{
			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests", wxPoint(400, 200), wxSize(400, 500));
			wxButton* number4 = testButton.CreateButton(testFrame, 20005, "4", wxPoint(10, 130), wxSize(50, 50));

			Assert::AreEqual(50, number4->GetSize().x);
		}

		TEST_METHOD(Number4YSize)
		{
			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests", wxPoint(400, 200), wxSize(400, 500));
			wxButton* number4 = testButton.CreateButton(testFrame, 20006, "4", wxPoint(10, 130), wxSize(50, 50));

			Assert::AreEqual(50, number4->GetSize().y);
		}

		TEST_METHOD(Equals)
		{
			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests", wxPoint(400, 200), wxSize(400, 500));
			wxButton* equals = testButton.CreateButton(testFrame, 20007, "=", wxPoint(190, 370), wxSize(50, 50));

			Assert::AreEqual("=", equals->GetLabel());
		}

		TEST_METHOD(EqualsId)
		{

			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests", wxPoint(400, 200), wxSize(400, 500));
			wxButton* equals = testButton.CreateButton(testFrame, 20008, "2", wxPoint(10, 130), wxSize(50, 50));

			Assert::AreEqual(20008, equals->GetId());
		}

		TEST_METHOD(ComplexLabel)
		{
			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests", wxPoint(400, 200), wxSize(400, 500));
			wxButton* label = testButton.CreateButton(testFrame, 20009, "Complex Label", wxPoint(10, 130), wxSize(50, 50));

			Assert::AreEqual("Complex Label", label->GetLabel());
		}

		TEST_METHOD(TestAll)
		{
			wxFrame* testFrame = new wxFrame(nullptr, wxID_ANY, "Unit Tests", wxPoint(400, 200), wxSize(400, 500));
			wxButton* number = testButton.CreateButton(testFrame, 20010, "1000", wxPoint(10, 130), wxSize(45, 70));

			Assert::AreEqual(20010, number->GetId());
			Assert::AreEqual("1000", number->GetLabel());
			Assert::AreEqual(10, number->GetPosition().x);
			Assert::AreEqual(130, number->GetPosition().y);
			Assert::AreEqual(45, number->GetSize().x);
			Assert::AreEqual(70, number->GetSize().y);
		}
	};
}
