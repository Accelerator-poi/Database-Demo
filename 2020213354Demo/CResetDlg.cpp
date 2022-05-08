// CResetDlg.cpp: 实现文件
//

#include "pch.h"
#include "2020213354Demo.h"
#include "afxdialogex.h"
#include "CResetDlg.h"
#include <vector>

extern CDatabase my_db;

// CResetDlg 对话框

IMPLEMENT_DYNAMIC(CResetDlg, CDialogEx)

CResetDlg::CResetDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_FIND, pParent)
{

}

CResetDlg::~CResetDlg()
{
}

void CResetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FINDACCOUNT, Find_account);
	DDX_Control(pDX, IDC_EDIT_FINDPASSWORD, Find_password);
	DDX_Control(pDX, IDC_EDIT_FINDEMAIL, Find_email);
	DDX_Control(pDX, IDC_DATETIMEPICKER_FIND, Find_birthday);
}


BEGIN_MESSAGE_MAP(CResetDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CResetDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CResetDlg 消息处理程序


void CResetDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString user_account, user_password, user_email, user_birthday;
	CTime birthday;//用以储存输入框中的各项信息
	int isfind = 0;//用以标记用户输入的各项信息是否能在数据库中找到；
	Find_account.GetWindowText(user_account);
	Find_password.GetWindowText(user_password);
	Find_email.GetWindowText(user_email);
	Find_birthday.GetTime(birthday);
	user_birthday = birthday.Format("%Y.%m.%d");//获取输入框中的信息

	if (user_account == _T(""))
	{
		AfxMessageBox(_T("账号栏不能为空！"));
		return;
	}
	if (user_password == _T(""))
	{
		AfxMessageBox(_T("新密码不能为空！"));
		return;
	}
	if (user_email == _T(""))
	{
		AfxMessageBox(_T("注册邮箱不能为空！"));
		return;
	}

	CRecordset my_set(&my_db);//申明CRecordset类的对象，用于调取表格数据 
	my_set.Open(AFX_DB_USE_DEFAULT_TYPE, _T("select * from userinformation"));//调取表格数据
	std::vector<CString>my_account;
	std::vector<CString>my_email;
	std::vector<CString>my_birthday;//声明三个vector容器，用以存储从数据库中读取的信息
	std::vector<CString>::iterator it_account;
	std::vector<CString>::iterator it_email;
	std::vector<CString>::iterator it_birthday;
	CString temp_account, temp_email, temp_birthday;

	while (!my_set.IsEOF())
	{
		my_set.GetFieldValue((short)0, temp_account);//取第一个属性
		my_set.GetFieldValue((short)2, temp_email);//取第三个属性
		my_set.GetFieldValue((short)3, temp_birthday);//取第四个属性

		my_account.push_back(temp_account);
		my_email.push_back(temp_email);
		my_birthday.push_back(temp_birthday);//将三组数据全部存入容器中

		my_set.MoveNext();//指针移向下一行
	}
	my_set.Close();//释放资源

	it_account = my_account.begin();
	it_email = my_email.begin();
	it_birthday = my_birthday.begin();

	while (it_account != my_account.end() && it_email != my_email.end() && it_birthday != my_birthday.end())
	{
		CRecordset my_set_account(&my_db), my_set_email(&my_db);
		CString sql_account, sql_email;//执行搜索的两条sql语句
		CString Caccount, Cemail;//用以保存搜索结果的两个CString变量

		sql_account.Format(_T("SELECT gs_decrypt_aes128('%s','Asdf1234')"), *it_account);
		sql_email.Format(_T("SELECT gs_decrypt_aes128('%s','Asdf1234')"), *it_email);
		//AfxMessageBox(sql_account);
		//AfxMessageBox(sql_email);//运行不成功时可以利用这两条语句检查

		my_set_account.Open(AFX_DB_USE_DEFAULT_TYPE, sql_account);
		my_set_account.GetFieldValue((short)0, Caccount);
		my_set_email.Open(AFX_DB_USE_DEFAULT_TYPE, sql_email);
		my_set_email.GetFieldValue((short)0, Cemail);//将容器中的加密字符解密后读出

		if (Caccount == user_account && Cemail == user_email && *it_birthday == user_birthday)
		{
			isfind = 1;//若用户输入的信息与数据库中信息一致，将该变量置为1；
			CString sql_modify, sql_lock;
			CString Locked_password;
			CRecordset my_set_lock(&my_db);
			sql_lock.Format(_T("SELECT gs_encrypt_aes128('%s','Asdf1234');"), user_password);
			//AfxMessageBox(sql_lock);
			my_set_lock.Open(AFX_DB_USE_DEFAULT_TYPE, sql_lock);
			my_set_lock.GetFieldValue((short)0, Locked_password);
			sql_modify.Format(_T("update userinformation set upassword='%s' where uname='%s';"), Locked_password, *it_account);
			//AfxMessageBox(sql_modify);
			//对数据库数据进行修改
			try
			{
				my_db.ExecuteSQL(sql_modify);
			}
			catch (CDBException* pe)
			{
				//如果有异常发生，弹出错误消息框，帮助纠正bug
				pe->ReportError();
				pe->Delete();
				return;
			}
		}
		
		it_account++;
		it_birthday++;
		it_email++;//指针全部下移

		my_set_account.Close();
		my_set_email.Close();
	}

	if (isfind == 0)//若用户输入的信息与数据库不符，则提醒用户检查
	{
		AfxMessageBox(_T("请检查输入的信息！"));
		return;
	}

	
	CDialogEx::OnOK();
}
