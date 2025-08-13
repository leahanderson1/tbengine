#include <stdio.h>
#include <string.h>
#include <tblib.h>
#include <tbextra.h>

// just so you know i randomly came up with the plot for this off the top of my head don't judge me :3
int main() {
	Text meow;
	meow.string = "AHAHAAHAHA! I have defeated you because of plot reasons! I will now banish you to some random dimension isekai-style so you will NEVER BOTHER ME AGAIN!";
	meow.color = BRIGHTRED;
	meow.bg = BLACK;
	meow.bold = false;
	tbout(meow, true, 50);
	tbconfirm(500);
	mtbout("MWAHAHA", BLACK, WHITE, false, true, 100);
	mtbout("HAHAHAHA", DARKGRAY, WHITE, false, true, 120);
	mtbout("HAHAHAHA.....", LIGHTGRAY, WHITE, false, true, 130);
	mtbout("HAHAHAHA?", WHITE, WHITE, false, true, 140);
	printf("\r");
	tbcolor(WHITE, BLACK, false);
	printf("\33[2K");
	meow.string = "Hello?";
	meow.color = BRIGHTCYAN;
	tbout(meow, true, 50);
	tbconfirm(500);
	meow.string = "Oh, thank goodness, you're awake.";
	tbout(meow, true, 50);
	tbconfirm(500);
	meow.string = "You've been laying here lifeless since a couple hours ago, when I came over here.";
	tbout(meow, true, 50);
	tbconfirm(500);
	mtbout("Say, what's your name?", BRIGHTCYAN, BLACK, false, true, 50);
	char *name = tbin(20);

	if (name != NULL) {
		char buffer[100];
		strcat(buffer, name);
		strcat(buffer, "... That's an interesting name! Nice to meet you, ");
		strcat(buffer, name);
		strcat(buffer, "!");
		mtbout(buffer, BRIGHTCYAN, BLACK, false, true, 50);
		tbconfirm(500);
	}
	return 0;
}
