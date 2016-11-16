/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RobotPart.h
 * Author: thomas
 *
 * Created on October 4, 2016, 8:52 PM
 */

#ifndef ROBOTPARTS_H
#define ROBOTPARTS_H

#include <string>
#include <vector>

class RobotPart {
public:
    std::string Name;
    std::string Type;
    double Weight;
    double Cost;
    std::string Description;
    RobotPart();
    virtual void SetInfo(std::string name, int modnum, double weight, double cost, std::string desc);
    int modelNumber;
    
};

class Head : public RobotPart
{
public:
    Head();
    void SetInfo(std::string name, int modnum, double weight, double cost, std::string desc);
    void PrintInfo();
};

class Locomotor : public RobotPart
{
public:
    Locomotor();
    double Speed;
    void SetInfo(std::string name, int modnum, double weight, double cost, std::string desc);
    void setLocomotorInfo(double speed);
    void PrintInfo();
};

class Battery : public RobotPart
{
public:
    Battery();
    double Energy;
    void SetInfo(std::string name, int modnum, double weight, double cost, std::string desc);
    void setBatteryInfo(double energy);
    void PrintInfo();
};

class Arm : public RobotPart
{
public:
    Arm();
    void setPowerConsumed(double power);
    void SetInfo(std::string name, int modnum, double weight, double cost, std::string desc);
    double powerConsumed;
    void PrintInfo();
};

class Torso : public RobotPart
{
public:
    Torso();
    int batteryCompartments;
    void SetInfo(std::string name, int modnum, double weight, double cost, std::string desc);
    void setBatteryCompartments(int batteries);
    void PrintInfo();
};

#endif /* ROBOTPARTS_H */