#include "editor.hpp"

int write_cutted_png_file() { // line 32
  struct Pixel **row_cutted_pointers = new Pixel *[height];
  for (int row = 0; row < height; row++) {
    row_cutted_pointers[row] = (Pixel *)calloc(width * 2, sizeof(struct Pixel));
  }
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      row_cutted_pointers[y][x].r = row_pointers[y][x].r;
      row_cutted_pointers[y][x].g = row_pointers[y][x].g;
      row_cutted_pointers[y][x].b = row_pointers[y][x].b;
      row_cutted_pointers[y][x].a = row_pointers[y][x].a;
    }
  }
  for (int y = 0; y <= height / 40; y++) {
    if (y >= height)
      break;
    for (int x = 0; x < width; x++) {
      row_cutted_pointers[40 * y][x].r = 0;
      row_cutted_pointers[40 * y][x].g = 0;
      row_cutted_pointers[40 * y][x].b = 0;
    }
  }
  for (int y = 0; y < height; y++) {
    for (int x = 0; x <= width / 40; x++) {
      if (x >= width)
        break;
      row_cutted_pointers[y][40 * x].r = 0;
      row_cutted_pointers[y][40 * x].g = 0;
      row_cutted_pointers[y][40 * x].b = 0;
    }
  }

  FILE *fp = fopen("cutted.png", "wb"); // line 62
  if (!fp) {
    fprintf(stderr, "could not open cutted.png\n");
    return 1;
  }

  png_structp png =
      png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png) {
    fprintf(stderr, "could not initialize png struct\n");
    return 1;
  }

  png_infop info = png_create_info_struct(png);
  if (!info) {
    png_destroy_write_struct(&png, (png_infopp)NULL);
    fclose(fp);
    return 1;
  }

  png_init_io(png, fp);

  // Output을 8bit depth, RGBA 포멧으로 지정.
  png_set_IHDR( // line 84
      png, info, MIN, MIN, 8, PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
      PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
  png_write_info(png, info);

  if (!row_cutted_pointers) {
    fprintf(stderr, "cannot read row_pointers\n");
    return 1;
  }

  png_write_image(png, (png_byte **)row_cutted_pointers);
  png_write_end(png, NULL);

  for (int y = 0; y < height; y++) {
    free(row_cutted_pointers[y]);
  }
  free(row_cutted_pointers);

  png_destroy_write_struct(&png, &info);

  fclose(fp);
  fp = NULL;

  return 0;
}