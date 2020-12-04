#pragma once
#define MemSize 25
typedef int TData;
class TStack {
protected:
	int Mem[MemSize];
	int Top;
public:
	TStack() { Top = -1; }
	int IsEmpty(void) const { Top == -1; }
	int IsFull(void) const { Top == MemSize - 1; }
	void Put(const int Val) { Mem[++Top] = Val; }
	TData Get(void) { return Mem[Top--]; }
};

