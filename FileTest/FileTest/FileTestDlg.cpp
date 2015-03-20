
// FileTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileTest.h"
#include "FileTestDlg.h"
#include "afxdialogex.h"

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


// CFileTestDlg �Ի���




CFileTestDlg::CFileTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileTestDlg::IDD, pParent)
	, m_strOpenEdit(_T(""))
	, m_strSaveEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_OPEN_EDIT, m_strOpenEdit);
	DDX_Text(pDX, IDC_SAVE_EDIT, m_strSaveEdit);
}

BEGIN_MESSAGE_MAP(CFileTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CFileTestDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CFileTestDlg::OnBnClickedSaveButton)
END_MESSAGE_MAP()


// CFileTestDlg ��Ϣ�������

BOOL CFileTestDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFileTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFileTestDlg::OnPaint()
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
HCURSOR CFileTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileTestDlg::OnBnClickedOpenButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*<���ù�����>*/
	TCHAR BASED_CODE szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	/*<������ļ��Ի���>*/
	CFileDialog fileDlg(TRUE,_T("txt"),NULL,0,szFilter,this,0,TRUE);
	if (IDOK == fileDlg.DoModal())
	{
		m_strOpenEdit = fileDlg.GetFolderPath();
		UpdateData(FALSE);
	}
}


void CFileTestDlg::OnBnClickedSaveButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*<���ù�����>*/
	TCHAR BASED_CODE szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|Word�ļ�(*.doc)|*.doc|�����ļ�(*.*)|*.*||");
	/*<������ļ��Ի���>*/
	CFileDialog fileDlg(FALSE,_T("doc"),_T("test"),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,this,0,TRUE);
	//CString strFilePath;
	if (IDOK == fileDlg.DoModal())
	{
		m_strSaveEdit = fileDlg.GetFolderPath();
		UpdateData(FALSE);
	}
}
