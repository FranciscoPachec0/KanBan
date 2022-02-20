#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "lists.h"

#define TRUE 1
#define FALSE 0
#define NUMEROINVALIDO 20

int nid=1;
char verifyinput[50];
int flag;
int count = 0;
char ch;

/* while(to_do->next!=NULL){
     to_do = to_do->next;
     printf("nrid: %d\n",to_do->info.nrid);
     printf("prio: %d\n",to_do->info.prio);
     printf("msg: %s\n",to_do->info.msg);
     printf("data: %s\n",to_do->info.date);
 }*/

//typedef struct Cartao card;
/*typedef struct Cartao{
    int nrid;
    int prio;
    time_t date;
    char msg[50];
};*/

/* while(to_do->next!=NULL){
     to_do = to_do->next;
     printf("nrid: %d\n",to_do->info.nrid);
     printf("prio: %d\n",to_do->info.prio);
     printf("msg: %s\n",to_do->info.msg);
     printf("data: %s\n",to_do->info.date);
 }*/

//typedef struct Cartao card;
/*typedef struct Cartao{
    int nrid;
    int prio;
    time_t date;
    char msg[50];
};*/
int verificarinput(char input[], int menor, int maior){
    int opcao;
        if (atoi(input)==0) printf("Opção Inválida");
        else{
            opcao = atoi(input);
            if (opcao<menor || opcao>maior) return -1;
        }
    return opcao;
}
void view(List to_do, List doing, List done) { // ESTA TUDO FUDIDO, TENTAR PRINTAR COM A FUNCAO DO STOR
    printf("+-----------------------+-----------------------+-----------------------+\n");
    printf("|         To Do         |         Doing         |          Done         |\n");
    printf("+-----------------------+-----------------------+-----------------------+\n");

    while (to_do->next != NULL || doing->next != NULL || done->next != NULL) {
        int flag_do = 1;
        int flag_doing = 1;
        int flag_done = 1;

        if (to_do->next != NULL) {
            to_do = to_do->next;
            printf("| id: %d", to_do->info.nrid);
            for (int i = 0; i < 17; i++) {
                printf(" ");
            }
            printf("|");
        } else {
            flag_do = 0;
            printf("|");
            for (int i = 0; i < 23; i++) {
                printf(" ");
            }
            printf("|");
        }

        if (doing->next != NULL) {
            doing = doing->next;
            printf(" id: %d", doing->info.nrid);
            for (int i = 0; i < 17; i++) {
                printf(" ");
            }
            printf("|");
        } else {
            flag_doing = 0;
            for (int i = 0; i < 23; i++) {
                printf(" ");
            }
            printf("|");
        }

        if (done->next != NULL) {
            done = done->next;
            printf(" id: %d", done->info.nrid);
            for (int i = 0; i < 17; i++) {
                printf(" ");
            }
            printf("|\n");
        } else {
            flag_done = 0;
            for (int i = 0; i < 23; i++) {
                printf(" ");
            }
            printf("|\n");
        }

        if (flag_do) {
            printf("| msg: %s", to_do->info.msg);
            for (int i = 0; i < 17 - strlen(to_do->info.msg); i++) {
                printf(" ");
            }
            printf("|");
        } else {
            printf("|");
            for (int i = 0; i < 23; i++) {
                printf(" ");
            }
            printf("|");
        }

        if (flag_doing) {
            printf(" msg: %s", doing->info.msg);
            for (int i = 0; i < 17 - strlen(doing->info.msg); i++) {
                printf(" ");
            }
            printf("|");
        } else {
            for (int i = 0; i < 23; i++) {
                printf(" ");
            }
            printf("|");
        }

        if (flag_done) {
            printf(" msg: %s", done->info.msg);
            for (int i = 0; i < 17 - strlen(done->info.msg); i++) {
                printf(" ");
            }
            printf("|\n");
        } else {
            for (int i = 0; i < 23; i++) {
                printf(" ");
            }
            printf("|\n");
        }

        if(flag_doing){
            printf("|");
            for (int i = 0; i < 23; i++) {
                printf(" ");
            }
            printf("|");
            printf(" prazo: %s", doing->info.prazo);
            for (int i = 0; i < 5; i++) {
                printf(" ");
            }
            printf("|");
            for (int i = 0; i < 23; i++) {
                printf(" ");
            }
            printf("|\n");
        }

        printf("+-----------------------+-----------------------+-----------------------+\n");
    }
    printf("Insira qualquer caracter para sair da tabela\n");
    scanf("%s", verifyinput);
    while(getchar()!='\n');
}
void view2(List to_do,List doing,List done){
    printf("++++++++++++++++++++++++++++++++++\n"); //34
    printf("+              To Do             +\n");
    printf("++++++++++++++++++++++++++++++++++\n");
    list_print(to_do, 1);
    printf("++++++++++++++++++++++++++++++++++\n"); //34
    printf("+              Doing             +\n");
    printf("++++++++++++++++++++++++++++++++++\n");
    list_print(doing, 2);
    printf("++++++++++++++++++++++++++++++++++\n"); //34
    printf("+              Done              +\n");
    printf("++++++++++++++++++++++++++++++++++\n");
    list_print(done, 3);
    printf("++++++++++++++++++++++++++++++++++\n");
}
void moves(List to_do,List doing,List done,int flag1){
    int id;
    int opt = 0;
    flag=1;
    card temp;
    char conclusao[26];
    char nome[20];
    struct timeval tv;
    struct tm* tm;
    char nvresponsavel[20];

    while (flag == 1) {
        printf("1 - Ver o Quadro\n");
        printf("2 - Escolher com base no id\n");
        scanf("%s", verifyinput);
        while (getchar()!='\n');
        if ((atoi(verifyinput) == 0)) {
            printf("Opção inválida!!\n");
        } else {
            opt = atoi(verifyinput);
            if (opt == 1) {
                flag = 0;
                view(to_do, doing, done);
            } else if (opt == 2) {
                flag = 0;
            }
        }
    }
    flag=1;
    while (flag == 1) {
        printf("Insira o id do cartao: ");
        scanf("%s", verifyinput);
        while (getchar()!='\n');
        if (atoi(verifyinput)==0) printf("Insira um caractér válido\n");
        else {
            id = atoi(verifyinput);
            if (nid-1 < id) {
                printf("Não exite nenhuma tarefa associada a este ID\n"); //esta condicao nao chega e temos de adicionar uma opção para sair
                printf("1 - Tentar outro ID | 2 - Cancelar\n");
                scanf("%s",verifyinput);
                while (getchar()!='\n');
                opt = verificarinput(verifyinput, 1, 2);
                if (opt==-1) printf("Opção Inválida\n");
                else{
                    if (opt==1) flag=1;
                    else return;
                }
            }  else {
                switch(flag1){
                    case 1: //doing done
                        temp.nrid = id;
                        if (list_search_id(doing, temp) == NULL) printf("Não existe!\n");
                        else {
                            temp = list_search_id(doing, temp)->info;
                            flag = 0;
                            gettimeofday(&tv, NULL);
                            tm = localtime(&tv.tv_sec);
                            strftime(conclusao, 26, "%Y:%m:%d %H:%M:%S", tm);
                            temp.nrid = id;
                            temp = list_search_id(doing, temp)->info;
                            list_kill_id(doing, temp);
                            strcpy(temp.date_conc, conclusao);
                            list_insert(done, temp);
                        }
                        break;
                    case 2:// mudar responsavel
                        temp.nrid = id;
                        if (list_search_id(doing, temp) == NULL) printf("Não existe!\n");
                        else {
                            temp = list_search_id(doing, temp)->info;
                            flag = 0;
                            printf("Insira o novo responsavel: ");
                            scanf("%[^\n]", nvresponsavel);
                            strcpy(list_search_id(doing, temp)->info.pessoa, nvresponsavel);
                        }
                        break;
                    case 3:
                        temp.nrid = id;
                        if (list_search_id(to_do, temp) == NULL) printf("Não existe!\n");
                        else {
                                temp = list_search_id(to_do, temp)->info;
                                flag = 0;
                                int flag2=1;
                                while(flag2==1) {
                                    count = 0;
                                    printf("Insira o nome: ");
                                    while ((ch = getchar()) != '\n') {
                                        nome[count++] = ch;
                                    }
                                    nome[count]='\0';
                                        //printf("Nome: %s\n", nome);
                                        //printf("count = %d\n", count);
                                        if (count == 0) {
                                            printf("Insira um nome válido\n");
                                            continue;
                                        }else{
                                            flag2=0;
                                        }
                                }
                                    list_kill_id(to_do, temp);
                                    strcpy(temp.pessoa, nome);
                                    int day;
                                    int month;
                                    int year;
                                    char inputValue[20], mes[3], ano[5];
                                    char dia[3];
                                    flag = 1;
                                    while (flag == 1) {
                                        int j = 0;
                                        printf("Indique uma data prazo (DD/MM/AAAA): ");
                                        scanf("%s", inputValue);
                                        while (getchar() != '\n');
                                        for (int i = 0; i < 2; i++) {
                                            dia[i] = inputValue[j++];
                                        }
                                        dia[2] = '\0';
                                        j++;
                                        for (int i = 0; i < 2; i++) {
                                            mes[i] = inputValue[j++];
                                        }
                                        mes[2] = '\0';
                                        j++;
                                        for (int i = 0; i < 4; i++) {
                                            ano[i] = inputValue[j++];
                                        }
                                        ano[4] = '\0';
                                        if (atoi(dia) * atoi(mes) * atoi(ano) != 0) {
                                            day = atoi(dia);
                                            month = atoi(mes);
                                            year = atoi(ano);
                                            if ((year >= 1919) && (year <= 2119)) {
                                                if ((month >= 1) && (month <= 12)) {
                                                    if (((day >= 1) && (day <= 31)) &&
                                                        ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
                                                         (month == 9) ||
                                                         (month == 11))) {
                                                        flag = 0;
                                                    } else if (((day >= 1) && (day <= 30)) &&
                                                               ((month == 4) || (month == 6) || (month == 8) ||
                                                                (month == 10) || (month == 12))) {
                                                        flag = 0;
                                                    } else if (((day >= 1) && (day <= 28)) && (month == 2)) {
                                                        flag = 0;
                                                    } else if ((day == 29) && (month == 2) &&
                                                               ((year % 400 == 0) ||
                                                                ((year % 4 == 0) && (year % 100 != 0)))) {
                                                        flag = 0;
                                                    } else {
                                                        printf("Data Invalida!!\n");
                                                    }
                                                } else {
                                                    printf("Data Invalida!!\n");
                                                }
                                            } else {
                                                printf("Data Invalida!!\n");
                                            }
                                        }
                                    }
                                    inputValue[2]='/';
                                    inputValue[5]='/';
                                    strcpy(temp.prazo, inputValue);
                                    list_insert(doing, temp);


                        }
                        break;
                    case 4:
                        temp.nrid = id;
                        if (list_search_id(doing, temp) == NULL) printf("Não existe!\n");
                        else {
                            temp = list_search_id(doing, temp)->info;
                            flag = 0;
                            list_kill_id(doing, temp);
                            strcpy(temp.pessoa, "Não está atribuida");
                            strcpy(temp.prazo, "Não está atribuido");
                            list_insert(to_do, temp);
                        }
                        break;
                    case 5:
                        //printf("id = %d\n", id);
                        temp.nrid = id;
                        int nprio;
                        if(list_search_id(done, temp)==NULL){
                            printf("Não Existe!\n");
                        } else {
                            temp = list_search_id(done, temp)->info;
                            list_kill(done, temp);
                            printf("Insira a Prioridade: ");
                            scanf("%d", &nprio);
                            printf("\n");
                            temp.prio = nprio;
                            strcpy(temp.date_conc, "Ainda nao foi concluida");
                            list_insert(to_do, temp);
                            flag=0;
                        }
                        //move_done_do(to_do, done, id);
                        break;
                    case 6:
                        temp.nrid = id;
                        if(list_search_id(to_do, temp)!=NULL){
                            //printf("Encontrou na lista To Do\n");
                            temp = list_search_id(to_do, temp)->info;
                            list_kill(to_do, temp);
                            flag = 0;
                        } else if(list_search_id(doing, temp)!=NULL){
                            //printf("Encontrou na lista Doing\n");
                            temp = list_search_id(doing, temp)->info;
                            list_kill(doing, temp);
                            flag = 0;
                        } else if(list_search_id(done, temp)!=NULL){
                            //printf("Encontrou na lista Done\n");
                            temp = list_search_id(done, temp)->info;
                            list_kill(done, temp);
                            flag = 0;
                        } else {
                          printf("Não encontrou\n");
                        }
                        break;
                    default:
                        printf("É milagre\n");
                        break;
                }
            }
        }
    }
}
void save_changes(List to_do,List doing ,List done){
    FILE *f = fopen("to_do.txt", "w+");
    if(!list_empty(to_do)){
        while(to_do->next!=NULL){
            to_do = to_do->next;
            fprintf(f, "%d\n%d\n%s\n%s\n",to_do->info.nrid,to_do->info.prio,to_do->info.date_criac, to_do->info.msg);
        }
    }
    fclose(f);
    FILE *fp = fopen("doing.txt", "w+");
    if(!list_empty(doing)){
        while(doing->next!=NULL){
            doing = doing->next;
            fprintf(fp,"%d\n",doing->info.nrid);
            fprintf(fp,"%d\n",doing->info.prio);
            fprintf(fp,"%s\n",doing->info.prazo);
            fprintf(fp,"%s\n",doing->info.date_criac);
            fprintf(fp,"%s\n",doing->info.pessoa);
            fprintf(fp,"%s\n",doing->info.msg);
        }
    }
    fclose(fp);
    FILE *ft = fopen("done.txt", "w+");
    if(!list_empty(done)){
        while(done->next!=NULL){
            done = done->next;
            fprintf(ft,"%d\n%d\n%s\n%s\n%s\n%s\n",done->info.nrid,done->info.prio,done->info.date_criac,done->info.date_conc,done->info.pessoa,done->info.msg);
        }
    }
    fclose(ft);
}
void insert(List to_do) {// FEITO
    card to_insert;
    struct tm* tm;
    //time_t t;
    char data[26];
    char mensagem[17];
    /*char buffer[26];
    int millisec;
    struct tm* tm_info;
    struct timeval tv;*/
    struct timeval tv;
    gettimeofday(&tv, NULL);
    tm = localtime(&tv.tv_sec);
    /*time(&t);
    tm = localtime(&t);*/
    /*int dates[6];
    int j=0;*/
    strftime(data, 26, "%Y:%m:%d %H:%M:%S", tm);
    /* char pr[2];
     char ano[4];
     ano[0] = data[0];
     ano[1] = data[1];
     ano[2] = data[2];
     ano[3] = data[3];
     dates[j++]=atoi(ano);
     for(int i=4;i<26;){
         pr[0] = data[i++];
         pr[1] = data[i++];
         dates[j++] = atoi(pr);
         i++;
     }*/
    //strftime(data, 20, "%d-%m-%y", tm);
    flag = 1;
    while (flag==1) {
        printf("Insira a prioridade da tarefa (0-10): ");
        scanf("%s", verifyinput);
        while(getchar()!='\n');
        if (atoi(verifyinput) == 0) {
            printf("Opção Inválida\n");
        } else {
            int prio = atoi(verifyinput);
            if (prio < 1 || prio > 10) printf("Insira uma prioridade válida!!\n");
            else {
                flag = 0;
                to_insert.prio = prio;
            }
        }
    }
    //scanf("%d", &to_insert.prio);
    printf("Insira uma descrição da tarefa: ");
    //getchar();
    /*for(int i=0; (ch=getchar())!='\n'; i++){
        if (i>18){
            while(getchar()!='\n');
            printf("Insira uma mensagem válida (maximo 17 caracteres): \n");
            printf("Insira uma descrição da tarefa: ");
            getchar();
            i = 0;
            mensagem[0] = '\0';
        }
        mensagem[i]=ch;
    }*/
    int i=0;
    while((ch=getchar())!='\n'){
        if (i>16){
            while(getchar()!='\n');
            printf("Insira uma mensagem válida (maximo 17 caracteres): \n");
            printf("Insira uma descrição da tarefa: ");
            getchar();
            i = 0;
            mensagem[0] = '\0';
        }
        mensagem[i]=ch;
        i++;
    }
    mensagem[i] = '\0';
    printf("mensagem: %s", mensagem);
    strcpy(to_insert.msg, mensagem);
    //scanf("%[^\n]", to_insert.msg);
    printf("\n");
    //scanf("%s", to_insert.msg);
    to_insert.nrid = (nid);
    strcpy(to_insert.date_criac, data);
    list_insert(to_do, to_insert);
    nid++;
}
void aux(List src,List temp,char p[]) { // relacionado com o ponto que retorna as atividades de uma pessoa
    card n;
    //printf("%d", strcmp())
    while (src->next != NULL) {
        src = src->next;
        //printf("pessoa : %s\n", p);
        //printf("pessoa src: %s\n", src->info.pessoa);
        //printf("%d\n", strcmp(p, src->info.pessoa));
        if (strcmp(src->info.pessoa, p) == 0) {
            n = src->info;
            list_insert(temp, n);
            temp = temp->next;
        }
    }
}
void pessoa_tarefas(List to_do, List doing, List done){
    char pessoa[20];
    List lista1 = list_new();
    List lista2 = list_new();
    List lista3 = list_new();
    printf("Insira o nome da pessoa: ");
    //getchar();
    scanf("%[^\n]", pessoa);
    //printf("pessoa: %s\n", pessoa);
    while (getchar()!='\n');
    aux(doing,lista2,pessoa);
    aux(done,lista3,pessoa);
    //view2(lista1,lista2,lista3);
    view(lista1,lista2,lista3);
}
void data_criacao(List to_do, List doing, List done){
    List do_temp = list_new();
    List doing_temp = list_new();
    List done_temp = list_new();

    List temp3 = to_do->next; // verificar se esta bem o valor (esta a comecar no 1 elemento pois o 1 é inutil)
    for (int i=0; i<list_size(to_do); i++){
        list_insert_data(do_temp, temp3->info);
        temp3 = temp3->next;
    }

    List temp = doing->next; // verificar se esta bem o valor (esta a comecar no 1 elemento pois o 1 é inutil)
    for (int i=0; i<list_size(doing); i++){
        list_insert_data(doing_temp, temp->info);
        temp = temp->next;
    }

    List temp2 = done->next; // verificar se esta bem o valor (esta a comecar no 1 elemento pois o 1 é inutil)
    for (int i=0; i<list_size(done); i++){
        list_insert_data(done_temp, temp2->info);
        temp2 = temp2->next;
    }
    view2(do_temp, doing_temp, done_temp);
}
void load_content(List to_do,List doing,List done){
    int maxid =0;
    FILE *f = fopen ("to_do.txt", "r");
    fseek(f,0L,SEEK_SET);
    card temp;
    while(fscanf(f,"%d",&temp.nrid)!=EOF){
        fgetc(f);
        fscanf(f,"%d",&temp.prio);
        fgetc(f);
        fscanf(f,"%[^\n]",temp.date_criac);
        fgetc(f);
        fscanf(f,"%[^\n]",temp.msg);
        fgetc(f);
        list_insert(to_do,temp);
        if(temp.nrid > maxid) maxid = temp.nrid;
    }

    FILE *fp = fopen ("doing.txt", "r");
    fseek(fp,0L,SEEK_SET);
    while(fscanf(fp,"%d",&temp.nrid)!=EOF){
        fgetc(fp);
        //printf("%d\n", temp.nrid);
        fscanf(fp,"%d",&temp.prio);
        fgetc(fp);
        //printf("%d\n", temp.prio);
        //printf("%s\n", temp.date_criac);
        fscanf(fp,"%[^\n]",temp.prazo);
        fgetc(fp);
        fscanf(fp,"%[^\n]",temp.date_criac);
        fgetc(fp);
        //printf("%s\n", temp.prazo);
        fscanf(fp,"%[^\n]",temp.pessoa);
        fgetc(fp);
        //printf("%s\n", temp.pessoa);
        fscanf(fp,"%[^\n]",temp.msg);
        fgetc(fp);
        //printf("%s\n", temp.msg);
        list_insert(doing,temp);
        if(temp.nrid > maxid) maxid = temp.nrid;
    }
    FILE *file = fopen ("done.txt", "r");
    fseek(file,0L,SEEK_SET);
    while(fscanf(file,"%d",&temp.nrid)!=EOF){
        fgetc(file);
        //printf("%d\n", temp.nrid);
        fscanf(file,"%d",&temp.prio);
        fgetc(file);
        //printf("%d\n", temp.prio);
        fscanf(file,"%[^\n]",temp.date_criac);
        fgetc(file);
        //printf("%s\n", temp.date_criac);
        fscanf(file,"%[^\n]",temp.date_conc);
        fgetc(file);
        //printf("%s\n", temp.date_conc);
        fscanf(file,"%[^\n]",temp.pessoa);
        fgetc(file);
        //printf("%s\n", temp.pessoa);
        fscanf(file,"%[^\n]",temp.msg);
        fgetc(file);
        //printf("%s\n", temp.msg);
        list_insert(done,temp);
        if(temp.nrid > maxid) maxid = temp.nrid;
    }
    nid = maxid+1;
}
int selection(List to_do, List doing, List done) {
    int opt = 0;
    printf("1 - Inserir uma nova tarefa na lista To Do | 2 - Mover uma tarefa da lista To Do para Doing\n");
    //printf("2 - Mover uma tarefa da lista To Do para Doing \n");
    printf("3 - Alterar a pessoa responsável por um cartão em Doing | 4 - Terminar uma tarefa\n");
    //printf("4 - Terminar uma tarefa\n");
    printf("5 - Reabrir tarefa | 6 - Visualizar o quadro\n");
    //printf("6 - Visualizar o quadro\n");
    printf("7 - Visualizar apenas as suas tarefas | 8 - Visualizar o quadro (Ordenação por data de criação)\n");
    //printf("8 - Visualizar o quadro (Ordenação por data de criação)\n");
    printf("9 - Eliminar uma tarefa | 10 - Vizualizar o quadro com todas as informações\n");
    printf("11 - Guardar alterações | 12 - Sair e guardar alterações\n");
    printf("\n");
    printf("Escolha uma opção: ");
    //scanf("%d", &opt);
    scanf("%s", verifyinput);
    while (getchar()!='\n');
    if (atoi(verifyinput) == 0){
        //printf("Insira um caracter válido!\n");
        opt = NUMEROINVALIDO;
    } else {
        opt = atoi(verifyinput);
    }
    printf("\n");
    switch (opt) {
        case 1:
            insert(to_do);
            return opt;
        case 2:
            flag=1;
            while(flag==1){
                printf("1 - Mover da lista To Do para a lista Doing | 2 - Mover da lista Doing para a Lista To Do\n");
                scanf("%s", verifyinput);
                while (getchar()!='\n');
                if (atoi(verifyinput)==0) printf("Opção Inválida!!\n");
                else {
                    opt = atoi(verifyinput);
                    if (opt<1 || opt>2) printf("Opção Inválida!!\n"); // podemos usar a funcao
                    else flag=0;
                }
            }
            //scanf("%d", &opt);
            if (opt == 1){
                //printf("Entrou na do_doing\n");
                //move_do_doing(to_do, doing, done);
                moves(to_do,doing,done,3);
            } else if (opt == 2){
                //printf("Entrou na doing_to\n");
                //move_doing_do(to_do, doing, done);
                moves(to_do,doing,done,4);
            }
            return opt;
        case 3:
            //mudar_responsavel(to_do, doing, done);
            moves(to_do,doing,done,2);
            return opt;
        case 4:
            moves(to_do,doing,done,1);
            //fechar_tarefa(to_do, doing, done);
            return opt;
        case 5:
            //reabrir_tarefa(to_do, doing, done);
            moves(to_do,doing,done,5);
            return opt;
        case 6:
            view(to_do, doing, done);
            return opt;
        case 7:
            pessoa_tarefas(to_do, doing, done);
            return opt;
        case 8:
            data_criacao(to_do, doing, done);
            return  opt;
        case 9: // eliminar uma tarefa
            moves(to_do, doing, done, 6);

            return opt;
        case 10:
            view2(to_do, doing, done);
            return opt;
        case 11: // gravar
            flag = 1;
            while (flag == 1) {
                printf("Tem a certeza que pretende gravar os novos dados?\n");
                printf("1 - Sim | 2 - Não\n");
                scanf("%s", verifyinput);
                //scanf("%d", &opt);
                while (getchar() != '\n');
                if (atoi(verifyinput) == 0) {
                    printf("Insira um caracter válido!\n");
                    //opt = NUMEROINVALIDO;
                    continue;
                } else {
                    opt = verificarinput(verifyinput, 1, 2);
                    if (opt == -1) printf("Opção Inválida\n");
                    else {
                        flag = 0;
                    }
                }
            }
            if (opt == 1) {
                save_changes(to_do, doing, done);
                printf("Gravação feita com sucesso\n");
            } else {
                printf("Gravação Cancelada\n");
            }
            return opt;
        case 12: // gravar e sair
            flag=1;
            int opt2 = 0;
            while (flag==1) {
                flag = 1;
                while (flag == 1) {
                    printf("Tem a certeza que pretende gravar os novos dados?\n");
                    printf("1 - Sim | 2 - Não\n");
                    scanf("%s", verifyinput);
                    //scanf("%d", &opt);
                    while (getchar() != '\n');
                    if (atoi(verifyinput) == 0) {
                        printf("Insira um caracter válido!\n");
                        //opt = NUMEROINVALIDO;
                        continue;
                    } else {
                        opt2 = verificarinput(verifyinput, 1, 2);
                        if (opt2 == -1) printf("Opção Inválida\n");
                        else {
                            flag = 0;
                        }
                    }
                }
                if (opt2 == 1) {
                    save_changes(to_do, doing, done);
                    printf("Gravação feita com sucesso\n");
                } else {
                    printf("Gravação Cancelada\n");
                }
                flag = 1;
                while (flag == 1) {
                    printf("Tem a certeza que pretende sair?\n");
                    printf("1 - Sim | 2 - Não\n");
                    scanf("%s", verifyinput);
                    while (getchar() != '\n');
                    if (atoi(verifyinput) == 0) {
                        printf("Insira um caracter válido!\n");
                        //opt = NUMEROINVALIDO;
                        continue;
                    } else {
                        opt = verificarinput(verifyinput, 1, 2);
                        if (opt == -1) printf("Opção Inválida\n");
                        else {
                            flag = 0;
                        }
                    }
                }
                if (opt == 1 && opt2==1) {
                    printf("Gravado e Terminado\n");
                    opt = 12;
                } else if (opt==1 && opt2==2) {
                    printf("Terminado mas não gravado\n");
                    opt = 12;
                } else if (opt==2 && opt2==1){
                    opt = 1;
                    printf("Gravado mas não terminado\n");
                } else if(opt==2 && opt2==2){
                    opt = 1;
                    printf("Não terminado nem gravou\n");
                }
            }
            return opt;

        default: // CERTO
            printf("Opção Inválida\n");
            break;
    }
    return 0;
}
int main() {
    List to_do = list_new();
    List doing = list_new();
    List done = list_new();
    int opt =1;
    flag =1;
    while(flag ==1){
        printf("Pretende carregadar o quadro guardado?\n");
        printf("1 - Sim | 2 - Não\n");
        scanf("%s", verifyinput);
        if((atoi(verifyinput) == 0)){
            printf("Opção inválida!!\n");
            break;
        } else {
            opt = atoi(verifyinput);
            if(opt == 1){
                flag=0;
                load_content(to_do,doing,done);
                printf("Quadro carregado com sucesso\n");
            }else if(opt==2){
                flag=0;
            }
        }
    }
    int n = 0;
    while (n != 12) {
        n = 0;
        n = selection(to_do, doing, done);
    }
    return 0;
}