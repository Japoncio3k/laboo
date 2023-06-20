// #include "Lista.h"
// #include "Plataforma.h"
// #include "UsuarioVerificado.h"
// #include "VideoCurto.h"
// #include <iostream>

// using namespace std;

// bool ehUsuarioVerificado(Usuario *user) {
//   UsuarioVerificado *testaUsuarioVerificado =
//       dynamic_cast<UsuarioVerificado *>(user);
//   if (testaUsuarioVerificado != NULL) {
//     return true;
//   }
//   return false;
// }

// void imprimeConteudo(Conteudo *conteudo) {
//   Lista *conteudoEhLista = dynamic_cast<Lista *>(conteudo);
//   if (conteudoEhLista != NULL) {
//     cout << "Lista: " << conteudoEhLista->getNome() << " - "
//          << conteudoEhLista->getQuantidade();
//     if (conteudoEhLista->getQuantidade() == 1) {
//       cout << " video" << endl;
//     } else {
//       cout << " videos" << endl;
//     }
//   }
//   Video *conteudoEhVideo = dynamic_cast<Video *>(conteudo);
//   if (conteudoEhVideo != NULL) {
//     conteudoEhVideo->imprimir();
//   }
// }

// void telaPostarVideo(Canal *canal, bool ehVerificado) {
//   char ehVideoCurto;
//   if (ehVerificado) {
//     cout << "Video curto (s/n)? ";
//     cin >> ehVideoCurto;
//   }
//   string nomeDoVideo;
//   cout << "Nome do video: ";
//   cin >> nomeDoVideo;
//   int duracao;
//   cout << "Duracao: ";
//   cin >> duracao;
//   if (ehVideoCurto) {
//     canal->postar(new VideoCurto(nomeDoVideo, duracao));
//   } else {
//     canal->postar(new Video(nomeDoVideo, duracao));
//   }
// }

// void populaLista(Lista *list, Conteudo **conteudos, int quantidade) {
//   for (int i = 0; i < quantidade; i++) {
//     cout << i + 1 << ") ";
//     imprimeConteudo(conteudos[i]);
//   }
//   cout << "Digite o numero, ou 0 para terminar: ";
//   int acao;
//   cin >> acao;
//   if (acao == 0) {
//     return;
//   } else {
//     bool adicionou;
//     Lista *conteudoEhLista = dynamic_cast<Lista *>(conteudos[acao - 1]);
//     if (conteudoEhLista != NULL) {
//       adicionou = list->adicionar(conteudoEhLista);
//     }
//     Video *conteudoEhVideo = dynamic_cast<Video *>(conteudos[acao - 1]);
//     if (conteudoEhVideo != NULL) {
//       adicionou = list->adicionar(conteudoEhVideo);
//     }
//     if (adicionou) {
//       cout << "Video adicionado a lista";
//     } else {
//       cout << "Nao foi possivel adicionar";
//     }
//     cout << endl;
//     populaLista(list, conteudos, quantidade);
//   }
// }

// void telaCriarLista(Canal *canal) {
//   cout << "Nome da lista: ";
//   string nomeDaLista;
//   cin >> nomeDaLista;
//   Lista *list = new Lista(nomeDaLista, 20);
//   populaLista(list, canal->getConteudos(), canal->getQuantidade());
//   canal->postar(list);
// }

// void telaAssistirVideo(Usuario *user) {
//   cout << "Canal: " << user->getCanal()->getNome()
//        << "Escolha o conteudo: " << endl;
//   for (int i = 0; i < user->getCanal()->getQuantidade(); i++) {
//     cout << i - 1 << ") ";
//     imprimeConteudo(user->getCanal()->getConteudos()[i]);
//   }
//   cout << "Digite o numero, ou 0 para terminar: ";
//   int video;
//   cin >> video;
//   VideoCurto* ehVideoCurto = dynamic_cast<VideoCurto*>(user->getCanal()->getConteudos()[video]);
//   if(ehVideoCurto != NULL) {
//     ehVideoCurto->assistir();
//   }
//   Video* ehVideoNormal = dynamic_cast<Video*>(user->getCanal()->getConteudos()[video]);
//   if(ehVideoNormal != NULL) {
//     cout << "Digite o tempo assistido: ";
//     int tempo;
//     cin >> tempo;
//     ehVideoNormal->assistir(tempo);
//   }
//   Lista* ehLista = dynamic_cast<Lista*>(user->getCanal()->getConteudos()[video]);
//   if(ehLista != NULL) {
//     cout << "Nao foi possivel assistir";
//   }
// }

