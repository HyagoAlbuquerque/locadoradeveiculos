# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int AstonMartinMARB00 = 1;
int LaFerrariAperta = 1;
int BugattiChiron = 1;
int KoenigseggRegera = 1;
int ArashAF10Hybrid = 1;
int sair = 1;
const int HORA_LOCACAO = 12; 

time_t timer;//usada da funão resolverDatas
struct tm dLocAstonMartinMARB00, dDevAstonMartinMARB00, dLocLaFerrariAperta,dDevLaFerrariAperta, dLocBugattiChiron, dDevBugattiChiron, dLocKoenigseggRegera, dDevKoenigseggRegera, dLocArashAF10Hybrid, dDevArashAF10Hybrid;

int hLocAstonMartinMARB00, hDevAstonMartinMARB00, hLocLaFerrariAperta, hDevLaFerrariAperta, hLocBugattiChiron, hDevBugattiChiron, hLocKoenigseggRegera, hDevKoenigseggRegera, hLocArashAF10Hybrid, hDevArashAF10Hybrid;

resolverDatas(struct tm *date1, struct tm *date2, int diasAMais)
    {
    /* essa função recebe as structs e prenche as variáveis
     * para cada locação será necessário chama-la, isso para que as datas 
     * fiquem armazenadas nas variáveis. A princípio as datas estão vazias, 
     * a função que irá parametiza-la.
     * date1 = data de locação 
     * date2 = data de devolução
     * diasAMais = número de dias que o veículos estará em posse do locatário
     */
    
    /*
     CODIGO ORIGINAL
     Fonte: http://cssimplified.com/c-programming/write-a-program-in-c-to-add-the-given-number-of-days-to-the-current-date-and-print-the-final-resultant-date-for-e-g-adding-12-days-to-22082005-will-result-in-03092005-10m-dec2005
     Referência para a criação da função resolveDatas()    
    #include <time.h>
    #include <stdio.h>
    void  main()
    {
        struct tm date = {0} ;
        time_t timer;
        clrscr();
        timer=time(NULL);
        date = *gmtime( &timer ) ;
        //printf("%s",asctime(localtime(&timer)));
        printf("%d/%d/%d\n",date.tm_mday-1,date.tm_mon+1,date.tm_year+1900);
        date.tm_year = date.tm_year;
        date.tm_mon = date.tm_mon;
        date.tm_mday = date.tm_mday + 12;
        timer = mktime( &date ) ;
        date = *gmtime( &timer ) ;
        //printf("%s",asctime(localtime(&timer)));
        printf("%d/%d/%d\n",date.tm_mday-1,date.tm_mon+1,date.tm_year+1900);
        getch();
    }
     */
    
    /*
     * é necessário criar as datas como variáveis globais, para cada 
     * carro haverá datas relacionadas a locação e devolução, para
     * chama-las na função, de qualquer lugar do sistema.
     * struct tm dataLocNomeCarro = {0}, datDevNomeCarro = {0} ;
     * time_t timer;
     * resolverDatas(&dataLocaNomeCarro, &dataDevNomeCarro, dias);
     */
    timer=time(NULL);
    (*date1) = *gmtime( &timer ) ;//essa é a primeira data, a data de locação, preenchida a partir do sistema
    //printf("Data Locação: %d/%d/%d\n",(*date1).tm_mday-1,(*date1).tm_mon+1,(*date1).tm_year+1900);
    (*date2).tm_year = (*date1).tm_year;
    (*date2).tm_mon = (*date1).tm_mon;
    (*date2).tm_mday = (*date1).tm_mday + diasAMais;
    timer = mktime( (*&date2) ) ;
    (*date2) = *gmtime( &timer ) ;
    //printf("Data Devolução: %d/%d/%d\n",(*date2).tm_mday-1,(*date2).tm_mon+1,(*date2).tm_year+1900);
    /*
     * Na função main() usar :
     * printf("Data Locação: %d/%d/%d\n",dataLocaNomeCarro.tm_mday-1,dataLocaNomeCarro.tm_mon+1,dataLocaNomeCarro.tm_year+1900);
     * printf("Data Devolução: %d/%d/%d\n",dataDevNomeCarro.tm_mday-1,dataDevNomeCarro.tm_mon+1,dataDevNomeCarro.tm_year+1900);
     */
    }

void logoLegalRentACar()
    {
    
         system ("cls");
         printf ("\t=============================================================\n");
         printf ("\t======================LEGAL RENT A CAR=======================\n");
         printf ("\t=============================================================\n\n");
    }

