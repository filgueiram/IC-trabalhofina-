#include <stdio.h>
#include <string.h>
#include <stdlib.h>

  
    struct dados{
    
    int codigo;
    char nome[50];
    char CPF[20];
    char tel[20];
    char endereco[100];
    };
    
    struct dados2{
        
    char agencia[20];
    int nconta;
    char nomeconta[20];
    float dinheiro;
    };
    
    int icodigo=0;
    int iconta=0;
    
void tela1(){
    // PRIMEIRA TELA //
    printf("======= Bem vindo ao DBanc =======\nDigite um comando para prosseguir:\n1-Gerenciar Clientes\n2-Gerenciar Contas\n3-Sair\n");
}
void tela2(){
    //SEGUNDA TELA //
    printf("======== Gerenciar Clientes ========\nDigite um comando para prosseguir:\n1-Cadastrar um cliente\n2-Listar todos os clientes cadastrados\n3-Buscar cliente já cadastrado\n4-Atualizar um cliente cadastrado\n5-Excluir um cliente cadastrado\n6-Voltar\n");
}   
void tela3(){    
    // TERCEIRA TELA //
    printf("======== Gerenciar Contas ========\nDigite um comando para prosseguir:\n1-Listagem de todas as contas cadastradas\n2-Cadastrar uma conta para um cliente\n3-Listar todas as contas de um cliente\n4-realizar um saque em uma conta\n5–realizar um deposito em uma conta\n6–realizar transferencia entre contas\n7–Exibir extrato de uma conta\n8–Voltar\n");
}

struct dados cadastrar(struct dados clientes[], FILE *pclientes){

  struct dados cliente;   
  icodigo++;
  cliente.codigo=icodigo;
  
  fprintf(pclientes, "%d ", cliente.codigo);
  
  scanf("%*c");
  //Nome
  printf ("Digite seu nome:");
  scanf ("%[^\n]", cliente.nome);
  fputs (cliente.nome, pclientes);

  fputs (" ", pclientes);

  //CPF
  printf ("Digite seu CPF/CNPJ:");
  scanf ("%s", cliente.CPF);
  fputs (cliente.CPF, pclientes);
  
  for(int iCPF=0; iCPF<icodigo; iCPF++){
    if(strcmp(cliente.CPF,clientes[iCPF].CPF)==0){
      printf("CPF/CNPJ invalido\n\n");
      
    }
  }
  fputs (" ", pclientes);

  //telefone
  printf ("Digite seu telefone:");
  scanf ("%s", cliente.tel);
  fputs (cliente.tel, pclientes);

  fputs (" ", pclientes);

  //endereco
  scanf("%*c");
  printf ("Digite seu endereco:");
  scanf ("%[^\n]", cliente.endereco);
  fputs (cliente.endereco, pclientes);
  
  fputs("\n", pclientes);
  
  printf("Cadastrado com sucesso!\n\n");
  return cliente;
  
}

void listar(struct dados cliente[]){
    
    system("clear");
    
    int ilistar=0;
    if(icodigo>0){
    for(ilistar; ilistar<icodigo; ilistar++){
        printf("%d %s %s %s %s \n\n",cliente[ilistar].codigo, cliente[ilistar].nome, cliente[ilistar].CPF, cliente[ilistar].tel, cliente[ilistar].endereco);
    }
    scanf("%*c");
    }
    else{
        printf("Nenhum cliente cadastrado\n\n");
    }
}

