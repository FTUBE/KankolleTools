#include<iostream>
#include<cstring>
#include<string>
#include<fstream>

using namespace std;

const int MAXLENGTH = 100;

int console();
void kenzouRecipe();
void kenzouTime();
void parse(char *line,int &now, char *type, char *kanmusu);

int main(){
  
  while(true){
    int c = console();
    switch(c){
    case 0:
      break;
    case 1:
      kenzouRecipe();
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
			   "遠征について (en)",
			   "改造レベル (kai)",
			   "艦載機 (kan)",
			   "出撃関連 (syu)",
			   "時間(jikan)"};
  
  for(int i = 0; i < 6;i++){
    cout << console_line[i] << endl;
  }
  
  char *comm = new char[MAXLENGTH];

  cin.getline(comm,MAXLENGTH);
  
  if(strcmp(comm,"ken") == 0){
    delete [] comm;
    return 1;
  }

  if(strcmp(comm,"en") == 0){
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
  
  printf("駆逐艦:\n30 30 30 30\n");
  printf("250 30 200 30 レア駆逐艦-雪風,島風,Z3(Z1旗艦),Z1(Z3旗艦)のみ\n\n");
  printf("軽巡:\n30 30 30 30\n");
  printf("250 30 200 30 低い確率で潜水艦\n\n");
  printf("重巡:\n250 30 200 30\n\n");
  printf("戦艦:\n400 30 600 30\n\n");
  printf("空母:\n300 30 400 300\n\n");
  printf("潜水艦:\n250 30 200 30\n\n");
  printf("======================\n\n");

  return;
}

void kenzouTime(){
  
  int time;
  cin >> time;
  
  ifstream in;
  in.open("jikan.data");

  char *line = new char[256];
  char *type = new char[56];
  char *kanmusu = new char[56];
  
  int now;
  char nextcomm;
  
  in.getline(line,256);
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
  delete []type;
  delete []kanmusu;
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