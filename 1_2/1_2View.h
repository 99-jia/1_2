﻿
// 1_2View.h: CMy12View 类的接口
//

#pragma once


class CMy12View : public CView
{
protected: // 仅从序列化创建
	CMy12View() noexcept;
	DECLARE_DYNCREATE(CMy12View)

// 特性
public:
	CMy12Doc* GetDocument() const;

// 操作
public:
	int ituxing;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnTimer(UINT nIDEvent);
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
// 实现
public:
	virtual ~CMy12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 1_2View.cpp 中的调试版本
inline CMy12Doc* CMy12View::GetDocument() const
   { return reinterpret_cast<CMy12Doc*>(m_pDocument); }
#endif

