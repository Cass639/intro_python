#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


#define max_cand 100

typedef struct {
    char nome[40], cpf[12];
    int dia, mes, ano, cor, gen, den_q, ant_cr, nvl_esc, tat, trat_med, rem_cont, trans_psi, srv, idade;
    char tat_r[100], trat_med_r[100], rem_cont_r[100], trans_psi_r[100], ant_cr_r[100], den_q_r[100];
    float alt;
} Candidato;

int contem_numero(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            return 1; // encontrou um número
        }
    }
    return 0; // não encontrou nenhum número
}

int is_somente_numeros(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; // achou um não-dígito
        }
    }
    return 1; // todos são dígitos
}

int contem_caractere_especial(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != ' ') {
            return 1; // encontrou caractere especial
        }
    }
    return 0; // não encontrou
}

int main() {
    
    Candidato candidatos[max_cand];
    int tot_cand = 0;
    int opcao, i;
    int rep = 0;

    while (1) {
        printf("\n==== MENU PRINCIPAL ====\n");
        printf("1 - Cadastro\n");
        printf("2 - Relatório Geral\n");
        printf("3 - Relatório Individual\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o '\n' do buffer

        if (opcao == 0) {
            printf("Encerrando o programa...\n");
            break;
        } else if (opcao == 1) {
        while(1){   
            if (tot_cand >= max_cand) {
                printf("Limite máximo de cadastros atingido.\n");
                continue;
            }

            Candidato c;

            printf("Digite o nome completo do candidato: \n");
            fgets(c.nome, sizeof(c.nome), stdin);
            c.nome[strcspn(c.nome, "\n")] = '\0';

                    if(strcmp(c.nome, "0") == 0) {
            break;  // Sai do loop quando nome for "0"
        }
            while(contem_caractere_especial(c.nome) ||contem_numero(c.nome) )
            {
            
            printf("Por favor, coloque somente letras!\n");
            printf("Digite o nome completo do candidato: \n");
            fgets(c.nome, sizeof(c.nome), stdin);
            c.nome[strcspn(c.nome, "\n")] = '\0';

            if(strcmp(c.nome, "0") == 0) {
            break;  // Sai do loop quando nome for "0"

            
            }
            }

            printf("Digite o CPF (somente números): ");
            fgets(c.cpf, sizeof(c.cpf), stdin);
            c.cpf[strcspn(c.cpf, "\n")] = '\0';
            while(!is_somente_numeros(c.cpf) || strlen(c.cpf)!=11){
            printf("Digite o CPF corretamente sem letras ou simbolos, somente com numero e com 11 digitos\n");
            fgets(c.cpf, sizeof(c.cpf), stdin);
            c.cpf[strcspn(c.cpf, "\n")] = '\0';
            }
            getchar();


            printf("Digite o dia de nascimento: ");
            scanf("%d", &c.dia);
            while(c.dia>31 || c.dia<1){
            printf("Digite um valor de 1 à 31\n");
            printf("Digite o dia de nascimento: ");
            scanf("%d", &c.dia);}

            printf("Digite o mês de nascimento: ");
            scanf("%d", &c.mes);
            while(c.mes<1 || c.mes>12){
            printf("Digite o mês de nascimento: ");
            scanf("%d", &c.mes);
            }

           
            printf("Digite o ano de nascimento: ");
            scanf("%d", &c.ano);
            while(c.ano<1900 || c.ano>2025){
            printf("Digite o ano de nascimento: ");
            scanf("%d", &c.ano);
            }
            getchar(); // Limpa buffer         

            // Calcular idade
            time_t t = time(NULL);
            struct tm *data = localtime(&t);
            c.idade = data->tm_year + 1900 - c.ano;
            if ((c.mes > data->tm_mon + 1) || (c.mes == data->tm_mon + 1 && c.dia > data->tm_mday)) {
                c.idade--;
            }

            if (data->tm_year + 1900 - c.ano < 18) {
                printf("Candidato menor de idade, não pode se cadastrar.\n");
                rep++;
                continue;
            }

            if (data->tm_year + 1900 - c.ano >45) {
                printf("Candidato atingiu o limite de idade, para se alistar.\n");
                rep++;
                continue;
            }
            printf("Digite a altura[ex: 1.80]: ");
            scanf("%f", &c.alt);

            printf("Gênero: Masculino[1] Feminino[2]: ");
            scanf("%d", &c.gen);
            while (c.gen != 1 && c.gen != 2) {
                printf("Opção inválida. Digite novamente: ");
                scanf("%d", &c.gen);
            }

            printf("Cor de pele: Preta[1] Branca[2] Amarela[3] Parda[4]: ");
            scanf("%d", &c.cor);
            while (c.cor < 1 || c.cor > 4) {
                printf("Opção inválida. Digite novamente: ");
                scanf("%d", &c.cor);
            }

            printf("Nível de escolaridade:\nFundamental Incompleto[1]\nFundamental Completo[2]\nMédio Incompleto[3]\nMedio Completo[4]\nSuperior Incompleto[5]\nSuperior Completo[6]");
            scanf("%d", &c.nvl_esc);
            while (c.nvl_esc < 1 || c.nvl_esc > 6) {
                printf("Opção inválida. Digite novamente: ");
                scanf("%d", &c.nvl_esc);
            }

            printf("Possui tatuagens? sim[1] não[2]: ");
            scanf("%d", &c.tat);
            getchar();
            while(c.tat<1 || c.tat>2){
            printf("Digite entre as opções 1 à 2");
            printf("Possui tatuagens? sim[1] não[2]: ");
            scanf("%d", &c.tat);
            getchar();
            }
            if (c.tat == 1) {
                printf("Descreva: ");
                fgets(c.tat_r, sizeof(c.tat_r), stdin);
                c.tat_r[strcspn(c.tat_r, "\n")] = '\0';
            }

            printf("Antecedentes criminais? sim[1] não[2]: ");
            scanf("%d", &c.ant_cr);
            getchar();
            while(c.ant_cr<1 || c.ant_cr>2){
            printf("Digite entre as opções 1 à 2");
            printf("Antecedentes criminais? sim[1] não[2]: ");
            scanf("%d", &c.ant_cr);
            getchar();
            }
            if (c.ant_cr == 1) {
                printf("Descreva: ");
                fgets(c.ant_cr_r, sizeof(c.ant_cr_r), stdin);
                c.ant_cr_r[strcspn(c.ant_cr_r, "\n")] = '\0';
            }

            printf("Dependente químico? sim[1] não[2]: ");
            scanf("%d", &c.den_q);
            getchar();
            while(c.den_q<1 || c.den_q>2){
            printf("Digite entre as opções 1 à 2");
            printf("Dependente químico? sim[1] não[2]: ");
            scanf("%d", &c.den_q);
            getchar();
            }
            if (c.den_q == 1) {
                printf("Descreva: ");
                fgets(c.den_q_r, sizeof(c.den_q_r), stdin);
                c.den_q_r[strcspn(c.den_q_r, "\n")] = '\0';
            }

            printf("Tratamento médico? sim[1] não[2]: ");
            scanf("%d", &c.trat_med);
            getchar();
            while(c.trat_med<1 || c.trat_med>2){
            printf("Digite entre as opções 1 à 2");
            printf("Tratamento médico? sim[1] não[2]: ");
            scanf("%d", &c.trat_med);
            getchar();
            }
            if (c.trat_med == 1) {
                printf("Descreva: ");
                fgets(c.trat_med_r, sizeof(c.trat_med_r), stdin);
                c.trat_med_r[strcspn(c.trat_med_r, "\n")] = '\0';
            }


            printf("Remédios controlados? sim[1] não[2]: ");
            scanf("%d", &c.rem_cont);
            getchar();
            while(c.rem_cont<1 || c.rem_cont>2){
            printf("Digite entre as opções 1 à 2");
            printf("Remédios controlados? sim[1] não[2]: ");
            scanf("%d", &c.rem_cont);
            getchar();
            }
            if (c.rem_cont == 1) {
                printf("Descreva: ");
                fgets(c.rem_cont_r, sizeof(c.rem_cont_r), stdin);
                c.rem_cont_r[strcspn(c.rem_cont_r, "\n")] = '\0';
            }

            printf("Transtorno psicológico? sim[1] não[2]: ");
            scanf("%d", &c.trans_psi);
            getchar();
            while(c.trans_psi<1 || c.trans_psi>2){
            printf("Digite entre as opções 1 à 2");
            printf("Transtorno psicológico? sim[1] não[2]: ");
            scanf("%d", &c.trans_psi);
            getchar();
            }
            if (c.trans_psi == 1) {
                printf("Descreva: ");
                fgets(c.trans_psi_r, sizeof(c.trans_psi_r), stdin);
                c.trans_psi_r[strcspn(c.trans_psi_r, "\n")] = '\0';
            }


            printf("Deseja servir? sim[1] não[2]: ");
            scanf("%d", &c.srv);
            getchar();
            while(c.srv<1 || c.srv>2){
            printf("Digite entre as opções 1 à 2");
            printf("Deseja servir? sim[1] não[2]: ");
            scanf("%d", &c.srv);
            getchar();
            }

            candidatos[tot_cand++] = c;
            printf("Cadastro realizado com sucesso!\n");


        }

        } else if (opcao == 2) {
int qtd_mas = 0;
int qtd_fem = 0;

int qtd_preta = 0;
int qtd_branca = 0;
int qtd_amar = 0;
int qtd_pard = 0;

int qtd_fund_incomp = 0;
int qtd_fun_com = 0;
int qtd_med_incomp = 0;
int qtd_med_comp = 0;
int qtd_sup_incomp = 0;
int qtd_sup_comp = 0;

int qtd_tatuagem = 0;
int qtd_no_tatuagem = 0;

int qtd_ant_cr = 0;
int qtd_no_ant_cr = 0;

int qtd_dep_quim = 0;
int qtd_no_dep_quim = 0;

int qtd_rem_cont = 0;
int qtd_no_rem_cont = 0;

int qtd_trans_psi = 0;
int qtd_no_trans_psi = 0;

int qtd_srv = 0;
int qtd_no_srv = 0;
for (i = 0; i < tot_cand; i++) {
    for (i = 0; i < tot_cand; i++) {
    if (candidatos[i].gen == 1) qtd_mas++;
    if (candidatos[i].gen == 2) qtd_fem++;

    if (candidatos[i].cor == 1) qtd_preta++;
    if (candidatos[i].cor == 2) qtd_branca++;
    if (candidatos[i].cor == 3) qtd_amar++;
    if (candidatos[i].cor == 4) qtd_pard++;

    if (candidatos[i].nvl_esc == 1) qtd_fund_incomp++;
    if (candidatos[i].nvl_esc == 2) qtd_fun_com++;
    if (candidatos[i].nvl_esc == 3) qtd_med_incomp++;
    if (candidatos[i].nvl_esc == 4) qtd_med_comp++;
    if (candidatos[i].nvl_esc == 5) qtd_sup_incomp++;
    if (candidatos[i].nvl_esc == 6) qtd_sup_comp++;

    if (candidatos[i].tat == 1) qtd_tatuagem++;
    if (candidatos[i].tat == 2) qtd_no_tatuagem++;

    if (candidatos[i].ant_cr == 1) qtd_ant_cr++;
    if (candidatos[i].ant_cr == 2) qtd_no_ant_cr++;

    if (candidatos[i].den_q == 1) qtd_dep_quim++;
    if (candidatos[i].den_q == 2) qtd_no_dep_quim++;

    if (candidatos[i].rem_cont == 1) qtd_rem_cont++;
    if (candidatos[i].rem_cont == 2) qtd_no_rem_cont++;

    if (candidatos[i].trans_psi == 1) qtd_trans_psi++;
    if (candidatos[i].trans_psi == 2) qtd_no_trans_psi++;

    if (candidatos[i].srv == 1) qtd_srv++;
    if (candidatos[i].srv == 2) qtd_no_srv++;
}


            }

            printf("\n==== RELATÓRIO GERAL ====\n");
            printf("Total de candidatos: %d\n", tot_cand);
            printf("Total de reprovados por idade: %d\n", rep);

            printf("Total de pessoas do genero masculino: %d\n", qtd_mas);
            printf("Total de pessoas do genero femenino: %d\n", qtd_fem);

            printf("Total de pessoas da cor preta: %d\n", qtd_preta);
            printf("Total de pessoas da cor branca: %d\n", qtd_branca);
            printf("Total de pessoas da cor amarela: %d\n", qtd_amar);
            printf("Total de pessoas da cor parda: %d\n", qtd_pard);

            printf("Total de pessoas com o ensino fundamental incompleto: %d\n", qtd_fund_incomp);
            printf("Total de pessoas com o ensino fundamental completo: %d\n", qtd_fun_com);
            printf("Total de pessoas com o ensino medio incompleto: %d\n", qtd_med_incomp);
            printf("Total de pessoas com o ensino medio completo: %d\n", qtd_med_comp);
            printf("Total de pessoas com o ensino superior incompleto: %d\n", qtd_sup_incomp);
            printf("Total de pessoas com o ensino superior completo: %d\n", qtd_sup_comp);

            printf("Total de pessoas com tatuagem: %d\n", qtd_tatuagem);
            printf("Total de pessoas sem tatuagem: %d\n", qtd_no_tatuagem);

            printf("Total de pessoas com antecedentes crimi. : %d\n", qtd_ant_cr);
            printf("Total de pessoas sem antecedentes crimi. : %d\n", qtd_no_ant_cr);

            printf("Total de pessoas com depen.quimicas : %d\n", qtd_dep_quim);
            printf("Total de pessoas sem depen.quimicas : %d\n", qtd_no_dep_quim);

            printf("Total de pessoas que precisam de rem.controlados : %d\n", qtd_rem_cont);
            printf("Total de pessoas que não precisam de rem.controlados : %d\n", qtd_no_rem_cont);

            printf("Total de pessoas que tem trans. psico. : %d\n", qtd_trans_psi);
            printf("Total de pessoas que não tem trans. psico. : %d\n", qtd_no_trans_psi);

            printf("Total de pessoas que não tem trans. psico. : %d\n", qtd_no_trans_psi);

            printf("Total de pessoas que quer servir : %d\n", qtd_srv);
            printf("Total de pessoas que não quer servir: %d\n", qtd_no_srv);



        } else if (opcao == 3) {
            if (tot_cand == 0) {
                printf("Nenhum candidato cadastrado ainda.\n");
                continue;
            }

            printf("\n==== CANDIDATOS ====\n");
            for (i = 0; i < tot_cand; i++) {
                printf("[%d] %s\n", i, candidatos[i].nome);
            }

            printf("Escolha o índice do candidato para ver detalhes: ");
            int indice;
            scanf("%d", &indice);
            getchar();

            if (indice < 0 || indice >= tot_cand) {
                printf("Índice inválido.\n");
            } else {
                Candidato c = candidatos[indice];
                printf("\n==== DADOS DO CANDIDATO ====\n");
                printf("Nome: %s\n", c.nome);
                printf("CPF: %s\n", c.cpf);
                printf("Idade: %d\n", c.idade);
                printf("Altura: %.2f\n", c.alt);
                printf("Tatuagem: %s\n", c.tat == 1 ? c.tat_r : "Não");
                printf("Dependente químico: %s\n", c.den_q == 1 ? c.den_q_r : "Não");
                printf("Antecedentes criminais: %s\n", c.ant_cr == 1 ? c.ant_cr_r : "Não");
                printf("Remédio controlado: %s\n", c.rem_cont == 1 ? c.rem_cont_r : "Não");
                printf("Tratamento médico: %s\n", c.trat_med == 1 ? c.trat_med_r : "Não");
                printf("Transtorno psicológico: %s\n", c.trans_psi == 1 ? c.trans_psi_r : "Não");
                printf("Deseja servir? %s\n", c.srv == 1 ? "Sim" : "Não");
            }

        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
    
    }