// CLoginDlg.cpp: 实现文件
//

#include<vector>
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

	CString user_account, user_password;//用以保存用户输入的值
	int IsFind = 0;//记录该用户名与密码是否在数据库中找到
	m_edtUser.GetWindowText(user_account);
	m_edtPassword.GetWindowText(user_password);

	if (user_account != _T("") && user_password != _T(""))
	{
		std::vector<CString>name;
		std::vector<CString>password;//用于储存从my_set中获取的数据
		CString temp_name, temp_password;//用于临时储存从my_set中获取的数据
		CRecordset my_set(&my_db);//申明CRecordset类的对象，用于调取表格数据 
		my_set.Open(AFX_DB_USE_DEFAULT_TYPE, _T("select * from userinformation"));//调取表格数据
		std::vector<CString>::iterator it_name;
		std::vector<CString>::iterator it_password;

		int i = 0;
		while (!my_set.IsEOF())//将information表里的所有数据储存到容器里
		{
			my_set.GetFieldValue((short)0, temp_name);//取第1个属性
			my_set.GetFieldValue((short)1, temp_password);//取第2个属性
			name.push_back(temp_name);
			password.push_back(temp_password);

			my_set.MoveNext();//数据指针下移一行
			i++;
		}


	}

	else
	{
		AfxMessageBox(_T("请输入账号与密码！"));
	}
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
	CString user_account, user_password;//用以保存用户输入的值
	m_edtUser.GetWindowText(user_account);
	m_edtPassword.GetWindowText(user_password);

	if (user_account != _T("") && user_password != _T(""))//确保用户输入了账号与密码
	{
		CString mysql;
		mysql.Format(_T("INSERT INTO userinformation VALUES(gs_encrypt_aes128('%s','Asdf1234'),gs_encrypt_aes128('%s','Asdf1234'));"), user_account, user_password);

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
		}

		AfxMessageBox(_T("注册成功！"));

		//清除输入框
		m_edtUser.SetSel(0, -1);
		m_edtUser.Clear();
		m_edtPassword.SetSel(0, -1);
		m_edtPassword.Clear();
	}

	else
	{
		AfxMessageBox(_T("请输入账号与密码！"));
	}
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
