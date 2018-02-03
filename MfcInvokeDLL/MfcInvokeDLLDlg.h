
// MfcInvokeDLLDlg.h : 头文件
//

#pragma once


// CMfcInvokeDLLDlg 对话框
class CMfcInvokeDLLDlg : public CDialogEx
{
// 构造
public:
	CMfcInvokeDLLDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCINVOKEDLL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CMenu m_Menu;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedAdd();
	double m_summand1;
	double m_summand2;
	double m_sum;
	afx_msg void On32773();
};

