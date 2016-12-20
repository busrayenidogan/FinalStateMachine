#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
        t       S       Next State
       ---     ---     ------------
        0       S0          S1
        0       S1          S1
        1       S1          S2
        1       S2          S2
        0       S2          S1
        1       S0          S3
        1       S3          S3
        0       S3          S4
        0       S4          S4
        1       S4          S3
*/
struct priority
{
    struct priority *adres1;
    struct priority *adres0;
};

int main()
{
    struct priority *s0,*s1,*s2,*s3,*s4,*_final;
    char *mesaj;
    int i;

    mesaj = (char*)malloc(sizeof(char)*20);

    printf("Prioty : ");
    scanf("%s",mesaj);

    s0 = (struct priority*)malloc(sizeof(struct priority));
    s1 = (struct priority*)malloc(sizeof(struct priority));
    s2 = (struct priority*)malloc(sizeof(struct priority));
    s3 = (struct priority*)malloc(sizeof(struct priority));
    s4 = (struct priority*)malloc(sizeof(struct priority));

    s0->adres0 = s1;
    s1->adres0 = s1;
    s1->adres1 = s2;
    s2->adres1 = s2;
    s2->adres0 = s1;
    s0->adres1 = s3;
    s3->adres1 = s3;
    s3->adres0 = s4;
    s4->adres0 = s4;
    s4->adres1 = s3;
    _final=s0;

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

    if (_final == s2 || _final == s4)
    {
        printf("Kabul");
    }
    else
    {
        printf("Red");
    }

    return 0;
}
