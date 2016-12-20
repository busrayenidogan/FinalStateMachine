#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    i       State                Next State
   ---     -------              ------------
   1        q0(Çift0,Çift1)         q1
   0        q1(Çift0,Tek1)          q2
   1        q2(Tek0,Tek1)           q3
   0        q3(Tek0,Çift1)          q0
   0        q0                      q3
   1        q3                      q2
   0        q2                      q1
   1        q1                      q0

            1
        -------->
    ÇÇ  <--------  ÇT
    | |     1      | |
   0| |0    1     0| |0
    TÇ  -------->  TT
        <--------
            1

  //Çift-Çift olması durumunda final state machinede kabul çıkıyor

*/
struct parity
{
    struct parity *adres0;
    struct parity *adres1;
};

int main()
{
    struct parity *q0,*q1,*q2,*q3,*_final;
    char *string;
    int i;

    string = (char*)malloc(sizeof(char)*20);

    q0 = (struct parity*)malloc(sizeof(struct parity));
    q1 = (struct parity*)malloc(sizeof(struct parity));
    q2 = (struct parity*)malloc(sizeof(struct parity));
    q3 = (struct parity*)malloc(sizeof(struct parity));

    printf("String : ");
    scanf("%s",string);

    q0->adres1 = q1;
    q0->adres0 = q3;
    q1->adres1 = q0;
    q1->adres0 = q2;
    q2->adres1 = q3;
    q2->adres0 = q1;
    q3->adres1 = q2;
    q3->adres0 = q0;

    _final=q0; //baslangic adresi

    for (i=0; i<strlen(string); i++)
    {
        if (string[i] == '1')
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
        printf("Kabul");
    }
    else
    {
        printf("Red");
    }
}
