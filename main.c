#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct kayit
{
    int ogrencino;
    char ad[30];
    char soyad[30];
    int kayitsirasi;
    char ogretimturu[3];
};
struct numara
{
    int ogrenciIndis;
    int ogrencino;
    int kayitsirasi;
    int ogretimturu;
};

typedef struct kayit kayitlar;
typedef struct numara numaraliste;

void numaraAta(numaraliste *numara,int numaraBoyut){
    int i,j,temp;
    int birinciIlkNumara=1701001;
    int ikinciIlkNumara=1702001;


    for(i=0;i<numaraBoyut;i++){
        if(numara[i].ogrencino>birinciIlkNumara && numara[i].ogretimturu==1){
            birinciIlkNumara=numara[i].ogrencino;
        }
        if(numara[i].ogrencino>ikinciIlkNumara && numara[i].ogretimturu==2){
            ikinciIlkNumara=numara[i].ogrencino;
        }
    }
    birinciIlkNumara++;
    ikinciIlkNumara++;

    for(i=0;i<numaraBoyut;i++){
        if(numara[i].ogretimturu==1 && numara[i].ogrencino==0){
            numara[i].ogrencino=birinciIlkNumara;
            birinciIlkNumara++;
        }else if(numara[i].ogretimturu==2 && numara[i].ogrencino==0){
            numara[i].ogrencino=ikinciIlkNumara;
            ikinciIlkNumara++;
        }
    }



    printf("Numarasi Olmayan Ogrencilerin Numaralari Verilmistir.\n\n");
    /*
    for(i=0; i<numaraBoyut; i++)
        {
        printf("%15d %15d %15d %15d\n",numara[i].ogrenciIndis,numara[i].ogrencino,numara[i].kayitsirasi,numara[i].ogretimturu);
    }
    */
}
void siralaVeYaz(kayitlar *ogrenciler,numaraliste *numaralar,int boyut){
    int i,j,tempInt;
    char tempString[30];
    for(i=0;i<boyut;i++){
        ogrenciler[numaralar[i].ogrenciIndis].ogrencino=numaralar[i].ogrencino;
        ogrenciler[numaralar[i].ogrenciIndis].kayitsirasi=numaralar[i].kayitsirasi;
    }
    for(i=0; i<boyut; i++)
        {
            for(j=0; j<boyut; j++)
            {
                if(ogrenciler[i].ogrencino<ogrenciler[j].ogrencino){
                    tempInt=ogrenciler[i].ogrencino;
                    ogrenciler[i].ogrencino=ogrenciler[j].ogrencino;
                    ogrenciler[j].ogrencino=tempInt;
                    strcpy(tempString,ogrenciler[i].ad);
                    strcpy(ogrenciler[i].ad,ogrenciler[j].ad);
                    strcpy(ogrenciler[j].ad,tempString);
                    strcpy(tempString,ogrenciler[i].soyad);
                    strcpy(ogrenciler[i].soyad,ogrenciler[j].soyad);
                    strcpy(ogrenciler[j].soyad,tempString);
                    tempInt=ogrenciler[i].kayitsirasi;
                    ogrenciler[i].kayitsirasi=ogrenciler[j].kayitsirasi;
                    ogrenciler[j].kayitsirasi=tempInt;
                    strcpy(tempString,ogrenciler[i].ogretimturu);
                    strcpy(ogrenciler[i].ogretimturu,ogrenciler[j].ogretimturu);
                    strcpy(ogrenciler[j].ogretimturu,tempString);
                }
            }
        }
    /*
    printf("\nSirala ve Yaz: \n\n");
    for(i=0;i<boyut;i++){
            printf("%-10d %-20s %-20s %-5d %-2s \n",ogrenciler[i].ogrencino,ogrenciler[i].ad,ogrenciler[i].soyad,ogrenciler[i].kayitsirasi,ogrenciler[i].ogretimturu);
        }*/
}
void siniflaraAyir(kayitlar *ogrenciler,numaraliste *numaralar,int boyut){
    int sinifSayisi,i,j,birinciOgretimToplam=0,ikinciOgretimToplam=0;
    printf("\nSinif Sayisini Giriniz: ");
    scanf("%d",&sinifSayisi);
    int *sinifSayisiDizi=(int *)malloc(sinifSayisi*sizeof(int));
    int *dagitilanSinifDiziBirinci=(int *)malloc(sinifSayisi*sizeof(int));
    int *dagitilanSinifDiziIkinci=(int *)malloc(sinifSayisi*sizeof(int));
    for(i=0;i<boyut;i++){
        if(numaralar[i].ogretimturu==1){birinciOgretimToplam++;}
        else if(numaralar[i].ogretimturu==2){ikinciOgretimToplam++;}
    }
    printf("\nSinif Kapasitelerini Giriniz: ");

    int toplam=0;
    for(i=0;i<sinifSayisi;i++){
        scanf("%d",&sinifSayisiDizi[i]);
        toplam+=sinifSayisiDizi[i];
    }
    while(toplam<birinciOgretimToplam || toplam<ikinciOgretimToplam){
        toplam=0;
        printf("\n\nGirdiginiz Sinif Kapasiteleri Ogrencileri Yerlestirmeye Yetmemektedir.Lutfen Tekrar Giris Yapiniz.\n");
        printf("\nSinif Kapasitelerini Giriniz: ");
        for(i=0;i<sinifSayisi;i++){
            scanf("%d",&sinifSayisiDizi[i]);
            toplam+=sinifSayisiDizi[i];
        }
    }
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("\nDersi Alan Ogrenci Sayisi - 1.Ogretim: %d  kisi. 2.Ogretim: %d  kisi.",birinciOgretimToplam,ikinciOgretimToplam);


    int esitDagilimBolumBirinci=birinciOgretimToplam/sinifSayisi;
    int esitDagilimBolumIkinci=ikinciOgretimToplam/sinifSayisi;
    int yerlestirilen=0;
    for(i=0;i<sinifSayisi;i++){
        dagitilanSinifDiziBirinci[i]=0;
        dagitilanSinifDiziIkinci[i]=0;
    }
    for(i=0;i<birinciOgretimToplam || yerlestirilen!=birinciOgretimToplam;i++){
        if(sinifSayisiDizi[i%sinifSayisi]-dagitilanSinifDiziBirinci[i%sinifSayisi]!=0){
            dagitilanSinifDiziBirinci[i%sinifSayisi]++;
            yerlestirilen++;
        }
    }

    printf("\n\nEsit Dagilim: 1.Ogretim:  ");
    for(i=0;i<sinifSayisi;i++){
        printf("%d ",dagitilanSinifDiziBirinci[i]);
    }
    FILE *hataicin=fopen("enaz.txt","w");
    fclose(hataicin);
    hataicin=fopen("esit.txt","w");
    fclose(hataicin);
    system("del enaz*.txt||rm enaz*.txt");
    system("del esit*.txt||rm esit*.txt");
    char dosyaismi1[30];
    char dosyaismi2[30];
    j=0;int k=0;
    for(i=0;i<sinifSayisi;i++){
        if(dagitilanSinifDiziBirinci[i]!=0){
            sprintf(dosyaismi1,"esit_ogr1sinif%d.txt",i+1);
            FILE *dosya=fopen(dosyaismi1,"w+");
            fputs("OgrenciNo|Ad|Soyad|KayitSirasi|OgretimTuru\n",dosya);
            while(k<dagitilanSinifDiziBirinci[i]){
                if(strcmp(ogrenciler[j].ogretimturu,"I")==0){
                    fprintf(dosya,"%d %s %s %d %s\n",ogrenciler[j].ogrencino,ogrenciler[j].ad,ogrenciler[j].soyad,ogrenciler[j].kayitsirasi,ogrenciler[j].ogretimturu);
                    k++;
                }
                j++;
            }
            k=0;
            fclose(dosya);
        }
    }
    yerlestirilen=0;
    for(i=0;i<sinifSayisi;i++){
        dagitilanSinifDiziIkinci[i]=0;
    }
    for(i=0;i<ikinciOgretimToplam || yerlestirilen!=ikinciOgretimToplam;i++){
        if(sinifSayisiDizi[i%sinifSayisi]-dagitilanSinifDiziIkinci[i%sinifSayisi]!=0){
            dagitilanSinifDiziIkinci[i%sinifSayisi]++;
            yerlestirilen++;
        }
    }
    printf("......... 2.Ogretim:  ");
    k=0;j=0;
    for(i=0;i<sinifSayisi;i++){
        if(dagitilanSinifDiziIkinci[i]!=0){
            sprintf(dosyaismi2,"esit_ogr2sinif%d.txt",i+1);
            FILE *dosya=fopen(dosyaismi2,"w+");
            fputs("OgrenciNo|Ad|Soyad|KayitSirasi|OgretimTuru\n",dosya);
            while(k<dagitilanSinifDiziIkinci[i]){
                if(strcmp(ogrenciler[j].ogretimturu,"II")==0){
                    fprintf(dosya,"%d %s %s %d %s\n",ogrenciler[j].ogrencino,ogrenciler[j].ad,ogrenciler[j].soyad,ogrenciler[j].kayitsirasi,ogrenciler[j].ogretimturu);
                    k++;
                }
                j++;
            }
            k=0;
            fclose(dosya);
        }
    }
    for(i=0;i<sinifSayisi;i++){
        printf("%d ",dagitilanSinifDiziIkinci[i]);
    }


    yerlestirilen=0;

    for(i=0;i<sinifSayisi;i++){
        dagitilanSinifDiziBirinci[i]=0;
        dagitilanSinifDiziIkinci[i]=0;
    }
    int enb=0;
    int enbIndis=0;
    for(i=0;i<birinciOgretimToplam;i++){
        for(j=0;j<sinifSayisi;j++){
            if(sinifSayisiDizi[j]-dagitilanSinifDiziBirinci[j]!=0){
                if(sinifSayisiDizi[j]>enb){
                    enb=sinifSayisiDizi[j];
                    enbIndis=j;
                }
            }
        }
        dagitilanSinifDiziBirinci[enbIndis]++;
        enb=0;
    }
    printf("\n\nEn Az Sinif Dagilimi:  1.ogretim:   ");
    for(i=0;i<sinifSayisi;i++){
        printf("%d ",dagitilanSinifDiziBirinci[i]);
    }

    j=0;k=0;
    for(i=0;i<sinifSayisi;i++){
        if(dagitilanSinifDiziBirinci[i]!=0){
            sprintf(dosyaismi1,"enaz_ogr1sinif%d.txt",i+1);
            FILE *dosya=fopen(dosyaismi1,"w+");
            fputs("OgrenciNo|Ad|Soyad|KayitSirasi|OgretimTuru\n",dosya);
            while(k<dagitilanSinifDiziBirinci[i]){
                if(strcmp(ogrenciler[j].ogretimturu,"I")==0){
                    fprintf(dosya,"%d %s %s %d %s\n",ogrenciler[j].ogrencino,ogrenciler[j].ad,ogrenciler[j].soyad,ogrenciler[j].kayitsirasi,ogrenciler[j].ogretimturu);
                    k++;
                }
                j++;
            }
            k=0;
            fclose(dosya);
        }
    }

    enb=0;
    enbIndis=0;
    for(i=0;i<ikinciOgretimToplam;i++){
        for(j=0;j<sinifSayisi;j++){
            if(sinifSayisiDizi[j]-dagitilanSinifDiziIkinci[j]!=0){
                if(sinifSayisiDizi[j]>enb){
                    enb=sinifSayisiDizi[j];
                    enbIndis=j;
                }
            }
        }
        dagitilanSinifDiziIkinci[enbIndis]++;
        enb=0;
    }
    printf("......... 2.Ogretim:  ");
    for(i=0;i<sinifSayisi;i++){
        printf("%d ",dagitilanSinifDiziIkinci[i]);
    }
    k=0;j=0;
    for(i=0;i<sinifSayisi;i++){
        if(dagitilanSinifDiziIkinci[i]!=0){
            sprintf(dosyaismi2,"enaz_ogr2sinif%d.txt",i+1);
            FILE *dosya=fopen(dosyaismi2,"w+");
            fputs("OgrenciNo|Ad|Soyad|KayitSirasi|OgretimTuru\n",dosya);
            while(k<dagitilanSinifDiziIkinci[i]){
                if(strcmp(ogrenciler[j].ogretimturu,"II")==0){
                    fprintf(dosya,"%d %s %s %d %s\n",ogrenciler[j].ogrencino,ogrenciler[j].ad,ogrenciler[j].soyad,ogrenciler[j].kayitsirasi,ogrenciler[j].ogretimturu);
                    k++;
                }
                j++;
            }
            k=0;
            fclose(dosya);
        }
    }

    printf("\n\n--------------------------------------------------------------------------------------\n");
}

