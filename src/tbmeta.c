#include <stdlib.h>
#include <ctype.h>
#include "tblib.h"

void mtbout(char* string, uint8_t color, uint8_t bg, bool bold, bool vn, unsigned int ms) {
	Text temp;
	temp.string = (char *)string;
	temp.color = color;
	temp.bg = bg;
	temp.bold = bold;
	tbout(temp, vn, ms);
}
uint8_t tbselect(uint8_t menu) {
    if (menu <= 0) {
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
        char *input = tbin(4);
        if (isdigit(input[0])) {
           choice = atoi(input);
           for (int i = 0; i < menu; i++) {
               if (options[i] == choice) {
                   valid = true;
                   break;
               }
           }
        }
        free(input);
    }
    return choice;
}
