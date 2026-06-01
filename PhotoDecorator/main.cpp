#include "editor.hpp"
#include <iostream>

using namespace std;

int MIN;
int width, height, color_depth;
int s_width, s_height, s_color_depth;
png_byte color_type;
png_byte bit_depth;
png_byte s_color_type;
png_byte s_bit_depth;

struct Pixel **row_pointers = NULL;
struct Pixel **st_pointers = NULL;

int main(int argc, char *argv[]) {
  if (argc != 3)
    abort();

  read_png_file(argv[1]);
  cout << "-----------------" << endl;
  cout << "The size of cutted png file is " << MIN << "*" << MIN << endl;
  write_cutted_png_file();
  cout << "Check 'cutted.png'!" << endl;
  cout << "The interval between grids is 40 pixel" << endl;
  process_png_file();
  write_png_file(argv[2]);

  return 0;
}
