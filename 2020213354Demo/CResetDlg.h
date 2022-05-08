#pragma once
#include "afxdialogex.h"


// CResetDlg 对话框

class CResetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResetDlg)

public:
	CResetDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CResetDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FIND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit Find_account;
	CEdit Find_password;
	CEdit Find_email;
	CDateTimeCtrl Find_birthday;
	afx_msg void OnBnClickedOk();
};