void printCatalogo()
{
         logoLegalRentACar();

         printf ("\t CARROS DISPONÍVEIS PARA LOCAÇÃO:  \n\n");
         if (AstonMartinMARB00 == 1){printf ("\t Aston Martin MA-RB00  \n");}
         if (LaFerrariAperta == 1){printf ("\t La Ferrari Aperta  \n");}
         if (BugattiChiron == 1){printf ("\t Bugatti Chiron  \n");}
         if (KoenigseggRegera == 1){printf ("\t Koenigsegg Regera  \n");}
         if (ArashAF10Hybrid == 1){printf ("\t Arash AF10 Hybrid  \n");}
         printf ("\n\n");
         
         printf ("\t CARROS NÃO DISPONÍVEIS | DATA DE LOC | PREVISÃO DE ENTREGA:  \n\n");
         if (AstonMartinMARB00 == 0){printf ("\t Aston Martin MA-RB00  \t  %d/%d/%d\t%d/%d/%d às %d:00h\n",dLocAstonMartinMARB00.tm_mday,dLocAstonMartinMARB00.tm_mon+1,dLocAstonMartinMARB00.tm_year+1900, dDevAstonMartinMARB00.tm_mday,dDevAstonMartinMARB00.tm_mon+1,dDevAstonMartinMARB00.tm_year+1900, HORA_LOCACAO);}
         if (LaFerrariAperta == 0){printf ("\t La Ferrari Aperta    \t  %d/%d/%d\t%d/%d/%d às %d:00h\n",dLocLaFerrariAperta.tm_mday,dLocLaFerrariAperta.tm_mon+1,dLocLaFerrariAperta.tm_year+1900, dDevLaFerrariAperta.tm_mday,dDevLaFerrariAperta.tm_mon+1,dDevLaFerrariAperta.tm_year+1900, HORA_LOCACAO);}
         if (BugattiChiron == 0){printf ("\t Bugatti Chiron   \t  %d/%d/%d\t%d/%d/%d às %d:00h\n",dLocBugattiChiron.tm_mday,dLocBugattiChiron.tm_mon+1,dLocBugattiChiron.tm_year+1900, dDevBugattiChiron.tm_mday,dDevBugattiChiron.tm_mon+1,dDevBugattiChiron.tm_year+1900, HORA_LOCACAO);}
         if (KoenigseggRegera == 0){printf ("\t Koenigsegg Regera  \t  %d/%d/%d\t%d/%d/%d às %d:00h\n",dLocKoenigseggRegera.tm_mday,dLocKoenigseggRegera.tm_mon+1,dLocKoenigseggRegera.tm_year+1900, dDevKoenigseggRegera.tm_mday,dDevKoenigseggRegera.tm_mon+1,dDevKoenigseggRegera.tm_year+1900, HORA_LOCACAO);}
         if (ArashAF10Hybrid == 0){printf ("\t Arash AF10 Hybrid    \t  %d/%d/%d\t%d/%d/%d às %d:00h\n",dLocArashAF10Hybrid.tm_mday,dLocArashAF10Hybrid.tm_mon+1,dLocArashAF10Hybrid.tm_year+1900, dDevAstonMartinMARB00.tm_mday,dDevArashAF10Hybrid.tm_mon+1,dDevArashAF10Hybrid.tm_year+1900, HORA_LOCACAO);}
         printf ("\n\n");

}
int printMenuPrincipal() //imprime o menu principal
{
         logoLegalRentACar();

         printf ("\t (1) Consultar Veículos Disponíveis\n");
         printf ("\t (2) Alugar Veículo\n");
         printf ("\t (3) Devolver Veículo\n");
         printf ("\t (0) Sair\n\n");
         
         int x;
         scanf("%i", &x);
         if(x<0 ||x>3)
            {
                system ("cls");
                printf ("\n\nValor inválido. Por gentileza, digite um valor válido:\n\n");
                printMenuPrincipal();
            }
         return x;
}
int printMenuLocacao() //imprime as opções de veículos
{
         logoLegalRentACar();
         
         printf ("\t Selecione o veículo:  \n\n");
         printf ("\t (1) Aston Martin MA-RB00  \n");
         printf ("\t (2) La Ferrari Aperta    \n");
         printf ("\t (3) Bugatti Chiron    \n");
         printf ("\t (4) Koenigsegg Regera  \n");
         printf ("\t (5) Arash AF10 Hybrid    \n");
         printf ("\t (0) Sair    \n");
         
         int x;
         scanf("%i", &x);
         if(x<0 ||x>5)
            {
                system ("cls");
                printf ("\tValor inválido. Por gentileza, digite um valor válido:\n\n");
                printMenuLocacao();
            }
         return x;
}

