#include <cstdlib>
#include <iostream>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>

using namespace std;
// Widgets
Fl_Window *win;
Fl_Menu_Bar *menubar;
Fl_Box *box;

// Callbacks
void CloseCB(Fl_Widget* w, void* p){
  win->hide();
}

// Menu

Fl_Menu_Item menuitems[]={
  { "&File",0,0,0,FL_SUBMENU },
    { "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
    { 0 },
  { 0 }
};

// Main
int main(){
  const int X = 640;
  const int Y = 480;

  win = new Fl_Window(X,Y,"Thomas' Robot Shop");

  menubar = new Fl_Menu_Bar(0,0,X,30);
  menubar->menu(menuitems);

  box = new Fl_Box(20,50,X-40,Y-70,"Welcome");
  box->box(FL_UP_BOX);
  box->labelfont(FL_BOLD+FL_ITALIC);
  box->labelsize(20);
  box->labeltype(FL_SHADOW_LABEL);

  win->callback(CloseCB, box);

  //Resizable
  win->resizable(*box);

  //Ending FLTK stuff
  win->end();
  win->show();
  return Fl::run();
}
