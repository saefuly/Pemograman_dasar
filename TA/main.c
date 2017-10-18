#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//file header
#include "library/supplier.h"

main(){
	int menu;
	do{
		do{
			
			// Main Menu
			printf("\n");
			printf("  ========================================================= \n");
			printf("  |                  SELAMAT DATANG DI RSCH.               | \n");
			printf("  ========================================================= \n");
			printf("\n");
			printf("       Menu \n");
			printf("  ============== \n");
			printf("  1. Produk \n");
			printf("  2. Supplier \n");
			printf("  3. Transaksi \n");
			printf("  0. Keluar");
			printf("\n");
			printf("  ========================================================= \n");
			printf("  Masukan menu yang anda pilih : "); menu=getch();
		}while(menu > '4');
		
		system("cls");
		switch(menu){
			case '1' : menuSupplier();
						break;
			//case '2' : menuSupplier();
						//break;
			//case '3' : menuTransaksi();
						//break;
		}
	}while(menu !='0');
	return 0;
}
