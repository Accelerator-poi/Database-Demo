
// 2020213354DemoDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "2020213354Demo.h"
#include "2020213354DemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern CDatabase my_db;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMClickListShow(NMHDR* pNMHDR, LRESULT* pResult);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST_SHOW, &CAboutDlg::OnNMClickListShow)
END_MESSAGE_MAP()


// CMy2020213354DemoDlg 对话框



CMy2020213354DemoDlg::CMy2020213354DemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY2020213354DEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2020213354DemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SHOW, m_list);
	DDX_Control(pDX, IDC_EDIT_SNO, m_edtsno);
	DDX_Control(pDX, IDC_EDIT_SNO, m_edtsno);
	DDX_Control(pDX, IDC_EDIT_SNAME, m_edtsname);
	DDX_Control(pDX, IDC_EDIT_SSEX, m_edtssex);
	DDX_Control(pDX, IDC_EDIT_SAGE, m_edtsage);
	DDX_Control(pDX, IDC_EDIT_SDEPT, m_edtsdept);
	DDX_Control(pDX, IDC_CHECK_C1, m_btn_check1);
	DDX_Control(pDX, IDC_CHECK_C2, m_btn_check2);
	DDX_Control(pDX, IDC_CHECK_C3, m_btn_check3);
	DDX_Control(pDX, IDC_CHECK_C4, m_btn_check4);
	DDX_Control(pDX, IDC_CHECK_C5, m_btn_check5);
	DDX_Control(pDX, IDC_EDIT_SEARCH, m_edtsearch);
}

BEGIN_MESSAGE_MAP(CMy2020213354DemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMy2020213354DemoDlg::OnBnClickedCancel)
//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_SHOW, &CMy2020213354DemoDlg::OnLvnItemchangedListShow)
	ON_STN_CLICKED(IDC_EDIT_SNO, &CMy2020213354DemoDlg::OnStnClickedEditSno)
	ON_EN_CHANGE(IDC_EDIT4, &CMy2020213354DemoDlg::OnEnChangeEdit4)
	ON_NOTIFY(NM_CLICK, IDC_LIST_SHOW, &CMy2020213354DemoDlg::OnNMClickListShow)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy2020213354DemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMy2020213354DemoDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMy2020213354DemoDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CMy2020213354DemoDlg::OnBnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CMy2020213354DemoDlg::OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CMy2020213354DemoDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy2020213354DemoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_STUDENT, &CMy2020213354DemoDlg::OnBnClickedButtonStudent)
	ON_BN_CLICKED(IDC_BUTTON_COURSE, &CMy2020213354DemoDlg::OnBnClickedButtonCourse)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CMy2020213354DemoDlg::OnBnClickedButtonSearch)
END_MESSAGE_MAP()


// CMy2020213354DemoDlg 消息处理程序

