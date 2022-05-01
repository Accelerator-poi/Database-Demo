
// 2020213354DemoDlg.h: 头文件
//

#pragma once


// CMy2020213354DemoDlg 对话框
class CMy2020213354DemoDlg : public CDialogEx
{
// 构造
public:
	CMy2020213354DemoDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY2020213354DEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	CString Array_Attribute = _T("");
	int ListState;//判断显示的表格，student表为0，sc表为1
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//CDatabase my_db;
	afx_msg void OnBnClickedCancel();
	CListCtrl m_list;
//	virtual HRESULT accDoDefaultAction(VARIANT varChild);
	void ShowData();
	void ShowData_sc();
//	afx_msg void OnLvnItemchangedListShow(NMHDR* pNMHDR, LRESULT* pResult);
	CStatic m_edtsno;
	afx_msg void OnStnClickedEditSno();
	afx_msg void OnEnChangeEdit4();
	CEdit m_edtsname;
	CEdit m_edtssex;
	CEdit m_edtsage;
	CEdit m_edtsdept;
	afx_msg void OnNMClickListShow(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedButtonSelect();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonStudent();
	afx_msg void OnBnClickedButtonCourse();
	CButton m_btn_check1;
	CButton m_btn_check2;
	CButton m_btn_check3;
	CButton m_btn_check4;
	CButton m_btn_check5;
	afx_msg void OnBnClickedButtonSearch();
	CEdit m_edtsearch;
};
