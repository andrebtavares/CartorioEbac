#include <stdio.h> //biblioteca de comunicac�o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��es de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()  //Fun��o para cadastros de usu�rios.
{	
		//inicio de cria��o das variaveis/strings
		char arquivo[40];
		char cpf [40];
		char nome [40];
		char sobrenome [40];
		char cargo [40];
		//final da cria��o de variaveis
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
		scanf("%s", cpf); // %s refere-se a strings
		
		strcpy(arquivo, cpf);  //Responsavel por copiar valores das strings
		
		FILE *file;   //cria o arquivo no banco de dados
		file = fopen(arquivo, "w");  // criar o arquivo na pasta onde esta o sistema, "w" escrever
		fprintf(file,"CPF: ");
		fprintf(file, cpf);  //salvo o valor da variavel
		fclose(file);   //fechamento do arquivo IMPORTANTE!!
		
		file = fopen(arquivo, "a");
		fprintf(file,"\nNome: ");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a"); //"a" de atualiza��o
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\nSobrenome: ");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\nCargo: ");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fprintf(file,"\n\n");
		fclose(file);
		
		system("pause");		
		
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");  //Definindo Linguagens 
	
	//inicio das variaveis	
	char cpf[40];
	char conteudo[200];
	
	//Fim das variaveis

	
			
	printf("Digite o cpf a ser consultado: "); //entrada de dados do usu�rio
	scanf("%s", cpf);
			
	FILE *file;
	file = fopen(cpf,"r");

	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n");
		
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: \n");
	
	while(fgets(conteudo, 200, file) !=NULL)
	{	
		
		printf("%s", conteudo);
			
		}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	//Analisa se o usu�rio esta cadastrado
	if(file == NULL)
	{
		printf("O usu�rio n�o esta cadastrado\n\n");
			
	}
	fclose(file); //fecha sistema
	
	//Analisa se o usuario foi deletado
	if(file != NULL)
	{
		remove(cpf);
		printf("\nUsuario deletado com sucesso!\n\n");
	}
    system("pause");
}
			


int main ()
{
	
	int opcao=0; //Definindo variavies
	int laco=1; //Defini��o variavel laco
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");  //Definindo Linguagens 
	
		printf("### Cart�rio da EBAC ### \n\n");   //inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1- Registrar nomes \n");
		printf("\t2- Consultar os nomes \n");
		printf("\t3- Deletar nomes \n"); 
		printf("\t4- Sair do menu \n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf ("%d", &opcao);  //armazenando escolha do usu�rio
		
		system("cls");
	
		switch(opcao) //inicio da selec��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;
						
			default:
			printf("Essa op��o n�o esta dispon�vel\n!");
			system("pause");
			break;
			//fim da sele��o
		}
		
	

	}
}

	


