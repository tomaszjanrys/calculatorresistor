#include <stdio.h>
#include <stdlib.h>
float uDioda = 0.0, uZasilania = 0.0, uRezystora = 0.0, iDiody = 0.0,
miliApery = 0.0, rezystancja = 0.0, powerR = 0.0;

void table(){
printf("***********************  NAPIECIE PRZEWODZENIA DIODY  ***********************************************************************************************");
printf("** [V] => IR = 1,1 - 1,7| RED = 1,6 - 2,2| YELLOW = 2,0 - 2,3 | GREEN = 2,0 - 3,7 | BLUE = 2,9 - 4,0 | WHITE = 3,0 - ,3,6 **");
printf("********************************************************************************************************************************************\n\n");
printf("**********  PRAD PRZEWODZENIA DIODY  ****************************************************************************************");
printf("**[mA] : RED = 10 mA lub 20 mA | YELLOW = 10 mA lub 20 mA | GREEN = 10 mA lub 20 mA | BLUE = 20 mA | WHITE = 10 mA lub 20 mA|**");
printf("********************************************************************************************************************************************");
return 0;
};
//Pobranie U Zasiania
float uZ(float *uz){
uZasilania = *uz;
return uZasilania;
}
//END
//Pobranie U diody
float uD(float *ud){
uDioda = *ud;
return uZasilania;
}
//END
// Przeliczanie mA na A
float mili(float *ID){
iDiody = *ID / 1000.0;
return iDiody;
}
//END
// Przeliczanie U rezystora
float uR(float *uz, float *ud){
uRezystora = *uz - *ud;
return uRezystora;
}
//END
// wyliczanie rezystancji
float rCal(float *ur, float *id){
rezystancja = *ur / *id;
return rezystancja;
}
//END
// wyliczanie mocy R
float powerRe(float *ur, float *id){
powerR = *ur * *id;
return powerR;
}
//END


int main()
{
    table();
//Pobranie napiecia zasilania
printf("\n\nPodaj U zasilania w V\n\n");
    scanf("%f",&uZasilania);
    uZ(&uZasilania);
    printf("Wynik : %f[V]\n\n",uZasilania);
//end
//Pobranie napiecia Diody
printf("\n\nPodaj U Diody w V\n\n");
    scanf("%f",&uDioda);
    uD(&uDioda);
    printf("Wynik : %f\n\n",uDioda);
//end
//Przelicznik na Apery//
    printf("\n\nPRAD PRZEWODZENIA DIODY z mA na A\n\n");
    scanf("%f",&iDiody);
    mili(&iDiody);
    printf("Wynik : %f\[A]\n\n",iDiody);
//END//
//U rezystora//
    printf("\n\nObliczam U rezystora Ur = Uz - Ud\n\n");
    uR(&uZasilania, &uDioda);
    printf("Wynik : %f\[V]\n\n",uRezystora);
//END//
//Oblicznie Rezystora//
    printf("\n\nObliczam Rezystancje R= Urezystora / Ididoa \n\n");
    rCal(&uRezystora, &iDiody);
    printf("Twoj Rezystor to  : %f\[OM]\n\n",rezystancja);
//END/
printf("********************************************************************************************************************************************");
printf("******MOC Rezystora  P = Ur * Idiody   *********************************************************************");
//Obliczanie mocy
powerRe(&uRezystora,&iDiody);
printf("\n\nMoc Rezystora : %f[W]\n\n",powerR);
//end


    return 0;
}
