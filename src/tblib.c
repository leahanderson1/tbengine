#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#ifndef WIN32
#include <pthread.h>
#define PTHREADS
#endif
#include "tbextra.h"
#include "tblib.h"

void tbout(Text text, bool vn, unsigned int ms) {
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
void mtbout(char* string, uint8_t color, uint8_t bg, bool bold, bool vn, unsigned int ms) {
	Text temp;
	temp.string = (char *)string;
	temp.color = color;
	temp.bg = bg;
	temp.bold = bold;
	tbout(temp, vn, ms);
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
void tbconfirm(unsigned int ms) {
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
char* tbin(unsigned int maxchars) {
	char buffer[maxchars];
	char* result = NULL;
	while (result == NULL) {
		printf("\n>");
    		result = fgets(buffer, sizeof(char) * maxchars, stdin);

    		if (buffer[strlen(buffer) - 1] != '\n') {
       			result = NULL;
    		}
	}
	// ABSOLUTELY NO NEWLINES ALLOWE<ctype.hD!!!!
	buffer[strcspn(buffer, "\r\n")] = 0;
	// i swear if someone files an issue calling this a memory leak i might explode
	// also about the line below: even though char is usually 1 byte there could be systems where this isn't the case and thats why you shouldn't hardcode this kinda stuff use sizeof
	char *output = calloc(maxchars, sizeof(char));
	strcpy(output, buffer);
	return output;
}

uint8_t tbselect(uint8_t menu) {
    if (menu > 10 || menu <= 0) {
        // invalid amount of options
        return 11;
    }
    uint8_t options[menu];
    // create an array of valid inputs
    for (int i = 0; i < menu; i++) {
        options[i] = i;
    }
    // get the input of the user
    uint8_t choice;
    bool valid = false;
    while (!valid) {
        printf("\r>");
        // atoi only accepts strings
        char in[1] = {getchar()};
        if (!isdigit(in[0])) {
            continue;
        }
        choice = atoi(in);
        for (int i = 0; i < menu || valid; i++)  {
                if (options[i] == choice) {
                    valid = true;
                    break;
                }
        }
    }
    return choice;
}
