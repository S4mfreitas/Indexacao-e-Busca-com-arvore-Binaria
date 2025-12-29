#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

struct DadosCliente
{
    int Codg;
    char Nome[51];
    char Endereco[31];
    char Telefone[16];
};
typedef struct DadosCliente Cliente;

struct Arvore_Cliente
{
    int Codigo;
    long posicao;
    struct Arvore_Cliente *esq, *dir;
};
typedef struct Arvore_Cliente ArvC;

int Menu_Inicial();
Cliente Cadastro_Cliente();
void Registrar_Cliente(Cliente C);
void Imprimir_Cliente(Cliente C);
ArvC *Criar_Arvore_Cliente(int codg, long posi);
ArvC *Registrar_Arvore_Cliente(ArvC *arvore, int codg, long posi);
void Indexar_Arvore(ArvC **arvore);
ArvC *Pesquisar_em_Arvore(ArvC* arvore, int codigo);
Cliente Pesquisar_Cliente(ArvC *arvore, int codigo);
void Imprimir_Arvore(ArvC *arvore);

#endif // ABB_H_INCLUDED
