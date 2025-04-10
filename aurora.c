#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings
int registro() // função para cadastrar usuarios do sistemas
{
    // inicio criaçao de variaveis / string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("digite o CPF a ser cadastrado :"); // coletando inf do usuario
    scanf("%s",cpf);

    strcpy(arquivo, cpf); // responsavel por copiar os valores das strings

    FILE*file; // cria o arquivo n o bd
    file = fopen(arquivo, "w");//cria o arquivo
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecho o arquivo

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("digite o nome a ser cadastrado :");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("digite o sobrenome a ser cadastrado :");
    scanf("%s",sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("digite o cargo a ser cadastrado :");
    scanf("%s",cargo);

    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");

}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("digite o CPF a ser consultado :");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("não foi  possivel abrir o arquivo ,  não localizado. \n");
    }

    while(fgets(conteudo, 200, file)!= NULL)
    {
        printf("\nEssas são as ionformações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");

}

int deletar()
{
    char cpf[40];

    printf("Digite o cpf a ser deletado :");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("O usuario não se encontra no sistema! \n");
        system("pause");
    }

}

int main ()

{
 int opcao=0; // defini a variavel
 int laco=1;

 for(laco=1;laco=1;)
 {

 system("cls");

setlocale(LC_ALL, "Portuguese"); //definir linguagem


    printf("### Cartório da EBAC ###\n\n");// inicio menu
    printf("Escolha a opção desejada do menu:\n\n");
    printf("\t1- * Registrar nomes : \n");
    printf("\t2- * Consultar nomes : \n");
    printf("\t3- * Deletar nomes : \n");
    printf("opcao::"); // fim do menu

 scanf("%d", &opcao); //armazenamento escolha do usuário

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

    default:
    printf("esta opcão não esta disponivel  escolha novamente\n ");
    system("pause");
    break;


 }


}
}