BOOL CMy2020213354DemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	


	//list 控件初始化
	m_list.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, _T("性别"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, _T("年龄"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, _T("所在系"), LVCFMT_LEFT, 100);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		//选择节点的时候选中整行

	ShowData();//显示表格数据

	ListState = 0;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy2020213354DemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy2020213354DemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy2020213354DemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy2020213354DemoDlg::OnBnClickedCancel()

{
	// TODO: 在此添加控件通知处理程序代码
	if (my_db.IsOpen())//判断是否处于数据库连接状态
	{
		my_db.Close();//如果当前处于连接状态，从数据源断开连接，释放系统资源
	}
	CDialogEx::OnCancel();
}


//HRESULT CMy2020213354DemoDlg::accDoDefaultAction(VARIANT varChild)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	return CDialogEx::accDoDefaultAction(varChild);
//}


void CMy2020213354DemoDlg::ShowData()
{
	// TODO: 在此处添加实现代码.
	m_list.DeleteAllItems();//清空原有数据 
	CRecordset my_set(&my_db);//申明CRecordset类的对象，用于调取表格数据 
	if (my_set.Open(AFX_DB_USE_DEFAULT_TYPE, _T("select * from student")))//获取数据
	{
		//AfxMessageBox(_T("读取数据集成功")); 
	}
	else
	{
		AfxMessageBox(_T("读取数据集失败！请检查连接是否异常！"));
		return;
	}
	if (my_set.IsBOF())//判断数据集是否为空
	{
		AfxMessageBox(_T("该表格数据集为空"));
		return;
	}

	int i = 0;//表示记录的行号，注意从第0行开始往list控件插入数据
	//5个字符串变量，用于保存一条记录的各个属性
	CString str_sno = _T("");
	CString str_sname = _T("");
	CString str_ssex = _T("");
	CString str_sage = _T("");
	CString str_sdept = _T("");
	while (!my_set.IsEOF()) {//判断当前是否有数据可供读取

		my_set.GetFieldValue((short)0, str_sno);//取第1个属性
		m_list.InsertItem(i, str_sno);
		my_set.GetFieldValue((short)1, str_sname);//取第2个属性
		m_list.SetItemText(i, 1, str_sname);
		my_set.GetFieldValue((short)2, str_ssex);//取第3个属性
		m_list.SetItemText(i, 2, str_ssex);

		my_set.GetFieldValue((short)3, str_sage);//取第4个属性
		m_list.SetItemText(i, 3, str_sage);
		my_set.GetFieldValue((short)4, str_sdept);//取第5个属性
		m_list.SetItemText(i, 4, str_sdept);
		my_set.MoveNext();//数据指针下移一行
		i++;
	}
	//释放当前资源
	my_set.Close();
}

void CMy2020213354DemoDlg::ShowData_sc()
{
	m_list.DeleteAllItems();//清空原有数据 

	CRecordset my_set(&my_db);//申明CRecordset类的对象，用于调取表格数据 
	if (my_set.Open(AFX_DB_USE_DEFAULT_TYPE, _T("select * from sc")))//获取数据
	{
		//AfxMessageBox(_T("读取数据集成功")); 
	}
	else
	{
		AfxMessageBox(_T("读取数据集失败！请检查连接是否异常！"));
		return;
	}
	if (my_set.IsBOF())//判断数据集是否为空
	{
		AfxMessageBox(_T("该表格数据集为空"));
		return;
	}

	int i = 0;//表示记录的行号，注意从第0行开始往list控件插入数据
	//3个字符串变量，用于保存一条记录的各个属性
	CString str_sno = _T("");
	CString str_cno = _T("");
	CString str_grade = _T("");
	while (!my_set.IsEOF()) {//判断当前是否有数据可供读取

		my_set.GetFieldValue((short)0, str_sno);//取第1个属性
		m_list.InsertItem(i, str_sno);
		my_set.GetFieldValue((short)1, str_cno);//取第2个属性
		m_list.SetItemText(i, 1, str_cno);
		my_set.GetFieldValue((short)2, str_grade);//取第3个属性
		if (str_grade == _T(""))
			m_list.SetItemText(i, 2, _T("无成绩"));
		else if (str_grade == _T("-1"))
			m_list.SetItemText(i, 2, _T("新选课"));
		else
		m_list.SetItemText(i, 2, str_grade);

		my_set.MoveNext();//数据指针下移一行
		i++;
	}
	//释放当前资源
	my_set.Close();
}

//void CMy2020213354DemoDlg::OnLvnItemchangedListShow(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//}


void CMy2020213354DemoDlg::OnStnClickedEditSno()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMy2020213354DemoDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAboutDlg::OnNMClickListShow(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMy2020213354DemoDlg::OnNMClickListShow(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strsno, strsname, strssex, strsage, strsdept;//用于保存从list控件上获取的值
	if (pNMItemActivate->iItem != -1)//pNMItemActivate->iItem为鼠标焦点处对应的行号
	{
		strsno = m_list.GetItemText(pNMItemActivate->iItem, 0);
		m_edtsno.SetWindowText(strsno);
		strsname = m_list.GetItemText(pNMItemActivate->iItem, 1);
		m_edtsname.SetWindowText(strsname);
		strssex = m_list.GetItemText(pNMItemActivate->iItem, 2);
		m_edtssex.SetWindowText(strssex);
		strsage = m_list.GetItemText(pNMItemActivate->iItem, 3);
		m_edtsage.SetWindowText(strsage);
		strsdept = m_list.GetItemText(pNMItemActivate->iItem, 4);
		m_edtsdept.SetWindowText(strsdept);
		Array_Attribute = strsno;
		UpdateData(FALSE);//刷新界面将底层代码的数据传递给上层的界面
	}
	*pResult = 0;
}


void CMy2020213354DemoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedButtonAdd();
}


void CMy2020213354DemoDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//刷新界面，把数据传递给底层代码
	if (ListState == 0)
	{
		CString strsno, strsname, strssex, strsage, strsdept;//用于保存从edit控件上获取的值
		//从界面上的edit控件获取用户输入的值
		m_edtsno.GetWindowText(strsno);
		m_edtsname.GetWindowText(strsname);
		m_edtssex.GetWindowText(strssex);
		m_edtsage.GetWindowText(strsage);
		m_edtsdept.GetWindowText(strsdept);
		if (strsno == _T(""))
		{
			AfxMessageBox(_T("学号为主码，取值不能为空！"));
			return;//等待用户重新输入
		}
		else
		{
			if (strsname == _T(""))
				strsname = _T("NULL");
			else
				strsname = _T("'") + strsname + _T("'");
			if (!strssex.CompareNoCase(_T("男")) || !strssex.CompareNoCase(_T("女")))
			{
				strssex = _T("'") + strssex + _T("'");
			}
			else {
				AfxMessageBox(_T("性别只能输入“男”或“女”！"));
				return;//等待用户重新输入 
			}

			if (strsage == _T(""))
				strsage = _T("NULL");
			if (strsdept == _T(""))
				strsdept = _T("NULL");
			else
				strsdept = _T("'") + strsdept + _T("'");
			CString mstrsql;
			mstrsql.Format(_T("insert into student values('%s',%s,%s,%s,%s)"), strsno, strsname, strssex,
				strsage, strsdept);
			//AfxMessageBox(mstrsql);//测试生成的sql语言，如果添加数据失败，可打开这个语句查看
			//SQL代码是否符合语法

			try
			{
				my_db.ExecuteSQL(mstrsql);
			}
			catch (CDBException* pe)
			{
				//如果有异常发生，弹出错误消息框，帮助纠正bug
				pe->ReportError();
				pe->Delete();
			}
			ShowData();//加载数据
		}
	}

	else
		AfxMessageBox(_T("本表格添加请用右侧的选课按钮！"));
}


