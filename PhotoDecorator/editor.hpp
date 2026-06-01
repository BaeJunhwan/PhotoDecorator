#include <stdlib.h>
#include <png.h>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#define PNG_SETJMP_NOT_SUPPORTED

struct Pixel {
  png_byte r, g, b, a;
};

extern int MIN;
extern int width, height, color_depth;
extern int s_width, s_height, s_color_depth;
extern png_byte color_type;
extern png_byte bit_depth;
extern png_byte s_color_type;
extern png_byte s_bit_depth;

extern struct Pixel **row_pointers;
extern struct Pixel **st_pointers;

/*extern int MIN;

extern int width, height, color_depth;
extern int s_width, s_height, s_color_depth;
extern png_byte color_type;
extern png_byte bit_depth;
extern png_byte s_color_type;
extern png_byte s_bit_depth;

extern struct Pixel **row_pointers = NULL;
extern struct Pixel **st_pointers = NULL;*/

int write_cutted_png_file();
int add_frame(char FR, char FC);
void apply_filter(char FI);
int make_sticker(int n);
int add_sticker(int pos_x, int pos_y);
int read_png_file(char *filename);
int write_png_file(char *filename);
void process_png_file();