void buscar(struct dados clientes[],int icodigo){
    
    int comando4;
    int inome=0;
    int jcodigo=0;
    int iCPF=0;
    
    printf("Digite um comando para prosseguir:\n1-Buscar pelo Nome\n2-Buscar pelo Codigo\n3-Buscar pelo CPF/CNPJ\n");
    
    scanf("%d", &comando4);
    
    char nomebuscar[20];
    char CPFbuscar[20];
    char codigobuscar[20];
    int teste=0;
    
    if(comando4==1){
        printf("Digite o nome que deseja buscar:");
        scanf("%*c");
        scanf("%[^\n]", nomebuscar);
        //Compara com cada cliente pelo nome
        do{
            if((strcmp(nomebuscar,clientes[inome].nome))==0){
                teste++;
                printf("%d %s %s %s %s\n\n", clientes[inome].codigo, clientes[inome].nome, clientes[inome].CPF, clientes[inome].tel, clientes[inome].endereco);
            }inome++;
        } while(inome<icodigo);
    }
    else if(comando4==2){
        //Compara com cada cliente pelo codigo
        printf("Digite o codigo que deseja buscar:");
        scanf("%*c");
        scanf("%s", codigobuscar);
        
        do{
            if((strcmp(codigobuscar,clientes[jcodigo].nome))==0){
                printf("%d %s %s %s %s\n\n", clientes[jcodigo].codigo, clientes[jcodigo].nome, clientes[jcodigo].CPF, clientes[jcodigo].tel, clientes[jcodigo].endereco);
                teste++;
            }
            jcodigo++;
        } while(jcodigo<icodigo);
    }
    else if(comando4==3){
        printf("Digite o CPF/CNPJ que deseja buscar:");
        scanf("%*c");
        scanf("%s", CPFbuscar);
        //Compara com cada cliente pelo CPF/CNPJ
        do{
            if((strcmp(CPFbuscar,clientes[iCPF].CPF))==0){
                printf("%d %s %s %s %s\n\n", clientes[iCPF].codigo, clientes[iCPF].nome, clientes[iCPF].CPF, clientes[iCPF].tel, clientes[iCPF].endereco);
                teste++;
            } 
            iCPF++;
        } while(iCPF<icodigo);
    }
    if(teste==0){
        printf("Usuario nao encontrado!\n\n");
    }
}

void atualizar(struct dados clientes[],int icodigo,FILE *pclientes){
    
    int comando6;
    char CPFat[20];
    int codigoat;
    int i=0, j=0;
    
    remove("clientes");
    pclientes = fopen("clientes", "w");
    
    printf("Digite:\n1-Atualizar por CPF\n2-Atualizar por codigo\n");
    scanf("%d", &comando6);
    
    if(comando6==1){
    //Comparar pelo CPF/CNPJ
        printf("Digite o CPF/CNPJ do cliente que deseja atualizar:");
        scanf("%*c");
        scanf("%s", CPFat);
        do{
            if((strcmp(CPFat,clientes[i].CPF))==0){
                 scanf("%*c");
                
        
        //Nome
        printf ("Digite seu nome:");
        scanf ("%[^\n]", clientes[i].nome);


        //CPF
        printf ("Digite seu CPF/CNPJ:");
        scanf ("%[^\n]", clientes[i].CPF);
  

        //telefone
        printf ("Digite seu telefone:");
        scanf ("%[^\n]", clientes[i].tel);


        //endereco
        scanf("%*c");
        printf ("Digite seu endereco:");
        scanf ("%[^\n]", clientes[i].endereco);
  
        printf("Atualizado com sucesso!\n\n");    }i++;
        } while(i<icodigo);
        }
        
    //Comparar pelo codigo    
    else if(comando6==2){
        printf("Digite o codigo do cliente que deseja atualizar:");
        scanf("%d", &codigoat);
        if(codigoat==clientes[i].codigo){
                 scanf("%*c");
        //Nome
        printf ("Digite seu nome:");
        scanf ("%[^\n]", clientes[i].nome);
        fputs (clientes[i].nome, pclientes);

        fputs (" ", pclientes);

        //CPF
        printf ("Digite seu CPF/CNPJ:");
        scanf ("%[^\n]", clientes[i].CPF);
        fputs (clientes[i].CPF, pclientes);
  
        fputs (" ", pclientes);

        //telefone
        printf ("Digite seu telefone:");
        scanf ("%[^\n]", clientes[i].tel);
        fputs (clientes[i].tel, pclientes);

        fputs (" ", pclientes);

        //endereco
        scanf("%*c");
        printf ("Digite seu endereco:");
        scanf ("%[^\n]", clientes[i].endereco);
        fputs (clientes[i].endereco, pclientes);
  
        fputs("\n", pclientes); 
        printf("Atualizado com sucesso!\n\n");
        }i++;
        
        
        
        }else{
        printf("Cliente nao encontrado!\n\n");while(i<icodigo);
        
        
    
    }
    for(i=0; i<icodigo; i++){
        
        	fprintf(pclientes, "%d %s %s %s %s\n", clientes[i].codigo, clientes[i].nome, clientes[i].CPF, clientes[i].tel, clientes[i].endereco);
        
        }
    fclose(pclientes);
}

