/*
================================================
Made by Felipe Spolidoro and Vinícius Windmöller
================================================
*/
//Includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

//Funções
void resultado(int pts_jg){ // win/lose animation
char msg[15] = "VitoriaDerrota";
int i;
    if(pts_jg==14){
    printf("\n\n         ");
    for(i=0;i<7;i++){
     printf("%c",msg[i]);
     Sleep(300);
    }
}else{
    printf("\n\n         ");
    for(i=7;i<14;i++){
     printf("%c",msg[i]);
     Sleep(300);
}}
printf("\n\n");
}
void print_op(int tab[]){ // print opponent hidden board
int i,j;
i=1,j=1;
printf("-=Tabuleiro do adversario=-\n");

printf("\n    A B C D E F G H I J\n  ");
        while(j<=10){
            printf("%d ",j-1);
        do{
            printf("%c ",tab[i-1]);
            i++;
        }while(i%10!=0);
        printf("%c\n  ",tab[i-1]);
        i++;
        j++;
    }
}
void print_jg(int tab[]){ // print player's board
int i,j;
i=1,j=1;
printf("\n-=-=-= Seu tabuleiro =-=-=-\n");

printf("\n    A B C D E F G H I J\n  ");
        while(j<=10){
            printf("%d ",j-1);
        do{
            printf("%c ",tab[i-1]);
            i++;
        }while(i%10!=0);
        printf("%c\n  ",tab[i-1]);
        i++;
        j++;
    }
}
void fz_jgd_jg(int tab[],int tab2[],int *pts){ // player move
    char c;
    int c_int,l_int,pos,jogada;
    do{
        jogada = 0;
    printf("\nFaca a sua jogada, lembre-se de nao repetir as suas jogadas!\n");
    do{
        printf("Digite a coluna, use valores entre 'A' e 'J'\n");
        fflush(stdin);
        scanf("%c",&c);
        c_int = toupper(c)-65;
    }while(c_int<0 || c_int>9);
    do{
        printf("Digite a linha, use valores entre '0' e '9'\n");
        scanf("%d",&l_int);
        ;
    }while(l_int<0 || l_int>9);

    pos = c_int + l_int*10;
    if(tab[pos]==1 && tab2[pos]==207){
        tab2[pos] = 254;
        jogada++;
        *pts = *pts + 1;
    }else if(tab2[pos]==207){
        tab2[pos] = 126;
        jogada++;
    }}while(jogada==0);
}
void fz_jgd_op(int tab[],int *pts,int *acts,int *acertos,int *posi){ // opponent move, with assistance from a basic Artificial Intelligence 
int pos, dir, soma = 0;
srand((unsigned)(time(NULL)));
if(*acts==1){ // Tests whether adjacent positions are valid moves
    if(*posi % 10 != 0 && tab[*posi-1] != 155 && tab[*posi-1] != 158){
        soma = soma + 1;}
    if(*posi % 10 != 9 && tab[*posi+1] != 155 && tab[*posi+1] != 158){
        soma = soma + 2;}
    if(*posi > 9 && tab[*posi-10] != 155 && tab[*posi-10] != 158){
        soma = soma + 4;}
    if(*posi < 90 && tab[*posi+10] != 155 && tab[*posi+10] != 158){
        soma = soma + 8;}
switch(soma){ // uses the sum to analyze the possible moves to be made using integer values to indicate directions   0 >> Left, 1 >> Up, 2 >> Right, 3 >> Down
case 0:
    *acertos = 0;
    break;
case 1:
    if(tab[*posi-1]==126){
        tab[*posi-1]=155;
    }else{
        tab[*posi-1]=158;
        *pts = *pts + 1;
        *acts = 0;}
    break;
case 2:
    if(tab[*posi+1]==126){
        tab[*posi+1]=155;
    }else{
        tab[*posi+1]=158;
        *pts = *pts + 1;
        *acts = 0;}
    break;
case 3:
    do{
        dir = rand()%3;
    }while(dir==1);
    if(dir == 0){
        if(tab[*posi-1]==126){
            tab[*posi-1]=155;
        }else{
            tab[*posi-1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi+1]==126){
            tab[*posi+1]=155;
        }else{
            tab[*posi+1]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 4:
    if(tab[*posi-10]==126){
        tab[*posi-10]=155;
    }else{
        tab[*posi-10]=158;
        *pts = *pts + 1;
        *acts = 0;}
    break;
case 5:
    dir = rand()%2;
    if(dir == 0){
        if(tab[*posi-1]==126){
            tab[*posi-1]=155;
        }else{
            tab[*posi-1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi-10]==126){
            tab[*posi-10]=155;
        }else{
            tab[*posi-10]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 6:
    dir = 1 + rand()%2;
    if(dir == 2){
        if(tab[*posi+1]==126){
            tab[*posi+1]=155;
        }else{
            tab[*posi+1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi-10]==126){
            tab[*posi-10]=155;
        }else{
            tab[*posi-10]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 7:
    dir = rand()%3;
    if(dir == 0){
        if(tab[*posi-1]==126){
            tab[*posi-1]=155;
        }else{
            tab[*posi-1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else if(dir == 1){
        if(tab[*posi-10]==126){
            tab[*posi-10]=155;
        }else{
            tab[*posi-10]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi+1]==126){
            tab[*posi+1]=155;
        }else{
            tab[*posi+1]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 8:
    if(tab[*posi+10]==126){
        tab[*posi+10]=155;;
    }else{
        tab[*posi+10]=158;
        *pts = *pts + 1;
        *acts = 0;}
    break;
case 9:
    do{
        dir = rand()%4;
    }while(dir != 0 || dir != 3);
    if(dir == 0){
        if(tab[*posi-1]==126){
            tab[*posi-1]=155;
        }else{
            tab[*posi-1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi+10]==126){
            tab[*posi+10]=155;
        }else{
            tab[*posi+10]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 10:
    dir = 2 + rand()%2;
    if(dir == 2){
        if(tab[*posi+1]==126){
            tab[*posi+1]=155;
        }else{
            tab[*posi+1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi+10]==126){
            tab[*posi+10]=155;
        }else{
            tab[*posi+10]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 11:
    do{
        dir = rand()%4;
    }while(dir == 1);
    if(dir == 0){
        if(tab[*posi-1]==126){
            tab[*posi-1]=155;
        }else{
            tab[*posi-1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else if(dir == 2){
        if(tab[*posi+1]==126){
            tab[*posi+1]=155;
        }else{
            tab[*posi+1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi+10]==126){
            tab[*posi+10]=155;
        }else{
            tab[*posi+10]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 12:
    do{
        dir = 1 + rand()%3;
    }while(dir == 2);
    if(dir == 1){
        if(tab[*posi-10]==126){
            tab[*posi-10]=155;
        }else{
            tab[*posi-10]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi+10]==126){
            tab[*posi+10]=155;
        }else{
            tab[*posi+10]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 13:
    do{
        dir = rand()%4;
    }while(dir == 2);
    if(dir == 0){
        if(tab[*posi-1]==126){
            tab[*posi-1]=155;
        }else{
            tab[*posi-1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else if(dir == 1){
        if(tab[*posi-10]==126){
            tab[*posi-10]=155;
        }else{
            tab[*posi-10]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi+10]==126){
            tab[*posi+10]=155;
        }else{
            tab[*posi+10]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 14:
        dir = 1 + rand()%3;
    if(dir == 2){
        if(tab[*posi+1]==126){
            tab[*posi+1]=155;
        }else{
            tab[*posi+1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else if(dir == 1){
        if(tab[*posi-10]==126){
            tab[*posi-10]=155;
        }else{
            tab[*posi-10]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi+10]==126){
            tab[*posi+10]=155;
        }else{
            tab[*posi+10]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
case 15:

    dir = rand()%4;
    if(dir == 0){
        if(tab[*posi-1]==126){
            tab[*posi-1]=155;
        }else{
            tab[*posi-1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else if(dir == 1){
        if(tab[*posi-10]==126){
            tab[*posi-10]=155;
        }else{
            tab[*posi-10]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else if(dir == 2){
        if(tab[*posi+1]==126){
            tab[*posi+1]=155;
        }else{
            tab[*posi+1]=158;
            *pts = *pts + 1;
            *acts = 0;}
    }else{
        if(tab[*posi+10]==126){
            tab[*posi+10]=155;
        }else{
            tab[*posi+10]=158;
            *pts = *pts + 1;
            *acts = 0;}}
    break;
}
}
    while(*acertos==0){ //randomize a move until hit a ship
    pos = rand()%100;
    if(tab[pos]==155||tab[pos]==158){
    }else{
        if(tab[pos]==126){
            tab[pos]=155;
            break;
        }else{
            tab[pos]=158;
            *pts = *pts + 1;
            *posi = pos;
            *acts = 1;
            break;
        }}}
*acertos = *acts;
}
void esperar(int tab_op2[],int pts_jg){ // do a cool animation
int i;
    for(i=0;i<3;i++){
        print_op(tab_op2);
        printf("\t\t\tAcertos:%d\n",pts_jg);
        printf("O computador esta jogando...\n");
        Sleep(200);
        system("cls");
        print_op(tab_op2);
        printf("\t\t\tAcertos:%d\n",pts_jg);
        printf("O computador esta jogando%c..\n",250);
        Sleep(125);
        system("cls");
        print_op(tab_op2);
        printf("\t\t\tAcertos:%d\n",pts_jg);
        printf("O computador esta jogando.%c.\n",250);
        Sleep(125);
        system("cls");
        print_op(tab_op2);
        printf("\t\t\tAcertos:%d\n",pts_jg);
        printf("O computador esta jogando..%c\n",250);
        Sleep(125);
        system("cls");
}}
//Main
int main(){
FILE *op, *jg;
int i = 0;
int tab_op[101], tab_jg[101], tab_op2[101];
int pts_jg = 0, pts_op = 0, acts = 0, posi = 0,acertos = 0;
char c;

op = fopen("oponente.cfg", "r");
if (op == NULL){  // check if there was an opening error in opponent file
        printf("Problemas na abertura do arquivo oponente.cfg \n");
        return -1;}
jg = fopen("jogador.cfg", "r");
if (jg == NULL){  // check if there was an opening error in player file
        printf("Problemas na abertura do arquivo jogador.cfg \n");
        return -1;}
    while(!feof(op)){ // read and index the positions of opponent ships within a vector
        while((c=fgetc(op))!=EOF){
            if(c=='A'){
                tab_op[i]= 0;
                    i++;
            }else if(c=='N'){
                tab_op[i] = 1;
                    i++;
    }}}
i = 0;
    while(!feof(jg)){ // read and index the positions of player ships within a vector
        while((c=fgetc(jg))!=EOF){
            if(c=='A'){
                tab_jg[i]= 126;
                i++;
            }else if(c=='N'){
                tab_jg[i] = 254;
                i++;
    }}}
for(i=0;i<100;i++){
    tab_op2[i]= 207;}
//Front End
printf("Pressione a tecla enter para iniciar...");
scanf("%c",&c);
system("cls"); // Limpa a tela
print_op(tab_op2);
print_jg(tab_jg);
while(pts_jg!=14 && pts_op!=14){ // Repeat the moves until someone hits all the ships
    fz_jgd_jg(tab_op,tab_op2,&pts_jg);
    system("cls");
    if(pts_jg==14) break;
    esperar(tab_op2,pts_jg);
    fz_jgd_op(tab_jg, &pts_op, &acts, &acertos, &posi);
    system("cls");
    print_op(tab_op2);
    printf("\t\t\tAcertos:%d\n",pts_jg);
    print_jg(tab_jg);
    printf("\t\t\tAcertos:%d\n",pts_op);
    }
resultado(pts_jg); // Calls the final result
return 0;
}
