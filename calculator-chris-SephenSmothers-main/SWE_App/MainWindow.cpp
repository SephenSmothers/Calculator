#include "MainWindow.h"
#include "wx/tokenzr.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

enum Buttons
{
	SinBox = 10000,
	CosBox,
	TanBox, 
	DivideBox,
	MultiplyBox,
	SubtractBox,
	AddBox, 
	EqualsBox,
	OneBox, 
	TwoBox, 
	ThreeBox,
	FourBox,
	FiveBox, 
	SixBox,
	SevenBox,
	EightBox, 
	NineBox, 
	ZeroBox, 
	NegateBox, 
	DotBox, 
	DeleteBox,
	ClearBox,
	ModuloBox,
	DisplayBox
};

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_BUTTON(Buttons::SinBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::CosBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::TanBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::DivideBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::MultiplyBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::SubtractBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::AddBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::EqualsBox, MainWindow::OnEquals)
EVT_BUTTON(Buttons::OneBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::TwoBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::ThreeBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::FourBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::FiveBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::SixBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::SevenBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::EightBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::NineBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::ZeroBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::NegateBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::DotBox, MainWindow::OnButtonClick)
EVT_BUTTON(Buttons::DeleteBox, MainWindow::OnDelete)
EVT_BUTTON(Buttons::ClearBox, MainWindow::OnClear)
EVT_BUTTON(Buttons::ModuloBox, MainWindow::OnButtonClick)

wxEND_EVENT_TABLE()

MainWindow::MainWindow() :
	wxFrame(nullptr, wxID_ANY, "Calculator App", wxPoint(400, 200), wxSize(400, 500))
{
	mDisplayBox = new wxTextCtrl(this, Buttons::DisplayBox, " ", wxPoint(10, 10), wxSize(200, 30));
	mEquateBox = new wxTextCtrl(this, Buttons::DisplayBox, " ", wxPoint(210, 10), wxSize(180, 30));
	ButtonFactory factor;

	mSinBox = factor.CreateButton(this, Buttons::SinBox, " Sin ", wxPoint(10, 70), wxSize(50, 50));
	mCosBox = factor.CreateButton(this, Buttons::CosBox, " Cos ", wxPoint(70, 70), wxSize(50, 50));
	mTanBox = factor.CreateButton(this, Buttons::TanBox, " Tan ", wxPoint(130, 70), wxSize(50, 50));
	mDivideBox = factor.CreateButton(this, Buttons::DivideBox, " / ", wxPoint(190, 70), wxSize(50, 50));
	mMultiplyBox = factor.CreateButton(this, Buttons::MultiplyBox, " x ", wxPoint(190, 130), wxSize(50, 50));
	mSubtractBox = factor.CreateButton(this, Buttons::SubtractBox, " - ", wxPoint(190, 190), wxSize(50, 50));
	mAddBox = factor.CreateButton(this, Buttons::AddBox, " + ", wxPoint(190, 250), wxSize(50, 50));
	mEqualsBox = factor.CreateButton(this, Buttons::EqualsBox, " = ", wxPoint(190, 370), wxSize(50, 50));
	mOneBox = factor.CreateButton(this, Buttons::OneBox, "1", wxPoint(10, 130), wxSize(50, 50));
	mTwoBox = factor.CreateButton(this, Buttons::TwoBox, "2", wxPoint(70, 130), wxSize(50, 50));
	mThreeBox = factor.CreateButton(this, Buttons::ThreeBox, "3", wxPoint(130, 130), wxSize(50, 50));
	mFourBox = factor.CreateButton(this, Buttons::FourBox, "4", wxPoint(10, 190), wxSize(50, 50));
	mFiveBox = factor.CreateButton(this, Buttons::FiveBox, "5", wxPoint(70, 190), wxSize(50, 50));
	mSixBox = factor.CreateButton(this, Buttons::SixBox, "6", wxPoint(130, 190), wxSize(50, 50));
	mSevenBox = factor.CreateButton(this, Buttons::SevenBox, "7", wxPoint(10, 250), wxSize(50, 50));
	mEightBox = factor.CreateButton(this, Buttons::EightBox, "8", wxPoint(70, 250), wxSize(50, 50));
	mNineBox = factor.CreateButton(this, Buttons::NineBox, "9", wxPoint(130, 250), wxSize(50, 50));
	mZeroBox = factor.CreateButton(this, Buttons::ZeroBox, "0", wxPoint(70, 310), wxSize(50, 50));
	mNegateBox = factor.CreateButton(this, Buttons::NegateBox, "-", wxPoint(10, 310), wxSize(50, 50));
	mDotBox = factor.CreateButton(this, Buttons::DotBox, ".", wxPoint(130, 310), wxSize(50, 50));
	mDeleteBox = factor.CreateButton(this, Buttons::DeleteBox, "Del", wxPoint(70, 370), wxSize(50, 50));
	mClearBox = factor.CreateButton(this, Buttons::ClearBox, "CLS", wxPoint(130, 370), wxSize(50, 50));
	mModuloBox = factor.CreateButton(this, Buttons::ModuloBox, " % ", wxPoint(190, 310), wxSize(50, 50));
}

void MainWindow::OnButtonClick(wxCommandEvent& event)
{
	int id = event.GetId();
	wxButton* invokingButton = static_cast<wxButton*>(event.GetEventObject());
	mDisplayBox->AppendText(invokingButton->GetLabel());
}

void MainWindow::OnClear(wxCommandEvent& event)
{
	mDisplayBox->Clear(); 
	mEquateBox->Clear();
	mTokens.clear();
}

void MainWindow::OnDelete(wxCommandEvent& event)
{
	wxString boxText = mDisplayBox->GetValue();
	if (!boxText.empty())
	{
		boxText.RemoveLast();
		mDisplayBox->SetValue(boxText);
	}
}

std::vector<std::string> MainWindow::TokenizeText(const wxString& input)
{
	std::string text = input.ToStdString();
	wxArrayString tokens;
	std::vector<std::string> allTokens;
	tokens = wxStringTokenize(text, " ");

	for (int i = 0; i < tokens.size(); i++)
	{
		allTokens.push_back(tokens[i].ToStdString());
	}

	return allTokens;
}

void MainWindow::OnEquals(wxCommandEvent& evt)
{
	mEquateBox->Clear();
	mTokens = TokenizeText(mDisplayBox->GetValue());
	double result = 0;
	std::string answer = " ";
	CalculatorProcessor* test = CalculatorProcessor::GetInstance();
	test->StackTokens(mTokens);
	result = test->SolveEquation(mTokens);
	answer = std::to_string(result);
	mEquateBox->AppendText(answer);
	mDisplayBox->Clear();
	mTokens.clear();
}