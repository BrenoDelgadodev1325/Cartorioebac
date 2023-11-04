#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro()
{
	
	char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    
    printf("Você escolheu Registrar nomes!\n");
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
	
	printf("Você escolheu consultar nomes!\n");
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
  	
    FILE *file;
    file = fopen(cpf,"r");
  	
    if(file == NULL)
{
	printf("Este usuário não existe!.\n");
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
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	
	if(file)
	{
	remove(cpf);
	printf("Usuário deletado com sucesso!\n");
    }
    else
    {
	printf("Usuário não cadastrado \n");
	}
	
	
    system("pause");

}



int main ()
{
	int opcao=0;// Definição da variável
	int laco=1;// variavel repetição
	
	for(laco=1;laco=1;)
	{
	   system("cls");//limpeza da tela
	   
	   setlocale(LC_ALL, "Portuguese");// Definição da linguagem
	   printf("###Cartório EBAC###\n\n");// Inicio do menu
	   printf("Escolha a opção desejada:\n\n");
	   printf("\t1- Registrar nomes\n");
	   printf("\t2- Consultar nomes\n");
	   printf("\t3- Deletar nomes \n\n");
	   printf("\t4- Sair do sistema\n");
	   printf("opção: ");// Fim do menu
	
	   scanf("%d", &opcao);// Armazenamento e escolha do usuário
	
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
	   	printf("essa opção não está disponível!\n");
	   	system("pause");
	   	break;
       }
   }

}
