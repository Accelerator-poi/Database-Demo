// CLoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "2020213354Demo.h"
#include "afxdialogex.h"
#include "CLoginDlg.h"

CDatabase my_db;

// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_USER, m_edtUser);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_edtPassword);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_EDIT_REGISTER, &CLoginDlg::OnBnClickedEditRegister)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CLoginDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	if (my_db.IsOpen())//判断是否处于数据库连接状态
	{
		my_db.Close();//如果当前处于连接状态，从数据源断开连接，释放系统资源
	}

	CDialogEx::OnCancel();
}


void CLoginDlg::OnBnClickedEditRegister()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//数据库初始化
	if (my_db.Open(_T("MyData")))//打开ODBC数据源驱动配置的用户DNS名称，返回值TRUE则表示正确连接上
	{
		AfxMessageBox(_T("OpenGauss数据库连接成功！"));
	}
	else
	{
		AfxMessageBox(_T("数据库连接失败，请检查虚拟机Opengauss是否运行或者ODBC驱动是否配置正确！"));
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