void printTicket(float valor, struct tm *dataLocacao, struct tm *dataDevolucao, int hora){
    
    printf("\t\n\nFUNÇÃO +++ TICKET +++  SENDO IMPLEMENTADA.");
    
    /*
    printf("\tValor Final: R$%.2f\n",valor)
    printf("\tData/Hora de Locação: i%/i%/i% / às i%:00hs\n",dataLocacao.dia,dataLocacao.mes,dataLocacao.ano,hora);     
    printf("\tData/Hora de Devolução: i%/i%/i% / às i%:00hs\n",dataDevolucao.dia,dataDevolucao.mes,dataDevolucao.ano,hora);     
 
     
     */
    
}

void locacaoAstonMartinMARB00()
{
float valorLocacao, x;
 
                   logoLegalRentACar();

                   printf ("\t Modelo Escolhido: Aston Martin MA-RB00.        \n");
                   printf ("\t Valor da diaria: R$ 28.800,00                  \n");//1.200,00 hr
                   printf ("\t Digite a quantidade de dias de locação:\n");
                   scanf ("%f",&x);
                   valorLocacao = 28800 * x;
                   //valorLocacao = verificarDesconto(valorLocacao);
                   
                   resolverDatas(&dLocAstonMartinMARB00, &dDevAstonMartinMARB00, x);
                   
                   printf ("\t Valor da locação : R$%.2f \n",valorLocacao );
                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                  // printf ("\t (1) SIM \n");
                  // printf ("\t (2) NAO \n");
                   scanf ("%f",&x);
                   
                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        AstonMartinMARB00=0;
                        printf ("\t Locação confirmada. Obrigado. \n\n");
                        printf ("\t Modelo Escolhido: Aston Martin MA-RB00.        \n");
                                          
                       // printTicket(valorLocacao, dLocAstonMartinMARB00, dDevAstonMartinMARB00, hLocAstonMartinMARB00, hDevAstonMartinMARB00);

                   }
                   else if (x == 2)
                   {
                        printf ("\t Locação Cancelada!\n\n");
                   }

}

void devolucaoAstonMartinMARB00()
{
float valorLocacao, x;
                   
                   logoLegalRentACar();
                   
                   printf ("\t Modelo Devolvido: Aston Martin MA-RB00.        \n");
                // printf ("\t Valor da diaria: R$ 100,00                    \n");
 //                  printf ("\t Quantos dias voce pretende ficar com o carro ? \n");
 //                  scanf ("%f",&x);
 //                  valorLocacao = 100 * x;
 //                  printf ("\t Valor da locação : R$%.00f \n",valorLocacao );
                   printf ("\t Para confirma digite 1 Cancelar 2: \n");

                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        AstonMartinMARB00=1;
                        printf ("\t Devolução Confirmada. Obrigado. \n\n");
                   }
                   else if (x == 2)
                   {
                        printf ("\t Devolução Cancelada!\n\n");
                   }

 }

void locacaoLaFerrariAperta()
{
float valorLocacao, x;
                   
                   logoLegalRentACar();
                   
                   printf ("\t Modelo Escolhido: La Ferrari Aperta.   \n");
                   printf ("\t Valor da diaria: R$ 21.600,00          \n");//900,00 hr
                   printf ("\t Digite a quantidade de dias de locação:\n");
                   scanf ("%f",&x);
                   valorLocacao = 21600 * x;
                   
                   resolverDatas(&dLocLaFerrariAperta, &dDevLaFerrariAperta, x);
                   
                   printf ("\t Valor da locação : R$%.2f \n",valorLocacao );
                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                  
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        LaFerrariAperta=0;
                        printf ("\t Locação confirmada. Obrigado. \n\n");
                      
                   }
                   else if (x == 2)
                   {
                        printf ("\t Locação Cancelada!\n\n");
                   }

}

void devolucaoLaFerrariAperta()
{
float valorLocacao, x;
                   
                   logoLegalRentACar();
                   
                   printf ("\t Modelo Devolvido: La Ferrari Aperta.          \n");
//                   printf ("\t Quantos dias voce pretende ficar com o carro ? \n");
//                   scanf ("%f",&x);
//                   valorLocacao = 120 * x;
//                   printf ("\t Valor da locação : R$%.00f \n",valorLocacao );
                   printf ("\t Para confirma digite 1 Cancelar 2: \n");

                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        LaFerrariAperta=1;
                        printf ("\t Devolução confirmada. Obrigado. \n\n");
 
                   }
                   else if (x == 2)
                   {
                        printf ("\t Devolução Cancelada!\n\n");

                   }

 }


