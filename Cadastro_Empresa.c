#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARANDO VARIÁVEIS GLOBAIS
char empresa[50], linha[89];
const int tam = 2;
FILE *file, *file_out;

//DECLARANDO A STRUC
struct tp_funcionario{
    char nome[50];
    int idade;
    int horas;
    int id;
}
cad_funcionario[2];


/* LISTAGEM DE PROCEDIMENTOS */
void menu_principal();  //PRONTO
void nome_empresa();    //PRONTO
void criar_registro();  //PRONTO
void ler_registro();    //PRONTO
void imprimir_registro();   //PRONTO
void atualizar_registro();  //PRONTO
void apagar_registro();     //PRONTO
void ordem_horas();     //PRONTO

int op;

void menu_principal(){  //PROCEDIMENTO QUE IMPRIME O MENU PRINCIPAL E RECEBE A OPÇÃO DO USUÁRIO
    system("cls");
    printf("[EMPRESA: %s]\n",empresa);
    printf ("\n___________________________\n");
    printf ("| [1]- Criar Registro     |\n");
    printf ("| [2]- Ler Registros      |\n");
    printf ("| [3]- Imprimir Registro  |\n");
    printf ("| [4]- Atualizar Registro |\n");
    printf ("| [5]- Apagar Registro    |\n");
    printf ("| [6]- ordenar por hora   |\n");
    printf ("| [0]- Sair do Programa   |\n");
    printf ("|_________________________|\n");

    printf("\nEscolha uma opcao: ");
    scanf("%d", &op);

    switch  (op){   
      
	case 1:
		criar_registro();   //FEITO
	break;
        
	case 2:
        ler_registro();	    //FEITO
	break;
        
    case 3:
        imprimir_registro();	
        printf("\n[Pressione qualquer tecla para voltar ao menu principal]\n");
        system("pause>NULL");
        menu_principal();    
	break;

    case 4:
        atualizar_registro();    //FEITO
    break;
        
    case 5:
        apagar_registro();    //FEITO
    break;

    case 6:
        ordem_horas();      //FEITO
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

void nome_empresa(){    //PROCEDIMENTO QUE RECEBE O NOME DA EMRPESA
    printf("[Digite o nome da sua empresa]\n\n");
    printf("[Nome]: ");
    fflush(stdin);
    gets(empresa);
}

void criar_registro(){  //PROCEDIMENTO QUE RECEBE OS DADOS PARA CRIAR O REGISTRO DE FUNCIONÁRIOS
    
    int i;    
    for(i = 0; i < tam; i++){   //laço de repetição para receber o número total de funcionários
        system("cls");
        printf("[EMPRESA: %s]\n",empresa);

        printf("[Insira o nome do funcionario %d]: ", i+1);
        fflush(stdin);
        gets(cad_funcionario[i].nome);  //recebendo o nome
        printf("[Insira a idade do funcionario]: ");
        scanf("%d", &cad_funcionario[i].idade); //recebendo a idade
        printf("[Insira o numero de horas trabalhadas do funcionario]: ");
        scanf("%d", &cad_funcionario[i].horas); //recebendo as horas

        cad_funcionario[i].id = i;  //id recebe o número da repetição atual do i
        
        if(i+1 < tam){  //condicional para identificar se é o último funcionário ou não
        //caso não for o último
        printf("\n[Funcionario %d cadastrado]\n\n", i+1);   
        printf("\n[Pressione qualquer tecla para cadastrar o proximo funcionario]\n");
        system("pause>NULL");
        }else{
            //caso for o último
            printf("\n\n[Todos os Funcionarios cadastrados]");
            printf("\n[Pressione qualquer tecla para voltar ao menu principal]\n");
            system("pause>NULL");
            menu_principal();
        }
    }    
}

void ler_registro(){    //PROCEDIMENTO QUE PASSA OS DADOS PARA O ARQUIVO TXT
    
    int j;
    
    file = fopen("registro_funcionarios.txt", "w"); //abertura do arquivo txt

        //imprimindo os dados no txt
        fprintf(file,"\n[EMPRESA]: %s\n",empresa);
        fprintf(file,"___________________________________Funcionarios cadastrados___________________________________\n");
        fprintf(file,"|                                                                                            |\n");
        fprintf(file,"|  |ID|  |Nome|                                              |Idade|    |Horas trabalhadas|  |\n");
        fprintf(file,"|--------------------------------------------------------------------------------------------|\n");
        
        for(j = 0; j < tam; j++){   //laço para limitar no total de funcionários
            fprintf(file,"|  %-5d %-51s %-10d %-21d|\n", cad_funcionario[j].id+1, cad_funcionario[j].nome, cad_funcionario[j].idade, cad_funcionario[j].horas);
        }
        fprintf(file,"|____________________________________________________________________________________________|\n");

    fclose(file);   //fechamento do arquivo txt

    imprimir_registro();   

    printf("\n[Pressione qualquer tecla para voltar ao menu principal]\n");
    system("pause>NULL");
    menu_principal();

}

void imprimir_registro(){   //PROCEDIMENTO QUE IMPRIME O ARQUIVO NO CMD
    
    system("cls");
    file = fopen("registro_funcionarios.txt", "r"); //abertura do arquivo txt
        if(file == NULL){   //caso o arquivo não exista
            printf("Nao foi possivel abrir o arquivo\n");
            printf("\n[Pressione qualquer tecla para voltar ao menu principal]\n");
            system("pause>NULL");
            menu_principal();
        }else{  //caso o arquivo exista
            while(fgets(linha, 89, file) != NULL)   //repetição para imprimir cada linha do arquivo no cmd
            printf("%s", linha);
        }   
    fclose(file);   //fechamento do arquivo txt
}

void atualizar_registro(){  //PROCEDIMENTO QUE ATUALIZA OS DADOS DO FUNCIONÁRIO ESCOLHIDO  

    system("cls");  

    //imprimindo os dados no cmd
    printf("\n[EMPRESA]: %s\n",empresa);
    printf("___________________________________Funcionarios cadastrados___________________________________\n");
    printf("|                                                                                            |\n");
    printf("|  |ID|  |Nome|                                              |Idade|    |Horas trabalhadas|  |\n");
    printf("|--------------------------------------------------------------------------------------------|\n");
            
    for(int j = 0; j < tam; j++){
        printf("|  %-5d %-51s %-10d %-21d|\n", j+1, cad_funcionario[j].nome, cad_funcionario[j].idade, cad_funcionario[j].horas);
    }
    printf("|____________________________________________________________________________________________|\n");

    
    int id_novo;    //variável do id que deseja atualizar
    
    printf ("\n\n[Digite o ID que deseja id_novo]: ");
    fflush(stdin);
    scanf ("%d",&id_novo);  //recebendo o id

    for(int i=0; i<tam;i++){    //repetição para total de funcionários
        
        if(id_novo == cad_funcionario[i].id+1){ //caso o novo id seja igual ao id do funcionário indicado pelo i
            printf ("\n[Nome do funcionario]: ");
            fflush(stdin);
            gets (cad_funcionario[i].nome);
            printf ("[Idade]: ");
            fflush(stdin);
            scanf ("%d", &cad_funcionario[i].idade);
            printf ("[Horas trabalhadas]: ");
            fflush(stdin);
            scanf ("%d", &cad_funcionario[i].horas);                                   
            
            file = fopen("registro_funcionarios.txt", "w"); //abertura do arquivo txt

            //imprimindo os dados atualizados no txt
            fprintf(file,"\n[EMPRESA]: %s\n",empresa);
            fprintf(file,"___________________________________Funcionarios cadastrados___________________________________\n");
            fprintf(file,"|                                                                                            |\n");
            fprintf(file,"|  |ID|  |Nome|                                              |Idade|    |Horas trabalhadas|  |\n");
            fprintf(file,"|--------------------------------------------------------------------------------------------|\n");
            
            for(int j = 0; j < tam; j++){
                fprintf(file,"|  %-5d %-51s %-10d %-21d|\n", cad_funcionario[j].id+1, cad_funcionario[j].nome, cad_funcionario[j].idade, cad_funcionario[j].horas);
            }
            fprintf(file,"|____________________________________________________________________________________________|\n");

            fclose(file);   //fechamento do arquivo txt

            imprimir_registro();    //imprimindo o txt no cmd

            printf ("\n\n[Funcionario Atualizado com sucesso]\n");
            printf ("[Pressione qualquer tecla para retornar ao menu principal]");
            system("Pause>null");
            menu_principal();
        }        
    }
}

void apagar_registro(){ //PROCEDIMENTO QUE APAGA UM FUNCIONÁRIO

    imprimir_registro();    //imprimindo o txt no cmd
    
    file = fopen("registro_funcionarios.txt", "r"); //Arquivo de entrada.
    file_out = fopen("transferindo.txt", "w"); //Arquivo de saída.

    char texto[100]; //string para armazenar a linha
    
    int id_apagar, cont=0;

    printf("\n[Qual id voce deseja apagar?]: ");
    fflush(stdin);
    scanf("%d", &id_apagar);

    //estrutura para identificar qual é a linha a ser excluída
    for (int i = 0; i < tam; i++)   //repetição do total de funcionários
    {
        if(id_apagar != cad_funcionario[i].id){ //caso o id para apagar for diferente do id atual da repetição
            cont++; //contador recebe +1
        }

    }

    int linha_selecionada = cont+6;      //cont+6 para ignorar o cabeçalho do txt
    int linha_atual = 1;                 //linha atual inicia em 1

    while(fgets(texto, 100, file) != NULL){       //enquanto existir algo no txta ser lido
        if(linha_atual != linha_selecionada){     //caso a linha atual seja diferente da linha selecionada
            fputs(texto, file_out);             //repete a linha no arquivo de saída
        }
        memset(texto, 0, sizeof(char) * 100);       //deleta a linha
        linha_atual++;         //acrescenta +1 à linha atual
    }

    fclose(file);   //fechamento do arquivo de entrada
    fclose(file_out);   //fechamento do arquivo de saída

    remove("registro_funcionarios.txt");    //exclui o arquivo txt de entrada
    rename("transferindo.txt", "registro_funcionarios.txt");    //renomeia o arquivo txt auxiliar como o arquivo txt de entrada

    imprimir_registro();
    printf ("\n\n[Pressione qualquer tecla para retornar ao menu principal]");
    system("Pause>null");
    menu_principal();

}

void ordem_horas(){ //PROCEDIMENTO QUE ORDENA POR HORAS TRABALHADAS

    system("cls");

    file = fopen("registro_funcionarios.txt","w");  //abertura do arquivo txt

        //declarando variáveis
        int alt;
        int aux,  num[2];
        
        //repetição para passar os dados de hora para a variável num
        for (int i = 0; i < tam; i++){   
            num[i]= cad_funcionario[i].horas;
        } 

        //estrutura para identificar o maior número utilizando variável auxiliar
        for (int i = 0; i < tam; i++){            
            for (int j = i + 1; j < tam; j++){                
                if (num[i] > num[j]){
                    aux =  num[i];
                    num[i] = num[j];
                    num[j] = aux;
                }
            }            
        }
        
        fprintf(file,"\n[EMPRESA]: %s\n",empresa);
        fprintf(file,"_________________________________Ordem por horas trabalhadas__________________________________\n");
        fprintf(file,"|                                                                                            |\n");
        fprintf(file,"|  |ID|  |Nome|                                              |Idade|    |Horas trabalhadas|  |\n");
        fprintf(file,"|--------------------------------------------------------------------------------------------|\n");
        
        for (int i = 0; i < tam; i++){               
            alt = num[i];   //alt recebe o número atual          
            for (int j=0;j<tam;j++){                
                if (alt==cad_funcionario[j].horas){ //caso o número atual seja igual a hora do funcionário atual da repetição j
                    fprintf (file,"|  %-5d %-51s %-10d %-21d|\n",cad_funcionario[j].id+1,cad_funcionario[j].nome,cad_funcionario[j].idade,num[i]);
                }               
            }
        }
        fprintf(file,"|____________________________________________________________________________________________|\n");
        
    fclose(file);   //fechamento do arquivo txt

    imprimir_registro();

    printf ("\n\n[Pressione qualquer tecla para retornar ao menu principal]\n");
    system("Pause>null");
    menu_principal();

}

//FUNÇÃO PRINCIPAL
int main(){

nome_empresa(); //chamando o procedimento nome_empresa
menu_principal();   //chamando o procedimento menu_principal


}

