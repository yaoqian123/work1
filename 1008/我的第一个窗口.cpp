#include<windows.h>
#include"resource.h"
#include<stdio.h>
#include<commctrl.h>


#define WM_FAIL WM_USER+1

BOOL CALLBACK DialogProc(
						 HWND hwndDlg,
						 UINT uMsg,
						 WPARAM wParam,
						 LPARAM lParam
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
	case WM_INITDIALOG:
		{
			//���ý������ķ�Χ
			SendMessage(GetDlgItem(hwndDlg,IDC_JINDUTIAO),PBM_SETRANGE,0,MAKELPARAM(1,100));
			//���ý�������ÿһ���Ĵ�С
			SendMessage(GetDlgItem(hwndDlg,IDC_JINDUTIAO),PBM_SETSTEP,1,0);
			//���ý������ĵ�ǰλ��
			SendMessage(GetDlgItem(hwndDlg,IDC_JINDUTIAO),PBM_SETPOS,0,0);
		}
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
					unsigned int total;
					fseek(sfp,0,SEEK_END);
					total=ftell(sfp);
					fseek(sfp,0,SEEK_SET);
					//char buf1[1024]
					char buf[1024]="";
					//��ȡ�ļ��ĳ���
				//	sprintf(buf1,"%d",total);
					int ilen=0;
					int loc=0;
					while((ilen=fread(buf,1,1024,sfp))>0)
					{ 
						loc+=ilen;
						SendMessage(GetDlgItem(hwndDlg,IDC_JINDUTIAO),PBM_SETPOS,(WPARAM)(int)((double)loc/total)*100,0);
						fwrite(buf,1,ilen,dfp);
					//	Sleep(1);
					}
					fclose(dfp);
					fclose(sfp);
					EnableWindow(GetDlgItem(hwndDlg,IDC_BUTTON),TRUE);
					MessageBox(hwndDlg,"�����ɹ���","tips",0);
	return 0;
}
