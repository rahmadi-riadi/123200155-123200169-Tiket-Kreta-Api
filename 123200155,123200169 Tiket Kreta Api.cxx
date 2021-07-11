#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream filein; 
ofstream fileout;

struct penumpang{
	string nama, tujuan, kelas, kereta, waktu,jam,tanggal;
	char ktp[17];
	int harga;
};

penumpang orang[25],temp;
int banyak,total,totall;
bool found;

void load()
{
	filein.open("jumlah.txt");
	if (filein.is_open())
	{
		filein>>total;
	}
	filein.close();
	filein.open("data.txt");
	if (filein.is_open())
	{
		for (int i = 0; i < total; i++)
		{
		getline(filein,orang[i].nama);
		filein>>orang[i].ktp; 
		filein>>orang[i].tujuan;
		filein>>orang[i].kelas;filein.ignore();
		getline(filein,orang[i].tanggal);
		filein>>orang[i].jam;
		filein>>orang[i].harga;
		filein.ignore();}
	}
	filein.close();
}

void save()
{
	filein.open("jumlah.txt");
	if (filein.is_open())
	{
		filein>>total;
	}
	filein.close();
	totall=total+banyak;
	fileout.open("jumlah.txt");
		if (fileout.is_open())
		{
			fileout<<totall;
		}
		fileout.close();
	fileout.open("data.txt");
	for (int i = 0; i < totall; i++)
	{
		fileout<<orang[i].nama<<endl;
		fileout<<orang[i].ktp<<endl; 
		fileout<<orang[i].tujuan<<endl;
		fileout<<orang[i].kelas<<endl;
		fileout<<orang[i].tanggal<<endl;
		fileout<<orang[i].jam<<endl;
		fileout<<orang[i].harga<<endl;
	}
	fileout.close();
}

void input()
{
	banyak=0;
	load();
	cout<< "==========================\n";
	cout<< "   INPUT DATA PEMESANAN\n";
	cout<< "==========================\n";
	cout<< "Masukkan banyaknya tiket: ";cin>>banyak;
	totall=total+banyak;
	for ( int i=total;i<totall;i++)
	{
		orang[i].harga=0;
		cout<<"Nama\t\t\t: "; cin.ignore();getline(cin,orang[i].nama);
		cout<<"Nomor identitas(KTP)\t: "; cin>>orang[i].ktp; 
		cout<<"Tujuan (jakarta/surabaya/bandung)\t : "; cin>>orang[i].tujuan;
		{if (orang[i].tujuan=="jakarta")
		{
			orang[i].harga=orang[i].harga+150000;
		}else if (orang[i].tujuan=="bandung")
		{
			orang[i].harga=orang[i].harga+130000;
		}else if (orang[i].tujuan=="surabaya")
		{
			orang[i].harga=orang[i].harga+150000;
		}}
		cout<<"Kelas (reguler/bisnis/eksekutif)\t : "; cin>>orang[i].kelas;
		{if (orang[i].kelas=="reguler")
		{
			orang[i].harga=orang[i].harga+10000;
		}else if (orang[i].kelas=="bisnis")
		{
			orang[i].harga=orang[i].harga+100000;
		}else if (orang[i].kelas=="eksekutif")
		{
			orang[i].harga=orang[i].harga+200000;
		}}cin.ignore();
		cout<<"Tanggal keberangkatan\t\t\t : ";getline(cin,orang[i].tanggal);
		cout<<"Waktu keberangkatan (pagi/siang/malam)\t : ";cin>>orang[i].waktu;
		{if (orang[i].waktu=="pagi")
		{
			orang[i].jam="08.00";
		}else if (orang[i].waktu=="siang")
		{
			orang[i].jam="13.00";
		}else if (orang[i].waktu=="malam")
		{
			orang[i].jam="20.00";
		}}
		cout<<"-----------------------------"<<endl;
	}
	save();
}

void output()
{
	load();
	cout<< "==========================\n";
	cout<< "   OUTPUT DATA PEMESANAN\n";
	cout<< "==========================\n";
	for ( int i=0;i<total;i++)
	{
		cout<<"Nama\t\t\t: "<<orang[i].nama<<endl;
		cout<<"Nomor identitas(KTP)\t: "<<orang[i].ktp<<endl; 
		cout<<"Tujuan \t\t\t: "<<orang[i].tujuan<<endl;
		cout<<"Kelas \t\t\t: "<<orang[i].kelas<<endl;
		cout<<"Tanggal keberangkatan\t: "<<orang[i].tanggal<<endl;
		cout<<"Waktu keberangkatan\t: "<<orang[i].jam<<endl;
		cout<<"Harga Tiket\t\t: "<<orang[i].harga<<endl;
		cout<<"-----------------------------"<<endl;
	}
}

