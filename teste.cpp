#include <iostream>
#include <string>
#include <cmath>
#include "Video.h"
#include "Canal.h"

using namespace std;

void teste () {
  Canal* hoosiers = new Canal("Hoosiers",7);
  Video* killer = new Video("Killer",34);
  Video* rules = new Video("Rules",58);
  Video* rubyBlue = new Video("Ruby Blue",17);
  for(int i=0;i<8;i++){
    killer->assistir(30);
  }
  for(int i=0;i<4;i++){
    rules->assistir(30);
  }
  for(int i=0;i<6;i++){
    rubyBlue->assistir(30);
  }
  hoosiers->postar(killer);
  hoosiers->postar(rules);
  hoosiers->postar(rubyBlue);
  hoosiers->imprimir();
  return;
}

//* COMENTE O MAIN AO SUBMETER
// int main () {
//   teste ();
//   return 0;
// }

//*/