void locacaoBugattiChiron()
{
float valorLocacao, x;
                   
                   logoLegalRentACar();
                   
                   printf ("\t Modelo Escolhido: Bugatti Chiron.\n");
                   printf ("\t Valor da diaria: R$ 24.000,00    \n"); //1.000,00 hr
                   printf ("\t Digite a quantidade de dias de locação:\n");
                   scanf ("%f", &x);
                   valorLocacao = 24000 * x;
                   
                   resolverDatas(&dLocBugattiChiron, &dDevBugattiChiron, x);
                   
                   printf ("\t Valor da locação : R$%.2f \n",valorLocacao );
                   printf ("\t Para confirmar digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);
                   
                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        BugattiChiron=0;
                        printf ("\t Locação confirmada. Obrigado. \n");
                        //printf ("\t Volte Sempre. \n");

                   }
                   else if (x == 2)
                   {
                        printf ("\t Locação Cancelada!\n");
                        
                   }

 }

void devolucaoBugattiChiron()
{
float valorLocacao, x;
                   
                   logoLegalRentACar();
                   
                   printf ("\t Modelo Devolvido: Bugatti Chiron.\n");

                   printf ("\t Para confirmar digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        BugattiChiron=0;
                        printf ("\t Locação confirmada. Obrigado. \n");
             
                   }
                   else if (x == 2)
                   {
                        printf ("\t Locação Cancelada!\n");
                    
                   }
 
 }



void locacaoKoenigseggRegera()
{
float valorLocacao, x;
                   
                   logoLegalRentACar();
                   
                   printf ("\t Modelo Escolhido: Koenigsegg Regera.        \n");
                   printf ("\t Valor da diaria: R$ 21.600,00               \n");// 900,00 hr
                   printf ("\t Digite a quantidade de dias de locação:     \n");
                   scanf ("%f",&x);
                   
                   resolverDatas(&dLocKoenigseggRegera, &dDevKoenigseggRegera, x);
                   
                   valorLocacao = 21600 * x;
                   printf ("\t Valor da locação : R$%.2f \n",valorLocacao );
                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);
                   
                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        KoenigseggRegera=0;
                        printf ("\t Locação confirmada. Obrigado. \n\n");

                   }
                   else if (x == 2)
                   {
                        printf ("\t Locação Cancelada!\n\n");
                   }

 }


void devolucaoKoenigseggRegera()
{
float valorLocacao, x;
                   
                   logoLegalRentACar();
                   
                   printf ("\t Modelo Devolvido: Koenigsegg Regera.        \n");
                  
                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        KoenigseggRegera=1;
                        printf ("\t Devolução confirmada. Obrigado. \n\n");

                   }
                   else if (x == 2)
                   {
                        printf ("\t Devolução Cancelada!\n\n");
                   }

 }


void locacaoArashAF10Hybrid()
{
float valorLocacao, x;
                   
                   logoLegalRentACar();
                   
                   printf ("\t Modelo Escolhido: ArashAF10Hybrid.         \n");
                   
                   printf ("\t Valor da diaria: R$ 21.600,00              \n");// 900,00 hr
                   printf ("\t Digite a quantidade de dias de locação:\n");
                   scanf ("%f",&x);
                   
                   resolverDatas(&dLocArashAF10Hybrid, &dDevArashAF10Hybrid, x);
                   
                   valorLocacao = 21600 * x;
                   printf ("\t Valor da locação : R$%.2f \n",valorLocacao );
                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);
                   
                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        ArashAF10Hybrid=0;
                        printf ("\t Locação confirmada. Obrigado.\n\n");

                   }
                   else if (x == 2)
                   {
                        printf ("\t Locação Cancelada!\n\n");
                   }

}

void devolucaoArashAF10Hybrid()
{
float valorLocacao, x;
                   
                   logoLegalRentACar();
                   
                   printf ("\t Modelo Devolvido: ArashAF10Hybrid         \n");
                                  
                   printf ("\t Para confirma digite 1 Cancelar 2: \n");
                   scanf ("%f",&x);

                   x = verificaEntradaUmOuDois((int)x);

                   if(x == 1)
                   {
                        ArashAF10Hybrid=1;
                        printf ("\t Devolução confirmada. Obrigado.\n\n");

                   }
                   else if (x == 2)
                   {
                        printf ("\t Devolução Cancelada!\n\n");
                   }

}

