#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct login
{   char username[20];
    char password[16];
};
struct menu
{   int opsi;
    char nominal[20];
};
float hitung(int);
void masukankupon(char[]);

int main()
{   struct login user1 ={"ibulely","rejekimelimpah"};
    struct login input;
    int kendali=1,*validator=&kendali, i, pilihan;
    struct menu gopei[6]={{1,"50000"},{2,"100000"},{3,"200000"},{4,"500000"},{5,"1000000"},{6,"Nominal Lain"}};
    float total;
    char opsi, kupon[14];

    do{
        do{
            printf("______Login______\n");
            printf("Username : ");
            scanf("%s", input.username);
            printf("Password : ");
            scanf("%s", input.password);

            if(strcmp(input.username,user1.username)==0){
                if(strcmp(input.password,user1.password)==0){
                    *validator=1;
                    printf("\n Selamat Datang!\n");
                    printf(" Gopei Top-Up Machine \n\n");

                    printf("Opsi \t Nominal \n");
                    printf("__________________\n");
                    for(i=0;i<6;i++){
                        printf("%d \t %s \n", gopei[i].opsi, gopei[i].nominal);
                        }

                    do{
                        fflush(stdin);
                        printf("masukkan opsi topup yang kamu inginkan : ");
                        scanf("%d", &pilihan);

                        if(pilihan>0 && pilihan<6)
                            {total = hitung(pilihan);}
                        else if(pilihan==6){
                            fflush(stdin);
                            printf("masukkan nominal : ");
                            scanf("%f", &total);}
                        else
                        {printf("\npilihan anda salah coba masukkan kembali\n");}
                    }while(pilihan<1 || pilihan>6);

                    printf("\n___________________________Report______________________________\n");

                    if(total>500000){
                        total=0.9*total;
                        printf("\nSelamat anda mendapat potongan tagihan top up sebesar 10 persen");
                        printf("\ntagihan top-up adalah Rp. %.2f. Top Up telah berhasil \npembayaran terkonfirmasi otomatis",total);

                        printf("\n\nselamat anda mendapatkan kupon dengan kode unik : tahunbaru");

                        fflush(stdin);
                        printf("\ningin meengklaim kupon sekarang?(y/t)");
                        scanf("%c", &opsi);
                        if(opsi=='y'){
                            fflush(stdin);
                            printf("\nmasukkan kode kupon anda : ");
                            fgets(kupon, sizeof kupon, stdin);
                            masukankupon(kupon);
                         }
                        }else{
                        printf("\ntagihan top-up adalah Rp. %.2f. Top Up telah berhasil \npembayaran terkonfirmasi otomatis",total);}

                }else{
                    *validator=0;
                    printf("\n Maaf, Password anda salah\n\n");}

            }else{
            *validator=0;
            printf("\n Pengguna Tidak Ditemukan\n\n");}

        }while(kendali==0);

        printf("\n_________________________________________________________\n");
        printf("Terimakasih telah menggunakan top up machine\n\n");

        fflush(stdin);
        printf("\ningin top-up lagi?(y/t)");
        scanf("%c", &opsi);
    }while(opsi=='y');

     printf("\n_________________________________________________________\n");
                printf("Logout Berhasil\n\n");
    return 0;
}

float hitung(int a){
    float total;
    switch(a){
        case 1: total=50000;
        break;
        case 2: total=100000;
        break;
        case 3: total=200000;
        break;
        case 4: total=500000;
        break;
        case 5: total=1000000;
        break;
        }
    return total;
}

void masukankupon(char kupon[]){
    char hadiah[]="tahunbaru\n";

        if(strcmp(hadiah, kupon)==0){
            printf("\n_______________________Hadiah Spesial Tahun Baru___________________________\n");
            printf("\nselamat, anda mendapatkan bonus saldo sebesar Rp. 10.000, \nsaldo akan dikirim dalam waktu 3x24 jam\n");}
        else{
            printf("\n_______________________Hadiah Spesial Tahun Baru___________________________\n");
            printf("\nmaaf, kupon yang anda masukkan salah\n");}
}
