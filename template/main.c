#include <stdio.h>
#include "tblib.h"

int main() {
	Text meow;
	meow.string = "You KILLLED her.";
	meow.color = BRIGHTRED;
	meow.bg = BLACK;
	meow.bold = false;
	tbout(meow, true, 50);
	tbconfirm(500);
	Text nya;
	nya.string = "just kidding!!!! :3";
	nya.color = BRIGHTCYAN;
	nya.bg = 69;
	nya.bold = false;
	tbout(nya, true, 50);
	tbconfirm(500);
	return 0;
}
