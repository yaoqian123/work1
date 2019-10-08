#include<windows.h>
#include<commctrl.h>
#include<stdio.h>
#pragma comment(lib,"comctl32.lib")

LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

static HINSTANCE hInst;
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
					int nCmdShow)

{

//1���崰���ಢע��
	WNDCLASSEX wnd;
	wnd.cbSize				=sizeof(WNDCLASSEX);
	wnd.style				=CS_VREDRAW|CS_HREDRAW;;
	wnd.lpfnWndProc			=WndProc;//�ص��� 
	wnd.cbClsExtra			=0;
	wnd.cbWndExtra			=0;
	wnd.hInstance			=hInstance;	
	wnd.hIcon				=NULL;
	wnd.hCursor				=NULL;
	wnd.hbrBackground		=(HBRUSH)COLOR_GRAYTEXT;
	wnd.lpszMenuName		=NULL;
	wnd.lpszClassName		="MainWindow";//��������
	wnd.hIconSm				=NULL;
	//ע��
	RegisterClassEx(&wnd);

	//2��������
	HWND hWnd;
	hWnd=CreateWindow("MainWindow","������",\
						WS_VISIBLE|WS_OVERLAPPEDWINDOW,\
						500,200,270,500,NULL,NULL,hInstance,NULL);
	//3��ʾ�����
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);

	//4��Ϣ����
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
//HWND hchart=NULL;
//������
LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	static HWND htv;
	switch(uMsg)
	{
		case WM_CREATE://�����ڱ�����ʱ
		{
			//����һ���οؼ� --�Ӵ��ڱ�����WS_CHILD|WS_VISIBLE
			htv=CreateWindowEx(WS_EX_WINDOWEDGE,WC_TREEVIEW,NULL,\
						  WS_CHILD|WS_VISIBLE|TVS_HASLINES|TVS_HASBUTTONS|TVS_LINESATROOT,\
						  0,0,255,490,\
						  hWnd,\
						  (HMENU)1001,\
						  (HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE),\
						  NULL
						  );
			//���Item1
			TVINSERTSTRUCT ts;
			ts.hParent=TVI_ROOT;//��Ŀ¼ 
			ts.hInsertAfter=TVI_LAST;//��������
			ts.item.mask=TVIF_TEXT;//��Ŀ¼ֻ������
			ts.item.pszText="�ҵĺ���";
			ts.item.cchTextMax=8;
			HTREEITEM parent=(HTREEITEM)SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
			//���Item1������Ŀ
				ts.hParent=parent;//���ڽ���Ŀ¼���뵽�ҵĺ����У���Ŀ¼Ϊ���ҵĺ��ѡ�
				ts.item.pszText="�ɼ�ѧ";
				ts.item.cchTextMax=6;
				SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
				ts.item.pszText="����";
				ts.item.cchTextMax=6;
				SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
				ts.item.pszText="Ҷ����";
				ts.item.cchTextMax=6;
				TreeView_InsertItem(htv,&ts);
			//���Item2
			ts.hParent=TVI_ROOT;////��Ŀ¼ 
			ts.item.pszText="�ҵĳ���";
			ts.item.cchTextMax=8;
			parent=(HTREEITEM)SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
			//���Item2������Ŀ
				ts.hParent=parent;//���ڽ���Ŀ¼���뵽�ҵĺ����У���Ŀ¼Ϊ���ҵĺ��ѡ�
				ts.item.pszText="�Կ���";
				ts.item.cchTextMax=4;
				SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
				ts.item.pszText="�ŷ�Զ";
				ts.item.cchTextMax=6;
				SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
			
		}break;
		case WM_NOTIFY:
			{
				LPNMHDR nm=(LPNMHDR)lParam;
				switch(nm->idFrom)
				{
				case 1001:
					{
						if(nm->code==NM_DBLCLK )
						{
							//��ȡ��Ļ������
							DWORD pos=GetMessagePos();
							POINT pt;
							pt.x		=LOWORD(pos);	//ȡ��pos��ĵ��ֽ�
							pt.y		=HIWORD(pos);
							
							
							//��Ļ����ת��������
							ScreenToClient(hWnd,&pt);

						/*	char buf[100]="";
							sprintf(buf,"%d %d",pt.x,pt.y);
							MessageBox(hWnd,buf,"tip",0);
							*/
							TVHITTESTINFO tvinfo;
							tvinfo.pt	=pt;	
							tvinfo.flags	=TVHT_ONITEM;
							HTREEITEM item=TreeView_HitTest(nm->hwndFrom,&tvinfo);
							if(item!=NULL)
							{
								char buf[100]="";

								TVITEM tvi;
								tvi.mask		=TVIF_TEXT;
								tvi.pszText		=buf;
								tvi.cchTextMax	=100;
								tvi.hItem		=item;	//�ǻ�ȡ����Ŀ�ľ��
								
								TreeView_GetItem(nm->hwndFrom,&tvi);
								
								MessageBox(hWnd,buf,"tip",0);
							}
						

							
						}
					}
					break;
				}
			}
			break;
		case WM_LBUTTONDOWN:
		{
			MessageBox(hWnd,"�����������","��ʾ",0);
		}
		break;
		case WM_CLOSE://�û�����˹رհ�ť 
		{
			if(IDNO==MessageBox(hWnd,"�����˹ر�Ӵ","Tip",MB_YESNO))
			{
				return -1;
			}
			
			PostQuitMessage(-1);
		}
		break;
	default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}


	return 0;
}
