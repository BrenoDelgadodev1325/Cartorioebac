#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro()
{
	
	char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    
    printf("Voc� escolheu Registrar nomes!\n");
	printf("Digite o CPF a ser cadastrado:\n");
	scanf("%s", cpf);
	 
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, "\nCpf:");
	fprintf(file, cpf);// salva o valor da variavel
	fclose(file); // fecha o arquivo

	
	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNome:");
	fprintf(file, nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome:");
	fprintf(file, sobrenome);
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado:\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo:");
	fprintf(file, cargo);
	fprintf(file, "\n\n");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[100];
	
	printf("Voc� escolheu consultar nomes!\n");
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
  	
    FILE *file;
    file = fopen(cpf,"r");
  	
    if(file == NULL)
{
	printf("Este usu�rio n�o existe!.\n");
}

    while(fgets(conteudo, 100, file) != NULL)
{
	printf("%s", conteudo);	
}
    fclose(file);
  	
system ("pause");
	
}

int deletar()
{
	char cpf[40]; 
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	
	if(file)
	{
	remove(cpf);
	printf("Usu�rio deletado com sucesso!\n");
    }
    else
    {
	printf("Usu�rio n�o cadastrado \n");
	}
	
	
    system("pause");

}



int main ()
{
	int opcao=0;// Defini��o da vari�vel
	int laco=1;// variavel repeti��o
	
	for(laco=1;laco=1;)
	{
	   system("cls");//limpeza da tela
	   
	   setlocale(LC_ALL, "Portuguese");// Defini��o da linguagem
	   printf("###Cart�rio EBAC###\n\n");// Inicio do menu
	   printf("Escolha a op��o desejada:\n\n");
	   printf("\t1- Registrar nomes\n");
	   printf("\t2- Consultar nomes\n");
	   printf("\t3- Deletar nomes \n\n");
	   printf("\t4- Sair do sistema\n");
	   printf("op��o: ");// Fim do menu
	
	   scanf("%d", &opcao);// Armazenamento e escolha do usu�rio
	
	   system("cls");
      
      switch(opcao)
	   {
	   
	   case 1:
	   	registro();
	   	break;
	   	
	   case 2:
	   	consulta();
	   	break;
	   	
	   case 3:
	   	deletar();
	   	break;
	   	
	   	case 4:
	   	printf("Obrigado por utilizar o sistema!");
	   	return 0;
	   	break;
	   	
	   default:
	   	printf("essa op��o n�o est� dispon�vel!\n");
	   	system("pause");
	   	break;
       }
   }

}