void CMy2020213354DemoDlg::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//刷新界面，把数据传递给底层代码

	if (ListState == 0)
	{
		if (Array_Attribute == _T(""))
		{
			AfxMessageBox(_T("请选择一位同学"));
			return;
		}//防止未选择就删除

		CString mstrsql1;
		CString mstrsql2;
		mstrsql1.Format(_T("delete from student where sno='%s'"), Array_Attribute);
		mstrsql2.Format(_T("delete from sc where sno='%s'"), Array_Attribute);
		//AfxMessageBox(mstrsql);//测试生成的sql语言，如果添加数据失败，可打开这个语句查看
		//SQL代码是否符合语法

		//为避开主码约束，先删除sc表数据，再删除student表数据
		//因为student表与sc表的数据须一起删除，故可以通过调整删除顺序，而不必解除约束
		try
		{
			my_db.ExecuteSQL(mstrsql2);
			my_db.ExecuteSQL(mstrsql1);
		}
		catch (CDBException* pe)
		{
			//如果有异常发生，弹出错误消息框，帮助纠正bug
			pe->ReportError();
			pe->Delete();
			return;
		}
		AfxMessageBox(_T("删除成功!"));
		ShowData();//加载数据
	}

	else
	{
		AfxMessageBox(_T("本表格不支持删除!"));
	}
}


