#include <errno.h>
#include <stdlib.h>
#include "krizkruz.h"

bool iduci_krizic = true; //bool definiran u krizkruz.h //typedef int bool; #define true 1 #define false 0
int brojac = 0;

int mainKK(){
    play();

    return 0;
}

void play(){
    char polje[3][3] = {
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
     };
    printf("******************************\n");
    ispis_polja(*polje);

    while(!krajigre(*polje)){
        int redak,stupac;

        printf("******************************\n");
        if(iduci_krizic == true){
            printf("igra krizic(X):\n");
        }
        if(iduci_krizic == false){
            printf("igra kruzic(O):\n");
        }

        printf("unesi redak(0, 1, 2) i stupac (0,1,2) sa razmakom:\n");
        scanf("%d %d", &redak,&stupac);

        if(!potez(*polje,redak,stupac)){
            printf("\n\aPogresan unos, ponovi!\n");
        }
        printf("******************************\n");
        ispis_polja(*polje);
    }

    if(krajigre(*polje)){
        FILE *f_;
        char winner;
        winner = pobjednik(*polje);

        f_ = fopen("history.kk", "a+");
        fwrite(&winner, 1, 1, f_);
        fwrite("\n",1,1,f_);
        fclose(f_);

        printf("Pobijedio je: %c\n", winner);
    }
}

void ispis_polja(char *polje){
    for (int i = 0; i < 9; i++){
        if ( i % 3 == 0 && i != 0){
            printf("\n");
        }
        printf("%c",*(polje + i));
        if (i == 8){
            printf ("\n");
        }
    }
}

bool krajigre(char *polje){
    if (brojac == 9)
        return true; //ako je odigrano 9 poteza gotovo

    if( (*(polje) == *(polje + 1) )
        && *(polje + 1) == *(polje + 2)
        && *(polje) != '-')
        return true;
    if( (*(polje + 3) == *(polje + 4) )
        && *(polje + 4) == *(polje + 5)
        && *(polje + 3) != '-')
        return true;
    if( (*(polje + 6) == *(polje + 7) )
        && *(polje + 7) == *(polje + 8)
        && *(polje + 6) != '-')
        return true;
        //
    if( (*(polje) == *(polje + 3) )
        && *(polje + 3) == *(polje + 6)
        && *(polje) != '-')
        return true;
    if( (*(polje + 1) == *(polje + 4) )
        && *(polje + 4) == *(polje + 7)
        && *(polje + 1) != '-')
        return true;
    if( (*(polje + 2) == *(polje + 5) )
        && *(polje + 5) == *(polje + 8)
        && *(polje + 2) != '-')
        return true;
        //
    if( (*(polje) == *(polje + 4) )
        && *(polje + 4) == *(polje + 8)
        && *(polje) != '-')
        return true;
    if( (*(polje + 2) == *(polje + 4) )
        && *(polje + 4) == *(polje + 6)
        && *(polje + 2) != '-')
        return true;

        return false;
}

bool potez(char *polje, int redak, int stupac)
{
    if(redak < 0 || stupac < 0 || redak > 2 || stupac > 2)
        return false;

    if((*(polje + redak * 3 + stupac)) != '-')
        return false;

    if(iduci_krizic == true){
        *(polje + redak * 3 + stupac) = 'X';
        iduci_krizic = false;
    }
    else{
        *(polje + redak * 3 + stupac) = 'O';
        iduci_krizic = true;
    }

    brojac++;

    return true;
}

char pobjednik(char *polje){
    if( (*(polje) == *(polje + 1) )
         && *(polje + 1) == *(polje + 2))
        return *(polje +2);
    if( (*(polje + 3) == *(polje + 4) )
        && *(polje + 4) == *(polje + 5))
        return *(polje + 5);
    if( (*(polje + 6) == *(polje + 7) )
        && *(polje + 7) == *(polje + 8))
        return *(polje + 8);
        //
    if( (*(polje) == *(polje + 3) )
        && *(polje + 3) == *(polje + 6))
        return *(polje + 6);
    if( (*(polje + 1) == *(polje + 4) )
        && *(polje + 4) == *(polje + 7))
        return *(polje + 7);
    if( (*(polje + 2) == *(polje + 5) )
        && *(polje + 5) == *(polje + 8))
        return *(polje +8);
        //
    if( (*(polje) == *(polje + 4) )
        && *(polje + 4) == *(polje + 8))
        return *(polje +4);
    if( (*(polje + 2) == *(polje + 4) )
        && *(polje + 4) == *(polje + 6))
        return *(polje + 6);

        return '/';

}
