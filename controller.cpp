#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include "RobotParts.h"
#include "RobotModel.h"

using namespace std;

// Declarations
void CreateRobotPartCB(Fl_Widget* w, void* p);
void CancelRobotPartCB(Fl_Widget* w, void* p);
void CreateRobotModelCB(Fl_Widget* w, void* p);
void CancelRobotModelCB(Fl_Widget* w, void* p);
class RobotPartDialog;
class RobotModelDialog;


// Classes
class Robot_Part_Dialog {
  public:
    Robot_Part_Dialog() { // Create and populate the dialog (but don't show it!)
      dialog = new Fl_Window(340, 270, "Robot Part");
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        rp_part_number = new Fl_Int_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
        rp_type->align(FL_ALIGN_LEFT);
        rp_weight = new Fl_Float_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        rp_cost = new Fl_Float_Input(120, 130, 210, 25, "Cost:");
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
    int part_number() {return stoi(rp_part_number->value());}
    string type() {return rp_type->value();}
    double weight() {return stod(rp_weight->value());}
    double cost() {return stod(rp_cost->value());}
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
class Robot_Model_Dialog {
  public:
    Robot_Model_Dialog() { // Create and populate the dialog (but don't show it!)
      dialog2 = new Fl_Window(340, 270, "Robot Model");
        rm_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rm_name->align(FL_ALIGN_LEFT);
        rm_part_number = new Fl_Int_Input(120, 40, 210, 25, "Part Number:");
        rm_part_number->align(FL_ALIGN_LEFT);
        rm_type = new Fl_Input(120, 70, 210, 25, "Type:");
        rm_type->align(FL_ALIGN_LEFT);
        rm_weight = new Fl_Float_Input(120, 100, 210, 25, "Weight:");
        rm_weight->align(FL_ALIGN_LEFT);
        rm_cost = new Fl_Float_Input(120, 130, 210, 25, "Cost:");
        rm_cost->align(FL_ALIGN_LEFT);
        rm_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rm_description->align(FL_ALIGN_LEFT);
        rm_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rm_create->callback((Fl_Callback *)CreateRobotModelCB, 0);
        rm_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rm_cancel->callback((Fl_Callback *)CancelRobotModelCB, 0);
      dialog2->end();
      dialog2->set_non_modal();
    }
    void show() {dialog2->show();}
    void hide() {dialog2->hide();}
    string name() {return rm_name->value();}
    int part_number() {return stoi(rm_part_number->value());}
    string type() {return rm_type->value();}
    double weight() {return stod(rm_weight->value());}
    double cost() {return stod(rm_cost->value());}
    string description() {return rm_description->value();}
  private:
    Fl_Window *dialog2;
    Fl_Input *rm_name;
    Fl_Input *rm_part_number;
    Fl_Input *rm_type;
    Fl_Input *rm_weight;
    Fl_Input *rm_cost;
    Fl_Input *rm_description;
    Fl_Return_Button *rm_create;
    Fl_Button *rm_cancel;
};
//Class functions

// Widgets
Fl_Window *win;
Fl_Menu_Bar *menubar;
Robot_Part_Dialog *robot_part_dlg;
Robot_Model_Dialog *robot_model_dlg;

// Callbacks
void CB(Fl_Widget* w, void* p){} //Does nothing

void CloseCB(Fl_Widget* w, void* p){ //Exits app
  win->hide();
}

void MenuCreateRobotPartCB(Fl_Widget* w, void* p){
  robot_part_dlg->show();
}
void MenuCreateRobotModelCB(Fl_Widget* w, void* p){
  robot_model_dlg->show();
}

void CreateRobotPartCB(Fl_Widget* w, void* p){ 
  cout << "### Creating robot part" << endl;
  string name = robot_part_dlg->name();
  string type = robot_part_dlg->type();
  int partnum = robot_part_dlg->part_number();
  double weight = robot_part_dlg->weight();
  double cost = robot_part_dlg->cost();
  string desc = robot_part_dlg->description();
  if(robot_part_dlg->type() == "Torso"||"torso"){
    Torso torso;
    torso.SetInfo(name,partnum,weight,cost,desc);
  }
  if(robot_part_dlg->type() == "Battery"||"battery"){
    Battery battery;
    battery.SetInfo(name,partnum,weight,cost,desc);
  }
  if(robot_part_dlg->type() == "Arm"||"arm"){
    Arm arm;
    arm.SetInfo(name,partnum,weight,cost,desc);
  }
  if(robot_part_dlg->type() == "Locomotor"||"locomotor"){
    Locomotor locomotor;
    locomotor.SetInfo(name,partnum,weight,cost,desc);
  }
  if(robot_part_dlg->type() == "Head"||"head"){
    Head head;
    head.SetInfo(name,partnum,weight,cost,desc);
  }
  cout << "Name : " << robot_part_dlg->name() << endl;
  cout << "Part # : " << robot_part_dlg->part_number() << endl;
  cout << "Type : " << robot_part_dlg->type() << endl;
  cout << "Weight : " << robot_part_dlg->weight() << endl;
  cout << "Cost : " << robot_part_dlg->cost() << endl;
  cout << "Descript: " << robot_part_dlg->description() << endl;
  robot_part_dlg->hide();
}
void CreateRobotModelCB(Fl_Widget* w, void* p){

}

void CancelRobotPartCB(Fl_Widget* w, void* p){
  robot_part_dlg->hide();
}
void CancelRobotModelCB(Fl_Widget* w, void* p){
  robot_model_dlg->hide();
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
  vector<RobotModel> robotmodels;
  vector<Head> headV;
  vector<Locomotor> locomotorV;
  vector<Torso> torsoV;
  vector<Arm> armV;
  vector<Battery> batteryV;

  robot_part_dlg = new Robot_Part_Dialog;
  robot_model_dlg = new Robot_Model_Dialog;

  win = new Fl_Window(X,Y,"Thomas' Robot Shop"); //Create window
  win->color(FL_WHITE);

  menubar = new Fl_Menu_Bar(0,0,X,30); //Create menubar
  menubar->menu(menuitems);

  win->callback(CloseCB, win); //Closing callback

  win->resizable(*win); //Resizable

  //Ending FLTK stuff
  win->end();
  win->show();
  return Fl::run();
}
