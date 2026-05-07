#ifndef DATA_H
#define DATA_H
#include<string>
struct vehicle_type {
    double a,b,c;
};

struct cable_type {
   std::string name;
    int current;
    double resistance;
    double cost;
};

extern vehicle_type vehicle[4];
extern cable_type cabel[3];
#endif

 
