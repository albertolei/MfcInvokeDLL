
// MfcInvokeDLLDlg.h : ͷ�ļ�
//

#pragma once


// CMfcInvokeDLLDlg �Ի���
class CMfcInvokeDLLDlg : public CDialogEx
{
// ����
public:
	CMfcInvokeDLLDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCINVOKEDLL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CMenu m_Menu;
	// ���ɵ���Ϣӳ�亯��
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

