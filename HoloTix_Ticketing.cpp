#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct data{
    int hari;
    int bulan;
    int tahun;
    int banyak;
	int harga;
	int total;
    char nama[50];
	char jenis[50];
	char event[50];
	int stok;
	int jumlah;
	int sisa;
};
void swap( struct data *p1,struct data *p2){
	struct data temp=*p1;
	*p1=*p2;
	*p2=temp;
}
void datesort(struct data tgl[],int t){
    struct data swap;
    int i,j;
    for (i = 0; i < t - 1; i++) {
        for (j = 0; j < t - 1 - i; j++) { 
            if (tgl[j].tahun > tgl[j + 1].tahun) {
                swap = tgl[j];
                tgl[j] = tgl[j + 1];
                tgl[j + 1] = swap;
            }
            else if(tgl[j].tahun==tgl[j+1].tahun){
                if (tgl[j].bulan > tgl[j + 1].bulan) {
                    swap = tgl[j];
                    tgl[j] = tgl[j + 1];
                    tgl[j + 1] = swap;
                }else if(tgl[j].bulan == tgl[j + 1].bulan){
                    if (tgl[j].hari > tgl[j + 1].hari) {
                        swap = tgl[j];
                        tgl[j] = tgl[j + 1];
                        tgl[j + 1] = swap;
                    }
                }
            }
        }
    }
}
void JumlahSort(struct data list[], int n){
    int i,j;
    struct data temp;
    for(i = 0;i < n-1;i++)
    {
        for(j = 0;j < n-1-i;j++)
        {
            if(list[j].banyak < list[j+1].banyak){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}
int dayofweek(int d, int m, int y){ 
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
    y -= m < 3; 
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7; 
} 
int main(){
	FILE *f = fopen("sales.txt","a+");
	struct data inp;
	int i,plhbl,plhbs,plhkn,plhms,plhtb,menu;
	int harga,banyak,stage,park;
	int s,total,n;
	int day,month,year;
	int temp[1000]={0};
	char select[6],yt[4];
	back :
	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb WELCOME to HoloTix \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");	
	printf("\t\t[1] Ticket\n\n");
	printf("\t\t[2] Data\n\n");
	printf("\t\t[3] EXIT\n\n");
	printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
	salah :
	printf("Pilih Menu : ");
	scanf("%d",&menu);
	if(menu == 1){
		system("cls");
		atas :
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb WELCOME to HoloTix \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");	
				printf("\t\t[1] Sport\n\n");
				printf("\t\t[2] Film\n\n");
				printf("\t\t[3] Music\n\n");
				printf("\t\t[4] Museum\n\n");
				printf("\t\t[5] Park\n\n");
				printf("\t\t[6] Back\n\n");
				printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
				salah2 :
				printf("Pilih Tiket: ");
				scanf("%s",&select);
				printf("Masukan Tanggal : ");
				scanf("%d %d %d",&inp.hari,&inp.bulan,&inp.tahun);
				s = dayofweek(inp.hari,inp.bulan,inp.tahun);	
				if(strcmp(select,"1")==0){
					system("cls");
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Tiket Sepak Bola \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
					printf("\t[1] Arema vs Persija\n\n");
					printf("\t[2] Persib vs Persibaya\n\n");
					printf("\t[3] Back\n\n");
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
					salahbl :
					printf("Pilih Tiket: ");
					scanf("%d",&plhbl);
					printf("\n");
					if(plhbl == 1){
						printf("\nHarga = Rp200.000\n");
						harga = 200000;									
					}
					else if(plhbl == 2){
						printf("\nHarga = Rp200.000\n");
						harga = 200000;									
					}
					else if(plhbl == 3){
						system("cls");
						goto atas;
					}
					else{
						printf("Input Salah, Tolong Masukan Input Yang Benar!\n");
						goto salahbl;
					}
				}
				else if(strcmp(select,"2")==0){
					system("cls");
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Tiket Film \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
					printf("   [1] Kimetsu no Yaiba : Mugen Train\n\n");
					printf("   [2] Sweet Home\n\n");
					printf("   [3] Asih 2\n\n");
					printf("   [4] Back\n\n");
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
					salahbs :
					printf("Pilih Tiket: ");
					scanf("%d",&plhbs);
					printf("\n");
					if(plhbs == 1){
						printf("Kimetsu no Yaiba : Mugen Train\n");
					}
					else if(plhbs == 2){
						printf("Sweet Home\n");		
					}
					else if(plhbs == 3){
						printf("Asih 2\n");	
					}
					else if(plhbs == 4){
						system("cls");
						goto atas;
					}
					else{
						printf("Input Salah, Tolong Masukan Input Yang Benar!\n");
						goto salahbs;
					}							
					if(s == 0){
						printf("\nHarga = Rp50.000\n");
						harga = 50000;
					}
					else{
						printf("\nHarga = Rp35.000\n");
						harga = 35000;	
					}
				}
				else if(strcmp(select,"3")==0){
					system("cls");
					
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Tiket Music \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
					printf("   [1] Tiket Konser AKB48\n\n");
					printf("   [2] Tiket Holofest 2nd Stage\n\n");
					printf("   [3] Tiket Konser Black Pink\n\n");
					printf("   [4] Back\n\n");
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
					printf("Pilih Tiket: ");
					scanf("%d",&plhkn);
					printf("\n");
					if(plhkn == 1){
						printf("\nHarga = Rp500.000\n");
						harga = 500000;
					}
					else if(plhkn == 2){
						system("cls");
						printf("\n");
						menuholo :
						printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Holofest 2nd Stage \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
						printf("  \t[1] Stage 1 (day 1)\n\n");
						printf("  \t[2] Stage 2 (day 2)\n\n");
						printf("  \t[3] Stage 1-2 (day 1-2)\n\n");
						printf("  \t[4] Back\n\n");
						printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
						salahst :
						printf("Pilih Menu : ");
						scanf("%d",&stage);
						if(stage == 1){
							printf("\nHarga = Rp800.000\n");
							harga = 800000;
						}
						else if(stage == 2){
							printf("\nHarga = Rp800.000\n");
							harga = 800000;
						}
						else if(stage == 3){
							printf("\nHarga = Rp1.400.000\n");
							harga = 1400000;
						}
						else if(stage == 4){
							system("cls");
							goto menuholo;
						}
						else{
							printf("Input Salah, Tolong Masukan Input Yang Benar!\n");
							goto salahst;
						}
					}
					else if(plhkn == 3){
						printf("Harga = Rp2.000.000\n");
						harga = 2000000;
					}
					else if(plhkn == 4){
						system("cls");
						goto atas;
					}
				}
				else if(strcmp(select,"4")==0){
					system("cls");
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Tiket Museum Malang \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
					printf("\t[1] Museum Brawijaya\n\n");
					printf("\t[2] Back\n\n");
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
					salah4 :
					printf("Pilih Tiket: ");
					scanf("%d",&plhms);
					if(plhms == 1){
						if(s == 0){
							printf("\nHarga = Rp50.000\n");
							harga = 50000;
						}
						else{
							printf("\nHarga = Rp20.000\n");
							harga = 20000;	
						}
					}
					else if(plhms == 2){
						system("cls");
						goto atas;
					}
					else{
						printf("Input Salah, Tolong Masukan Input Yang Benar!\n");
						goto salah4;	
					}
				}
				else if(strcmp(select,"5")==0){
					system("cls");
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Tiket Park \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
					printf("\t[1] Jatim Park 1\n\n");
					printf("\t[2] Jatim Park 2\n\n");
					printf("\t[3] Jatim Park 3\n\n");
					printf("\t[4] Hawaii Park\n\n");
					printf("\t[5] Back\n\n");
					printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
					salahpark :
					printf("Pilih Tiket: ");
					scanf("%d",&park);
					printf("\n");
					if(park == 1){
						printf("\nHarga = Rp100.000\n");
						harga = 100000;
					}
					else if(park == 2){
						printf("\nHarga = Rp150.000\n");
						harga = 150000;
					}
					else if(park == 3){
						printf("\nHarga = Rp200.000\n");
						harga = 200000;
					}
					else if(park == 4){
						printf("\nHarga = Rp50.000\n");
						harga = 50000;
					}
					else if(park == 5){
						system("cls");
						goto atas;
					}
					else{
						printf("Input Salah, Tolong Masukan Input Yang Benar!\n");
						goto salahpark;
					}					
				}
				else if(strcmp(select,"6")==0){
					system("cls");
					goto back;
				}
				else{
					printf("Input Salah, Tolong Masukan Input Yang Benar!\n");
					goto salah2;
				}	
				printf("Melanjutkan Transaksi?(y/t)\n");
				scanf("%s",&yt);
				if(strcmp(yt,"y")==0||strcmp(yt,"Y")==0){
					printf("\nBanyak Tiket : ");
					scanf("%d",&banyak);
					printf("\nNama : ");
					scanf("\n%[^\n]s",&inp.nama);
					fprintf(f,"#%d#%d#%d",inp.hari,inp.bulan,inp.tahun);
					fprintf(f,"#%s",inp.nama);
					if(strcmp(select,"1")==0){
						fprintf(f,"#Sport");
					}
					else if(strcmp(select,"2")==0){
						fprintf(f,"#Film");
					}
					else if(strcmp(select,"3")==0){
						fprintf(f,"#Music");
					}
					else if(strcmp(select,"4")==0){
						fprintf(f,"#Museum");
					}
					else if(strcmp(select,"5")==0){
						fprintf(f,"#Park");
					}
					if(strcmp(select,"1")==0){
						if(plhbl == 1){
							fprintf(f,"#Arema vs Persija");									
						}
						else if(plhbl == 2){
							fprintf(f,"#Persib vs Persibaya");									
						}
					}
					else if(strcmp(select,"2")==0){		
						if(plhbs == 1){
							fprintf(f,"#Kimetsu no Yaiba");
						}
						else if(plhbs == 2){
							fprintf(f,"#Sweet Home");		
						}
						else if(plhbs == 3){
							fprintf(f,"#Asih 2");	
						}
					}
					else if(strcmp(select,"3")==0){
						if(plhkn == 1){
							fprintf(f,"#AKB48");
						}
						else if(plhkn == 2){
							if(stage == 1){
								fprintf(f,"#Holofest 2nd1");
							}
							else if(stage == 2){
								fprintf(f,"#Holofest 2nd2");
							}
							else if(stage == 3){
								fprintf(f,"#Holofest 2nd1-2");
							}
						}
						else if(plhkn == 3){
							fprintf(f,"#Black Pink");
						}
					}
					else if(strcmp(select,"4")==0){
						fprintf(f,"#Museum Malang");
					}
					else if(strcmp(select,"5")==0){
						if(park == 1){
							fprintf(f,"#Jatim Park 1");
						}
						else if(park == 2){
							fprintf(f,"#Jatim Park 2");
						}
						else if(park == 3){
							fprintf(f,"#Jatim Park 3");
						}
						else if(park == 4){
							fprintf(f,"#Hawaii");
						}
					}	
					fprintf(f,"#%d",banyak);
					if(strcmp(select,"1")==0){
						if(plhbl == 1){
							fprintf(f,"#200000");									
						}
						else if(plhbl == 2){
							fprintf(f,"#200000");									
						}
					}
					else if(strcmp(select,"2")==0){		
						if(s == 0){
							fprintf(f,"#50000");
						}
						else{
							fprintf(f,"#35000");	
						}
					}
					else if(strcmp(select,"3")==0){
						if(plhkn == 1){
							fprintf(f,"#500000");
						}
						else if(plhkn == 2){
							if(stage == 1){
								fprintf(f,"#800000");
							}
							else if(stage == 2){
								fprintf(f,"#800000");
							}
							else if(stage == 3){
								fprintf(f,"#1400000");
							}
						}
						else if(plhkn == 3){
							fprintf(f,"#2000000");
						}
					}
					else if(strcmp(select,"4")==0){
						if(s == 0){
							fprintf(f,"#50000");
						}
						else{
							fprintf(f,"#20000");
						}
					}
					else if(strcmp(select,"5")==0){
						if(park == 1){
							fprintf(f,"#100000");
						}
						else if(park == 2){
							fprintf(f,"#150000");
						}
						else if(park == 3){
							fprintf(f,"#200.000");
						}
					}
					total = banyak * harga;
					fprintf(f,"#%d\n\n",total);					
				}
				else{
					system("cls");
					goto back;
				}
				
	}
	else if(menu == 2){
		fclose(f);
		FILE *f = fopen("sales.txt","r");
		int n=0;
		int selectd,i;
		struct data dt[1000];
		int stock;
		fclose(f);
		fopen("sales.txt","a+");
		system("cls");
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Data Sales \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");			
		printf("    [1] Pendataan Data\n\n");
		printf("    [2] Laporan Berdasarkan Tanggal\n\n");
		printf("    [3] Laporan Berdasarkan Produk\n\n");
		printf("    [4] Back\n\n");
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
		salah1 :
		printf("Pilih Menu : ");
		scanf("%d",&selectd);
		while(!feof(f)){
			temp[n]=n;
			fscanf(f,"#%d#%d#%d#",&dt[n].hari,&dt[n].bulan,&dt[n].tahun);
			fscanf(f,"%[^#]#%[^#]#%[^#]",&dt[n].nama,&dt[n].jenis,&dt[n].event);
			fscanf(f,"#%d#%d#%d\n",&dt[n].banyak,&dt[n].harga,&dt[n].total);		
			n++;
		}
		int stok = 100;
		for(int i=0;i<n;i++){
			dt[i].jumlah+=dt[i].banyak;
			//jumlah+=dt[i].banyak;
			//printf("Jumlah = %d\n",dt[i].jumlah);
			dt[i].sisa=stok-dt[i].jumlah;
		}
		if(selectd == 1){
		system("cls");
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Data Collection \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
		printf("Tanggal\t     Nama    Jenis\tTiket\t\tBanyak\tSisa Stock\tHarga\t        Total\n\n");
			for(int i=0;i<n;i++){
					if(dt[i].hari<9 && dt[i].bulan<9){
						printf("0%d 0%d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
					}
					else if(dt[i].hari < 9){
						printf("0%d %d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
					}
					else if(dt[i].bulan < 9){
						printf("%d 0%d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
					}
					else{
						printf("%d %d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
					}
				printf("   %s    %s\t%s\t",dt[i].nama,dt[i].jenis,dt[i].event);
				printf("%d\t %d\t\tRp.%d\tRp.%d\n",dt[i].banyak,dt[i].sisa,dt[i].harga,dt[i].total);
			}
			printf("\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
		}
		else if(selectd == 2){
			system("cls");
			datesort(dt,n);
			printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Data Collection \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
			printf("Tanggal\t     Nama    Jenis\tTiket\t\tBanyak\tSisa Stock\tHarga\t        Total\n\n");
				for(int i=0;i<n;i++){
						if(dt[i].hari<9 && dt[i].bulan<9){
							printf("0%d 0%d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
						}
						else if(dt[i].hari < 9){
							printf("0%d %d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
						}
						else if(dt[i].bulan < 9){
							printf("%d 0%d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
						}
						else{
							printf("%d %d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
						}
					printf("   %s    %s\t%s\t",dt[i].nama,dt[i].jenis,dt[i].event);
					printf("%d\t %d\t\tRp.%d\tRp.%d\n",dt[i].banyak,dt[i].sisa,dt[i].harga,dt[i].total);
				}
			printf("\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
		}
		else if(selectd == 3){
			system("cls");
			JumlahSort(dt,n);
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Data Collection \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
		printf("Tanggal\t     Nama    Jenis\tTiket\t\tBanyak\tSisa Stock\tHarga\t        Total\n\n");
			for(int i=0;i<n;i++){
					if(dt[i].hari<9 && dt[i].bulan<9){
						printf("0%d 0%d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
					}
					else if(dt[i].hari < 9){
						printf("0%d %d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
					}
					else if(dt[i].bulan < 9){
						printf("%d 0%d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
					}
					else{
						printf("%d %d %d",dt[i].hari,dt[i].bulan,dt[i].tahun);
					}
				printf("   %s    %s\t%s\t",dt[i].nama,dt[i].jenis,dt[i].event);
				printf("%d\t %d\t\tRp.%d\tRp.%d\n",dt[i].banyak,dt[i].sisa,dt[i].harga,dt[i].total);
			}
			printf("\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
		}
		else if(selectd == 4){
			system("cls");
			goto back;
		}
		else{
			printf("Input Salah, Tolong Masukan Input Yang Benar!\n");
			goto salah1;
		}	
	}	
	else if(menu == 3){
		system("cls");
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");		
		printf("\t\tTERIMAKASIH TELAH MENGGUNAKAN HoloTix\n\n");
		printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
		system("exit");
	}
	else{
		printf("Input Salah, Tolong Masukan Input Yang Benar!\n");
		goto salah;
	}			
	fclose(f);
	return 0;
}
