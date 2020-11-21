#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "dataroot.h"

TDataRoot::TDataRoot(int Size) :TDataCom() {
	DataCount = 0;
	MemSize = Size;
	if (Size == 0) {
		pMem = NULL; MemType = MEM_RENTER;
	}
	else {
		pMem = new TElem[MemSize];
		MemType = MEM_HOLDER;
	}
}

TDataRoot::~TDataRoot() {
	if (MemType == MEM_HOLDER) delete pMem;
	pMem = NULL;
}

void TDataRoot::SetMem(void* pMem, int Size) {
	if (MemType == MEM_HOLDER) delete pMem;
	pMem = (TElem*)pMem;
	MemType = MEM_RENTER;
	MemSize = Size;
}

int TDataRoot::IsEmpty(void) const {
	return DataCount == 0;
}

int TDataRoot::IsFull(void) const {
	return DataCount == MemSize;
}