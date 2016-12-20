#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    t       State       Next State
   ---     -------     ------------

   0        q0              q0
   1        q0              q1
   0        q1              q1
   1        q1              q0


   ----------          1        +++++++++
  0|  q0    |       ----->      +   q1  + 0
   |        |       <-----      +       +
   ----------           1       +++++++++


*/

struct parity
{
    struct parity *adres0;
    struct parity *adres1;
};

int main()
{
    struct parity *q0,*q1,*_final;
    int i;
    char *mesaj;
    mesaj = (char *)malloc(sizeof(char)*20);

    printf("Parity : ");
    scanf("%s",mesaj);

    q0 = (struct parity*)malloc(sizeof(struct parity));
    q1 = (struct parity*)malloc(sizeof(struct parity));

    q0->adres0 = q0;
    q0->adres1 = q1;
    q1->adres0 = q1;
    q1->adres1 = q0;
    _final=q0;

    for (i=0; i<strlen(mesaj); i++)
    {
        if (mesaj[i] == '1')
        {
            _final = _final->adres1;
        }
        else
        {
            _final = _final->adres0;
        }
    }

    if (_final == q0)
    {
        printf("Çift");
    }
    else
    {
        printf("Tek");
    }

    return 0;
}
