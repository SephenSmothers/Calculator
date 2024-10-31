#pragma once
#include "wx/wx.h"

class MainWindow : public wxFrame
{
	//Display Box
	wxTextCtrl* mDisplayBox = nullptr;
	wxTextCtrl* mEquateBox = nullptr;

	//All Buttons
	wxButton* mSinBox = nullptr;
	wxButton* mCosBox = nullptr;
	wxButton* mTanBox = nullptr;
	wxButton* mDivideBox = nullptr;
	wxButton* mMultiplyBox = nullptr;
	wxButton* mSubtractBox = nullptr;
	wxButton* mAddBox = nullptr;
	wxButton* mEqualsBox = nullptr;
	wxButton* mOneBox = nullptr;
	wxButton* mTwoBox = nullptr;
	wxButton* mThreeBox = nullptr;
	wxButton* mFourBox = nullptr;
	wxButton* mFiveBox = nullptr;
	wxButton* mSixBox = nullptr;
	wxButton* mSevenBox = nullptr;
	wxButton* mEightBox = nullptr;
	wxButton* mNineBox = nullptr;
	wxButton* mZeroBox = nullptr;
	wxButton* mNegateBox = nullptr;
	wxButton* mDotBox = nullptr;
	wxButton* mDeleteBox = nullptr;
	wxButton* mClearBox = nullptr;
	wxButton* mModuloBox = nullptr;

	//Token Vector
	std::vector<std::string> mTokens;

public:

	MainWindow();
	void OnButtonClick(wxCommandEvent& event);
	void OnClear(wxCommandEvent& event);
	void OnDelete(wxCommandEvent& event);
	void OnEquals(wxCommandEvent& evt);
	std::vector<std::string> TokenizeText(const wxString& input);
	

	wxDECLARE_EVENT_TABLE();
};

