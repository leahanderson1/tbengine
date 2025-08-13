#ifndef TBEXTRA_H
#include <stdint.h>
#include <stdbool.h>
#define TBEXTRA_H
void tbcolor(uint8_t fg, uint8_t bg, bool bold);
void msleep(unsigned int ms);
void setecho(bool enable);
#endif
