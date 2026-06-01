#include "editor.hpp"

//사진에 스티커를 추가
int add_sticker(int pos_x, int pos_y) {
  for(int y = 0; y < MIN; y++) {
    for(int x = 0; x < MIN; x++) {
      if(y < s_height && x < s_width && st_pointers[y][x].a != 0) {
        row_pointers[pos_y+y][pos_x+x].r = st_pointers[y][x].r;
        row_pointers[pos_y+y][pos_x+x].g = st_pointers[y][x].g;
        row_pointers[pos_y+y][pos_x+x].b = st_pointers[y][x].b;
        row_pointers[pos_y+y][pos_x+x].a = st_pointers[y][x].a;
      }
    }
  }
  return 0;
}