/*---------------------------------------------------------------------------*
  Project:  My template library
  File:     mytl.h

  (C)2005 HUDSON SOFT

  $Header: /home/cvsroot/SDK/include/win32/mytl.h,v 1.2 2006-03-09 12:28:40 yasuh-to Exp $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef	__MYTL_H__
#define	__MYTL_H__

#include <assert.h>
#include <deque>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// TMyList
//

template <class T>
class TMYList : public deque<T>
{
public:
	typedef BOOL	(* COMPARE)(T pItem1, LPVOID pData);

	// リスト数を取得（Warning 抑止対策）
	int	GetCount() { return (int)size(); } 

	// インデックスに対応するリストアイテムを取得
	T	GetItem(int nIndex)
	{
		assert((nIndex >= 0) && (nIndex < GetCount()));
		return at(nIndex);
	}

	// リストの最後にアイテムを追加
	int	AddTail(T pItem)
	{
		push_back(pItem);
		return GetCount() - 1;
	}

	// 指定アイテムのインデックスを取得
	int	IndexOf(T pItem)
	{
		for (int i=0; i<GetCount(); i++)
		{
			if ( at(i) == pItem ) return i;
		}
		return -1;
	}

	// 指定データが設定されているアイテムのインデックスを取得
	int	IndexOf(LPVOID pData, COMPARE fncCompare)
	{
		assert(fncCompare != NULL);
		for (int i=0; i<GetCount(); i++)
		{
			if ( fncCompare(at(i), pData) ) return i;
		}
		return -1;
	}

	// インデックスに対応するリストアイテムを削除
	void	Remove(int nIndex, BOOL bDelItem=TRUE)
	{
		assert((nIndex >= 0) && (nIndex < GetCount()));
		if ( bDelItem ) delete at(nIndex);
		erase(begin() + nIndex);
	}

	// 指定アイテムを削除
	void	Remove(T pItem, BOOL bDelItem=TRUE)
	{
		int nIndex = IndexOf(pItem);
		assert(nIndex != -1);
		if ( bDelItem ) delete at(nIndex);
		erase(begin() + nIndex);
	}

	// リストをクリア
	void	Clear(BOOL bDelItem=TRUE)
	{
		if ( bDelItem )
		{
			for (int i=0; i<GetCount(); i++) delete at(i);
		}
		clear();
	}
};

#endif	// __MYTL_H__
