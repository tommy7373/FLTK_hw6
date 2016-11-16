/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RobotPart.cpp
 * Author: thomas
 * 
 * Created on October 4, 2016, 8:52 PM
 */

#include "RobotParts.h"
#include <iostream>

RobotPart::RobotPart() {
}
void RobotPart::SetInfo(std::string name, int modnum, double weight, double cost, std::string desc){
    Name=name; modelNumber=modnum; Weight=weight; Cost=cost; Description=desc;
    std::cout << Name << '\n' << modelNumber << '\n' << Type << '\n' << Weight << '\n' << Cost << '\n' << Description;
}

Head::Head(){
    Type="Head";
}
void Head::SetInfo(std::string name, int modnum, double weight, double cost, std::string desc){
    Name=name; modelNumber=modnum; Weight=weight; Cost=cost; Description=desc;
    std::cout << "Head created!\n";
    std::cout << Name << '\n' << modelNumber << '\n' << Type << '\n' << Weight << '\n' << Cost << '\n' << Description;
}
void Head::PrintInfo(){
    std::cout << Type << "\t\t" << modelNumber << "\t" << Name << "\t" << Weight << '\t' << Cost << '\n';
    std::cout << "Description: " << Description << "\n";
}

Locomotor::Locomotor(){
    Type="Locomotor";
}
void Locomotor::SetInfo(std::string name, int modnum, double weight, double cost, std::string desc){
    Name=name; modelNumber=modnum; Weight=weight; Cost=cost; Description=desc;
    std::cout << "Locomotor created!\n";
    std::cout << Name << '\n' << modelNumber << '\n' << Type << '\n' << Weight << '\n' << Cost << '\n' << Description << '\n';
}
void Locomotor::setLocomotorInfo(double speed){
    Speed=speed;
}
void Locomotor::PrintInfo(){
    std::cout << Type << "\t" << modelNumber << "\t" << Name << "\t" << Weight << '\t' << Cost << "\t Speed: "<< Speed;
    std::cout << "\nDescription: " << Description << "\n";
}

Torso::Torso(){
    Type="Torso";
}
void Torso::SetInfo(std::string name, int modnum, double weight, double cost, std::string desc){
    Name=name; modelNumber=modnum; Weight=weight; Cost=cost; Description=desc;
    std::cout << "Torso created!\n";
    std::cout << Name << '\n' << modelNumber << '\n' << Type << '\n' << Weight << '\n' << Cost << '\n' << Description << '\n';
}
void Torso::setBatteryCompartments(int batteries){
    batteryCompartments=batteries;
}
void Torso::PrintInfo(){
    std::cout << Type << "\t\t" << modelNumber << "\t" << Name << "\t" << Weight << '\t' << Cost << "\t Compartments: " << batteryCompartments;
    std::cout << "\nDescription: " << Description << "\n";
}

Arm::Arm(){
    Type="Arm";
}
void Arm::SetInfo(std::string name, int modnum, double weight, double cost, std::string desc){
    Name=name; modelNumber=modnum; Weight=weight; Cost=cost; Description=desc;
    std::cout << "Arm created!\n";
    std::cout << Name << '\n' << modelNumber << '\n' << Type << '\n' << Weight << '\n' << Cost << '\n' << Description << '\n';
}
void Arm::setPowerConsumed(double power){
    powerConsumed=power;
}
void Arm::PrintInfo(){
    std::cout << Type << "\t\t" << modelNumber << "\t" << Name << "\t" << Weight << '\t' << Cost << "\t Power: " << powerConsumed;
    std::cout << "\nDescription: " << Description << "\n";
}

Battery::Battery(){
    Type="Battery";
}
void Battery::SetInfo(std::string name, int modnum, double weight, double cost, std::string desc){
    Name=name; modelNumber=modnum; Weight=weight; Cost=cost; Description=desc;
    std::cout << "Battery created!\n";
    std::cout << Name << '\n' << modelNumber << '\n' << Type << '\n' << Weight << '\n' << Cost << '\n' << Description << '\n';
}
void Battery::setBatteryInfo(double energy){
    Energy=energy;
}
void Battery::PrintInfo(){
    std::cout << Type << "\t\t" << modelNumber << "\t" << Name << "\t" << Weight << '\t' << Cost << "\t Capacity: "<< Energy;
    std::cout << "\nDescription: " << Description << "\n";
}
