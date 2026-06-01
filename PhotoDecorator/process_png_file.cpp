#include "editor.hpp"

#include <iostream>
using namespace std;
void process_png_file() { // line 671
  char FI, FR, FC;        // line 672
  char YN, ST;
  int pos_x, pos_y;

  while (1) {
    cout << "-----------------" << endl;
    cout << "Choose one filter \n(g : gray scale, c : cotton candy, a : alien, "
            "z : cheese, n : normal, i : invert, b : bright, s : sepia)\n";
    cin >> FI;
    cin.ignore(100, '\n');
    if (FI != 'g' && FI != 'c' && FI != 'a' && FI != 'z' && FI != 'n' &&
        FI != 'i' && FI != 'b' && FI != 's') {
      cout << "Choose right filter\n";
    } else
      break;
  }
  apply_filter(FI);

  while (true) { // line 688
    cout << "-----------------" << endl;
    cout << "Choose one frame(s: standard rectangular frame, m: medieval "
            "frame, f: four leaf clover frame, c: circle frame)\n";
    cin >> FR;
    cin.ignore(100, '\n');
    if (FR == 's' || FR == 'c' || FR == 'f' || FR == 'm') {
      break;
    }
  }
  while (true) {
    cout << "Choose one frame color(r: red, g: green, w:white, b:blue, d:dark "
            "black, l:light brown)\n";
    cin >> FC;
    cin.ignore(100, '\n');
    if (FC == 'r' || FC == 'g' || FC == 'w' || FC == 'b' || FC == 'd' ||
        FC == 'l') {
      break;
    }
  }
  add_frame(FR, FC);

  while (1) {
    cout << "-----------------" << endl;
    cout << "Do you want to add stickers? [y/n]\n";
    cin >> YN;
    cin.ignore(100, '\n');
    if (YN == 'y') {
      cout << "Which sticker do you want to add? (1 : hat, 2 : mustache, 3 : "
              "tree, 4 : tree decoration)\n";
      cin >> ST;
      cin.ignore(100, '\n');
      if (ST == '1' || ST == '2' || ST == '3' || ST == '4') {
        int m = ST - '0';
        cout << "Write left_upper position of the sticker ({pos_x} {pos_y})"
             << endl;
        cin >> pos_x >> pos_y;
        make_sticker(m);
        add_sticker(pos_x, pos_y);
      } else {
        cout << "Write correct sticker!\n";
      }
    } else if (YN == 'n')
      break;
    else {
      cout << "You can write only 'y' or 'n'!\n";
    }
  }
}
