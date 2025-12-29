# Exercício: Indexação e Busca com Árvore Binária
Este diretório contém a resolução de um exercício prático da disciplina de Algoritmos e Estruturas de Dados II. O objetivo é implementar um sistema híbrido que utiliza armazenamento em disco (arquivo binário) e indexação em memória (Árvore Binária de Busca).

📋 Funcionalidades Implementadas

O código realiza as seguintes operações:


- Gerenciamento de Registros: Entrada e saída de dados de Clientes (Código, Nome, Endereço, Telefone) via struct.


- Persistência de Dados: Gravação dos registros em arquivo binário global utilizando fwrite e fseek para inserção ao final.


- Indexação Dinâmica: Construção de uma Árvore Binária de Busca que armazena apenas a Chave (Código) e a Posição Física (ftell) do registro no arquivo.


- Carregamento de Índice: Função que lê o arquivo binário integralmente para popular a árvore de índices.


- Busca Otimizada: Pesquisa na árvore para localizar a posição do arquivo e recuperação do registro completo via acesso direto.


- Relatórios: Listagem dos clientes em ordem crescente através do percurso In-Order na árvore.


Professor: Heveraldo Rodrigues de Oliveira