int main()
{
    char soru='h';
    do
    {
        FILE *dosya=fopen("ogrenci_kayit_bilgileri.txt","r+");
        char ch;
        int satirsayac=0,ilksatirmi=0,satirsayac2=0;
        int i,j,k;
        char tampon[30];

        while(!feof(dosya))
        {
            ch=getc(dosya);
            if(ch=='\n')
            {
                satirsayac++;
            }
        }
        printf("Toplam kayit sayisi: %d\n\n",satirsayac);
        kayitlar *ogrenciler=(kayitlar *)malloc(satirsayac*sizeof(kayitlar));
        rewind(dosya);


        FILE *dosya2=fopen("bosluksuz_ogrenci_kayit_bilgileri.txt","w+");
        while(!feof(dosya))
        {
            ch=getc(dosya);
            if(ilksatirmi!=0)
            {
                if(ch!=' ' && ch!='\t' && ch!='ÿ')
                {
                    fprintf(dosya2,"%c",ch);
                }
                else
                {
                    fputc('\n',dosya2);
                }
            }
            if(ch=='\n')
            {
                ilksatirmi++;
            }
        }

        fclose(dosya);
        fclose(dosya2);
        FILE *dosya3=fopen("bosluksuz_ogrenci_kayit_bilgileri.txt","r+");
        satirsayac2=0;
        while(fgets(tampon,30,dosya3)!=NULL)
        {
            for(i=0; i<30; i++)
            {
                if(tampon[i]=='\n')
                {
                    tampon[i]='\0';
                }
            }
            if(satirsayac2%5==0)
            {
                if(atoi(tampon)!=0)
                {
                    ogrenciler[satirsayac2/5].ogrencino=atoi(tampon);
                }
                else
                {
                    ogrenciler[satirsayac2/5].ogrencino=0;
                }
            }
            else if(satirsayac2%5==1)
            {
                strcpy(ogrenciler[satirsayac2/5].ad,tampon);
            }
            else if(satirsayac2%5==2)
            {
                strcpy(ogrenciler[satirsayac2/5].soyad,tampon);
            }
            else if(satirsayac2%5==3)
            {
                ogrenciler[satirsayac2/5].kayitsirasi=atoi(tampon);
            }
            else if(satirsayac2%5==4)
            {
                strcpy(ogrenciler[satirsayac2/5].ogretimturu,tampon);
            }
            satirsayac2++;
        }
        fclose(dosya3);
        /*printf("\n");
        for(i=0; i<satirsayac; i++)
        {
            printf("%-10d %-20s %-20s %-5d %-2s \n",ogrenciler[i].ogrencino,ogrenciler[i].ad,ogrenciler[i].soyad,ogrenciler[i].kayitsirasi,ogrenciler[i].ogretimturu);
        }*/
        printf("Tekrar eden isimler: \n\n");
        for(i=0; i<satirsayac-1; i++)
        {
            for(j=i+1; j<satirsayac; j++)
            {
                if(strcmp(ogrenciler[i].ad,ogrenciler[j].ad)==0 && strcmp(ogrenciler[i].soyad,ogrenciler[j].soyad)==0)
                {
                    if(ogrenciler[i].kayitsirasi>ogrenciler[j].kayitsirasi)
                    {
                        ogrenciler[i].kayitsirasi=ogrenciler[j].kayitsirasi;
                    }
                    printf("    %s %s\n\n",ogrenciler[i].ad,ogrenciler[i].soyad);
                    for(k=j; k<satirsayac-1; k++)
                    {
                        ogrenciler[k].ogrencino=ogrenciler[k+1].ogrencino;
                        strcpy(ogrenciler[k].ad,ogrenciler[k+1].ad);
                        strcpy(ogrenciler[k].soyad,ogrenciler[k+1].soyad);
                        ogrenciler[k].kayitsirasi=ogrenciler[k+1].kayitsirasi;
                        strcpy(ogrenciler[k].ogretimturu,ogrenciler[k+1].ogretimturu);

                    }
                    j--;
                    satirsayac--;
                }
            }
        }
        printf("Tekrar eden isimler silinmistir.\n\n");
        numaraliste *numaralar=(numaraliste *)malloc(satirsayac*sizeof(numaraliste));
        int temp;
        //printf("\n\nDuzenlenmis liste: \n");

        int ogretimturusayac=0;
        for(i=0; i<satirsayac; i++)
        {
            numaralar[i].ogrenciIndis=i;
            numaralar[i].ogrencino=ogrenciler[i].ogrencino;
            numaralar[i].kayitsirasi=ogrenciler[i].kayitsirasi;
            for(j=0;j<2;j++){
                if(ogrenciler[i].ogretimturu[j]=='I'){
                    ogretimturusayac++;
                }
            }
            if(ogretimturusayac==1){
                numaralar[i].ogretimturu=1;
            }else{
                numaralar[i].ogretimturu=2;
            }
            ogretimturusayac=0;

        }/*
        for(i=0;i<satirsayac;i++){
            printf("%-10d %-20s %-20s %-5d %-2s \n",ogrenciler[i].ogrencino,ogrenciler[i].ad,ogrenciler[i].soyad,ogrenciler[i].kayitsirasi,ogrenciler[i].ogretimturu);
        }*/
        for(i=0;i<satirsayac;i++){
            if(numaralar[i].ogrencino!=0 && numaralar[i].ogrencino/100000<=16){
                numaralar[i].kayitsirasi=0;
            }
        }


        for(i=0; i<satirsayac; i++)
        {
            for(j=0; j<satirsayac; j++)
            {
                if(numaralar[i].kayitsirasi<numaralar[j].kayitsirasi)
                {
                    temp=numaralar[j].ogrenciIndis;
                    numaralar[j].ogrenciIndis=numaralar[i].ogrenciIndis;
                    numaralar[i].ogrenciIndis=temp;
                    temp=numaralar[j].ogrencino;
                    numaralar[j].ogrencino=numaralar[i].ogrencino;
                    numaralar[i].ogrencino=temp;
                    temp=numaralar[j].kayitsirasi;
                    numaralar[j].kayitsirasi=numaralar[i].kayitsirasi;
                    numaralar[i].kayitsirasi=temp;
                    temp=numaralar[j].ogretimturu;
                    numaralar[j].ogretimturu=numaralar[i].ogretimturu;
                    numaralar[i].ogretimturu=temp;
                }
            }
        }
        for(i=0; i<satirsayac-1; i++)
        {

                if(numaralar[i+1].kayitsirasi>numaralar[i].kayitsirasi)
                {
                    numaralar[i+1].kayitsirasi=numaralar[i].kayitsirasi+1;
                }

        }
        printf("Kayit siralari guncellenmistir.\n\n");
        /*
        printf("\n\nOgrenci kayit sayisal bilgiler: \n");
        printf("Ogrenci Indisi | Ogrenci Numarasi | Ogrenci Kayit Sirasi | Ogretim Turu\n");
        for(i=0; i<satirsayac; i++)
        {
            printf("%15d %15d %15d %15d\n",numaralar[i].ogrenciIndis,numaralar[i].ogrencino,numaralar[i].kayitsirasi,numaralar[i].ogretimturu);
        }*/

        numaraAta(numaralar,satirsayac);
        siralaVeYaz(ogrenciler,numaralar,satirsayac);
        siniflaraAyir(ogrenciler,numaralar,satirsayac);

        printf("\n\nYeni Ogrenci Girisi Yapacak Misiniz?(e/h)");
        scanf(" %c", &soru);

        ogrenciler=(kayitlar *)realloc(ogrenciler,satirsayac*sizeof(kayitlar));
        numaralar=(numaraliste *)realloc(numaralar,satirsayac*sizeof(numaraliste));
        int c;
        if(soru=='e'){
            int ogrenciNum,ogrOgretim;
            char ogrAd[30];
            char ogrOgretimStr[3];
            char ogrSoyad[30];
            satirsayac++;
            ogrenciler=(kayitlar *)realloc(ogrenciler,satirsayac*sizeof(kayitlar));
            numaralar=(numaraliste *)realloc(numaralar,satirsayac*sizeof(numaraliste));


            printf("\nOgrenci Numarasini Giriniz (Eger numarasi yoksa 0 giriniz.): ");
            scanf("%d",&ogrenciNum);
            printf("\nOgrencinin Adini Giriniz: ");
            scanf("%s",&ogrAd);
            printf("\nOgrencinin Soyadini Giriniz: ");
            scanf("%s",&ogrSoyad);
            printf("\nOgrencinin Ogretim Turunu Giriniz: ");
            scanf("%d",&ogrOgretim);


            if(ogrOgretim==1){
                strcpy(ogrOgretimStr,"I");
            }else if(ogrOgretim==2){
                strcpy(ogrOgretimStr,"II");
            }
            FILE *dosya4=fopen("ogrenci_kayit_bilgileri.txt","a+");
            fprintf(dosya4,"\n%d %s %s %d %s",ogrenciNum,ogrAd,ogrSoyad,numaralar[satirsayac-2].kayitsirasi+1,ogrOgretimStr);
            fclose(dosya4);
        }else{
            FILE *dosya4=fopen("ogrenci_kayit_bilgileri.txt","w+");
            fputs("OgrenciNo|Ad|Soyad|KayitSirasi|OgretimTuru\n",dosya4);
            for(i=0;i<satirsayac;i++){
                if(i!=satirsayac-1){
                    fprintf(dosya4,"%d %s %s %d %s\n",ogrenciler[i].ogrencino,ogrenciler[i].ad,ogrenciler[i].soyad,ogrenciler[i].kayitsirasi,ogrenciler[i].ogretimturu);
                }else{
                    fprintf(dosya4,"%d %s %s %d %s\0",ogrenciler[i].ogrencino,ogrenciler[i].ad,ogrenciler[i].soyad,ogrenciler[i].kayitsirasi,ogrenciler[i].ogretimturu);
                }
            }

            fclose(dosya4);
        }
        system("@cls||clear");
    }
    while(soru=='e');


    return 0;
}
