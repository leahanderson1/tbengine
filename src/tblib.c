#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef WIN32
#include <pthread.h>
#define PTHREADS
#endif
#include "tbextra.h"
#include "tblib.h"

void tbout(Text text, bool vn, int ms) {
	tbcolor(text.color, text.bg, text.bold);
	if (vn) {
		int length = strlen(text.string);
		for (int i = 0; i < length; i++) {
        		putchar(text.string[i]);
#ifndef WIN32
			fflush(stdout);
#endif
			msleep(ms);
    		}
	} else {
		printf(text.string);
	}
	printf(COLOR_RESET);
}

#ifndef WIN32
void *blinkcursor(void *i) {
	int a = *((int *) i);
	free(i);
	setecho(false);
	printf("\n>");
	for (;;) {
		fflush(stdout);
		msleep(a);
		printf("\r ");
		fflush(stdout);
		msleep(a);
		printf("\r>");	
	}
	return NULL;
}
#endif
void tbconfirm(int ms) {
#ifdef PTHREADS
	pthread_t id;
	int *arg = (int *) malloc(sizeof(*arg));
	*arg = ms;
	pthread_create(&id, 0, blinkcursor, arg);
	getchar();
	pthread_cancel(id);
	printf("\r \r");
        setecho(true);

#else
	printf("\n>");
	setecho(false);
	getchar();
	printf("\r \r");
	setecho(true);
#endif
}
