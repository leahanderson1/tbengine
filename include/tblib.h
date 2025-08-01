#ifndef TBLIB_H
#define TBLIB_H
#ifdef __cplusplus
#include <cstdint>
using namespace std;
#else
#include <stdint.h>
#endif
#define RED 0
#define GREEN 1
#define YELLOW 2
#define BLUE 3
#define MAGENTA 4
#define CYAN 5
#define LIGHTGRAY 6
#define BLACK 7
#define WHITE 8
#define DARKGRAY 9
#define BRIGHTRED 10
#define BRIGHTGREEN 11
#define BRIGHTYELLOW 12
#define BRIGHTBLUE 13
#define BRIGHTMAGENTA 14
#define BRIGHTCYAN 15
#define COLOR_RESET "\e[0m"
#ifdef __cplusplus
typedef struct {
	char *string;
	uint8_t color = WHITE;
	uint8_t bg = BLACK;
	bool bold = false;
} Text;
void tbout(Text text, bool vn = false, int ms = 0);
void tbconfirm(int ms = 500);
#else
typedef struct {
	char *string;
	uint8_t color;
	uint8_t bg;
	bool bold;
} Text;
void tbout(Text text, bool vn, int ms);
void tbconfirm(int ms);
#endif
#endif
