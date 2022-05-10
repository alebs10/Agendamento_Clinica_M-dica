#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#define SIZE 300
#define LOGIN_MAX	64
#define SENHA_MAX	32

struct usuario_t {
	char login[64];
	char senha[32];
};

struct tp_agendamento
{
	char nomePaciente[SIZE];
	char nomeMedico[SIZE];
	char especialidade[SIZE];
	char dia[SIZE];
	char horario[SIZE];
	char local[SIZE];
};

struct tp_agendamento cad_agen[30];

void cadastrar()
{
	FILE *fp;
	struct usuario_t usuario;
	memset(&usuario, 0, sizeof(struct usuario_t));

	printf("Cadastro de usu�rio: \n");
	printf("login: ");
	scanf("%s", &usuario.login);
	printf("senha: ");
	scanf("%s", &usuario.senha);

	fp = fopen("login.txt", "wb");
	if (!fp) {
		printf("N�o foi poss�vel criar o arquivo de login");
		return;
	}
	fwrite(&usuario, sizeof(struct usuario_t), 1, fp);
	fclose(fp);
}

int login()
{
    FILE *fp;
	struct usuario_t usuario;
	fp = fopen("login", "rb");
	if (!fp) {
		cadastrar();
		fp = fopen("login", "rb");
		if (!fp) {
		    printf("N�o foi possivel encontrar o arquivo de login\n");
		    return 0;
		}
	}
	memset(&usuario, 0, sizeof(struct usuario_t));

	fread(&usuario, sizeof(struct usuario_t), 1, fp);
	fclose(fp);
	if (!strcmp("", usuario.login)) {
		printf("Nenhum usu�rio encontrado, abrindo cadastro!\n");
		cadastrar();
	} else {
	    int tentativas = 0;
		do {
			char login[LOGIN_MAX];
			char senha[SENHA_MAX];
			printf("Login: ");
			scanf("%s", &login);
			printf("Senha: ");
			scanf("%s", &senha);
			if (!strcmp(login, usuario.login) && !strcmp(senha, usuario.senha)) {
				printf("Bem vindo %s\n", usuario.login);
				return 1;
			} else {
				printf("Usu�rio ou senha invalidos!\n");
				tentativas++;
			}
		} while (tentativas < 3);
		printf("Numero maximo de tentativas alcan�ado!\n");
        return 0;
	}
	return 0;
}

void agendada()// sem retorno 
{
 	printf("Consulta agendada");
}

void contato()
{
	printf("\n\n\t\t\t***Fale Conosco***");
	printf("\nQualquer d�vida entrar em contado conocsco:");
	printf("\nTelefone para contato: (11) 4032-9852");
	printf("\nEmail para contato: doctorcorp@gmail.com.br\n");
	system("pause");
	system("cls");
}


void sair()// sem retorno 
{
    printf("Obrigado, volte sempre!\n");
}