void CMy2020213354DemoDlg::OnBnClickedButtonModify()
{
	UpdateData(TRUE);//刷新界面，把数据传递给底层代码
	if (ListState == 0)
	{
		CString strsno, strsname, strssex, strsage, strsdept;//用于保存从edit控件上获取的值
		//从界面上的edit控件获取用户输入的值
		m_edtsno.GetWindowText(strsno);
		m_edtsname.GetWindowText(strsname);
		m_edtssex.GetWindowText(strssex);
		m_edtsage.GetWindowText(strsage);
		m_edtsdept.GetWindowText(strsdept);

		//防止未选择就修改
		if (Array_Attribute == _T(""))
		{
			AfxMessageBox(_T("请选择一位同学"));
			return;
		}

		if (strsno == _T(""))
		{
			AfxMessageBox(_T("学号为主码，取值不能为空！"));
			return;//等待用户重新输入
		}
		else
		{
			if (strsname == _T(""))
				strsname = _T("NULL");
			else
				strsname = _T("'") + strsname + _T("'");
			if (!strssex.CompareNoCase(_T("男")) || !strssex.CompareNoCase(_T("女")))
			{
				strssex = _T("'") + strssex + _T("'");
			}
			else {
				AfxMessageBox(_T("性别只能输入“男”或“女”！"));
				return;//等待用户重新输入 
			}

			if (strsage == _T(""))
				strsage = _T("NULL");
			if (strsdept == _T(""))
				strsdept = _T("NULL");
			else
				strsdept = _T("'") + strsdept + _T("'");

		
			CString mstrsql1,mstrsql2, mstrsql3, mstrsql4, mstrsql5, mstrsql6;

			//对关系约束先进行关闭，防止修改时产生错误
			//修改完成后重新打开约束，防止日后发生错误
			mstrsql1.Format(_T("ALTER TABLE sc DISABLE TRIGGER ALL;"));
			mstrsql2.Format(_T("update sc set sno='%s' where sno='%s';"), strsno, Array_Attribute);
			mstrsql3.Format(_T("ALTER TABLE sc ENABLE TRIGGER ALL;"));
			mstrsql4.Format(_T("ALTER TABLE student DISABLE TRIGGER ALL;"));
			mstrsql5.Format(_T("update student set sno='%s',sname=%s,ssex=%s,sage=%s,sdept=%s where sno='%s';"), strsno, strsname, strssex,
				strsage, strsdept, Array_Attribute);
			//mstrsql.Format(_T("ALTER TABLE sc ENABLE TGIGGER ALL"));
			mstrsql6.Format(_T("ALTER TABLE student ENABLE TRIGGER ALL;"));
			//AfxMessageBox(mstrsql);//测试生成的sql语言，如果添加数据失败，可打开这个语句查看
			//SQL代码是否符合语法

			try
			{
				my_db.ExecuteSQL(mstrsql1);
				my_db.ExecuteSQL(mstrsql2);
				my_db.ExecuteSQL(mstrsql3);
				my_db.ExecuteSQL(mstrsql4);
				my_db.ExecuteSQL(mstrsql5);
				my_db.ExecuteSQL(mstrsql6);
			}
			catch (CDBException* pe)
			{
				//如果有异常发生，弹出错误消息框，帮助纠正bug
				pe->ReportError();
				pe->Delete();
				return;
			}

			AfxMessageBox(_T("修改成功！"));
			ShowData();//加载数据
		}
	}
	else
		AfxMessageBox(_T("本表格不支持修改!"));
}


