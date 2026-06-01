#include "editor.hpp"

//사진에 액자를 추가
int add_frame(char FR, char FC) { //line 112
  int c_m=MIN/2, w_c1=MIN/4, w_c2=MIN/4*3, ro=MIN/2-1;
  int FC_r, FC_g, FC_b;

  //액자 색상 정보 저장
  switch(FC) //line 117
  {
    case 'r':
      FC_r=255;
      FC_g=0;
      FC_b=0;
      break;

    case 'g':
      FC_r=0;
      FC_g=255;
      FC_b=0;
      break;

    case 'w':
      FC_r=255;
      FC_g=255;
      FC_b=255;
      break;

    case 'b':
      FC_r=0;
      FC_g=0;
      FC_b=255;
      break;

    case 'd':
      FC_r=0;
      FC_g=0;
      FC_b=0;
      break;

    case 'l':
      FC_r=153;
      FC_g=102;
      FC_b=51;
      break;

    default:
      break;
  }

  //액자 모양 정보 저장
  switch (FR) //line 160
  {
    case 's':
      for(int y = 0; y < MIN; y++) {
        for(int x = 0; x < MIN; x++) {
          if(((x<30||x>MIN-30) && (y<50 || y>MIN-50)) || (y<15||y>MIN-15) ||(x<15||x>MIN-15)) {
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[y][x].a = 255;
          }
        } 
      }
      break;

    case 'c': 
      for(int y=0; y<MIN; y++) {
        for(int x=0; x<MIN; x++) {
          if((x-c_m)*(x-c_m)   + (y-c_m)*(y-c_m) >= ro*ro) {
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[y][x].a = 255;
          }
        }
      }
      break;

    case 'f': //line 188
      for(int y=0; y<MIN; y++) {
        for(int x=0; x<MIN; x++) {
          if((((x-w_c1)*(x-w_c1)   + (y-w_c1)*(y-w_c1) <= w_c1*w_c1) &&((x-w_c1)*(x-w_c1)   + (y-w_c1)*(y-w_c1) >= (w_c1-5)*(w_c1-5))) && ((x<w_c1 && y<MIN/2))) {
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[x][y].r=FC_r;
            row_pointers[x][y].g=FC_g;
            row_pointers[x][y].b=FC_b;
            row_pointers[y][x].a = 255;
            row_pointers[x][y].a = 255;
          }

          else if((((x-w_c1)*(x-w_c1)   + (y-w_c2)*(y-w_c2) <= w_c1*w_c1) &&((x-w_c1)*(x-w_c1)   + (y-w_c2)*(y-w_c2) >= (w_c1-5)*(w_c1-5))) && ((x<w_c1 && y>MIN/2 && y<MIN))) {
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[x][y].r=FC_r;
            row_pointers[x][y].g=FC_g;
            row_pointers[x][y].b=FC_b;
            row_pointers[y][x].a = 255;
            row_pointers[x][y].a = 255;
          }

          else if((((x-w_c2)*(x-w_c2)   + (y-w_c1)*(y-w_c1) <= w_c1*w_c1) &&((x-w_c2)*(x-w_c2)   + (y-w_c1)*(y-w_c1) >= (w_c1-5)*(w_c1-5))) && ((x>w_c2 && x<MIN && y<MIN/2))) {
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[x][y].r=FC_r;
            row_pointers[x][y].g=FC_g;
            row_pointers[x][y].b=FC_b;
            row_pointers[y][x].a = 255;
            row_pointers[x][y].a = 255;
          }

          else if((((x-w_c2)*(x-w_c2)   + (y-w_c2)*(y-w_c2) <= w_c1*w_c1) &&((x-w_c2)*(x-w_c2)   + (y-w_c2)*(y-w_c2) >= (w_c1-5)*(w_c1-5))) && ((x>w_c2 && x<MIN && y>MIN/2 &&y<MIN))) {
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[x][y].r=FC_r;
            row_pointers[x][y].g=FC_g;
            row_pointers[x][y].b=FC_b;
            row_pointers[y][x].a = 255;
            row_pointers[x][y].a = 255;
          }
        }
      }
      break;

    case 'm': //line 238
      for(int y=0; y<w_c1+20; y++) {
        for(int x=0; x<w_c1+20; x++) {
          if(x*x+y*y<=(w_c1*w_c1)) {
            row_pointers[y][x].a=0;
          }
          else if((x*x+y*y>(w_c1*w_c1)) && (x*x+y*y<=(w_c1+20)*(w_c1+20))){
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[y][x].a = 255;
          }
        }
      }
      for(int y=0; y<20; y++) {
        for(int x=w_c1; x<w_c2; x++) {
          row_pointers[y][x].r =FC_r;
          row_pointers[y][x].g =FC_g;
          row_pointers[y][x].b =FC_b;
          row_pointers[y][x].a = 255;
        }
      }
      for(int y=0; y<w_c1+20; y++) {
        for(int x=w_c2-20; x<MIN; x++) {
          if((MIN-x)*(MIN-x)+y*y<=(w_c1*w_c1)) {
            row_pointers[y][x].a=0;
          }
          else if(((MIN-x)*(MIN-x)+y*y>(w_c1*w_c1)) && ((MIN-x)*(MIN-x)+y*y<=(w_c1+20)*(w_c1+20))){
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[y][x].a = 255;
          }

        }
      }
      for(int y=w_c1; y<w_c2; y++) {
        for(int x=0; x<20; x++) {
          row_pointers[y][x].r =FC_r;
          row_pointers[y][x].g =FC_g;
          row_pointers[y][x].b =FC_b;
          row_pointers[y][x].a = 255;
        }
      }
      for(int y=w_c2-20; y<MIN; y++) {
        for(int x=0; x<w_c1+20; x++) {
          if(x*x+(MIN-y)*(MIN-y)<=(w_c1*w_c1)) {
              row_pointers[y][x].a=0;
          }
          else if((x*x+(MIN-y)*(MIN-y)>(w_c1*w_c1)) && (x*x+(MIN-y)*(MIN-y)<=(w_c1+20)*(w_c1+20))){
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[y][x].a = 255;
          } 
        }
      }

      for(int y=w_c1; y<w_c2; y++) {
        for(int x=MIN-20; x<MIN; x++) {
          row_pointers[y][x].r =FC_r;
          row_pointers[y][x].g =FC_g;
          row_pointers[y][x].b =FC_b;
          row_pointers[y][x].a = 255;
        }
      }


      for(int y=MIN-20; y<MIN; y++) {
        for(int x=w_c1; x<w_c2; x++) {
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[y][x].a = 255;
        }
      }

      for(int y=w_c2-20; y<MIN; y++) {
        for(int x=w_c2-20; x<MIN; x++) {
          if((MIN-x)*(MIN-x)+(MIN-y)*(MIN-y)<=(w_c1*w_c1)) {
            row_pointers[y][x].a=0;
          }
          else if(((MIN-x)*(MIN-x)+(MIN-y)*(MIN-y)>(w_c1*w_c1)) && ((MIN-x)*(MIN-x)+(MIN-y)*(MIN-y)<=(w_c1+20)*(w_c1+20))){
            row_pointers[y][x].r =FC_r;
            row_pointers[y][x].g =FC_g;
            row_pointers[y][x].b =FC_b;
            row_pointers[y][x].a = 255;
          }
        }
      } 
      break;

    default:
      break;
  }

  return 0;

}