void excluir(struct dados clientes[],int icodigo){
    
    int comando5;
    char exCPF[15], excodigo[3];
    int i=0, j=0;
    printf("Digite:\n1-Excluir por CPF\n2-Excluir por codigo\n");
    scanf("%d", &comando5);
    
    if(comando5==1){
        printf("Digite o CPF do cliente que deseja excluir:");
        scanf("%*c");
        scanf("%s", exCPF);
        do{
            if((strcmp(exCPF,clientes[i].CPF))==0){
                //Substitui o endereco no vetor clientes
                while(i<icodigo){
                clientes[i].codigo=clientes[i+1].codigo;
                strcpy(clientes[i].nome,clientes[i+1].nome);
                strcpy(clientes[i].CPF,clientes[i+1].CPF);
                strcpy(clientes[i].tel,clientes[i+1].tel);
                strcpy(clientes[i].endereco,clientes[i+1].endereco);
                i++;
                    
                }
                    
                } 
            
        } while(i<icodigo);
    }
    else if(comando5==2){
        printf("Digite o Codigo do cliente que deseja excluir:");
        scanf("%*c");
        scanf("%s", excodigo);
        do{
            if((strcmp(excodigo,clientes[j].CPF))==0){
                
                while(j<icodigo){
                clientes[j].codigo=clientes[j+1].codigo;
                strcpy(clientes[j].nome,clientes[j+1].nome);
                strcpy(clientes[j].CPF,clientes[j+1].CPF);
                strcpy(clientes[j].tel,clientes[j+1].tel);
                strcpy(clientes[j].endereco,clientes[j+1].endereco);
                j++;
                    
                }
                    
                } 
            
        } while(j<icodigo);
    }
    printf("Excluido com sucesso!\n\n");
    icodigo--;
}

struct dados2 cadastrarcontas(struct dados clientes[], struct dados2 contas[],FILE *pcontas){
    
    struct dados2 conta;
    conta.nconta=iconta;
    int teste=0;
    if(icodigo!=0){
    fprintf(pcontas, "%d ", conta.nconta);
    iconta++;
    
    scanf("%*c");
    printf ("Digite a agencia:");
    scanf ("%[^\n]", conta.agencia);
    fputs (conta.agencia, pcontas);
    fputs (" ", pcontas);
    
    scanf("%*c");
    printf ("Digite o nome do cliente:");
    scanf ("%[^\n]", conta.nomeconta);
    fputs (conta.nomeconta, pcontas);
    fputs (" ", pcontas);
    
    fprintf(pcontas, "%.02f \n", conta.dinheiro);
    
    for(int i=0; i<icodigo; i++){
    if(strcmp(clientes[i].nome,conta.nomeconta)!=0){
      printf("Cliente invalido\n\n");
      teste++;
    }
    }
    
    if(teste==0){
    printf("Conta cadastrada com sucesso!\n\n");
    }
        
    }
    else{
        printf("Nenhum cliente cadastrado!\n\n");
    }
    return conta;
}