void CMy2020213354DemoDlg::OnBnClickedButtonSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	//数组存储选择框的选择状态
	int Array_Check[5] = { m_btn_check1.GetCheck(),m_btn_check2.GetCheck(),
	m_btn_check3.GetCheck(),m_btn_check4.GetCheck(),m_btn_check5.GetCheck() };
	//CRecordset my_set(&my_db);//申明CRecordset类的对象，用于调取表格数据 
	//CString mysql;

	for (int i = 0; i <= 4; i++)
	{
		//判断是否选中一位同学以及该选择框是否选中
		if (Array_Check[i] == 1 && Array_Attribute != _T(""))
		{
			CRecordset my_set(&my_db);//申明CRecordset类的对象，用于调取表格数据 
			CString mysql;
			mysql.Format(_T("select * from sc where sno = '%s' and cno = '%ld';"), Array_Attribute, i + 1);
			my_set.Open(AFX_DB_USE_DEFAULT_TYPE, mysql);//查询数据库中该同学是否有该门课的选课记录

			//AfxMessageBox(mysql);//测试生成的sql语言，如果添加数据失败，可打开这个语句查看
			    //SQL代码是否符合语法
			
			if (my_set.IsBOF())//若无，给他选课；若有，则跳过该门课的选择
			{
				CString mysql_select;
				mysql_select.Format(_T("insert into sc values('%s','%ld',-1)"), Array_Attribute, i + 1);

				//AfxMessageBox(mysql_select);//测试生成的sql语言，如果添加数据失败，可打开这个语句查看
			    //SQL代码是否符合语法

				try
				{
					my_db.ExecuteSQL(mysql_select);
				}
				catch (CDBException* pe)
				{
					//如果有异常发生，弹出错误消息框，帮助纠正bug
					pe->ReportError();
					pe->Delete();
					return;
				}
				OnBnClickedButtonCourse();//加载数据
				
			}
			my_set.Close();
		}
	}
	AfxMessageBox(_T("选课成功！"));
}


void CMy2020213354DemoDlg::OnBnClickedButtonReset()
{
	// TODO: 在此添加控件通知处理程序代码
	//选择一名同学
	if (Array_Attribute != _T(""))
	{
		CString mysql;
		mysql.Format(_T("delete from sc where sno='%s' and grade=-1"), Array_Attribute);

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
		OnBnClickedButtonCourse();//加载数据
	}
	AfxMessageBox(_T("重置成功！"));
}


void CMy2020213354DemoDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//将表格显示内容变为选课表
	OnBnClickedButtonCourse();
}


void CMy2020213354DemoDlg::OnBnClickedButtonStudent()
{
	// TODO: 在此添加控件通知处理程序代码
	 
	//在删除了第i列以后，后面的列自动向前补
	//因此要重复删除第0列
	for (int i = 0; i < 5; i++)
		m_list.DeleteColumn(0);
	//list 控件初始化
	
	m_list.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, _T("性别"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, _T("年龄"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, _T("所在系"), LVCFMT_LEFT, 100);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	ShowData();

	ListState = 0;//将表格状态设置为student表
}


void CMy2020213354DemoDlg::OnBnClickedButtonCourse()
{
	// TODO: 在此添加控件通知处理程序代码
	
	//在删除了第i列以后，后面的列自动向前补
	//因此要重复删除第0列
	for (int i = 0; i < 5; i++)
		m_list.DeleteColumn(0);

	//list 控件初始化
	m_list.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("课程号"), LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, _T("成绩"), LVCFMT_LEFT, 100);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//将数据刷入控件展示
	ShowData_sc();

	//将表格状态设置为sc表
	ListState = 1;
}


