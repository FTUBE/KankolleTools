#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<vector>
#include "ensei.h"

using namespace std;

const int MAXLENGTH = 100;
const int COMMLENGTH = 18;
const int JIKANLENGTH = 256;
const int TYPELENGTH = 256;
const int KANMUSULENGTH = 256;

int console();
void kenzouRecipe();
void kenzouTime();
void parse(char *line,int &now, char *type, char *kanmusu);
void getEnseiSearch();

int main(){
    bool enseiload = false;
  
  while(true){
    int c = console();
    switch(c){
    case 0:
      break;
    case 1:
      kenzouRecipe();
      break;
    case 2:
      if(!enseiload)loadEnsei();
      getEnseiSearch();
    break;
    case 6:
      kenzouTime();
      break;
    default:
      break;
    }
  }
  return 0;
}

int console(){

  string console_line[] = {"建造レシピ (ken)",
			   "遠征について (ensei)",
			   "改造レベル (kai)",
			   "艦載機（制空/砲撃戦）の最大化方案 (kan)",
			   "出撃関連 (syu)",
			   "時間(jikan)"};
  
  for(int i = 0; i < 6;i++){
    cout << console_line[i] << endl;
  }
  
  char *comm = new char[COMMLENGTH+1];
  cin.getline(comm,COMMLENGTH);

  if(strcmp(comm,"ken") == 0){
    delete [] comm;
    return 1;
  }

  if(strcmp(comm,"ensei") == 0){
    delete [] comm;
    return 2;
  }
  
  if(strcmp(comm,"kai") == 0){
    delete [] comm;
    return 3;
  }

  if(strcmp(comm,"jikan") == 0){
    delete [] comm;
    return 6;
  }
  
  return 0;
}


void kenzouRecipe(){

  printf("======================\n");
  printf("駆逐艦:\n30 30 30 30\n");
  printf("250 30 200 30 レア駆逐艦-雪風,島風,Z3(Z1旗艦),Z1(Z3旗艦)のみ\n\n");
  printf("軽巡:\n30 30 30 30\n");
  printf("250 30 200 30 低い確率で潜水艦\n\n");
  printf("重巡:\n250 30 200 30\n\n");
  printf("戦艦:\n400 30 600 30\n\n");
  printf("空母:\n300 30 400 300\n\n");
  printf("潜水艦:\n250 30 200 30\n");
  printf("======================\n\n");

  return;
}

void kenzouTime(){
  
  int time;
  cin >> time;
  
  ifstream in;
  in.open("jikan.data");

  char *line = new char[JIKANLENGTH];
  char *type = new char[TYPELENGTH];
  char *kanmusu = new char[KANMUSULENGTH];
  
  int now;
  char nextcomm;
  
  in.getline(line,JIKANLENGTH);
  parse(line,now,type,kanmusu);
  printf("\n");
  if(now == time){
    printf("----->%d, %s , %s\n\n",now,type,kanmusu);
  }
  while(in.getline(line,256)){
    parse(line,now,type,kanmusu);
    if(now > time) break;
    if(now == time) printf("----->%d, %s , %s\n\n",now,type,kanmusu);
  }
  
  delete []line;
  delete []kanmusu;
  delete []type;
  
  in.close();
}

void parse(char *line,int &now, char *type, char *kanmusu){
  char *piece = strtok(line,",");
  string time_str(piece);
  now = stoi(time_str);
  piece = strtok(NULL,",");
  strcpy(type,piece);
  piece = strtok(NULL,",");
  strcpy(kanmusu,piece);
  return;
}

void getEnseiSearch(){

  char comm_c;
  bool q = false;
  
  cin >> comm_c;
  char *query_str, *piece;
  vector<int> query;
  switch(comm_c){
    
  case 's':
    cin.ignore();
    query_str = new char[MAXLENGTH];
    cin.getline(query_str,MAXLENGTH);
    cout <<"=============";
    piece = strtok(query_str," ");
    while(piece != NULL){
      string q_int(piece);
      query.push_back(stoi(q_int));
      piece = strtok(NULL," ");
    }
    for(int i = 0; i < query.size();i++) getEnseiInfo(query[i]);
    cout <<"=============\n";
    break;
    
  default:
    q = true;
    break;
  }
}