void deposito(struct dados2 contas[], FILE *pcontas){
    
    int qdeposito, i=0, j=0, teste=0;
    char depositoagencia[20];
    char depositoconta[10];
    system("clear");
    remove("contas");
    pcontas = fopen("contas", "w");
    
    printf("Para prosseguir, digite:\n");
    printf("-A agencia:");
    scanf("%[^\n]", depositoagencia);
    printf("-O nome da conta:");
    scanf("%[^\n]", depositoconta);
    
    do{                                                   //
            if((strcmp(depositoagencia,contas[i].agencia))==0){
                teste++;
                printf("Digite a quantia do deposito:");
                scanf("%*c");
                scanf("%d", &qdeposito);
                
                contas[i].dinheiro=contas[i].dinheiro+qdeposito;
                
                printf("Depositado com sucesso!\n");
            }
            i++;
            
            } while(i<iconta);
            if(teste==0){
                printf("Conta nao encontrada!\n");
            }    
            
    
    for(j; j<iconta; j++){
        fputs (contas[j].agencia, pcontas);
        fputs (" ", pcontas);
        fprintf(pcontas, "%d ", contas[j].nconta);
        fputs (contas[j].nomeconta, pcontas);
        fputs (" ", pcontas);
        fprintf(pcontas, "%.02f \n", contas[j].dinheiro);
    }       
} 

void listartodascontas(struct dados2 contas[], FILE *pcontas){
    
    int ilistar=0;
    if(iconta>0){
    for(ilistar; ilistar<iconta; ilistar++){
        printf("%d %s %s %.02f \n\n",contas[ilistar].nconta, contas[ilistar].agencia, contas[ilistar].nomeconta, contas[ilistar].dinheiro);
    }
    scanf("%*c");
    }
    else{
        printf("Nenhuma conta cadastrada!\n\n");
    }
}

void saque(struct dados2 contas[], FILE *pcontas){
    
    int qsaque, i=0, j=0, teste=0;
    char saqueagencia[20];
    char saqueconta[10];
    system("clear");
    remove("contas");
    pcontas = fopen("contas", "w");
    
    printf("Para prosseguir, digite:\n");
    printf("-A agencia:");
    scanf("%s", saqueagencia);
    printf("-O nome da conta:");
    scanf("%s", saqueconta);
    
    do{                                                   //
            if((strcmp(saqueagencia,contas[i].agencia))==0){
                teste++;
                printf("Digite a quantia do saque:");
                scanf("%*c");
                scanf("%d", &qsaque);
                
                contas[i].dinheiro=contas[i].dinheiro-qsaque;
                
                printf("Saque realizado com sucesso!\n\n");
            }
            i++;
            
            } while(i<iconta);
            if(teste==0){
                printf("Conta nao encontrada!\n\n");
            }    
            
    
    for(j; j<iconta; j++){
        fputs (contas[j].agencia, pcontas);
        fputs (" ", pcontas);
        fprintf(pcontas, "%d ", contas[j].nconta);
        fputs (contas[j].nomeconta, pcontas);
        fputs (" ", pcontas);
        fprintf(pcontas, "%.02f \n", contas[j].dinheiro);
    }
}

void listarcontasdocliente(struct dados clientes[],struct dados2 contas[]){
    
    char CPFbuscar[20];
    int comando7;
    int i=0;
    
    printf("Deseja buscar contas por:\n1-CPF/CNPJ\n2-Codigo\n");
    scanf("%d", &comando7);
    if(comando7==1){
    printf("Digite o CPF/CNPJ que deseja buscar:\n");
    }
    if(comando7==2){
    printf("Digite o codigo que deseja buscar:\n");
    }
    scanf("%s", CPFbuscar);
    
    
    for(i;i<icodigo;i++){
            if((strcmp(CPFbuscar,clientes[i].CPF))==0){
                if((strcmp(contas[i].nomeconta,clientes[i].nome))==0){
                    printf("%d %s %s %.02f\n\n", contas[i].nconta, contas[i].agencia, contas[i].nomeconta, contas[i].dinheiro);
                }
                else{
                    printf("Nenuma conta cadastrada!\n\n");
            }
            }
    }
}

