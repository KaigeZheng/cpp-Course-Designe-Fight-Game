#include"games.h"
#include"configure.h"

int main() {
	initMenu();
	EndBatchDraw();
	_getch();
	closegraph();
	return 0;
}



