
// Bejeweled2 Deluxe Cheat ToolDlg.h : header file
//

#pragma once


// CBejeweled2DeluxeCheatToolDlg dialog
class CBejeweled2DeluxeCheatToolDlg : public CDialogEx
{
// Construction
public:
	CBejeweled2DeluxeCheatToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BEJEWELED2DELUXECHEATTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButtonRw();
	HANDLE CBejeweled2DeluxeCheatToolDlg::getHandle();
	LPCVOID CBejeweled2DeluxeCheatToolDlg::getBaseAddress();
	static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

	int iGameData;
	afx_msg void OnEnChangeEditData();
};
