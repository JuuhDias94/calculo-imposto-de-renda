#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para trabalhar com texto
#include <locale.h> //para poder usar palavras com acentuação

//estrutura para armazenar nome e salário:
struct Func
{
	char nomeFunc[40]; //variável do tipo caractere
	float salario; //variável do tipo float
}; struct Func IR; 

int main() //início da função
{
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentuação

	float c, imp, salF; //variáveis do tipo float

	//tabela base para cálculo do IR:
	printf("\n");
	printf("*** SISTEMA DE CÁLCULO DO IMPOSTO DE RENDA ***\n\n");
	printf(" _____________________________________________\n");
	printf("| Base de cálculo mensal em R$ | Alíquota (%%) |\n");
	printf("|______________________________|______________|\n");
	printf("| Até 1.637,11                 | -            |\n");
	printf("|______________________________|______________|\n");
	printf("| De 1.637,12 até 2.453,50     | 7,5          |\n");
	printf("|______________________________|______________|\n");
	printf("| De 2.453,51 até 3.271,38     | 15,0         |\n");
	printf("|______________________________|______________|\n");
	printf("| De 3.271,39 até 4.087,65     | 22,5         |\n");
	printf("|______________________________|______________|\n");
	printf("| Acima de 4.087,65            | 27,5         |\n");
	printf("|______________________________|______________|\n");
	printf("\n\n");

	//pede nome do funcionário:
	printf("Digite o nome do(a) funcionário(a): ");
	fgets(IR.nomeFunc, 40, stdin); //salva o nome (string)
	
	//pede salário do funcionário:
	printf("Digite o salário do(a) funcionário(a): ");
	scanf_s("%f", &IR.salario);
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado

	//imprime na tela o nome e o salário do funcionário:
	printf("\n\n*** CÁLCULO DO IMPOSTO DE RENDA ***\n\n");
	printf("Funcionário(a): %s", IR.nomeFunc);
	printf("Salário: %.2f\n", IR.salario);

	//imprime na tela salário, alíquota e salário após desconto:
	if (IR.salario > 4087.65) {
		imp = IR.salario * (27.5 / 100); //calcula o imposto
		salF = IR.salario - imp; //deduz o imposto do salário
		printf("Alíquota: 27,5%%\n"); //alíquota
		printf("Imposto: %.2f\n", imp); //imposto
		printf("Salário final: %.2f\n", salF); //salário após desconto
	}
	else if (IR.salario > 3271.38) {
		imp = IR.salario * (22.5 / 100);
		salF = IR.salario - imp;
		printf("Alíquota: 22,5%%\n");
		printf("Imposto: %.2f\n", imp);
		printf("Salário final: %.2f\n", salF);
	}
	else if (IR.salario > 2453.50) {
		imp = IR.salario * (15.0 / 100);
		salF = IR.salario - imp;
		printf("Alíquota: 15,0%%\n");
		printf("Imposto: %.2f\n", imp);
		printf("Salário final: %.2f\n", salF);
	}
	else if (IR.salario > 1637.11) {
		imp = IR.salario * (7.5 / 100);
		salF = IR.salario - imp;
		printf("Alíquota: 7,5%%\n");
		printf("Imposto: %.2f\n", imp);
		printf("Salário final: %.2f\n", salF);
	}
	else {
		printf("Funcionário isento.\n"); //funcionário isento do imposto
		printf("Salário final: %.2f\n", IR.salario);
	}

	printf("\n\n"); //para pular linha

	system("pause");
	return 0;
} //fim da função