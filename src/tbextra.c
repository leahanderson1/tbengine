#include <stdio.h>
#include <stdint.h>
#ifdef WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif
#include "tblib.h"
#include "tbextra.h"

void tbcolor(uint8_t fg, uint8_t bg, bool bold) {
	printf("\e[");
	if (bold == true) {
		printf("1;");
	} else {
		printf("0;");
	}
	switch(bg) {
		case RED:
			printf("41");
			break;
		case GREEN:
			printf("42");
			break;
		case YELLOW:
			printf("43");
			break;
		case BLUE:
			printf("44");
			break;
		case MAGENTA:
			printf("45");
			break;
		case CYAN:
			printf("46");
			break;
		case LIGHTGRAY:
			printf("47");
			break;
		case BLACK:
			printf("40");
			break;
		case WHITE:
			printf("107");
			break;
		case DARKGRAY:
			printf("100");
			break;
		case BRIGHTRED:
			printf("101");
			break;
		case BRIGHTGREEN:
			printf("102");
			break;
		case BRIGHTYELLOW:
			printf("103");
			break;
		case BRIGHTBLUE:
			printf("104");
			break;
		case BRIGHTMAGENTA:
			printf("105");
			break;
		case BRIGHTCYAN:
			printf("106");
			break;
		default:
			printf("40");
			break;
	};
	printf(";");
	switch(fg) {
		case RED:
			printf("31");
			break;
		case GREEN:
			printf("32");
			break;
		case YELLOW:
			printf("33");
			break;
		case BLUE:
			printf("34");
			break;
		case MAGENTA:
			printf("35");
			break;
		case CYAN:
			printf("36");
			break;
		case LIGHTGRAY:
			printf("37");
			break;
		case BLACK:
			printf("30");
			break;
		case WHITE:
			printf("97");
			break;
		case DARKGRAY:
			printf("90");
			break;
		case BRIGHTRED:
			printf("91");
			break;
		case BRIGHTGREEN:
			printf("92");
			break;
		case BRIGHTYELLOW:
			printf("93");
			break;
		case BRIGHTBLUE:
			printf("94");
			break;
		case BRIGHTMAGENTA:
			printf("95");
			break;
		case BRIGHTCYAN:
			printf("96");
			break;
		default:
			printf("37");
			break;
	};
	printf("m");
}

void msleep(int ms) {
	usleep(ms * 1000);
}
void setecho(bool enable) {
#ifdef WIN32
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
	DWORD mode;
	GetConsoleMode(hStdin, &mode);

	if (!enable) {
		mode &= ~ENABLE_ECHO_INPUT;
	} else {
		mode |= ENABLE_ECHO_INPUT;
	}
 	SetConsoleMode(hStdin, mode );
#else
	struct termios tty;
	tcgetattr(STDIN_FILENO, &tty);
	if (!enable) {
		tty.c_lflag &= ~ECHO;
	}
	else {
		tty.c_lflag |= ECHO;
	}
	(void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}
