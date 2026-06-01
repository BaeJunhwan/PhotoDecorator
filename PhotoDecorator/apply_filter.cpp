#include "editor.hpp"

//사진에 필터를 적용
void apply_filter(char FI) { //line 339
  switch (FI)
    {
    case 'g':
      for(int y = 0; y < height; y++) {
          for(int x = 0; x < width; x++) {
              int avg = (row_pointers[y][x].r + row_pointers[y][x].g + row_pointers[y][x].b) / 3;
              row_pointers[y][x].r = avg;
              row_pointers[y][x].g = avg;
              row_pointers[y][x].b = avg;
          }
      }
      break;

    case 'c': //line 353
      for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
          row_pointers[y][x].r = 0;
        }
      }
      break;

    case 'a':
      for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
          row_pointers[y][x].g = 0;
        }
      }
      break;

    case 'z':
      for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
          row_pointers[y][x].b = 0;
        }
      }
      break;
    case 'i':
      for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
          row_pointers[y][x].r = 255 - row_pointers[y][x].r;
          row_pointers[y][x].g = 255 - row_pointers[y][x].g;
          row_pointers[y][x].b = 255 - row_pointers[y][x].b;
        }
      }
      break;

    case 'b':
      for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
          if(row_pointers[y][x].r+38 > 255) row_pointers[y][x].r = 255;
          else row_pointers[y][x].r += 38;
          if(row_pointers[y][x].g+38 > 255) row_pointers[y][x].g = 255;
          else row_pointers[y][x].g += 38;
          if(row_pointers[y][x].b+38 > 255) row_pointers[y][x].b = 255;
          else row_pointers[y][x].b += 38;
        }
      }
      break;

    case 's':
      for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
          int r = row_pointers[y][x].r;
          int g = row_pointers[y][x].g;
          int b = row_pointers[y][x].b;
          if(r*0.3588 + g*0.7044 + b*0.1368 > 255) row_pointers[y][x].r = 255;
          else row_pointers[y][x].r = r*0.3588 + g*0.7044 + b*0.1368;
          if(r*0.2990 + g*0.5870 + b*0.1140 > 255) row_pointers[y][x].g = 255;
          else row_pointers[y][x].g = r*0.2990 + g*0.5870 + b*0.1140;
          if(r*0.2392 + g*0.4696 + b*0.0912 > 255) row_pointers[y][x].b = 255;
          else row_pointers[y][x].b = r*0.2392 + g*0.4696 + b*0.0912;
        }
      }
      break;

    default:
        break;
    }
}