#ifndef ENSEI_H
#define ENSEI_H
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int ALL = 8;
const int MAXLENGTH_ensei = 512;

class ensei{

 public:
  int no,level,oil,bul,haga,al;
  string name,req;
  static ensei *e_list;
  ensei();

};

void loadEnsei();
void getEnseiInfo(int);

#endif
