#include <stdio.h>
#include <stdlib.h>


char empresa[50], linha[89];
const int tam = 2;
int i, j;
FILE *file;

struct tp_funcionario{
    char nome[50];
    int idade;
    int horas;
}
cad_funcionario[2];


int op;

void menu_principal(){
    system("cls");
    printf("[EMPRESA: %s]\n",empresa);
    printf ("\n___________________________\n");
    printf ("| [1]- Criar Registro     |\n");
    printf ("| [2]- Ler Registros      |\n");
    printf ("| [3]- Atualizar Registro |\n");
    printf ("| [4]- Apagar Registro    |\n");
    printf ("| [0]- Sair do Programa   |\n");
    printf ("|_________________________|\n");

    printf("\nEscolha uma opcao: ");
    scanf("%d", &op);

    switch  (op){   
      
	case 1:
		criar_registro();	
	break;
        
	case 2:
        ler_registro();	
	break;
        
    case 3:
        atualizar_registro();    //INCOMPLETO
    break;
        
    case 4:
        //apagar_registro();    
    break;

        case 0:
        system("cls");
        printf("\nSaindo...\n");
        return 0;
    break;

    default:
        printf("\n[Valor invalido]");
        printf("\n[Pressione qualquer tecla para voltar ao menu principal]\n");
        system("pause>NULL");
        menu_principal();
    break;
    }
}

void nome_empresa(){
    printf("[Digite o nome da sua empresa]\n\n");
    printf("[Nome]: ");
    fflush(stdin);
    gets(empresa);
}

void criar_registro(){
    for(i = 0; i < tam; i++){
        system("cls");
        printf("[EMPRESA: %s]\n",empresa);

        printf("[Insira o nome do funcionario %d]: ", i+1);
        fflush(stdin);
        gets(cad_funcionario[i].nome);
        printf("[Insira a idade do funcionario]: ");
        scanf("%d", &cad_funcionario[i].idade);
        printf("[Insira o numero de horas trabalhadas do funcionario]: ");
        scanf("%d", &cad_funcionario[i].horas);
        
        if(i+1 < tam){
        printf("\n[Funcionario %d cadastrado]\n\n", i+1);
        printf("\n[Pressione qualquer tecla para cadastrar o proximo funcionario]\n");
        system("pause>NULL");
        }else{
            printf("\n\n[Todos os Funcionarios cadastrados]");
            printf("\n[Pressione qualquer tecla para voltar ao menu principal]\n");
            system("pause>NULL");
            menu_principal();
        }
    }
    
}

void ler_registro(){
    file = fopen("registro_funcionarios", "w");

        fprintf(file,"\n[EMPRESA]: %s\n",empresa);
        fprintf(file,"________________________________Funcionarios cadastrados________________________________\n");
        fprintf(file,"|                                                                                      |\n");
        fprintf(file,"|  |Nome|                                              |Idade|    |Horas trabalhadas|  |\n");
        fprintf(file,"|--------------------------------------------------------------------------------------|\n");
        
        for(j = 0; j < tam; j++){
            fprintf(file,"|  %-51s %-10d %-21d|\n", cad_funcionario[j].nome, cad_funcionario[j].idade, cad_funcionario[j].horas);
        }
        fprintf(file,"|______________________________________________________________________________________|\n");

    fclose(file);

    imprimir_registro();

    printf("\n[Pressione qualquer tecla para voltar ao menu principal]\n");
    system("pause>NULL");
    menu_principal();

}

void imprimir_registro(){
    
    system("cls");
    
    file = fopen("registro_funcionarios", "r");
        if(file == NULL){
            printf("Nao foi possivel abrir o arquivo\n");
            printf("\n[Pressione qualquer tecla para voltar ao menu principal]\n");
            system("pause>NULL");
            menu_principal();
        }else{
            while(fgets(linha, 89, file) != NULL)
            printf("%s", linha);
        }   
    fclose(file);
}

void atualizar_registro(){  //INCOMPLETO

    char nome_alt[50];

    system("cls");
    file = fopen("registro_funcionarios", "a");

        if(file == NULL){
            printf("Nao foi possivel abrir o arquivo\n");
            printf("\n[Pressione qualquer tecla para voltar ao menu principal]\n");
            system("pause>NULL");
            menu_principal();
        }else{
            imprimir_registro();
        }   

    fclose(file);

    printf("\n[Insira o nome do funcionario que voce deseja alteral]: ");
    fflush(stdin);
    gets(nome_alt);

   

}

int main(){

nome_empresa();
menu_principal();


}