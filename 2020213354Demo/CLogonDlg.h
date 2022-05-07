#pragma once
#include "afxdialogex.h"


// CLogonDlg 对话框

class CLogonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogonDlg)

public:
	CLogonDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLogonDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGON };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit Logon_Account;
	CEdit Logon_Password;
	CEdit Logon_Email;
	CDateTimeCtrl Logon_Birthday;
	afx_msg void OnBnClickedOk();
};
