#include "editor.hpp"

int write_png_file(char *filename) {
  FILE *fp = fopen(filename, "wb");
     if (!fp) {
      fprintf(stderr, "could not open out.png\n");
      return 1;
   }

    if (!fp) {
      fprintf(stderr, "could not open in.png\n");
      return 1;
   }

  png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(!png) {
    fprintf(stderr, "could not initialize png struct\n");
    return 1;
  }

  png_infop info = png_create_info_struct(png);
    if(!info) {
    png_destroy_write_struct(&png, (png_infopp)NULL);
    fclose(fp);
    return 1;
  }

  png_init_io(png, fp);

  // Output을 8bit depth, RGBA 포멧으로 지정.
  png_set_IHDR(
    png, info, MIN, MIN, 8,
    PNG_COLOR_TYPE_RGB_ALPHA,PNG_INTERLACE_NONE,
    PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
  png_write_info(png, info);

  if (!row_pointers) {
    fprintf(stderr, "cannot read row_pointers\n");
    return 1;
  }

  png_write_image(png, (png_byte **)row_pointers);
  png_write_end(png, NULL);

  for(int y = 0; y < height; y++) {
    free(row_pointers[y]);
  }
  free(row_pointers);

  png_destroy_write_struct(&png, &info);

  fclose(fp);
  fp=NULL;

  return 0;

}
