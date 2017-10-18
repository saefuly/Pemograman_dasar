#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
main()
{
    int pilih1, pilih2, pilih3;
    FILE *pf;
    int data=0 , i, x, s,y ;
    char nama[40];
    char kar, again='y', ulangi='y';
    struct data{
        char merk[100];
        char warna[100];
        int tahun;
        int harga;
	}motor[1000];
       
    do{
        printf("\n================= Selamat Datang =================\n");
        printf("\n===========================================\n PT. Astro Motor Maju Terus Pantang Mundur\n-------------------------------------------\n");
        printf("\n1. Data Motor Astro\n");
        printf("\n2. Pembelian Motor\n");
        printf("\n3. Lihat data Cicilan\n");
        printf("\n4. Simulasi Kredit\n");
        printf("\n-------------------------------------------\n");
        printf("pilihan Anda ? ");
        scanf("%d",&pilih1);
        if(pilih1>4){
            printf("INPUT SALAH, COBA LAGI!!\n");
        }
        switch(pilih1){   
        	
            // Caase Data Motor
            case 1:
            {
                do{
                    printf("\n===========================================\n 1. Data Motor Astro\n-------------------------------------------\n");
                    printf("\n1. Input Data Motor\n");
                    printf("\n2. Lihat Data Motor\n");
                    printf("\n3. Cari Data Motor\n");
                    printf("\n-------------------------------------------\n");
                    printf("pilihan Anda ? ");
                    scanf("%d",&pilih2);
                    printf("\n===========================================\n");
                    if(pilih2>3){
                        printf("INPUT SALAH, MASUKAN DATA YANG BENAR!!\n");
                    }
                    switch(pilih2){   
            
                        // Case Input Data Motor
                        case 1:
                        {
                            printf("Masukkan banyaknya data :");
                            scanf("%d",&data);
                            for(i=1;i<=data;i++)
                            {   
                                x = i-1;
                                printf("Data Motor ke-%d\n",i);
                                printf("Merk : ");scanf(" %s",motor[x].merk);
                                printf("Warna : ");scanf(" %s",motor[x].warna);
                                printf("Tahun : ");scanf(" %d",&motor[x].tahun);
                                printf("Harga : ");scanf(" %d",&motor[x].harga);             
                            }
                            printf("============================\n");
                            printf("Oke. Data sudah disimpan !!\n");
                            printf("============================\n");
                        }
                        printf("Kembali ke menu Data Motor [y/t] ? \n");
                        ulangi=getch();
                        break;

                        // Case Lihat Data Motor
                        case 2:
                        {
                            printf("----Data Motor Astro----\n");
                            printf("Nomor\t |Merk Motor\t  | Warna Motor\t   | Tahun Dibuat\t   | Harga Motor\t\n");
                            for(s=0;s<data;s++){
                                y=s+1;
                                printf("%d\t |%s\t      | %s\t        | %d\t        | %d\t\n",s+1,motor[s].merk,motor[s].warna,motor[s].tahun,motor[s].harga);
                            }   
                        }
                        printf("Kembali ke menu Data Motor [y/t] ? \n");
                        ulangi=getch();
                        break;

                        // Case Cari Data Motor
                        case 3:
                        {
                            printf("============================\n");
                            printf("Dalam pengembangan\n");
                            printf("============================\n");
                        }
                        printf("Kembali ke menu Data Motor [y/t] ? \n");
                        ulangi=getch();
                        break;
                    }
                }while(ulangi=='y');
                again=getch();
            }  
            printf("Kembali ke menu [y/t] ? ");
        	again=getch();
        	break;

            // Case Pembelian Motor
        	case 2:
            {
                if((pf=fopen("latihan.txt","a"))== NULL){
                    printf("file gagal diciptakan!\n");
                    exit(1);
                }
                printf("Masukkan banyaknya Barang :");
                scanf("%d",&data);
                for(i=1;i<=data;i++){
                    printf("\nBarang ke %d : ",i);fflush(stdin);
                    gets(nama);
                    strcat(nama,"\n");
                    fputs(nama, pf);               
                }
                printf("============================\n");
                printf("Oke. Data sudah disimpan !!\n");
                printf("============================\n");
                fclose(pf);
            }
            printf("Kembali ke menu [y/t] ? ");
        	again=getch();
        	break;
            
            // Case Lihat Data Cicilan
        	case 3:
            {
                if ((pf=fopen("latihan.txt","r"))== NULL){
                    printf("file tak dapat dibuka !\r\n");
                    exit(1);
                }
                while((kar=fgetc(pf)) !=EOF)
                putchar(kar);
                printf("\n");
                fclose(pf);
            }
        	printf("Kembali ke menu [y/t] ? ");
        	again=getch();
    		break;
    	   
            //Case Simulasi Kredit 
    		case 4:
            {
                printf("====================================\n");
                printf("Program dalam Proses Pengembangan ^^\n");
                printf("====================================\n"); 
            }
        	printf("Kembali ke menu [y/t] ? ");
        	again=getch();
    		break;
        }
    //Akhir kondisi Do pertama 
  	}while(again=='y');  
}
