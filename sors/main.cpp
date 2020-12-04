
#include <iostream>
#include <conio.h>
#include "datstack.h"

#pragma argsused
int main(int argc, char* argv[]) {
	TStack a;
	for (int i = 0; i < 25; i++) {
		a.Put(i);
	}
	for (int i = 0; i < 25; i++) {
		std::cout << a.Get() << std::endl;
	}
	return 0;
}