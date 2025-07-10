
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<conio.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
typedef struct HOMBRE{
    int x;
    int y;
    int vidas;
}HOMBRE;
typedef struct enemigo{
    int x;
    int y;
}ENEMIGO;
typedef struct bala{
    int x;
    int y;
}BALA;
typedef struct enemigo2{
    int x;
    int y;
}ENEMIGO2;
void combo();
void borrarEnemigo(ENEMIGO);
void continuar();
int inicio();
void ganar(int,int [],int,HOMBRE);
void OcultarCursor();
void gotoxy(int, int);
int mover(HOMBRE,ENEMIGO,BALA,bool,int,ENEMIGO2,int,int[]);
void borrar(HOMBRE);
void pintar(HOMBRE);
void limites();
void corazones(HOMBRE,bool);
void morir(HOMBRE,bool,int);
void pintarEnemigo(ENEMIGO);
void pintarEnemigo2(ENEMIGO2);
void puntuacion(int [],int);
void bala(BALA,HOMBRE);

int  main(){
    int a=9,b=0,c=0,f[10];
    f[0]=0;
    BALA bal;
    ENEMIGO2 enem2;
    enem2.x=20;
    enem2.y=33;
    ENEMIGO enem;
    enem.x=3;
    enem.y=32;
    HOMBRE hom;
    bool gameover=false;
     hom.x=15;
     hom.y=4;
     hom.vidas=10;
     do{
     OcultarCursor();
     b=inicio();
     gotoxy(20,2);printf("VIDAS %d",a);
     gotoxy(3,2);printf("POLI-CAIDALIBRE");
    limites();
    OcultarCursor();
    }while((mover(hom,enem,bal,gameover,a,enem2,b,f))==1);
    exit;
return 0;
}
int mover(HOMBRE hom,ENEMIGO enem,BALA bal,bool gameover,int a,ENEMIGO2 enem2,int b,int f[]){
    int d=0,k=0;
     OcultarCursor();
    pintar(hom);
    while(!gameover){
    if(kbhit()){
        char tecla = getch();
        if(tecla==100){/*inicio disparo*/
    bal.x=hom.x+6;
    bal.y=hom.y+9;
    while(bal.y<32){
     if(kbhit()){/*movimiento hombre*/
        char tecla2 = getch();
        borrar(hom);
        if(tecla2==LEFT && hom.x>3)hom.x--;
        if(tecla2==RIGHT && hom.x+6<77)hom.x++;
        if(tecla2==DOWN && hom.y+3<33)hom.y++;
        if(tecla2==UP && hom.y>4)hom.y--;
        pintar(hom);}/*fin movimiento hombre*/
    gotoxy(bal.x,bal.y);printf(" ");
    bal.y++;
     if(bal.x==enem2.x){
            if(bal.y==enem2.y-1){gotoxy(enem2.x,enem2.y);printf(" ");k++;if(k==8){a++;k=0;combo();gotoxy(26,2);printf("%d",a);}enem2.x=0;enem2.y=0;}}/*choque bala cn enem 2*/
    Sleep(b);
    gotoxy(bal.x,bal.y);printf("%c",178);/*termino disparo*/

    borrarEnemigo(enem);/*enemigo*/
    enem.y--;
    if(enem.y<=4){/*inicio enemigo que salga aletaroriamente*/
        enem.y= rand()%30 + 4;
        if((rand()%30)%2==0){
            enem.x=3;
        }else if((rand()%30)%21!=0){
            enem.x=28;
    }
     if(hom.x<=7 || hom.x+7>=28){/*inicio choque derecho e izq*/
             a--;
    if(a==-1){gameover=true;gotoxy(14,15);printf("%cGAMEOVER",184);Sleep(4000);exit;}
    gotoxy(25,2);printf(" %d",a);
            gotoxy(enem.x,enem.y);printf("     ");
            enem.x=0;enem.y=0;
            morir(hom,gameover,a);
        }/*termino choque en la derecha*/}pintarEnemigo(enem);/*termino enemigo que salga aleatoriamente*/
    gotoxy(enem2.x,enem2.y);printf(" ");/*enemigo DOS */
    enem2.y--;
      if(bal.x==enem2.x){
            if(bal.y==enem2.y-1){gotoxy(enem2.x,enem2.y);printf(" ");k++;if(k==8){a++;k=0;combo();gotoxy(26,2);printf("%d",a);}enem2.x=0;enem2.y=0;}}/*choque bala cn enem 2*/
    if(enem2.y<5){/*inicio enemigo que salga aletaroriamente*/
        f[0]++;
        if(f[0]==10){b=b-2;}else if(f[0]==40 && b<=10 && b>=7){ganar(a,f,b,hom);
        d=0;
     system("cls");
    f[0]=0;
    continuar();
    scanf("%d",&d);
    gotoxy(6,20);printf("                   ");
     if(d==1){system("cls");}
        return d;}
        gotoxy(8,1);printf("PUNTUACION: %d",f[0]*10);
        enem2.x= rand()%30+8;if(enem2.x>27){enem2.x=rand()%20+9;}
        enem2.y=33;
        }
         if(enem2.x<=hom.x+7 && enem2.x>=hom.x && enem2.y==hom.y+8 ){/*choque inicio izqquierdo*/
             a--;
    if(a==-1){gameover=true;gotoxy(14,15);printf("%cGAMEOVER",184);Sleep(5000);
    d=0;
    system("cls");
    puntuacion(f,b);
    f[0]=0;
    continuar();
    scanf("%d",&d);
    gotoxy(3,20);printf("                              ");
    if(d==1){system("cls");}
    return d;}
    gotoxy(25,2);printf(" %d",a);
            gotoxy(enem2.x,enem2.y);printf(" ");
            enem2.x=0;enem2.y=0;
            morir(hom,gameover,a);
        }/*termina choque*/
    pintarEnemigo2(enem2);/*termino enemigo DOS que salga aleatoriamente*/
        if(bal.x==enem2.x){
            if(bal.y==enem2.y-1){gotoxy(enem2.x,enem2.y);printf(" ");k++;if(k==8){a++;k=0;combo();gotoxy(26,2);printf("%d",a);}enem2.x=0;enem2.y=0;}}/*choque bala cn enem 2*/
        Sleep(b);
}gotoxy(bal.x,bal.y);printf(" ");/*termino explocion*/
        }/*if tecla ==100*/
         else if(tecla==97){/*inicio disparo*/
    bal.x=hom.x+1;
    bal.y=hom.y+9;
    while(bal.y<32){
     if(kbhit()){/*movimiento hombre*/
        char tecla2 = getch();
        borrar(hom);
        if(tecla2==LEFT && hom.x>3)hom.x--;
        if(tecla2==RIGHT && hom.x+6<77)hom.x++;
        if(tecla2==DOWN && hom.y+3<33)hom.y++;
        if(tecla2==UP && hom.y>4)hom.y--;
        pintar(hom);}/*fin movimiento hombre*/
    gotoxy(bal.x,bal.y);printf(" ");
    bal.y++;
   if(bal.x==enem2.x){
            if(bal.y==enem2.y-1){gotoxy(enem2.x,enem2.y);printf(" ");k++;if(k==8){a++;k=0;combo();gotoxy(26,2);printf("%d",a);}enem2.x=0;enem2.y=0;}}/*choque bala cn enem 2*/
    Sleep(b);
    gotoxy(bal.x,bal.y);printf("%c",178);/*termino disparo*/
    borrarEnemigo(enem);/*enemigo*/
    enem.y--;
    if(enem.y<=4){/*inicio enemigo que salga aletaroriamente*/
        enem.y= rand()%30 + 4;
        if((rand()%30)%2==0){
            enem.x=3;
        }else if((rand()%30)%21!=0){
            enem.x=28;
    }
     if(hom.x<=7 || hom.x+7>=28){/*inicio choque derecho e izq*/
             a--;
    if(a==-1){gameover=true;gotoxy(14,15);printf("%cGAMEOVER",184);Sleep(4000);exit;}
    gotoxy(25,2);printf(" %d",a);
            gotoxy(enem.x,enem.y);printf("     ");
            enem.x=0;enem.y=0;
            morir(hom,gameover,a);
        }/*termino choque en la derecha*/}pintarEnemigo(enem);/*termino enemigo que salga aleatoriamente*/
    gotoxy(enem2.x,enem2.y);printf(" ");/*enemigo DOS */
    enem2.y--;
      if(bal.x==enem2.x){
            if(bal.y==enem2.y-1){gotoxy(enem2.x,enem2.y);printf(" ");k++;if(k==8){a++;k=0;combo();gotoxy(26,2);printf("%d",a);}enem2.x=0;enem2.y=0;}}/*choque bala cn enem 2*/
    if(enem2.y<5){/*inicio enemigo que salga aletaroriamente*/
        f[0]++;
        if(f[0]==10){b=b-2;}else if(f[0]==40 && b<=10 && b>=7){ganar(a,f,b,hom);
        d=0;
     system("cls");
    f[0]=0;
    continuar();
    scanf("%d",&d);
    gotoxy(6,20);printf("                   ");
     if(d==1){system("cls");}
        return d;}
        gotoxy(8,1);printf("PUNTUACION: %d",f[0]*10);
        enem2.x= rand()%30+8;if(enem2.x>27){enem2.x=rand()%20+9;}
        enem2.y=33;
        }
         if(enem2.x<=hom.x+7 && enem2.x>=hom.x && enem2.y==hom.y+8 ){/*choque inicio izqquierdo*/
             a--;
    if(a==-1){gameover=true;gotoxy(14,15);printf("%cGAMEOVER",184);Sleep(5000);
    d=0;
    system("cls");
    puntuacion(f,b);
    f[0]=0;
    continuar();
    scanf("%d",&d);
    gotoxy(3,20);printf("                              ");
    if(d==1){system("cls");}
    return d;}
    gotoxy(25,2);printf(" %d",a);
            gotoxy(enem2.x,enem2.y);printf(" ");
            enem2.x=0;enem2.y=0;
            morir(hom,gameover,a);
        }/*termina choque*/
    pintarEnemigo2(enem2);/*termino enemigo DOS que salga aleatoriamente*/
         if(bal.x==enem2.x){
            if(bal.y==enem2.y-1){gotoxy(enem2.x,enem2.y);printf(" ");k++;if(k==8){a++;k=0;combo();gotoxy(26,2);printf("%d",a);}enem2.x=0;enem2.y=0;}}/*choque bala cn enem 2*/
        Sleep(b);
}gotoxy(bal.x,bal.y);printf(" ");/*termino explocion*/
        }/*if tecla ==97*/
        borrar(hom);
        if(tecla==LEFT && hom.x>3)hom.x--;
        if(tecla==RIGHT && hom.x+6<77)hom.x++;
        if(tecla==DOWN && hom.y+3<33)hom.y++;
        if(tecla==UP && hom.y>4)hom.y--;
        pintar(hom);
    }Sleep(b);/*fin de kbith*/


    /*mientras no presiono teclas q salgan los enemigos*/
   borrarEnemigo(enem);/*enemigo*/
    enem.y--;
    if(enem.y<=4){/*inicio enemigo que salga aletaroriamente*/
        enem.y= rand()%30 + 4;
        if((rand()%30)%2==0){
            enem.x=3;
        }else if((rand()%30)%21!=0){
            enem.x=28;
    }
     if(hom.x<=7 || hom.x+7>=28){/*inicio choque derecho*/
             a--;
    if(a==-1){gameover=true;gotoxy(14,15);printf("%cGAMEOVER",184);Sleep(4000);exit;}
    gotoxy(25,2);printf(" %d",a);
            gotoxy(enem.x,enem.y);printf("     ");
            enem.x=0;enem.y=0;
            morir(hom,gameover,a);
        }/*termino choque en la derecha*/}pintarEnemigo(enem);/*termino enemigo que salga aleatoriamente*/
       gotoxy(enem2.x,enem2.y);printf(" ");/*enemigo DOS */
    enem2.y--;
     if(bal.x==enem2.x){
            if(bal.y==enem2.y-1){gotoxy(enem2.x,enem2.y);printf(" ");k++;if(k==8){a++;k=0;combo();gotoxy(26,2);printf("%d",a);}enem2.x=0;enem2.y=0;}}/*choque bala cn enem 2*/
              Sleep(b);
    if(enem2.y<5){/*inicio enemigo que salga aletaroriamente*/
            f[0]++;
            if(f[0]==20){b=b-2;}else if(f[0]==70 && b<=10 &&b>=7){ganar(a,f,b,hom);
            d=0;
     system("cls");
    f[0]=0;
                                continuar();
    scanf("%d",&d);
    gotoxy(6,20);printf("                   ");
     if(d==1){system("cls");}
            return d;}
            else if(f[0]==100 && b<=20 &&b>=10){ganar(a,f,b,hom);
            d=0;
     system("cls");
    f[0]=0;
                                continuar();
    scanf("%d",&d);
    gotoxy(6,20);printf("                   ");
     if(d==1){system("cls");}
            return d;}
            else if(f[0]==55 && b<=7 &&b>=0){ganar(a,f,b,hom);
            d=0;
     system("cls");
    f[0]=0;
                                continuar();
    scanf("%d",&d);
    gotoxy(6,20);printf("                   ");
     if(d==1){system("cls");}
            return 1;}
            gotoxy(8,1);printf("PUNTUACION: %d",f[0]*10);
        enem2.x= rand()%30+8;if(enem2.x>27){enem2.x=rand()%20+8;}
        enem2.y=33;
        }
         if(enem2.x<=hom.x+7 && enem2.x>=hom.x && enem2.y==hom.y+8){/*choque inicio izqquierdo*/
             a--;
    if(a==-1){gameover=true;gotoxy(14,15);printf("%cGAMEOVER",184);Sleep(5000);
     d=0;
     system("cls");
    puntuacion(f,b);
    f[0]=0;
                                continuar();
    scanf("%d",&d);
    gotoxy(6,20);printf("                   ");
     if(d==1){system("cls");}
    return d;}
    gotoxy(25,2);printf(" %d",a);
            gotoxy(enem2.x,enem2.y);printf(" ");
            enem2.x=0;enem2.y=0;
            morir(hom,gameover,a);
        }/*termina choque*/
    pintarEnemigo2(enem2);/*termino enemigo DOS que salga aleatoriamente*/
    if(bal.x!=enem.x){
   }
     else{
        if(bal.y==enem.y-1){gotoxy(enem.x,enem.y);printf("     ");}
    }Sleep(b);
}
}
void gotoxy(int x, int y){
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon, dwPos);
}
void OcultarCursor(){
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=2;/*APARIECIA DEL CURSOR*/
    cci.bVisible=FALSE;
    SetConsoleCursorInfo(hCon,&cci);
}
void pintar(HOMBRE hom){
    gotoxy(hom.x,hom.y);  printf("   %c%c ",226,226);
    gotoxy(hom.x,hom.y+1);printf("  (**)  ");
    gotoxy(hom.x,hom.y+2);printf("  (**)  ");
    gotoxy(hom.x,hom.y+3);printf(" (****) ");
    gotoxy(hom.x,hom.y+4);printf(" (****) ");
    gotoxy(hom.x,hom.y+5);printf("  (**)  ");
    gotoxy(hom.x,hom.y+6);printf("  (**)  ");
    gotoxy(hom.x,hom.y+7);printf(" (*)(*) ");
    gotoxy(hom.x,hom.y+8);printf("(*)  (*)");
}
void pintarEnemigo(ENEMIGO enem){
    gotoxy(enem.x,enem.y);  printf("%c*%c*%c",126,126,126);
}
void borrarEnemigo(ENEMIGO enem){
    gotoxy(enem.x,enem.y);  printf("     ");
}
void pintarEnemigo2(ENEMIGO2 enem2){
    gotoxy(enem2.x,enem2.y);printf("%c",206);
}
void borrar(HOMBRE hom){
    gotoxy(hom.x,hom.y);  printf("        ");
    gotoxy(hom.x,hom.y+1);printf("        ");
    gotoxy(hom.x,hom.y+2);printf("        ");
    gotoxy(hom.x,hom.y+3);printf("        ");
    gotoxy(hom.x,hom.y+4);printf("        ");
    gotoxy(hom.x,hom.y+5);printf("        ");
    gotoxy(hom.x,hom.y+6);printf("        ");
    gotoxy(hom.x,hom.y+7);printf("        ");
    gotoxy(hom.x,hom.y+8);printf("        ");
}
void limites(){
    int i=0;
    for(i=2;i<33;i++){
        gotoxy(i,3);printf("%c",205);
    }i=0;
    for(i=4;i<=33;i++){
        gotoxy(2,i);printf("%c",186);
        gotoxy(33,i);printf("%c",186);
    }
    gotoxy(2,3);printf("%c",201);
    gotoxy(33,3);printf("%c",187);
}
void corazones(HOMBRE hom,bool gameover){
    hom.vidas--;
    if(hom.vidas==0){gameover=false;exit;}
    gotoxy(50,2);printf("        ");
    gotoxy(50,2);printf("VIDAS %d",hom.vidas);
}
void morir(HOMBRE hom,bool gameover,int a){
    gotoxy(hom.x,hom.y);  printf("*    ");
    gotoxy(hom.x,hom.y+1);printf(" *  *");
    gotoxy(hom.x,hom.y+2);printf("* * *");
    gotoxy(hom.x,hom.y+3);printf(" *   ");
    gotoxy(hom.x,hom.y+4);printf(" * * ");
    gotoxy(hom.x,hom.y+5);printf("*** *");
    gotoxy(hom.x,hom.y+6);printf("     ");
    gotoxy(hom.x,hom.y+7);printf("* * *");
    gotoxy(hom.x,hom.y+8);printf("*****");
    Sleep(10);
         borrar(hom);
    gotoxy(hom.x,hom.y);  printf("    *");
    gotoxy(hom.x,hom.y+1);printf("* * *");
    gotoxy(hom.x,hom.y+2);printf("*****");
    gotoxy(hom.x,hom.y+3);printf(" * * ");
    gotoxy(hom.x,hom.y+4);printf(" *   ");
    gotoxy(hom.x,hom.y+5);printf("    *");
    gotoxy(hom.x,hom.y+6);printf("     ");
    gotoxy(hom.x,hom.y+7);printf("* * *");
    gotoxy(hom.x,hom.y+8);printf("* ***");
    Sleep(20);
    borrar(hom);
    pintar(hom);
}
int inicio(){
    int *b,c=0;
    OcultarCursor();
    system("color A9");
    gotoxy(10,1);printf("%c POLI-CAIDALIBRE %c",169,169);
    gotoxy(2,3);printf("Puedes esquivar los obstaculos o");
    gotoxy(2,4);printf("dispararlos, cada 8 acertaciones");
    gotoxy(2,5);printf("tu vida sube, no puedes tocar las");
    gotoxy(2,6);printf("nubes, tienes 9 vidas,PUEDES DURAR?");
    gotoxy(2,7);printf("VAMOS!! HAZ QUE LLEGUE A TIERRA");
    gotoxy(2,9); printf("   %c%c ",226,226);
    gotoxy(2,10);printf("  (**)  ");
    gotoxy(2,11);printf("  (**)  ");
    gotoxy(2,12);printf(" (****) ");
    gotoxy(2,13);printf(" (****) ");
    gotoxy(2,14);printf("  (**)  ");
    gotoxy(2,15);printf("  (**)  ");
    gotoxy(2,16);printf(" (*)(*) ");
    gotoxy(2,17);printf("(*)  (*)");
     gotoxy(15,10);printf("ARRIBA");
    gotoxy(18,11);printf("^");
    gotoxy(19,12);printf(" %c%c DER",175,175);
    gotoxy(11,12);printf("IZQ %c%c",174,174);
    gotoxy(18,13);printf("%c",193);
    gotoxy(16,14);printf("ABAJO");

    gotoxy(11,16);printf("DISPAROS IZQUIERDOS: A");
    gotoxy(11,17);printf("DISPAROS DERECHOS:   D");

    gotoxy(3,20);printf("ESCOJE EL NIVEL DE DIFICULTAD");
    gotoxy(3,21);printf("UDLA:   1\n");
    gotoxy(3,22);printf("CENTRAL:   2\n");
    gotoxy(3,23);printf("POLITECNICA: 3\n\n");
    gotoxy(3,25);printf("        NIVEL: ");
    scanf("%d",&c);
    if(c==1){c=20;b=&c;}
    else if(c==2){c=10;b=&c;}
    else if(c==3){c=7;b=&c;}
    gotoxy(10,1);printf("                          ");
    gotoxy(2,3);printf("                                   ");
    gotoxy(2,4);printf("                                   ");
    gotoxy(2,5);printf("                                   ");
    gotoxy(2,6);printf("                                   ");
    gotoxy(2,7);printf("                                   ");
    gotoxy(2,9);printf("        ");
    gotoxy(2,10);printf("        ");
    gotoxy(2,11);printf("        ");
    gotoxy(2,12);printf("        ");
    gotoxy(2,13);printf("        ");
    gotoxy(2,14);printf("        ");
    gotoxy(2,15);printf("        ");
    gotoxy(2,16);printf("        ");
    gotoxy(2,17);printf("        ");
     gotoxy(15,10);printf("         ");
    gotoxy(18,11);printf(" ");
    gotoxy(19,12);printf("         ");
    gotoxy(11,12);printf("            ");
    gotoxy(18,13);printf(" ");
    gotoxy(16,14);printf("      ");
     gotoxy(11,16);printf("                      ");
    gotoxy(11,17);printf("                       ");
    gotoxy(3,20);printf("                                 ");
    gotoxy(3,21);printf("                     ");
    gotoxy(3,22);printf("                     ");
    gotoxy(3,23);printf("                     ");
    gotoxy(3,24);printf("                    ");
    gotoxy(3,25);printf("                     ");
    gotoxy(3,26);printf("                     ");
    gotoxy(10,29);printf("               ");
    system("color 1F");
    return *b;
}
void puntuacion(int n[],int b){
    if(b<=30 && b>10){
        if(n[0]<50){
        gotoxy(4,11);printf("LA CAIDA LIBRE FUE UN DESASTRE");
        gotoxy(10,13);printf("PUNTUACION: %d",n[0]*10);
    }else if(n[0]>=50 && n[0]<=150){
        gotoxy(12,11);printf("CASI LO LOGRAS");
        gotoxy(12,13);printf("PUNTUACION: %d",n[0]*10);
    }else if(n[0]>150){
         gotoxy(3,11);printf("ERES UN POLITECNICO DE CORAZON XD");
        gotoxy(10,13);printf("PUNTUACION: %d",n[0]*10);
    }
  }
  if(b<=10 && b>7){
     if(n[0]<30){
        gotoxy(4,11);printf("LA CAIDA LIBRE FUE UN DESASTRE");
        gotoxy(10,13);printf("PUNTUACION: %d",n[0]*10);
    }else if(n[0]>=30 && n[0]<100){
        gotoxy(12,11);printf("CASI LO LOGRAS");
        gotoxy(12,13);printf("PUNTUACION: %d",n[0]*10);
    }else if(n[0]>=100){
         gotoxy(3,11);printf("ERES UN POLITECNICO DE CORAZON XD");
        gotoxy(10,13);printf("PUNTUACION: %d",n[0]*10);
    }
  }
  if(b<=7){
     if(n[0]<15){
        gotoxy(4,11);printf("LA CAIDA LIBRE FUE UN DESASTRE");
        gotoxy(10,13);printf("PUNTUACION: %d",n[0]*10);
    }else if(n[0]>=15 && n[0]<30){
        gotoxy(12,11);printf("CASI LO LOGRAS");
        gotoxy(12,13);printf("PUNTUACION: %d",n[0]*10);
    }else if(n[0]>=30){
         gotoxy(3,11);printf("ERES UN POLITECNICO DE CORAZON XD");
        gotoxy(10,13);printf("PUNTUACION: %d",n[0]*10);
    }
  }
}
void ganar(int a,int f[],int b,HOMBRE hom){
    int i=0,j=0;
     system("cls");
     OcultarCursor();
     limites();
      gotoxy(20,2);printf("VIDAS %d",a);
     gotoxy(3,2);printf("POLI-CAIDALIBRE");
     for(i=hom.y;i<=23;i++){
    system("color 12");
    gotoxy(4,1);printf("!!SALVASTE AL PARACAIDISTA!!");
     pintar(hom);
     Sleep(200);
     gotoxy(4,1);printf("                            ");
     borrar(hom);
     hom.y++;
     }pintar(hom);
     gotoxy(4,1);printf("!!SALVASTE AL PARACAIDISTA!!");
    gotoxy(3,33);printf("******************************");
    Sleep(400);
    system("color 12");
    borrar(hom);
    gotoxy(3,33);printf("                              ");
    Sleep(400);
    system("color 18");
    pintar(hom);
     gotoxy(3,33);printf("******************************");
    Sleep(400);
    system("color 19");
     borrar(hom);
    gotoxy(3,33);printf("                              ");
    Sleep(400);
    system("color 13");
    pintar(hom);
     gotoxy(3,33);printf("******************************");
     Sleep(400);
     system("color 14");
      pintar(hom);
        Sleep(400);system("color 16");
      borrar(hom);
      Sleep(400);system("color 14");
       pintar(hom);
       gotoxy(3,33);printf("******************************");
       Sleep(900);system("color 1F");
    puntuacion(f,b);
    system("cls");
}
void continuar(){
    gotoxy(5,15);printf("DESEAS VOLVER A JUGAR ???");
    gotoxy(6,17);printf("PRESIONA 1 para JUGAR");
    gotoxy(6,18);printf("PRESIONA 0 para SALIR: \n");
     gotoxy(3,20);printf("                   ");
}
void combo(){
    system("color 1C");
    gotoxy(5,14);printf("COOO00MBO!! +++ 1 VIDA");Sleep(2000);
    gotoxy(5,14);printf("                       ");
    system("color 1F");
}



