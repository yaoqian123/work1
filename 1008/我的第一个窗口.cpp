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
	//创建模态框
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
				//控件的ID
			case IDC_BUTTON:
				//控件的消息	1:如果按钮被点击
				{
					
					if(HIWORD(wParam)==BN_CLICKED)
					{
						//在下载完成之前把按钮设置为禁用状态
						EnableWindow(GetDlgItem(hwndDlg,IDC_BUTTON),FALSE);
					}
					//创建线程
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
			if(MessageBox(hwndDlg,"你确定要离开我吗？","提示",MB_YESNO)==IDNO)
			{
				return 0;
			}
			EndDialog(hwndDlg,1);
		}
		break;
	case WM_FAIL:
		{
			MessageBox(hwndDlg,"拷贝失败！","提示",0);
		}
		break;
	case WM_INITDIALOG:
		{
			//设置进度条的范围
			SendMessage(GetDlgItem(hwndDlg,IDC_JINDUTIAO),PBM_SETRANGE,0,MAKELPARAM(1,100));
			//设置进度条的每一步的大小
			SendMessage(GetDlgItem(hwndDlg,IDC_JINDUTIAO),PBM_SETSTEP,1,0);
			//设置进度条的当前位置
			SendMessage(GetDlgItem(hwndDlg,IDC_JINDUTIAO),PBM_SETPOS,0,0);
		}
	default:
		return false;
		break;
	}
}
//线程函数
DWORD WINAPI ThreadProc(
  LPVOID lpParameter   // thread data
)
{
	HWND hwndDlg=(HWND)lpParameter;
	char spath[256]="";
					char dpath[256]="";
					//获取控件内的文本信息
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
					//获取文件的长度
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
					MessageBox(hwndDlg,"拷贝成功！","tips",0);
	return 0;
}
