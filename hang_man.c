#include <stdio.h>
#include <string.h>

void forcaDesenho(int estado) 
{
    if (estado==0) {
        printf("\n-------------");
        printf("\n|            |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    }
    else if (estado==1) {
        printf("\n-------------");
        printf("\n|            |");
        printf("\n|            0");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    }
    else if (estado==2) {
        printf("\n-------------");
        printf("\n|            |");
        printf("\n|            0");
        printf("\n|            |");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    }
    else if (estado==3) {
        printf("\n-------------");
        printf("\n|            |");
        printf("\n|            0");
        printf("\n|           -|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    }
    else if (estado==4) {
        printf("\n-------------");
        printf("\n|            |");
        printf("\n|            0");
        printf("\n|           -|-");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    }
    else if (estado==5) {
        printf("\n-------------");
        printf("\n|            |");
        printf("\n|            0");
        printf("\n|           -|-");
        printf("\n|           /");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    }
    else if (estado==6) {
        printf("\n-------------");
        printf("\n|            |");
        printf("\n|            0");
        printf("\n|           -|-");
        printf("\n|           / \\");
        printf("\n|");
        printf("\n|");
        printf("\n-");
    }


}

int main(){
    //Pegando a palavra que vai rodar o jogo
    char palavra[100];
    printf("Digite uma palavra: \n");
    gets(palavra);

    //Criando uma máscara que vai cobrir as letras não advinhadas
    //Para a máscara funcionar vamos utilizar uma lógica "booleana" que diz: 
    //A máscara só vai ser criada quando o jogador inserir uma palavra. 
    //Portanto a lógica é que =0 ela não esta ativa =1 ela esta ativa

    int num = strlen(palavra);
    int mascara[num];
    for(int i = 0; i < num; i++){
        mascara[i]=0;
    }

    //criando contador da forca
    int forca=0, cont;
    int estadoForca=0;

    //Inicio do loop que vai rodar o jogo
    int jogo = 0;
    while(! jogo){
        int estado=0;
        cont=0;
        //Fazer com que no lugar das letras que não foram advinhadas insira-se um #
        printf("A palavra eh: ");
        for(int j=0; j<num; j++){
            if(mascara[j]){
                printf("%c", palavra[j]);
            }else {
                printf("*");
            }
        }
        printf("\n");

        //Tentativas
        char letras;
        printf("Digite uma letra: ");
        scanf(" %c", &letras);


        //VERIFICANDO TODAS AS POSIÇÕES NA MÁSCARA QUE CORRESPONDEM COM A TENTATIVA
        for(int k=0; k<num; k++){
            if(letras == palavra[k]){
                mascara[k]=1;
                cont++;
            }if(letras != palavra[k]){
                    forca++;
            }  
        }
        if(estado == cont){
            estadoForca++;
        }
        forcaDesenho(estadoForca);
        forcaDesenho;
        
        //printf("%d", forca);

        //criando as condiçoes para o jogo encerrar
        //jogo = 1 finaliza ganhador
        //forca = 6 finaliza perdedor
        jogo = 1;
        for(int l=0; l<num; l++){
            if(!mascara[l]){
                jogo = 0;
                break;
            }
        }
        if (forca >= 6*num){
                break;
            }
    }
    if(forca >= 6*num){
        printf("Enforcado.... a palavra era: %s", palavra);
    }else{
        printf("Parabens!! Voce escapou da forca... a palara era: %s", palavra);
    }

    return 0;
}
