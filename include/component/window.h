#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

void window(int height, int width, const char *title);
void window_parent(uint16_t window);

#endif