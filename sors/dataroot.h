#pragma once
#include "datacom.h"
#define DefMemSize 25

#define DataEmpty -101
#define DataFull -102
#define DataNoMem -103

typedef int TElem;
typedef TElem* PTElem;
typedef int TData;

enum TMemType {MEM_HOLDER, MEM_RENTER};
class TDataRoot : public TDataCom {
protected:
	PTElem pMem;
	int MemSize;
	int DataCount;
	TMemType MemType;
protected:
	void SetMem(void *pMem, int Size);
public:
	~TDataRoot();
	TDataRoot(int Size = DefMemSize);
	virtual int IsEmpty(void) const;
	virtual int IsFull(void) const;
	virtual void Put(const TData& Val) = 0;
	virtual TData Get(void) = 0;
	virtual void Print() = 0;
	virtual int IsValid() = 0;

	friend class TMultiStack;
	friend class TSuperMultiStack;
	friend class TComplexMultiStack;
};
