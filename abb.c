#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
FILE*fp;

int Menu_Inicial()
{
    int escolha;
    printf("\n\tMENU OPCOES:\n\n");
    printf("|1| INSERIR\n");
    printf("|2| INDEXAR\n");
    printf("|3| PESQUISAR\n");
    printf("|4| LISTAR\n");
    printf("|0| SAIR\n");
    printf("SELECIONE A OPCAO DESEJADA: ");
    scanf("%d", &escolha);
    return escolha;
}

Cliente Cadastro_Cliente()
{
    Cliente C;
    printf("\n---CADASTRO CLIENTE---\n\n");
    printf("Digite o codigo: ");
    scanf("%d", &C.Codg);
    printf("Digite o nome: ");
    scanf(" %[^\n]", &C.Nome);
    printf("Digite o endereco: ");
    scanf(" %[^\n]", &C.Endereco);
    printf("Digite o telefone: ");
    scanf(" %[^\n]", &C.Telefone);
    printf("\n");
    return C;
}

void Registrar_Cliente(Cliente C)
{
    fseek(fp,0,SEEK_END);
    fwrite(&C,sizeof(Cliente), 1, fp);
}

void Imprimir_Cliente(Cliente C)
{
    printf("\n");
    printf("Codigo: %3.0d\n", C.Codg);
    printf("Nome: %s\n", C.Nome);
    printf("Endereco: %s\n", C.Endereco);
    printf("Telefone: %s\n", C.Telefone);
    printf("\n");
}

ArvC *Criar_Arvore_Cliente(int codg, long posi)
{
    ArvC *Novo=(ArvC*)malloc(sizeof(ArvC));
    Novo->Codigo=codg;
    Novo->posicao=posi;
    Novo->esq=Novo->dir=NULL;
    return Novo;
}

ArvC *Registrar_Arvore_Cliente(ArvC *arvore, int codg, long posi)
{
    if(arvore==NULL)
    {
        return Criar_Arvore_Cliente(codg, posi);
    }
    if(codg<arvore->Codigo)
    {
        arvore->esq=Registrar_Arvore_Cliente(arvore->esq, codg, posi);
    }
    if(codg>arvore->Codigo)
    {
        arvore->dir=Registrar_Arvore_Cliente(arvore->dir, codg, posi);
    }
    return arvore;
}

void Indexar_Arvore(ArvC **arvore)
{
    Cliente C;
    long posicao;
    fseek(fp, 0, SEEK_SET);
    while(fread(&C, sizeof(Cliente), 1, fp))
    {
        posicao = ftell(fp) - sizeof(Cliente);
        *arvore = Registrar_Arvore_Cliente(*arvore, C.Codg, posicao);
    }
}

ArvC *Pesquisar_em_Arvore(ArvC* arvore, int codigo)
{
    if (arvore == NULL || arvore->Codigo == codigo)
        return arvore;

    if (codigo < arvore->Codigo)
        return Pesquisar_em_Arvore(arvore->esq, codigo);

    return Pesquisar_em_Arvore(arvore->dir, codigo);

}

Cliente Pesquisar_Cliente(ArvC *arvore, int codigo)
{
    Cliente C;
    ArvC *encontrado = Pesquisar_em_Arvore(arvore, codigo);
    if(encontrado!=NULL)
    {
        fseek(fp, encontrado->posicao, SEEK_SET);
        fread(&C, sizeof(Cliente), 1, fp);
    }
    else
    {
        printf("Cliente %d nao encontrado!\n");
        C.Codg=-1;
    }
 return C;
}

void Imprimir_Arvore(ArvC *arvore)
{
    Cliente C;
    if(arvore==NULL)
        return;
    Imprimir_Arvore(arvore->esq);
    C=Pesquisar_Cliente(arvore, arvore->Codigo);
        if(C.Codg!=-1)
        {
            Imprimir_Cliente(C);
        }
    Imprimir_Arvore(arvore->dir);
}
