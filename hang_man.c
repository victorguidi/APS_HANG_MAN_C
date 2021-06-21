//REGRAS DO JOGO: Não pode ser palavra composta!
// O jogo é Case Sensitive! Atente-se.
//O jogo não aceita palavras com acento.

#include <stdio.h>
#include <string.h>

//Função que cria o desenho do boneco da forca.
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

//Função principal do jogo

int main(){
    //Pegando a palavra que vai iniciar o jogo
    char palavra[100];
    printf("Digite uma palavra: \n");
    gets(palavra);

    //Cria-se uma máscara que vai cobrir as letras da palavra digitada
    //Para a máscara funcionar vamos utilizar uma lógica que diz: 
    //A máscara só vai ser criada quando o jogador inserir uma palavra. 
    //Portanto em que mascara=0 ela não esta ativa mascara=1 ela esta ativa

    int num = strlen(palavra);
    printf("A palavra tem %d letras\n", num);
    int mascara[num];
    for(int i = 0; i < num; i++){
        mascara[i]=0;
    }

    //criando contadores para a forca
    int cont;
    int estadoForca=0;

    //Inicio do loop que vai rodar o jogo
    int jogo = 0;
    while(! jogo){
        int estado=0;
        cont=0;

        //Ativando a máscara e colocando no lugar das letras que não foram advinhadas um: _
        printf("A palavra eh: ");
        for(int j=0; j<num; j++){
            if(mascara[j]){
                printf("%c", palavra[j]);
            }else {
                printf("_ ");
            }
        }
        printf("\n");

        //Tentativas
        char letras;
        printf("\n");
        printf("Digite uma letra: ");
        scanf(" %c", &letras);


        //VERIFICANDO TODAS AS POSIÇÕES NA PALAVRA QUE CORRESPONDEM COM A TENTATIVA
        for(int k=0; k<num; k++){
            if(letras == palavra[k]){
                mascara[k]=1;
                cont++;
            }
        }
        if(estado == cont){
            estadoForca++;
        }
        //Chamando a função do desenho
        forcaDesenho(estadoForca);
        forcaDesenho;
        printf("\n");
        
        //criando as condiçoes para o jogo encerrar
        //jogo = 1 finaliza ganhador
        //estadoForca = 6 finaliza perdedor
        jogo = 1;
        for(int l=0; l<num; l++){
            if(!mascara[l]){
                jogo = 0;
                break;
            }
        }
        if (estadoForca == 6){
                break;
            }
    }
    if(estadoForca == 6){
        printf("Enforcado.... a palavra era: %s\n", palavra);
    }else{
        printf("Parabens!! Voce escapou da forca... a palara era: %s\n", palavra);
    }
    //replay();

    return 0;
}


/* void replay(){
    printf("Jogar novamente? (s/n) \n");
    char resposta;
    scanf(" %c", &resposta);
    if(resposta == 's'){
        main();
    }else{
        return 0;
    }
} */