int main(int argc, char *argv[])
{
	
	system ("color F0");//altera a cor de fundo e a cor do texto
	int menuEscolha;//vari�veis declaradas
	int i;
	int tipo, diario, mensal;//vari�veis declaradas
	int formaPagamento, pagamentoCartao, dinheiro, escolha_fatura, servico, tipo_relatorio, escolha_servico, id, novo_Cad, nota;
	int idade_Paciente, tel_Paciente;
	float valor=100, divi, total_pagar;
	char sexo_Paciente, nome_Paciente[40], cpf_Paciente[12];
	setlocale(LC_ALL, "");//altera a localidade para a localidade padr�o do S.O.

	FILE *pont_rel_cadastro;
	FILE *pont_rel_faturamento;
	
	printf("\n\t\t\t-----Seja bem-vindo a DoctorCorp-----\n\n\n");
	login();
	system("cls");
	
	printf ("\n\t\t\t\tPortal de Consulta\n\n\n");
	
	do
	{
	printf("[1] Agendamento de consulta\n");
	printf("[2] Consultas Agendadas\n");
	printf("[3] Cadastramento de pacientes\n");
	printf("[4] Pagamentos\n");
	printf("[5] Relat�rios\n");
	printf("[6] Fale Conosco\n");
	printf("[7] Avaliar servi�o\n");
	printf("[8] Sair\n");
	
	printf("\nDigite a op��o desejada: ");
	scanf("%d", &menuEscolha);//captura o dado informado
	system("cls");//limpar a tela
	
if(menuEscolha>0&&menuEscolha<=8){

	}else{
		menuEscolha=0;
	}
		
	switch(menuEscolha){	
	case 1:
		printf("Agendamento de consulta\n");
	
	for(i=0; i<30; i++)
	{
		printf("\nNome do Paciente: ");
		scanf("%s", &cad_agen[i].nomePaciente);
		
		printf("\nNome do M�dico: ");
		scanf("%s", &cad_agen[i].nomeMedico);
		
		printf("\nDigite a especialidade: ");
		scanf("%s", &cad_agen[i].especialidade);
		
		printf("\nDigite o dia: ");
		scanf("%s", &cad_agen[i].dia);
		
		printf("\nDigite o hor�rio: ");
		scanf("%s", &cad_agen[i].horario);
		
		printf("\nDigite o local do exame agendado: ");
		scanf("%s", &cad_agen[i].local);
	}
		system("pause");
		system("cls");
		break;//finaliza a execu��o do 'switch' e passa para a pr�xima instru��o
		
	case 2:
		agendada();
		printf("\n\nConsultas agendadas\n");
	
		for(i=0; i<30; i++)
		{
		printf("\n\nNome do Paciente : %s", cad_agen[i].nomePaciente);
		printf("\nNome do M�dico : %s", cad_agen[i].nomeMedico);
		printf("\nEspeciliadade : %s", cad_agen[i].especialidade);
		printf("\nDia : %s", cad_agen[i].dia);
		printf("\nHor�rio: %s", cad_agen[i].horario);
		printf("\nLocal do Exame : %s", cad_agen[i].local);
		}
		system("pause");
		system("cls");
		break;//finaliza a execu��o do 'switch' e passa para a pr�xima instru��o
		
	case 3:
		pont_rel_cadastro=fopen("C:\\Users\\ttava\\Desktop\\UNIP\\2� semestre\\PIM\\C�digos Fonte\\Relat�rio de cadastros.txt", "a");
		
		printf("\t\t\t***Cadastramento de Pacientes***\n");
		printf("ID: ");
		scanf("%d", &id);
		fflush(stdin);
		printf("Nome do paciente: ");
		gets(nome_Paciente);
		fflush(stdin);
		printf("CPF: ");
		gets(cpf_Paciente);
		fflush(stdin);
		printf("Sexo: ");
		scanf("%c", &sexo_Paciente);
		fflush(stdin);
		printf("Idade: ");
		scanf("%d", &idade_Paciente);
		fflush(stdin);
		printf("Telefone: ");
		scanf("%d", &tel_Paciente);
		fflush(stdin);
		printf("\nCadastro realizado!\n");
	
		fprintf(pont_rel_cadastro, "ID: %d | Nome: %s | CPF: %s | Sexo: %c | Idade: %d | Telefone: %d\n", id, nome_Paciente, cpf_Paciente, sexo_Paciente, idade_Paciente, tel_Paciente);
	  	fclose(pont_rel_cadastro);
	  	system("pause");
		break;
	
	case 4:
		pont_rel_faturamento=fopen("C:\\Users\\ttava\\Desktop\\UNIP\\2� semestre\\PIM\\C�digos Fonte\\Relat�rio de faturamento.txt", "a");
	  	
		printf("\t\t\t***Pagamento***\n");
		printf("Servi�o realizado:\n[1] Consulta (R$ 90,00)\n[2] Exame (R$ 120,00)\n=> ");
		scanf("%d", &escolha_servico);
	
		while(escolha_servico!=1 && escolha_servico!= 2){
			printf("Informe o c�digo correto do servi�o!\n");
			printf("Servi�o realizado:\n[1] Consulta (R$ 90,00)\n[2] Exame (R$ 120,00)\n=> ");
			scanf("%d", &escolha_servico);	
		}
		if(escolha_servico==1){
			total_pagar=90.00;
		}else{
			total_pagar=120.00;
		}
		printf("\n[1] Fechar fatura\n[2] Adicionar mais servi�os realizados\n=> ");
		scanf("%d", &escolha_fatura);
		
		while(escolha_fatura!=1 && escolha_fatura!=2){
		printf("Informe o c�digo correto do servi�o!\n");
		printf("[1] Fechar fatura\n[2] Adicionar mais servi�os realizados\n=> ");
		scanf("%d", &escolha_fatura);
		}
		if(escolha_fatura==1){
			printf("Total a pagar: R$ %.2f\n", total_pagar);
		}else{
			while(escolha_fatura==2){
				system("cls");
				printf("\nServi�o realizado:\n[1] Consulta (R$ 90,00)\n[2] Exame (R$ 120,00)\n=> ");
				scanf("%d", &escolha_servico);
							
				if(escolha_servico==1){
					total_pagar=total_pagar+90.00;
					printf("Total a pagar: R$ %.2f\n", total_pagar);
				}else if(escolha_servico==2){
					total_pagar=total_pagar+120.00;
					printf("Total a pagar: R$ %.2f\n", total_pagar);
				}
				printf("\n[1] Fechar fatura\n[2] Adicionar mais servi�os realizados\n=> ");
				scanf("%d", &escolha_fatura);
				system("cls");
				if(escolha_fatura==1){
				printf("Total a pagar: R$ %.2f\n", total_pagar);
				}
			}
		}
		printf("\nEscolha a forma de pagamento:");
		printf("\n[1] Cr�dito/D�bito");
		printf("\n[2] Dinheiro\n=> ");
		scanf("%d", &formaPagamento);
		
		while(formaPagamento!=1&&formaPagamento!=2){
			printf("Informe uma op��o v�lida!");
			printf("\nEscolha a forma de pagamento:");
			printf("\n[1] Cr�dito/D�bito");
			printf("\n[2] Dinheiro\n=> ");
			scanf("%d", &formaPagamento);
		}
		if(formaPagamento==1){
			if(formaPagamento==1){
				printf("\nSelecione a quantidade de parcelas:\n");
				printf("\n[1] � vista\n[2] 2x sem juros\n[3] 3x sem juros\n[4] 4x sem juros\n=>");
				scanf("%d", &pagamentoCartao);
				while(pagamentoCartao!=1&&pagamentoCartao!=2&&pagamentoCartao!=3&&pagamentoCartao!=4){
					printf("Informe um valor v�lido!");
					printf("\nSelecione a quantidade de parcelas:\n");
					printf("\n[1] � vista\n[2] 2x sem juros\n[3] 3x sem juros\n[4] 4x sem juros\n=>");
					scanf("%d", &pagamentoCartao);
				}
				if(pagamentoCartao==1){
					printf("Pagamento em 1x sem juros.\n");
				}else if(pagamentoCartao==2){
					printf("Pagamento em 2x sem juros.\n");
				}else if(pagamentoCartao==3){
					printf("Pagamento em 3x sem juros.\n");
				}else{
					printf("Pagamento em 4x sem juros.\n");
				}
			}else{
				printf("Total � vista: R$%.2f", total_pagar);
			}
		}
		fprintf(pont_rel_faturamento, "\nLEGENDA: Servi�o 1=Consulta | Servi�o 2=Exame\nLEGENDA: Forma de pagamento 1=Cart�o | Forma de pagamento 2=Dinheiro\n\n");
		fprintf(pont_rel_faturamento, "Servi�o realizado: %d | Total a pagar: %.2f | Forma de pagamento: %d\n", escolha_servico, total_pagar, formaPagamento);
	  	fclose(pont_rel_faturamento);

		fflush(stdin);
		printf("Venda realizada com sucesso!");
		getchar();
		system("cls");
		break;
		
	case 5:
		printf("Escolha um relat�rio:\n[1] Relat�rio de Faturamento\n[2] Relat�rio de Cadastros\n=> ");
		scanf("%d", &tipo_relatorio);
		switch(tipo_relatorio){
			case 1:
				printf("\t\t\t***Relat�rios de Faturamentos***\n");
				printf("Abrindo relat�rio...");
            	pont_rel_faturamento=fopen("C:\\Users\\ttava\\Desktop\\UNIP\\2� semestre\\PIM\\C�digos Fonte\\Relat�rio de faturamento.txt", "a");//cria/abre o arquivo *.txt para grava��o
            	fclose(pont_rel_faturamento);//fecha o processo em aberto do arquivo *.txt
            	system("\"C:\\Users\\ttava\\Desktop\\UNIP\\2� semestre\\PIM\\C�digos Fonte\\Relat�rio de faturamento.txt\"");//executa o arquivo *.txt
				break;//finaliza a execu��o do 'switch' e passa para a pr�xima instru��o
						
			case 2:
				printf("\t\t\t***Relat�rios de Cadastros***\n");
				printf("Abrindo Relat�rio...");
				pont_rel_cadastro=fopen("C:\\Users\\ttava\\Desktop\\UNIP\\2� semestre\\PIM\\C�digos Fonte\\Relat�rio de cadastros.txt", "a");
				fclose(pont_rel_cadastro);
		    	system("\"C:\\Users\\ttava\\Desktop\\UNIP\\2� semestre\\PIM\\C�digos Fonte\\Relat�rio de cadastros.txt\"");
				break;
		break;
		system("cls");
		break;
	
		}
	case 6:
		contato();
		break;
	
	case 7:
    		printf("Avalie nosso servi�o de 0 a 10: ");
    		scanf("%d", &nota);
    	
    		if(nota>=0&&nota<=10){
    			printf("Agradecemos a avalia��o!\n");
    			system("pause");
    			break;
			}else{
				nota=0;
			}
			printf("\nAgradecemos sua avalia��o!\n");
			system("pause");
			break;
	
	case 8:
		sair();
		return 0;
		break;

	
	default:
		printf("\nValor inv�lido, tente novamente\n");
		system("pause");
		system("cls");
		break;
	}
  }while(menuEscolha);

}