void CMy2020213354DemoDlg::OnBnClickedButtonSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	CString my_search, mysql;
	m_edtsearch.GetWindowText(my_search);//获取输入框里的内容
	CRecordset my_set(&my_db);

	if (my_search == _T(""))//若用户未输入任何搜索内容
	{
		AfxMessageBox(_T("请输入要搜索的姓名或学号！"));
			return;
	}

	if (ListState == 0)//当表格为student表时
	{

		mysql.Format(_T("select * from student where sno='%s' or sname='%s' "), my_search, my_search);
		// AfxMessageBox(mysql);//测试生成的sql语言，如果添加数据失败，可打开这个语句查看
				//SQL代码是否符合语法
		my_set.Open(AFX_DB_USE_DEFAULT_TYPE, mysql);//先查询该学号或姓名的所有信息
		m_list.DeleteAllItems();//清空原有数据 

		//在删除了第i列以后，后面的列自动向前补
	    //因此要重复删除第0列
		for (int i = 0; i < 5; i++)
			m_list.DeleteColumn(0);

        //list 控件初始化
		m_list.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 100);
		m_list.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 120);
		m_list.InsertColumn(2, _T("性别"), LVCFMT_LEFT, 100);
		m_list.InsertColumn(3, _T("年龄"), LVCFMT_LEFT, 100);
		m_list.InsertColumn(4, _T("所在系"), LVCFMT_LEFT, 100);
		m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		int i = 0;//表示记录的行号，注意从第0行开始往list控件插入数据
	//5个字符串变量，用于保存一条记录的各个属性
		CString str_sno = _T("");
		CString str_sname = _T("");
		CString str_ssex = _T("");
		CString str_sage = _T("");
		CString str_sdept = _T("");

		if (my_set.IsEOF())//若查询不到有关信息，报出错误
		{
			AfxMessageBox(_T("查无此人！"));
			return;
		}

		while (!my_set.IsEOF()) {//判断当前是否有数据可供读取

			my_set.GetFieldValue((short)0, str_sno);//取第1个属性
			m_list.InsertItem(i, str_sno);
			my_set.GetFieldValue((short)1, str_sname);//取第2个属性
			m_list.SetItemText(i, 1, str_sname);
			my_set.GetFieldValue((short)2, str_ssex);//取第3个属性
			m_list.SetItemText(i, 2, str_ssex);
			my_set.GetFieldValue((short)3, str_sage);//取第4个属性
			m_list.SetItemText(i, 3, str_sage);
			my_set.GetFieldValue((short)4, str_sdept);//取第5个属性
			m_list.SetItemText(i, 4, str_sdept);
			my_set.MoveNext();//数据指针下移一行
			i++;
		}
		//释放当前资源
		my_set.Close();
	}

	else if (ListState == 1)//当表格为sc表时
	{
		
		mysql.Format(_T("select sc.sno,cno,grade from sc,student where sc.sno=student.sno and sc.sno='%s' or sname='%s' and sc.sno=student.sno;"), my_search, my_search);
		 //AfxMessageBox(mysql);//测试生成的sql语言，如果添加数据失败，可打开这个语句查看
				//SQL代码是否符合语法
		my_set.Open(AFX_DB_USE_DEFAULT_TYPE, mysql);//先查询该学号或姓名的所有信息
		m_list.DeleteAllItems();//清空原有数据 

		//在删除了第i列以后，后面的列自动向前补
		//因此要重复删除第0列
		for (int i = 0; i < 5; i++)
			m_list.DeleteColumn(0);

        //list 控件初始化
		m_list.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 100);
		m_list.InsertColumn(1, _T("课程号"), LVCFMT_LEFT, 120);
		m_list.InsertColumn(2, _T("成绩"), LVCFMT_LEFT, 100);
		m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		int i = 0;//表示记录的行号，注意从第0行开始往list控件插入数据
	    //3个字符串变量，用于保存一条记录的各个属性
		CString str_sno = _T("");
		CString str_cno = _T("");
		CString str_grade = _T("");

		if (my_set.IsEOF())//若查询不到有关信息，报出错误
		{
			AfxMessageBox(_T("查无此人！"));
			return;
		}

		while (!my_set.IsEOF())
		{//判断当前是否有数据可供读取

			my_set.GetFieldValue((short)0, str_sno);//取第1个属性
			m_list.InsertItem(i, str_sno);
			my_set.GetFieldValue((short)1, str_cno);//取第2个属性
			m_list.SetItemText(i, 1, str_cno);
			my_set.GetFieldValue((short)2, str_grade);//取第3个属性
			if (str_grade == _T(""))
				m_list.SetItemText(i, 2, _T("无成绩"));
			else if (str_grade == _T("-1"))
				m_list.SetItemText(i, 2, _T("新选课"));
			else
				m_list.SetItemText(i, 2, str_grade);

			my_set.MoveNext();//数据指针下移一行
			i++;
		}
		//释放当前资源
		my_set.Close();

	}
}
