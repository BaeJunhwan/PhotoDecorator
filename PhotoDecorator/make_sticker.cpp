#include "editor.hpp"

#include <iostream>

using namespace std;


//스티커를 st_pointers에 저장
int make_sticker(int n) {
  FILE *fp;
  if (n == 1) {
    fp = fopen("santa.png", "rb");
     if (!fp) {
      fprintf(stderr, "could not open in.png\n");
      return 1;
   }
  }
  else if (n == 2) {
    fp = fopen("mustache.png", "rb");
     if (!fp) {
      fprintf(stderr, "could not open in.png\n");
      return 1;
   }
  }
  else if (n == 3) {
    fp = fopen("tree.png", "rb");
     if (!fp) {
      fprintf(stderr, "could not open in.png\n");
      return 1;
   }
  }
  else if (n == 4) {
    fp = fopen("treedecoration.png", "rb");
     if (!fp) {
      fprintf(stderr, "could not open in.png\n");
      return 1;
    }
  }
  else {
    cout << "not correct value of n\n";
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

  s_width      = png_get_image_width(png, info);
  s_height     = png_get_image_height(png, info);
  s_color_type = png_get_color_type(png, info);
  s_bit_depth  = png_get_bit_depth(png, info);

  if(s_height == 16)
    png_set_strip_16(png);

  if(s_color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_palette_to_rgb(png);

  // PNG_COLOR_TYPE_GRAY_ALPHA는 늘 8bit나 16bit depth를 지님.
  if(s_color_type == PNG_COLOR_TYPE_GRAY && s_bit_depth < 8)
    png_set_expand_gray_1_2_4_to_8(png);

  if(png_get_valid(png, info, PNG_INFO_tRNS))
    png_set_tRNS_to_alpha(png);

  // 알파값을 지니지 않은 color_type에는 0xff를 채움.
  if(s_color_type == PNG_COLOR_TYPE_RGB ||
     s_color_type == PNG_COLOR_TYPE_GRAY ||
     s_color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

  if(s_color_type == PNG_COLOR_TYPE_GRAY ||
     s_color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    png_set_gray_to_rgb(png);

  png_read_update_info(png, info);

  st_pointers = new Pixel* [s_height];
  for(int row=0; row<s_height; row++) {
    st_pointers[row]=(Pixel *)calloc(s_width*2, sizeof(struct Pixel));
  }


  png_read_image(png, (png_byte **)st_pointers);

  png_read_end(png, NULL);

  png_destroy_read_struct(&png, &info, NULL);

  fclose(fp);
  fp=NULL;

  return 0;
}