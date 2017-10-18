FILE *f;
int menu;
int i, pilih, lanjut, no_record;
long int offset_byte;
char ulangi;

struct{
	char kode_supplier[20];
    char nama[100];
    char alamat[100];
    int no_tlp;
    char email[100];
} supplier;

void dataSupplier(){
	//buka file
	do{
		if((f = fopen("data-supplier.dat","rb")) == NULL){
			printf("Maaf file tidak ditemukan atau anda gagal membuat file");
		}
		
		printf("%2s. |%-10s |%-10s |%-10s |%-10s |%-10s |\n\n", "No", "Kode Supplier", "Nama", "Alamat", "No Tlp", "Email");
		while(fread(&supplier, sizeof(supplier), 1, f) == 1)
		printf("%2d. |%-10s |%-10s |%-10s |%-10d |%-10s |\n", i++, supplier.kode_supplier, supplier.nama, supplier.alamat, supplier.no_tlp, supplier.email);
		printf("\n");
		
		//tutup file
		fclose(f);
		printf("Kembali ke menu ? (Y/T)");
		do{
			ulangi = getchar();
			pilih = ((ulangi == 'Y') || (ulangi == 'y') || (ulangi == 'T') || (ulangi == 't'));
		}while(!pilih);
	}while(ulangi == 'T' || ulangi == 't');
}

void inputSupplier(){
	if((f = fopen("data-supplier.dat", "wb")) !=NULL){
		do{
			//hapus isi penampung
			fflush(stdin);
			printf("Masukkan Kode Supplier : "); gets(supplier.kode_supplier);
			printf("Masukkan Nama Supplier : "); gets(supplier.nama);
			printf("Masukkan Alamat : "); gets(supplier.alamat);
			printf("Masukkan No Tlp : "); scanf("%d", &supplier.no_tlp);
			printf("Masukkan Email : "); gets(supplier.email);
			fflush(stdin);
			
			//save data
			fwrite(&supplier, sizeof(supplier), 1, f);
			printf("\n Tambah Supplier lagi [Y/T] ? ");
			
			//cek inputan lagi
			do{
				ulangi = getchar();
				lanjut = ((ulangi == 'Y') || (ulangi == 'y') || (ulangi == 'T') || (ulangi == 't'));
			}while(!lanjut);
			printf("\n");
		}while(ulangi == 'Y' || ulangi == 'y');
		
		//tutup file
		fclose(f);
	}else{
		printf("Maaf file tidak ditemukan -_- ");
		exit(1);
	}
}

void cariSupplier(){
	if((f = fopen("data-supplier.dat", "rb")) == NULL){
		printf("Maaf file tidak ditemukan -_- ");
		exit(1);
	}
	do{
		i=1;
		printf("Kode Supplier yang dicari : "); scanf("%d", &no_record);
		
		offset_byte = (no_record-1) * sizeof(supplier);
		fseek(f, offset_byte, SEEK_SET);
		
		if(fread(&supplier, sizeof(supplier), 1, f) == 0){
			printf("Kode supplier tidak ditemukan -_- \n");
		}else{
			printf("%2s. |%-10s |%-10s |%-10s |%-10s |%-10s \n", "No", "Kode Supplier", "Nama", "Alamat", "No Tlp", "Email");
			printf("%2s. |%-10s |%-10s |%-10s |%-10d |%-10s \n", i++, supplier.kode_supplier, supplier.nama, supplier.alamat, supplier.no_tlp, supplier.email);
		}
		printf("Cari data Supplier lagi [Y/T] ? ");
		do{
			ulangi = getchar();
			pilih = ((ulangi == 'Y') || (ulangi == 'y') || (ulangi == 'T') || (ulangi == 't'));
		}while(!pilih);
	}while(pilih == 'y' || pilih == 'Y');
	
	printf("\n");
	fclose(f);
}

void menuSupplier(){
	do{
		do{
			system("cls");
			// main menu
			printf("  ========================================================= \n");
			printf("\n");
			printf("         Supplier \n");
			printf("  ======================\n");
			printf("  1. List Supplier \n");
			printf("  2. Tambah Supplier \n");
			printf("  3. Cari Supplier \n");
			printf("  0. Kembali ke menu utama \n");
			type(" Masukkan menu yang anda pilih : "); menu = getch();
		}while(menu > '3');
		
		system("cls");
		switch(menu){
			case 1 : dataSupplier();
			break;
			case 2 : inputSupplier();
			break;
			case 3 : cariSupplier();
			break;
		}
	}while(menu != '0');
}