void alugarVeiculo(int menuItem)
{

    switch(menuItem)
    {
        case 1:
            locacaoAstonMartinMARB00();
            break;
        case 2:
            locacaoLaFerrariAperta();
            break;
        case 3:
            locacaoBugattiChiron();
            break;
        case 4:
            locacaoKoenigseggRegera();
            break;
        case 5:
            locacaoArashAF10Hybrid();
            break;
    }
}

void devolverVeiculo(int menuItem)
{

    switch(menuItem)
    {
        case 1:
            devolucaoAstonMartinMARB00();
            break;
        case 2:
            devolucaoLaFerrariAperta();
            break;
        case 3:
            devolucaoBugattiChiron();
            break;
        case 4:
            devolucaoKoenigseggRegera();
            break;
        case 5:
            devolucaoArashAF10Hybrid();
            break;
    }
    
}

void escolhaMenuPrincipal(int escolha)
{
   switch(escolha)
   {
       case 1:
           printCatalogo();
           break;
       case 2:
           alugarVeiculo(printMenuLocacao());                
           //alugarVeiculo();                
           break;           
       case 3:
           devolverVeiculo(printMenuLocacao());
           //devolverVeiculo();
           break;
       case 0:
           //sair             
           break;
   }  
}

int verificaEntradaUmOuDois(int valor)
{
    if (valor<1)
        {
            printf("\tPor gentileza, digite 1 ou 2.\n");
            scanf("%i", &valor);
            verificaEntradaUmOuDois(valor);//scanf("%i", &valor);

        }else if(valor>2)
        {
            printf("\tPor gentileza, digite 1 ou 2.\n");
            scanf("%i", &valor);
            verificaEntradaUmOuDois(valor);//scanf("%i", &valor);
                       
        }else
            
    return valor;
}

int verificarSair(int x ){
    
    if (x == 1)
        {
            return x;
        }else
        {
            system ("cls");
            printf ("\t=============================================================\n");
            printf ("\t=====================PROGRAMA FINALIZADO=====================\n");
            printf ("\t=============================================================\n\n");
            return 0;
    }
       
}

float verificarDesconto(float valor)
{    
    int x;
    printf("\tAPLICAR DESCONTO.\n");
    printf("\t(1)Idoso.\n");
    printf("\t(2)Empresa parceira.\n");
    printf("\t(0)Sem desconto.\n");

    scanf("%i", &x);
    
    while (x<0 || x>2)
        {
            printf("\tPor gentileza, digite 1, 2 ou 0.\n");
            scanf("%i", &x);
            //verificarDesconto(valor);//scanf("%i", &valor);
        }
        if (x == 1)
        {
            printf("\tValor com 10%% de Desconto: R$%.2f\n", valor*0.9);
            return valor*0.9;

        }else if (x == 2)
        {
            printf("\tValor com 5%% de Desconto: R$%.2f\n", valor*0.95);
            return valor*0.95;
        }else if (x == 0)
        {
            return valor*1.0;
        }
    //return valor;
}

//+++++++++++++++++++++++++++++++++++


void main ()
{
do{
        int menuItem;
        
        //printCatalogo(); teste printCatalogo();
/* código para teste da funçao verificaDesconto();   
 * COM ESSE COMENTÁRIO A FUNÇÃO ESTÁ SENDO 
 * TESTADA EM locacaoAston Martin MA-RB00();     
        float test;
        printf("digite um valor:");
        scanf("%f", &test);
        printf(verificarDesconto(test));
 */   
        menuItem = printMenuPrincipal();
         
        escolhaMenuPrincipal(menuItem);
        
        //scanf ("%i",&menuItem);
        /* void escolhaMenuPrincipal(int escolha)
         {
            switch(escolha)
            {
                case 1:
                    printCatalogo();
                    break;
                case 2:
                    printMenuLocacao();                
                    alugarVeiculo();                
                    break;           
                case 3:
                    //devolver veiculo
                    break;
                case 0:
                    //sair             
                    break;
            }  
         }
        */

        //printMenuLocacao();
        
        
        printf("\tMenu principal-DIGITE 1 - Sair do programa - DIGITE OUTRO NÚMERO.\n");
        scanf("%i", &sair);

        sair = verificarSair(sair);

        /*
        void verificaEntradaUmOuDois(int valor)
        {
            int a=0;
            do
            {
                if (valor == 1)
                    {
                        a = 1;
                    }
                if(valor == 2)
                    {
                        a = 1;
                    }
                if(a==0)
                    {
                        printf("Por gentileza, digite 1 ou 2.\n");
                        scanf("%i", &valor);
                    }
            }while(a==0);
        }
        */

    }
    while(sair == 1);
      system (" pause ");
}


