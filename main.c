#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
}*kyrk_ilk,*kyrk_son,*list_gecici,*kyrk_ilk_gecici;
 
int ilkElemaniGoster();
void elemanEkle(int data);
void elemanCikar();
void bosMu();
void elemanlariGoster();
void kuyrukElemanSayisi();
 
int sayac = 0;
 
void main()
{
    int secim, e,eleman;
 
    printf("\n 1 - Eleman Ekleme islemi");
    printf("\n 2 - Eleman Cikarma islemi");
    printf("\n 3 - Kuyruk Bos Mu?");
    printf("\n 4 - Kuyruk Eleman Sayisi");
    printf("\n 5 - Elemanlari Sergile");
    printf("\n 6 - Programdan Cik");
    kyrk_ilk=kyrk_son=NULL; 
    while (1)
    {
        printf("\n Seciminizi Giriniz : ");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            printf("Eklemek istediginiz veriyi giriniz : ");
            scanf("%d", &eleman);
            elemanEkle(eleman);
            break;
        case 2:
            elemanCikar();
            break;
        case 3:
            bosMu();
            break;
        case 4:
        	kuyrukElemanSayisi();
        	break;
        case 5:
            elemanlariGoster();
            break;
        case 6:
            exit(0);            
            break;
        default:
            printf("Yanlis Secim Yaptiniz. Seciminiz 1-6 arasinda olmali.  ");
            break;
        }
    }
}
  /************************** Kuyruk Eleman Sayisi Kismi ***************************///buketecrinozturk

void kuyrukElemanSayisi()
{
    printf("\n Kuyruk Eleman Sayisi : %d", sayac);
}

/************************** Kuyruk Eleman Ekleme Kismi ***************************///buketecrinozturk

void elemanEkle(int data)
{
    if (kyrk_son == NULL) // listeye eklenecek ilk veriyse
    {
        kyrk_son = (struct node *)malloc(1*sizeof(struct node));
        kyrk_son->next = NULL;
        kyrk_son->data = data;
        kyrk_ilk = kyrk_son;
    }
    else
    {
        list_gecici=(struct node *)malloc(1*sizeof(struct node));
        kyrk_son->next = list_gecici;
        list_gecici->data = data;
        list_gecici->next = NULL;
        kyrk_son = list_gecici;
    }
    sayac++; // eleman sayisini hesaplamak için ekleme isleminde sayaci 1 arttırıyoruz.
}

/************************** Kuyruk Elemanları Sergileme Kismi ***************************///buketecrinozturk

void elemanlariGoster()
{
    kyrk_ilk_gecici = kyrk_ilk;
 
    if ((kyrk_ilk_gecici == NULL) && (kyrk_son == NULL))
    {
        printf("Kuyruk Bos !!!");
        return;
    }
    while (kyrk_ilk_gecici != kyrk_son)
    {
        printf("%d ", kyrk_ilk_gecici->data);
        kyrk_ilk_gecici = kyrk_ilk_gecici->next;
    }
    if (kyrk_ilk_gecici == kyrk_son)
        printf("%d", kyrk_ilk_gecici->data);
}

/************************** Kuyruk Eleman Cikarma Kismi ***************************///buketecrinozturk

void elemanCikar()
{
    kyrk_ilk_gecici = kyrk_ilk;
 
    if (kyrk_ilk_gecici == NULL)
    {
        printf("\n Kuyruk Bos !!!");
        return;
    }
    else
        if (kyrk_ilk_gecici->next != NULL) // Listede birden fazla eleman varsa
        {
            kyrk_ilk_gecici = kyrk_ilk_gecici->next;
            printf("\n Cikarilan Elemen : %d", kyrk_ilk->data);
            free(kyrk_ilk);
            kyrk_ilk = kyrk_ilk_gecici;
        }
        else
        { // Listede de tek veri var ve siz onu cikarmak istiyorsunuz
            printf("\n Cikarilan Eleman : %d", kyrk_ilk->data);
            free(kyrk_ilk);
            kyrk_ilk = NULL;
            kyrk_son = NULL;
        }
        sayac--;
}
/************************** Kuyruk Bosmu ***************************///buketecrinozturk
void bosMu()
{
     if ((kyrk_ilk == NULL) && (kyrk_son == NULL))
        printf("\n Kuyruk Bos");
    else
       printf("Kuyrukta Eleman Var");
}
