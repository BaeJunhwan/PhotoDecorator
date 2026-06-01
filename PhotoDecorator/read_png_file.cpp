#include "editor.hpp"
#include <iostream>
#include <png.h>
using namespace std;

//png 파일을 읽어서 row_pointers에 저장
int read_png_file(char *filename) { //line 536
  FILE *fp = fopen(filename, "rb"); //line 537
     if (!fp) {
      fprintf(stderr, "could not open input file\n");
      return 1;
   }

  png_structp png;
  png_infop info;

  png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if(!png) {
    fprintf(stderr, "could not initialize png struct\n");
    return 1;
  }

  info = png_create_info_struct(png);
  if(!info) {
    png_destroy_write_struct(&png, (png_infopp)NULL);
    fclose(fp);
    return 1;
  }

  png_init_io(png, fp);
  png_read_info(png, info);

  width      = png_get_image_width(png, info);
  height     = png_get_image_height(png, info);
  color_type = png_get_color_type(png, info);
  bit_depth  = png_get_bit_depth(png, info);

  MIN = min(width, height);

  if(bit_depth == 16) //line 569
    png_set_strip_16(png);

  if(color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_palette_to_rgb(png);

  // PNG_COLOR_TYPE_GRAY_ALPHA는 늘 8bit나 16bit depth를 지님.
  if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
    png_set_expand_gray_1_2_4_to_8(png);

  if(png_get_valid(png, info, PNG_INFO_tRNS))
    png_set_tRNS_to_alpha(png);

  // 알파값을 지니지 않은 color_type에는 0xff를 채움.
  if(color_type == PNG_COLOR_TYPE_RGB ||
     color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

  if(color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    png_set_gray_to_rgb(png);

  png_read_update_info(png, info);

  row_pointers = new Pixel* [height];
  for(int row=0; row<height; row++) {
    row_pointers[row]=(Pixel *)calloc(width*2, sizeof(struct Pixel));
  }


  png_read_image(png, (png_byte **)row_pointers);

  png_read_end(png, NULL);

  png_destroy_read_struct(&png, &info, NULL);

  fclose(fp);
  fp=NULL;

  return 0;

}