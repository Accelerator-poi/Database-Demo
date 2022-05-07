// CLogonDlg.cpp: 实现文件
//

#include "pch.h"
#include "2020213354Demo.h"
#include "afxdialogex.h"
#include "CLogonDlg.h"

extern CDatabase my_db;
// CLogonDlg 对话框

IMPLEMENT_DYNAMIC(CLogonDlg, CDialogEx)

CLogonDlg::CLogonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGON, pParent)
{

}

CLogonDlg::~CLogonDlg()
{
}

void CLogonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ACCOUNT, Logon_Account);
	DDX_Control(pDX, IDC_EDIT_LPASSWORD, Logon_Password);
	DDX_Control(pDX, IDC_EDIT_EMAIL, Logon_Email);
	DDX_Control(pDX, IDC_DATETIMEPICKER_BIRTHDAY, Logon_Birthday);
}


BEGIN_MESSAGE_MAP(CLogonDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLogonDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLogonDlg 消息处理程序


void CLogonDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString user_account, user_password,user_email,user_birthdate;//用以保存用户输入的值
	CTime date;
	Logon_Account.GetWindowText(user_account);
	Logon_Password.GetWindowText(user_password);
	Logon_Email.GetWindowText(user_email);
	Logon_Birthday.GetTime(date);//获取用户填入的日期
	user_birthdate = date.Format("%Y.%m.%d");//将CTime的日期转为CString

	//确保三条信息均被填写
	if (user_account == _T(""))
	{
		AfxMessageBox(_T("账号不能为空！"));
		return;
	}
		
	if (user_password==_T(""))
	{ 
		AfxMessageBox(_T("密码不能为空！"));
		return;
	}
		
	if (user_email == _T(""))
	{
		AfxMessageBox(_T("注册邮箱不能为空！"));
		return;
	}
		

		CString mysql;
		mysql.Format(_T("INSERT INTO userinformation VALUES(gs_encrypt_aes128('%s','Asdf1234'),gs_encrypt_aes128('%s','Asdf1234'),gs_encrypt_aes128('%s','Asdf1234'),'%s');"), user_account, user_password,user_email,user_birthdate);

		//AfxMessageBox(mysql);//测试生成的sql语言，如果添加数据失败，可打开这个语句查看
				//SQL代码是否符合语法

		try
		{
			my_db.ExecuteSQL(mysql);
		}
		catch (CDBException* pe)
		{
			//如果有异常发生，弹出错误消息框，帮助纠正bug
			pe->ReportError();
			pe->Delete();
			return;
		}

		AfxMessageBox(_T("注册成功！"));

		CDialogEx::OnOK();
}
