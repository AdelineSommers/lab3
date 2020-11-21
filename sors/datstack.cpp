#pragma once
#include <conio.h>
#include <stdio.h>
#include "datstack.h"

void TStack::Put(const TData& Val) {
	if (pMem == NULL) SetRetCode(DataNoMem);
	else if (IsFull()) SetRetCode(DataFull);
	else {
		Hi = GetNextIndex(Hi);
		pMem[Hi] = Val;
		DataCount++;
	}
}

TData TStack::Get(void) {
	TData temp = -1;
	if (pMem == NULL) SetRetCode(DataNoMem);
	else if (IsEmpty()) SetRetCode(DataEmpty);
	else {
		temp = pMem[Hi--];
		DataCount--;
	}
	return temp;
}

int TStack::GetNextIndex(int index) {
	return ++index;
}

void TStack::Paint(int y, int x1, int x2) {
	int i, px;
	//gotoxy(x1, y);
	if (DataCount == 0) px = x1 - 1;
	else {
		px = x1 + double(DataCount) * (x2 - x1 + 1) / MemSize - 1;
		if ((px < x1) && (DataCount > 0))px = x1;
		if (DataCount == MemSize) px = x2;
	}
	for (i = x1; i <= px; i++) cprintf("#");
	for (i = px + 1; i <= x2; i++) cprintf(" ");
	if ((x1 < 1) || (x1 > 79) || (px < 1) || (px > 79) || (x2 < 1) || (x2 > 79)) {
		printf("Error in parameters of painting...\n");
		getch();
	}
}

void TStack::Print() {
	for (int i = 0; i < DataCount; i++)
		printf("%d", pMem[i]);
	printf("\n");
}

int TStack::IsValid() {
	int res = 0;
	if (pMem == NULL) res = 1;
	if (MemSize < DataCount) res += 2;
	return res;
}

void TStack::CopyToVector(TElem v[]) {
	for (int i = 0; i < DataCount; i++)
		v[i] = pMem[i];
}