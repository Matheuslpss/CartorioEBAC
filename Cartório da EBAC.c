#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa� em m�moria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel da string


    int registro() //fun��o da cria��o do usuario
{
	 // inicio cria��o de vari�veis/ strings
	 char arquivo [40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
     
     printf("Digite o CPF a ser cadastrado:"); // coletar infor��es do usu�rio
     scanf("%s", cpf); //%s refere-se a string
     
    strcpy(arquivo, cpf); //responsavel para copiar as string
    
    FILE *file; // criar o arquivo
    file = fopen(arquivo,"w"); // criar no banco de dados
    fprintf(file,cpf); // salvar o valor da variavel
    fclose(file); // fechar o arquivo
    
    file= fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file= fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:");
     scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s", cargo);
     
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}
	
	int consultar()
	{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");	
	}
	
	while(fgets(conteudo,200,file)!= NULL)
	{
	printf("\nESssas s�o as informa��es do usu�rio: ");
	printf("%s",conteudo);
	printf("\n\n");
	
	system("pause"); //manter na aba
	}
	
	}

    
	int deletar() // fun��o de deletar os dados do usu�rio 
	{
		
    char cpf[40];
	printf("Digite o CPF a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //responsavel pra quando nao encontnrar nada 
	{
		printf("O usu�rio n�o foi encotrando no sistema!.\n");
		system("pause");
	}
	 
	
	}	








    int main()
{
	int opcao=0; //Definindo a variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); // repondesal por apagar tudo
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagens
	
	printf("*** Cart�rio da EBAC ***\n\n"); //Inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n\n"); //Fim do menu
	printf("\t4 - Sair do sistema\n\n");
	printf("Op��o: ");  //Fim do menu
	
	scanf("%d",&opcao); //Armazenando a escolha do us�rio
	
	system("cls");
	
	switch(opcao)
	{
		case 1:	
	    registro();
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
	    deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar nosso sistema!\n");
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o existe!\n");
		system("pause");
		break;
	}
	
     //Fim das sele��es
		
	}
}
