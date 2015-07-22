
// Bejeweled2 Deluxe Cheat ToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bejeweled2 Deluxe Cheat Tool.h"
#include "Bejeweled2 Deluxe Cheat ToolDlg.h"
#include "afxdialogex.h"

#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HWND m_hWind;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBejeweled2DeluxeCheatToolDlg dialog



CBejeweled2DeluxeCheatToolDlg::CBejeweled2DeluxeCheatToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBejeweled2DeluxeCheatToolDlg::IDD, pParent)
	, iGameData(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBejeweled2DeluxeCheatToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DATA, iGameData);
}

BEGIN_MESSAGE_MAP(CBejeweled2DeluxeCheatToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()	
	ON_BN_CLICKED(IDC_BUTTON_RW, &CBejeweled2DeluxeCheatToolDlg::OnBnClickedButtonRw)
	ON_EN_CHANGE(IDC_EDIT_DATA, &CBejeweled2DeluxeCheatToolDlg::OnEnChangeEditData)
END_MESSAGE_MAP()


// CBejeweled2DeluxeCheatToolDlg message handlers

BOOL CBejeweled2DeluxeCheatToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBejeweled2DeluxeCheatToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBejeweled2DeluxeCheatToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBejeweled2DeluxeCheatToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBejeweled2DeluxeCheatToolDlg::OnBnClickedButtonRw()
{	
	HANDLE processH = getHandle();	
	LPVOID  nbuffer = (LPVOID)&iGameData;
	DWORD byread = 0x0;
	LPCVOID addressBase = getBaseAddress();
	ReadProcessMemory(processH, addressBase, nbuffer, 4, &byread);
	UpdateData(false);
}






BOOL CALLBACK CBejeweled2DeluxeCheatToolDlg::EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	// Step 1: 取出 window Title
	TCHAR strTitle[200];
	::GetWindowText(hwnd, strTitle, 200);
	CString cstrTitle = strTitle;

	// Step 2: 看看是否有符合的視窗
	CString *strSpecifiedTitle = (CString*)lParam;
	if (cstrTitle.Find(*strSpecifiedTitle) != -1){

		// Step 3: 對符合的視窗做進一步的處理
		m_hWind = ::FindWindow(NULL, cstrTitle);
		return FALSE; // 不需要繼續搜尋了
	}
	else{
		return TRUE; // 繼續搜尋
	}
}


HANDLE CBejeweled2DeluxeCheatToolDlg::getHandle()
{
	CString strTarget = _T("Bejeweled 2 Deluxe 1.0");
	EnumWindows(&EnumWindowsProc, (LPARAM)&strTarget);
	DWORD processid = 0x0;
	GetWindowThreadProcessId(m_hWind, &processid);

	HANDLE processH = ::OpenProcess(PROCESS_ALL_ACCESS, false, processid);

	return processH;

}

LPCVOID CBejeweled2DeluxeCheatToolDlg::getBaseAddress()
{

	HANDLE processH = getHandle();
	DWORD byread;
	LPVOID  getPointerAddress = 0x0;	
	LPCVOID addressBase = (LPCVOID)0x0059ACB8;
	int offset = 0x15DF0;
	ReadProcessMemory(processH, addressBase, &getPointerAddress, 4, &byread);
	addressBase = (LPVOID)((int)getPointerAddress + offset);

	return addressBase;
}

void CBejeweled2DeluxeCheatToolDlg::OnEnChangeEditData()
{
	UpdateData(true);

	HANDLE processH = getHandle();
	DWORD byread;
	LPCVOID addressBase = getBaseAddress();
	LPVOID  nbuffer = (LPVOID)&iGameData;
	WriteProcessMemory(processH, (void *)addressBase, nbuffer, 4, &byread);
}
