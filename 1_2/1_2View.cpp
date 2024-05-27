
// 1_2View.cpp: CMy12View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "1_2.h"
#endif

#include "1_2Doc.h"
#include "1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy12View

IMPLEMENT_DYNCREATE(CMy12View, CView)

BEGIN_MESSAGE_MAP(CMy12View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy12View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMy12View 构造/析构

CMy12View::CMy12View() noexcept
{
	// TODO: 在此处添加构造代码
	ituxing = 0;
}

CMy12View::~CMy12View()
{
}

BOOL CMy12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy12View 绘图

void CMy12View::OnDraw(CDC* pDC)
{
	CMy12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	//清除当前图形
	CBrush mybrush1;
	mybrush1.CreateSolidBrush(RGB(255, 255, 255));
	CRect myrect1(0, 0, 1024, 768);
	pDC->FillRect(myrect1, &mybrush1);

	//用当前图形位置ituxing	
//画圆
	pDC->Ellipse(30 * ituxing, 30 * ituxing, 30 * ituxing + 50, 30 * ituxing + 50);
}




// CMy12View 打印


void CMy12View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy12View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy12View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy12View 诊断

#ifdef _DEBUG
void CMy12View::AssertValid() const
{
	CView::AssertValid();
}

void CMy12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy12Doc* CMy12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy12Doc)));
	return (CMy12Doc*)m_pDocument;
}
#endif //_DEBUG
void CMy12View::OnTimer(UINT nIDEvent)
{

	//获取指针pdc
	CDC* pDC = GetDC();

	//调用OnDraw(pDC)重画
	OnDraw(pDC);

	//使ituxing循环
	ituxing = (ituxing + 1) % 10;
	CView::OnTimer(nIDEvent);
}

int CMy12View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	//设置更新时间
	SetTimer(1, 750, NULL);
	return 0;
}

// CMy12View 消息处理程序
