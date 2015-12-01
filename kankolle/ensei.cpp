#include "ensei.h"

ensei::ensei(){};
ensei* ensei::e_list = new ensei[ALL];

void loadEnsei(){
  
  ifstream in;
  in.open("ensei.data");

  char *line = new char[MAXLENGTH_ensei];
  for(int i = 0; i < ALL;i++){
    in.getline(line,MAXLENGTH_ensei);
    char *piece = strtok(line,",");
    ensei e;
    e.no = stoi(piece);
    piece = strtok(NULL,",");
    string name_str(piece);
    e.name = name_str;
    piece = strtok(NULL,",");
    e.level = stoi(piece);
    piece = strtok(NULL,",");
    e.oil = stoi(piece);
    piece = strtok(NULL,",");
    e.bul = stoi(piece);
    piece = strtok(NULL,",");
    e.haga = stoi(piece);
    piece = strtok(NULL,",");
    e.al = stoi(piece);
    piece = strtok(NULL,",");
    string req_str(piece);
    e.req = req_str;
    ensei::e_list[i] = e;
  }
  
};

void getEnseiInfo(int no){
  ensei e = ensei::e_list[no-1];
  cout << "\n"<<e.no<<"."<<e.name << "\n必要レベル:"<<e.level<<endl;
  cout << "燃:"<<e.oil<<endl;
  cout << "弾:"<<e.bul<<endl;
  cout << "鋼:"<<e.haga<<endl;
  cout << "ポーキ:"<<e.al<<endl;
  cout << "編成:"<<e.req<<endl;
}
