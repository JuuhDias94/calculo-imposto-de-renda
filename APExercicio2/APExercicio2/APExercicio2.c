#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para trabalhar com texto
#include <locale.h> //para poder usar palavras com acentua��o

//estrutura para armazenar nome e sal�rio:
struct Func
{
	char nomeFunc[40]; //vari�vel do tipo caractere
	float salario; //vari�vel do tipo float
}; struct Func IR; 

int main() //in�cio da fun��o
{
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentua��o

	float c, imp, salF; //vari�veis do tipo float

	//tabela base para c�lculo do IR:
	printf("\n");
	printf("*** SISTEMA DE C�LCULO DO IMPOSTO DE RENDA ***\n\n");
	printf(" _____________________________________________\n");
	printf("| Base de c�lculo mensal em R$ | Al�quota (%%) |\n");
	printf("|______________________________|______________|\n");
	printf("| At� 1.637,11                 | -            |\n");
	printf("|______________________________|______________|\n");
	printf("| De 1.637,12 at� 2.453,50     | 7,5          |\n");
	printf("|______________________________|______________|\n");
	printf("| De 2.453,51 at� 3.271,38     | 15,0         |\n");
	printf("|______________________________|______________|\n");
	printf("| De 3.271,39 at� 4.087,65     | 22,5         |\n");
	printf("|______________________________|______________|\n");
	printf("| Acima de 4.087,65            | 27,5         |\n");
	printf("|______________________________|______________|\n");
	printf("\n\n");

	//pede nome do funcion�rio:
	printf("Digite o nome do(a) funcion�rio(a): ");
	fgets(IR.nomeFunc, 40, stdin); //salva o nome (string)
	
	//pede sal�rio do funcion�rio:
	printf("Digite o sal�rio do(a) funcion�rio(a): ");
	scanf_s("%f", &IR.salario);
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado

	//imprime na tela o nome e o sal�rio do funcion�rio:
	printf("\n\n*** C�LCULO DO IMPOSTO DE RENDA ***\n\n");
	printf("Funcion�rio(a): %s", IR.nomeFunc);
	printf("Sal�rio: %.2f\n", IR.salario);

	//imprime na tela sal�rio, al�quota e sal�rio ap�s desconto:
	if (IR.salario > 4087.65) {
		imp = IR.salario * (27.5 / 100); //calcula o imposto
		salF = IR.salario - imp; //deduz o imposto do sal�rio
		printf("Al�quota: 27,5%%\n"); //al�quota
		printf("Imposto: %.2f\n", imp); //imposto
		printf("Sal�rio final: %.2f\n", salF); //sal�rio ap�s desconto
	}
	else if (IR.salario > 3271.38) {
		imp = IR.salario * (22.5 / 100);
		salF = IR.salario - imp;
		printf("Al�quota: 22,5%%\n");
		printf("Imposto: %.2f\n", imp);
		printf("Sal�rio final: %.2f\n", salF);
	}
	else if (IR.salario > 2453.50) {
		imp = IR.salario * (15.0 / 100);
		salF = IR.salario - imp;
		printf("Al�quota: 15,0%%\n");
		printf("Imposto: %.2f\n", imp);
		printf("Sal�rio final: %.2f\n", salF);
	}
	else if (IR.salario > 1637.11) {
		imp = IR.salario * (7.5 / 100);
		salF = IR.salario - imp;
		printf("Al�quota: 7,5%%\n");
		printf("Imposto: %.2f\n", imp);
		printf("Sal�rio final: %.2f\n", salF);
	}
	else {
		printf("Funcion�rio isento.\n"); //funcion�rio isento do imposto
		printf("Sal�rio final: %.2f\n", IR.salario);
	}

	printf("\n\n"); //para pular linha

	system("pause");
	return 0;
} //fim da fun��o