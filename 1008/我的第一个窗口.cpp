#include<windows.h>
#include"resource.h"
#include<stdio.h>

#define WM_FAIL WM_USER+1

BOOL CALLBACK DialogProc(
						 HWND hwndDlg,
						 UINT uMsg,
						 WPARAM wParam,
						 LPARAM lParam
						 );
BOOL InitCommonControlsEx(
    LPINITCOMMONCONTROLSEX lpInitCtrls
);

DWORD WINAPI ThreadProc(
  LPVOID lpParameter   // thread data
);

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
					int nCmdShow)

{
	//����ģ̬��
	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG1),NULL,DialogProc);

}
BOOL CALLBACK DialogProc(
						 HWND hwndDlg,
						 UINT uMsg,
						 WPARAM wParam,
						 LPARAM lPara
						 )
{
	switch(uMsg)
	{
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				//�ؼ���ID
			case IDC_BUTTON:
				//�ؼ�����Ϣ	1:�����ť�����
				{
					
					if(HIWORD(wParam)==BN_CLICKED)
					{
						//���������֮ǰ�Ѱ�ť����Ϊ����״̬
						EnableWindow(GetDlgItem(hwndDlg,IDC_BUTTON),FALSE);
					}
					//�����߳�
					if(CreateThread(NULL,0,ThreadProc,(PVOID)hwndDlg,0,NULL)==NULL)
					{
						EnableWindow(GetDlgItem(hwndDlg,IDC_BUTTON),TRUE);
					}
				}
				break;
			}
		}
		break;
	case WM_CLOSE:
		{
			if(MessageBox(hwndDlg,"��ȷ��Ҫ�뿪����","��ʾ",MB_YESNO)==IDNO)
			{
				return 0;
			}
			EndDialog(hwndDlg,1);
		}
		break;
	case WM_FAIL:
		{
			MessageBox(hwndDlg,"����ʧ�ܣ�","��ʾ",0);
		}
		break;
	default:
		return false;
		break;
	}
}
//�̺߳���
DWORD WINAPI ThreadProc(
  LPVOID lpParameter   // thread data
)
{
	HWND hwndDlg=(HWND)lpParameter;
	char spath[256]="";
					char dpath[256]="";
					//��ȡ�ؼ��ڵ��ı���Ϣ
					GetDlgItemText(hwndDlg,IDC_EDIT1,spath,255);
					GetDlgItemText(hwndDlg,IDC_EDIT2,dpath,255);
					FILE* sfp=fopen(spath,"rb");
					FILE* dfp=fopen(dpath,"wb");
	//				MessageBox(hwndDlg,spath,dpath,0);
					if(sfp==NULL || dfp==NULL)
					{
						SendMessage(hwndDlg,WM_FAIL,0,0);
					}
					char buf[1024]="";
					int ilen=0;
					while((ilen=fread(buf,1,1024,sfp))>0)
					{ 
						fwrite(buf,1,ilen,dfp);
					}
					fclose(dfp);
					fclose(sfp);
					EnableWindow(GetDlgItem(hwndDlg,IDC_BUTTON),TRUE);
					MessageBox(hwndDlg,"�����ɹ���","tips",0);
	return 0;
}
