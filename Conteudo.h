#ifndef CONTEUDO_H
#define CONTEUDO_H
#include <string>

using namespace std;

class Conteudo {
private:
  string nome;

protected:
  int duracao;
  int visualizacoes = 0;

public:
  Conteudo(string nome, int duracao);
  virtual ~Conteudo();
  string getNome();
  int getDuracao();
  virtual int getVisualizacoes();
};

#endif