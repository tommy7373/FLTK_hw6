# Makefile for HW6
CXX = $(shell fltk-config --cxx)
CXXFLAGS = -std=c++11 $(shell fltk-config --cxxflags)
LINKFLTK = $(shell fltk-config --ldstaticflags)
LINKFLTK_IMG = $(shell fltk-config --use-images --ldstaticflags)

all: executable

debug: CXXFLAGS += -g
debug: executable

rebuild: clean executable
executable: RobotModel.o RobotParts.o controller.o
	$(CXX) RobotModel.o RobotParts.o controller.o $(LINKFLTK)
RobotModel.o: RobotModel.cpp RobotModel.h
	$(CXX) $(CXXFLAGS) -w -c RobotModel.cpp
RobotParts.o: RobotParts.cpp RobotParts.h
	$(CXX) $(CXXFLAGS) -w -c RobotParts.cpp
controller.o: controller.cpp RobotParts.h RobotModel.h
	$(CXX) $(CXXFLAGS) -w -c controller.cpp

clean:
	rm -f *.o hw6.out
