#include <stdio.h>
#include <stdlib.h>



typedef struct//cria uma sruc para armazenar os dados de uma pessoa
{
	int numFunc;//define o numero de funcionarios
	char nome[20];
	float cnpj[30];
	struct Empreiteira *proximo;
	//struct listFunc *anterior; //DUPLAMENTE ENCADEADA
} Empreiteira;
//funcoes declardas
Empreiteira* adicionar();
void imprimir(Empreiteira *inicio);
void remover(Empreiteira *inicio, int id);

void main()
{
	Empreiteira *inicio = NULL, *fim;
	int i, opcao = 0, id, existe = 0;
	
	while(opcao != 4)
		{
		printf("Escolha uma das opcoes\n");
		printf("1 - Criar a lista de funcionarios;\n");
		printf("2 - Adicionar um funcionario na lista;\n");
		printf("3 - Remover um funcioario da lista;\n");
		printf("4 - Para sair;");
		scanf("%d", &opcao);
	
		switch(opcao)
		{
			case 1:
				if (existe)
					printf("Lista ja existe!");
				else
				{
					printf("Lista iniciada com sucesso!");
					existe = 1;
				}
				break;
				
			case 2:
				if(inicio == NULL)
					inicio = adicionar();
				else
				{
					//Adicionando no FIM
					fim = inicio;
					while(fim->proximo != NULL)
					{
						fim = fim->proximo;
					}
					fim->proximo = adicionar();
				}
				break;
				
			case 3:
				imprimir(inicio);
				printf("Digite o id do funcionario a ser removido: ");
				scanf("%d", &id);
				
				remover(inicio, id);
				break;
				
			case 4:
				break;
			default:
				break;
		}
	}	
}

Empreiteira* adicionar()
{
	Empreiteira *novo = (Empreiteira*)malloc(sizeof(Empreiteira));
	
	novo->proximo = NULL;
	printf("Digite o numero de funcionarios: ");
	scanf("%d", novo->numFunc);
	printf("\nDigite o nome do funcionario: ");
	scanf("%s", novo->nome);
	
	return novo;
}
void imprimir(Empreiteira *inicio)
{
	Empreiteira *aux = inicio;
	int cont = 0;
	
	do
	{
		printf("Id: %d\n", cont);
		printf("Marca: %s", aux->nome);
		printf("\nQuantidade de portas: %d\n\n", aux->numFunc);
		aux = aux->proximo;
		cont++;
	}while(aux->proximo != NULL);
	
	free(aux);
}

void remover(Empreiteira *inicio, int id)
{
	Empreiteira *aux = inicio, *ant = inicio;
	int cont = 0;
	
	if(id == 0)
	{
		inicio = inicio->proximo;
		aux->proximo = NULL;
	}
	else
	{
		while(id != cont)
		{	
			if(cont == 0)
			{
				aux = ant->proximo;
			}
			else
			{
				ant = ant->proximo;
				aux = ant->proximo;
			}
			cont++;
		}
		
		// ÚLTIMA POSIÇÃO
		if(aux->proximo == NULL)
		{
			ant->proximo = NULL;
		}
		else
		{
			// Posições 1 ... n-1
			ant->proximo = aux->proximo;
			aux->proximo = NULL;
		}
	}
	
	free(aux); free(ant);
}