void extrato(struct dados2 contas[], FILE *pcontas){
    
    char extratoagencia[20];
    char extratoconta[20];
    int i=0, teste=0, j=0;
    
    printf("Para prosseguir, digite:\n");
    printf("-A agencia:");
    scanf("%[^\n]", extratoagencia);
    printf("-O nome da conta:");
    scanf("%[^\n]", extratoconta);
    
    do{                                                   
            if((strcmp(extratoagencia,contas[i].agencia))==0){
                teste++;
                printf("%.02f\n", contas[i].dinheiro);
            }
            i++;
            
            } while(i<iconta);
            if(teste==0){
                printf("Conta nao encontrada!\n");
            }    
}

void transferencia(struct dados2 contas[], FILE *pcontas){
    
    char perdeuconta[20];
    char ganhouconta[20];
    char modo[20];
    char data[20];
    int valor;
    char descricao[100];
    int i=0, j=0, k=0;
    
    system("clear");
    remove("contas");
    pcontas = fopen("contas", "w");
    
    printf("Digite a conta que ira transferir:");
    scanf("%*c");
    scanf("%s" ,perdeuconta);
    printf("Digite a conta que recebera a transferencia:");
    scanf("%*c");
    scanf("%s" ,ganhouconta);
    printf("Digite o valor da transferencia:");
    scanf("%*c");
    scanf("%d", &valor);
    printf("Digite a data da transferencia:");
    scanf("%*c");
    scanf("%s", data);
    printf("Escolha entre credito e debito:");
    scanf("%*c");
    scanf("%s", modo);
    printf("Digite uma descricao para a transferencia:");
    scanf("%*c");
    scanf("%s", descricao);
    
    
    do{                                                   //
            if((strcmp(perdeuconta,contas[i].nomeconta))==0){
                
                contas[i].dinheiro=contas[i].dinheiro-valor;
                
            }
            i++;
            
            } while(i<iconta);
            
        do{                                                   //
            if((strcmp(ganhouconta,contas[k].nomeconta))==0){
                
                contas[k].dinheiro=contas[k].dinheiro+valor;
                
                printf("Transferencia realizado com sucesso!\n\n");
            }
            j++;
            
            } while(j<iconta);
        for(j; j<iconta; j++){
        fputs (contas[j].agencia, pcontas);
        fputs (" ", pcontas);
        fprintf(pcontas, "%d ", contas[j].nconta);
        fputs (contas[j].nomeconta, pcontas);
        fputs (" ", pcontas);
        fprintf(pcontas, "%.02f \n", contas[j].dinheiro);
    }
} 

int main(){
    
    struct dados cliente[100];
    struct dados2 contas[200];
    
    int comando1, comando2, comando3;
    
    FILE *pclientes;
    pclientes = fopen("clientes", "w");
    
    FILE *pcontas;
    pcontas = fopen("contas", "w");
        
while(comando1!=3){
    
    system("clear");
    tela1();

    scanf("%d", &comando1); 
    
    if(comando1==1){
        system("clear");
        comando2=0;
        
        while(comando2!=6){
            
        tela2();
        scanf("%d", &comando2);    
        
        if(comando2==1){
            cliente[icodigo]=cadastrar(cliente, pclientes);
        }
        else if(comando2==2){
            listar(cliente);
        }
        else if(comando2==3){
            buscar(cliente, icodigo);
        }
        else if(comando2==4){
            atualizar(cliente, icodigo, pclientes);
        }
        else if(comando2==5){
            excluir(cliente, icodigo);
        }
        }
    }
    if(comando1==2){
        comando3=0;
        system("clear");
       
        while(comando3!=8){ 
        tela3();
        scanf("%d", &comando3);
        if(comando3==1){
            listartodascontas(contas, pcontas);
        }
        else if(comando3==2){
            contas[iconta]=cadastrarcontas(cliente, contas, pcontas);
        }
        else if(comando3==3){
            listarcontasdocliente(cliente,contas);
        }
        else if(comando3==4){
            saque(contas, pcontas);
        }
        else if(comando3==5){
            deposito(contas, pcontas);
        }
        else if(comando3==6){
            transferencia(contas, pcontas);
        }
        else if(comando3==7){
            extrato(contas, pcontas);
        }
        }
        
    }    
    else if(comando1==3){
        system("clear");
        printf("===Obrigado por escolher DBanc===");
}
}
}

