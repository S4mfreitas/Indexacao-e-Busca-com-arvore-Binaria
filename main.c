#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
FILE*fp;

int main()
{
    ArvC *arvore =NULL;
    Cliente cliente;
    int opcao, codigo;

    fp=fopen("BDClientes.bin","a+b");
    if(fp==NULL)
    {
        printf("Erro em BDCliente.bin\n");
        exit(1);
    }

    do
    {
        opcao = Menu_Inicial();

        switch(opcao)
        {
        case 1:
            cliente = Cadastro_Cliente();
            Registrar_Cliente(cliente);
            break;
        case 2:
            Indexar_Arvore(&arvore);
            break;
        case 3:
            printf("Digite o codigo do cliente a pesquisar: ");
            scanf("%d", &codigo);
            cliente=Pesquisar_Cliente(arvore, codigo);
            if(cliente.Codg!=-1)
            {
                Imprimir_Cliente(cliente);
            }
            break;
        case 4:
            Imprimir_Arvore(arvore);
            break;
        case 0:
            fclose(fp);
            printf("\nEncerrando o programa!\n");
            exit(0);
        default:
            printf("\nOpcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    }
    while(opcao != 0);

    return 0;
}

