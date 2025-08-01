#ifndef TBEXTRA_H
#include <stdint.h>
#define TBEXTRA_H
void tbcolor(uint8_t fg, uint8_t bg, bool bold);
void msleep(int ms);
void setecho(bool enable);
#endif