// void telaEscolherUser(Plataforma *plat) {
//   cout << "Escolha um usuario: " << endl;
//   for (int i = 0; i < plat->getQuantidadeDeUsuarios(); i++) {
//     bool ehVerificado = ehUsuarioVerificado(plat->getUsuarios()[i]);
//     cout << i + 1 << ") " << plat->getUsuarios()[i]->getNome();
//     if (ehVerificado) {
//       cout << " (verificado)";
//     }
//     cout << endl;
//   }
//   cout << "Digite o numero, ou 0 para cancelar: ";
//   int userId;
//   cin >> userId;
//   if (userId != 0) {
//     telaAssistirVideo(plat->getUsuarios()[userId]);
//   }
// }

// void telaUsuarioLogado(Plataforma *plat, Usuario *user) {
//   bool ehVerificado = ehUsuarioVerificado(user);
//   cout << "Usuario: " << user->getNome();
//   if (ehVerificado) {
//     cout << " (verificado)";
//   }
//   cout << endl
//        << "Canal: " << user->getCanal()->getNome() << endl
//        << "Quantidade de conteudos no canal: "
//        << user->getCanal()->getQuantidade() << endl
//        << "----" << endl
//        << "Escolha uma opcao:" << endl
//        << "1) Postar video" << endl
//        << "2) Criar lista" << endl
//        << "3) Assistir video" << endl
//        << "0) Deslogar" << endl;

//   int acao;
//   cin >> acao;
//   if (acao == 0) {
//     return;
//   } else if (acao == 1) {
//     telaPostarVideo(user->getCanal(), ehVerificado);
//     telaUsuarioLogado(plat, user);
//   } else if (acao == 2) {
//     telaCriarLista(user->getCanal());
//     telaUsuarioLogado(plat, user);
//   } else if (acao == 3) {
//     telaEscolherUser(plat);
//     telaUsuarioLogado(plat, user);
//   }
// }

// void telaLogar(Plataforma *plat) {
//   int acao;
//   cout << "Escolha um usuario:" << endl;
//   for (int i = 0; i < plat->getQuantidadeDeUsuarios(); i++) {
//     bool ehVerificado = ehUsuarioVerificado(plat->getUsuarios()[i]);
//     cout << i + 1 << ") " << plat->getUsuarios()[i]->getNome();
//     if (ehVerificado) {
//       cout << " (verificado)";
//     }
//     cout << endl;
//   }
//   cout << "Digite o numero, ou 0 para cancelar: ";
//   cin >> acao;
//   if (acao == 0) {
//     return;
//   } else {
//     telaUsuarioLogado(plat, plat->getUsuarios()[acao - 1]);
//   }
// }

// void telaCadastrarUsuario(Plataforma *plat) {
//   char verificado;
//   cout << "Informe os dados do usuario:" << endl << "Verificado (s/n)? ";
//   cin >> verificado;
//   cout << "Digite o nome do usuario: ";
//   string nomeUsuario, nomeCanal;
//   cin >> nomeUsuario;
//   cout << "Digite o nome do seu canal: ";
//   cin >> nomeCanal;
//   if (verificado == 's') {
//     plat->adicionar(new UsuarioVerificado(nomeUsuario, nomeCanal, 20));
//   } else {
//     plat->adicionar(new Usuario(nomeUsuario, nomeCanal, 20));
//   }
// }

// void telaInicial(Plataforma *plat) {
//   int acao;
//   cout << "Escolha uma opcao:" << endl
//        << "1) Cadastrar Usuario" << endl
//        << "2) Logar" << endl
//        << "0) Sair da plataforma" << endl;
//   cin >> acao;
//   if (acao == 0) {
//     return;
//   }
//   if (acao == 1) {
//     telaCadastrarUsuario(plat);
//     telaInicial(plat);
//   } else if (acao == 2) {
//     telaLogar(plat);
//     telaInicial(plat);
//   }
// }

// // int main() {
// //   Plataforma *plat = new Plataforma();
// //   telaInicial(plat);
// // }