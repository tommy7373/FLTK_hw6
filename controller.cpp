#include <cstdlib>
#include <iostream>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>

using namespace std;

// Declarations
void CreateRobotPartCB(Fl_Widget* w, void* p);
void CancelRobotPartCB(Fl_Widget* w, void* p);
class RobotPartDialog;

// Classes
class Robot_Part_Dialog {
  public:
    Robot_Part_Dialog() { // Create and populate the dialog (but don't show it!)
      dialog = new Fl_Window(340, 270, "Robot Part");
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
        rp_type->align(FL_ALIGN_LEFT);
        rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)CreateRobotPartCB, 0);
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)CancelRobotPartCB, 0);
      dialog->end();
      dialog->set_non_modal();
    }
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rp_name->value();}
    string part_number() {return rp_part_number->value();}
    string type() {return rp_type->value();}
    string weight() {return rp_weight->value();}
    string cost() {return rp_cost->value();}
    string description() {return rp_description->value();}
  private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_part_number;
    Fl_Input *rp_type;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

// Widgets
Fl_Window *win;
Fl_Menu_Bar *menubar;
Robot_Part_Dialog *robot_part_dlg;


// Callbacks
void CB(Fl_Widget* w, void* p){} //Does nothing

void CloseCB(Fl_Widget* w, void* p){
  win->hide();
}

void MenuCreateRobotPartCB(Fl_Widget* w, void* p){
  robot_part_dlg->show();
}

void CreateRobotPartCB(Fl_Widget* w, void* p){ 
  cout << "### Creating robot part" << endl;
  cout << "Name : " << robot_part_dlg->name() << endl;
  cout << "Part # : " << robot_part_dlg->part_number() << endl;
  cout << "Type : " << robot_part_dlg->type() << endl;
  cout << "Weight : " << robot_part_dlg->weight() << endl;
  cout << "Cost : " << robot_part_dlg->cost() << endl;
  cout << "Descript: " << robot_part_dlg->description() << endl;
  robot_part_dlg->hide();
}

void CancelRobotPartCB(Fl_Widget* w, void* p){
  robot_part_dlg->hide();
}

// Menu
Fl_Menu_Item menuitems[]={
  { "&File",0,0,0,FL_SUBMENU },
    { "&New", FL_ALT + 'n', (Fl_Callback *)CB },
    { "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
    { 0 },
  { "&Edit",0,0,0,FL_SUBMENU },
    { 0 },
  { "&Create",0,0,0,FL_SUBMENU },
    { "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
    { "Customer", 0, (Fl_Callback *)CB },
    { "Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
    { "Robot Part", 0, (Fl_Callback *)MenuCreateRobotPartCB },
    { "Robot Model", 0, (Fl_Callback *)CB },
    { 0 },
  { "&Report",0,0,0,FL_SUBMENU },
    { 0 },
  { "&Help",0,0,0,FL_SUBMENU },
    { 0 },
  { 0 }
};

// Main
int main(){
  const int X = 640;
  const int Y = 480;

  robot_part_dlg = new Robot_Part_Dialog;

  win = new Fl_Window(X,Y,"Thomas' Robot Shop"); //Create window
  win->color(FL_WHITE);

  menubar = new Fl_Menu_Bar(0,0,X,30); //Create menubar
  menubar->menu(menuitems);

  /* Test box
  box = new Fl_Box(20,50,X-40,Y-70,"Welcome");
  box->box(FL_UP_BOX);
  box->labelfont(FL_BOLD+FL_ITALIC);
  box->labelsize(20);
  box->labeltype(FL_SHADOW_LABEL);
  */

  win->callback(CloseCB, win); //Closing callback

  win->resizable(*win); //Resizable

  //Ending FLTK stuff
  win->end();
  win->show();
  return Fl::run();
}
