#!/bin/sh
g++ -c -O2 -o MCEventDict.o ../src/MCEventDict.cc -fPIC `root-config --cflags` -I../include
g++ -c -O2 -o MCEvent.o ../src/MCEvent.cc -fPIC `root-config --cflags` -I../include -I/opt/geant4.10.00.p03-install/include/Geant4
g++ -c -O2 -o make_plots.o make_plots.cc -fPIC `root-config --cflags` -I../include
g++ -o make_plots make_plots.o  MCEvent.o MCEventDict.o `root-config --glibs` `root-config --cflags` -I../include
rm *.o