void searchnama()
{
	found=false;
	load();
	string namaa;
	cout<<"===============================================\n";
	cout<<" Mencari data pemesanan tiket berdasarkan Nama\n";
	cout<<"===============================================\n";
	cout<<"Masukkan Nama Customer : "; cin.ignore(); getline(cin,namaa);
	for (int i=0; i<total; ++i){	
		if(namaa==orang[i].nama)
		{
			found=true;
			cout<<"\nPelanggan dengan nomor nama "<<namaa<<" ditemukan!\n\n";
			cout<<"Nama\t\t\t: "<<orang[i].nama<<endl;
			cout<<"Nomor identitas(KTP)\t: "<<orang[i].ktp<<endl; 
			cout<<"Tujuan \t\t\t: "<<orang[i].tujuan<<endl;
			cout<<"Kelas \t\t\t: "<<orang[i].kelas<<endl;
			cout<<"Tanggal keberangkatan\t: "<<orang[i].tanggal<<endl;
			cout<<"Waktu keberangkatan\t: "<<orang[i].jam<<endl;
			cout<<"Harga Tiket\t\t: "<<orang[i].harga<<endl<<endl;
		}else if (found!=true&&i==total-1)
		{
			cout<<"\nMaaf, Pelanggan dengan nomor nama "<<namaa<<" tidak ditemukan dalam data.\n";
		}
	}
	
}

void searchktp()
{
	load();
	char ktp[17];
	cout<<"=================================================\n";
	cout<<" Mencari data pemesanan tiket berdasarkan No.KTP\n";
	cout<<"=================================================\n";
	cout<<"Masukkan no.ktp yang ingin dicari : ";cin>>ktp;
	for (int i=0; i<total; ++i){
		for (int j = 0; j < 16; j++)
		{
			if (orang[i].ktp[j]==ktp[j])
			{
				found=true;
			}else {found=false; break;}
		}
		if(found)
		{
			cout<<"\nPelanggan dengan nomor KTP "<<ktp<<" ditemukan!\n\n";
			cout<<"Nama\t\t\t: "<<orang[i].nama<<endl;
			cout<<"Nomor identitas(KTP)\t: "<<orang[i].ktp<<endl; 
			cout<<"Tujuan \t\t\t: "<<orang[i].tujuan<<endl;
			cout<<"Kelas \t\t\t: "<<orang[i].kelas<<endl;
			cout<<"Tanggal keberangkatan\t: "<<orang[i].tanggal<<endl;
			cout<<"Waktu keberangkatan\t: "<<orang[i].jam<<endl;
			cout<<"Harga Tiket\t\t: "<<orang[i].harga<<endl<<endl;
			break;
		}else if (i==total-1&&!found)
		{
			cout<<"\nMaaf, Pelanggan dengan nomor KTP "<<ktp<<" tidak ditemukan dalam data.\n";
		} 
	}
}

void sort()
{
	load();
	cout<<"===============================================\n";
	cout<<" Sorting data pemesanan tiket berdasarkan nama\n";
	cout<<"===============================================\n";
	for(int i = 0; i<total-1; i++) 
		{
			for(int j = 0; j<total-1-i; j++) 
			{
				if(orang[j].nama > orang[j+1].nama) {
					temp = orang[j];
					orang[j] = orang[j+1];
					orang[j+1] = temp;}}}
	for ( int i=0;i<total;i++)
	{
		cout<<"Nama\t\t\t: "<<orang[i].nama<<endl;
		cout<<"Nomor identitas(KTP)\t: "<<orang[i].ktp<<endl; 
		cout<<"Tujuan \t\t\t: "<<orang[i].tujuan<<endl;
		cout<<"Kelas \t\t\t: "<<orang[i].kelas<<endl;
		cout<<"Tanggal keberangkatan\t: "<<orang[i].tanggal<<endl;
		cout<<"Waktu keberangkatan\t: "<<orang[i].jam<<endl;
		cout<<"Harga Tiket\t\t: "<<orang[i].harga<<endl;
		cout<<"-----------------------------"<<endl;
	}
}
	

int main()
{
	int pilih,cari;
	char kembali;
	do
	{
		system("cls");
		cout<< "======================================\n";
		cout<< " PEMESANAN TIKET KERETA API ARGO JAYA\n";
		cout<< "  Berangkat dari STASIUN TUGU YOGYA\n";
		cout<< "======================================\n";
		cout<< "1. INPUT DATA \n2. TAMPILKAN DATA \n3. SEARCHING \n4. SORTING DATA \n5. Keluar\n";
		cout<< "PILIH : "; cin>>pilih;
		
		switch (pilih){
			case 1:
				system("cls");
				input();
				break;
			case 2:
				system("cls");
				output();
				break;
			case 3:
				system("cls");
				cout<<"=========================="<<endl;
				cout<<" PENCARIAN DATA PENUMPANG"<<endl;
				cout<<"=========================="<<endl;
				cout<<"Pilih Pencarian dengan Menggunakan"<<endl;
				cout<<"1. Nama"<<endl;
				cout<<"2. No. KTP"<<endl;
				cout<<"Pilih = ";cin>>cari;
				switch (cari)
				{
					case 1:
						system("cls");
						searchnama();
						break;
					case 2:
						system("cls");
						searchktp();
					default:
						break;
				}
				break;
			case 4:
				system("cls");
				sort();
				break;
			case 5:
				return 0;
			default :
				cout<< "Mohon Masukkan pilihan yang benar\n";
		}
		cout<<"\nKembali ke Menu Utama?\n\nY = kembali\nN = keluar\nPilih = ";
		cin>>kembali;
	} while (kembali=='Y'||kembali=='y');
}
	
