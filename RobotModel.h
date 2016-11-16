/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RobotModel.h
 * Author: thomas
 *
 * Created on October 19, 2016, 10:08 AM
 */

#ifndef ROBOTMODEL_H
#define ROBOTMODEL_H

#include <vector>
#include <string>

class RobotModel {
public:
    RobotModel();
    int torso,head,locomotor;
    int batt1=-1,batt2=-1,batt3=-1; 
    int arm1=-1,arm2=-1,arm3=-1;
    std::string name;
};

#endif /* ROBOTMODEL_H */

