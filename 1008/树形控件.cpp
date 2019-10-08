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

//1定义窗口类并注册
	WNDCLASSEX wnd;
	wnd.cbSize				=sizeof(WNDCLASSEX);
	wnd.style				=CS_VREDRAW|CS_HREDRAW;;
	wnd.lpfnWndProc			=WndProc;//回调用 
	wnd.cbClsExtra			=0;
	wnd.cbWndExtra			=0;
	wnd.hInstance			=hInstance;	
	wnd.hIcon				=NULL;
	wnd.hCursor				=NULL;
	wnd.hbrBackground		=(HBRUSH)COLOR_GRAYTEXT;
	wnd.lpszMenuName		=NULL;
	wnd.lpszClassName		="MainWindow";//窗口类名
	wnd.hIconSm				=NULL;
	//注册
	RegisterClassEx(&wnd);

	//2创建窗口
	HWND hWnd;
	hWnd=CreateWindow("MainWindow","主窗口",\
						WS_VISIBLE|WS_OVERLAPPEDWINDOW,\
						500,200,270,500,NULL,NULL,hInstance,NULL);
	//3显示与更新
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);

	//4消息处理
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
//HWND hchart=NULL;
//主窗口
LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	static HWND htv;
	switch(uMsg)
	{
		case WM_CREATE://当窗口被创建时
		{
			//创建一树形控件 --子窗口必须有WS_CHILD|WS_VISIBLE
			htv=CreateWindowEx(WS_EX_WINDOWEDGE,WC_TREEVIEW,NULL,\
						  WS_CHILD|WS_VISIBLE|TVS_HASLINES|TVS_HASBUTTONS|TVS_LINESATROOT,\
						  0,0,255,490,\
						  hWnd,\
						  (HMENU)1001,\
						  (HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE),\
						  NULL
						  );
			//添加Item1
			TVINSERTSTRUCT ts;
			ts.hParent=TVI_ROOT;//根目录 
			ts.hInsertAfter=TVI_LAST;//添加最后面
			ts.item.mask=TVIF_TEXT;//此目录只有文字
			ts.item.pszText="我的好友";
			ts.item.cchTextMax=8;
			HTREEITEM parent=(HTREEITEM)SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
			//添加Item1的子条目
				ts.hParent=parent;//由于将此目录插入到我的好友中，父目录为“我的好友”
				ts.item.pszText="成家学";
				ts.item.cchTextMax=6;
				SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
				ts.item.pszText="赵正";
				ts.item.cchTextMax=6;
				SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
				ts.item.pszText="叶才林";
				ts.item.cchTextMax=6;
				TreeView_InsertItem(htv,&ts);
			//添加Item2
			ts.hParent=TVI_ROOT;////根目录 
			ts.item.pszText="我的仇人";
			ts.item.cchTextMax=8;
			parent=(HTREEITEM)SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
			//添加Item2的子条目
				ts.hParent=parent;//由于将此目录插入到我的好友中，父目录为“我的好友”
				ts.item.pszText="赵俊杰";
				ts.item.cchTextMax=4;
				SendMessage(htv,TVM_INSERTITEM,0,(LPARAM)&ts);
				ts.item.pszText="张方远";
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
							//获取屏幕的坐标
							DWORD pos=GetMessagePos();
							POINT pt;
							pt.x		=LOWORD(pos);	//取出pos里的低字节
							pt.y		=HIWORD(pos);
							
							
							//屏幕坐标转窗口坐标
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
								tvi.hItem		=item;	//是获取的条目的句柄
								
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
			MessageBox(hWnd,"鼠标左键被点击","提示",0);
		}
		break;
		case WM_CLOSE://用户点击了关闭按钮 
		{
			if(IDNO==MessageBox(hWnd,"你点击了关闭哟","Tip",MB_YESNO))
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
