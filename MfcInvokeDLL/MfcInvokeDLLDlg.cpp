
// MfcInvokeDLLDlg.cpp : ʵ���ļ�
//
#include<cstdlib>
#include "stdafx.h"
#include "MfcInvokeDLL.h"
#include "MfcInvokeDLLDlg.h"
#include "afxdialogex.h"
#include "invokeDLLH.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMfcInvokeDLLDlg �Ի���
CMfcInvokeDLLDlg::CMfcInvokeDLLDlg(CWnd* pParent /*=NULL*/) : CDialogEx(CMfcInvokeDLLDlg::IDD, pParent), m_summand1(0), m_summand2(0), m_sum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
void CMfcInvokeDLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SUMMAND_EDIT1, m_summand1);
	DDX_Text(pDX, IDC_SUMMAND_EDIT2, m_summand2);
	DDX_Text(pDX, IDC_SUM_EDIT, m_sum);
}
BEGIN_MESSAGE_MAP(CMfcInvokeDLLDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMfcInvokeDLLDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_ADD, &CMfcInvokeDLLDlg::OnBnClickedAdd)	
	ON_COMMAND(ID_32773, &CMfcInvokeDLLDlg::On32773)
END_MESSAGE_MAP()


// CMfcInvokeDLLDlg ��Ϣ�������
BOOL CMfcInvokeDLLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CWnd::SetWindowPos(NULL, 0, 0, 600, 500, SWP_NOZORDER);
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}
void CMfcInvokeDLLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�
void CMfcInvokeDLLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMfcInvokeDLLDlg::OnQueryDragIcon()
{
	
	return static_cast<HCURSOR>(m_hIcon);
}

//���ȷ����ť����Ӧ�¼�
void CMfcInvokeDLLDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MessageBox(L"Goodbye World");
	CDialogEx::OnOK();
}
void CMfcInvokeDLLDlg::OnBnClickedAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_summand1 != NULL || m_summand2 != NULL)
	{
		m_sum = add(m_summand1, m_summand2);
	} 
	else
	{
		m_sum = -1;
	}
	UpdateData(FALSE);
}
void CMfcInvokeDLLDlg::On32773()
{
	// TODO:  �ڴ���������������
	CAboutDlg *aboutDlg = new CAboutDlg;
	aboutDlg->Create(MAKEINTRESOURCE(IDD_ABOUTBOX));
	aboutDlg->ShowWindow(SW_SHOW);
}
