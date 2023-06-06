#include "Conteudo.h"
#include <iostream>

using namespace std;

Conteudo::Conteudo(string nome, int duracao) : nome(nome), duracao(duracao) {}

Conteudo::~Conteudo() {}

string Conteudo::getNome() { return this->nome; }

int Conteudo::getDuracao() { return this->duracao; }
