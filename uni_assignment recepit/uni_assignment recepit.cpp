#include <iostream>
using namespace std;
#include <fstream>

struct items
{
	string barang[100];
	int harga[100];
	int stok[100];
}; items item1;

struct pembelian
{
	string barang[100];
	int b_beli[100];
	int hb[100];
	int jumlah;
}; pembelian beli;


int main()
{
	int menu; //mnu pembelian
	int p = 0; //perulangan
	char choice;  //loop
	bool b = true; //loop
	bool b2 = true; //loop 2
	
	
	
		cout << "==============================================[Inventory]======================================\n";
		cout << "Masukkan barang yang ingin dijual (maks 5)\n";

		for (int i = 0; i < 5; i++) //pemasukkan data yang dijual dalam menu
		{
			cout << "Nama barang\t : "; cin >> item1.barang[i];
			cout << "Harga Barang\t : Rp."; cin >> item1.harga[i];
			cout << "Banyak " << item1.barang[i] << " yang ingin dijual\t : "; cin >> item1.stok[i];
		}
		system("CLS");
		while (b2) //pengulangan program dengan menu yang sama
		{
			cout << "==============================================[Penjualan]=======================================\n";

			for (int i = 0; i < 5; i++)
			{
				cout << "NO\t||Nama barang\t \t ||Harga Barang\t \t ||Stok yang tersedia\n";
				cout << i + 1 << ". \t   " << item1.barang[i] << "\t \t \t " << "Rp." << item1.harga[i] << ",00" << endl;
			}
			while (b) //pengulangan pembelian
			{
				cout << "Masukkan nomor barang yang anda ingin pesan\t: "; cin >> menu;
				if (menu > 5 || menu <= 0)
				{
					cout << "invalid";
					exit(0);
				}
				else
				{
					if (menu == 1) //menu
					{
						beli.barang[p] = item1.barang[0];
						cout << "Masukkan banyak " << beli.barang[p] << " anda ingin beli\t: "; cin >> beli.b_beli[0];
						beli.jumlah += item1.harga[0]; beli.hb[p] = item1.harga[0];
						item1.stok[0] -= beli.b_beli[0];
					}
					else if (menu == 2)
					{
						beli.barang[p] = item1.barang[1];
						cout << "Masukkan banyak " << beli.barang[p] << " anda ingin beli\t: "; cin >> beli.b_beli[p];
						beli.jumlah += item1.harga[1]; beli.hb[p] = item1.harga[1];
						item1.stok[1] -= beli.b_beli[1];
					}
					else if (menu == 3)
					{
						beli.barang[p] = item1.barang[2];
						cout << "Masukkan banyak " << beli.barang[p] << " anda ingin beli\t: "; cin >> beli.b_beli[p];
						beli.jumlah += item1.harga[2]; beli.hb[p] = item1.harga[2];
						item1.stok[2] -= beli.b_beli[2];
					}
					else if (menu == 4)
					{
						beli.barang[p] = item1.barang[3];
						cout << "Masukkan banyak " << beli.barang[p] << " anda ingin beli\t: "; cin >> beli.b_beli[p];
						beli.jumlah += item1.harga[3]; beli.hb[p] = item1.harga[3];
						item1.stok[3] -= beli.b_beli[3];
					}
					else if (menu == 5)
					{
						beli.barang[p] = item1.barang[4];
						cout << "Masukkan banyak " << beli.barang[p] << " anda ingin beli\t: "; cin >> beli.b_beli[p];
						beli.jumlah += item1.harga[4]; beli.hb[p] = item1.harga[4];
						item1.stok[4] -= beli.b_beli[4];
					}
					else
					{
						cout << "invalid input"; 
					}
				}
				cout << "Apakah anda ingin memesan lagi?(Y/N)" << endl; //loop pemesanan lagi
				cin >> choice;
				if (choice == 'Y' || choice == 'y') {
					b = true; p++;
				}
				else if (choice == 'N' || choice == 'n') {
					b = false;
				}

			}
			cout << "=========================================================[struk]==========================================================\n"; //struk dalam command line
			cout << "Banyak barang\t||Nama barang\t \t ||Harga Barang\n";
			for (int i = 0; i < p + 1; i++)
			{
				cout << beli.b_beli[i] << "\t \t" << beli.barang[i] << "\t \t \t" << beli.hb[i] << endl;
			}
			cout << "jumlah yang harus dibayar\t: " << "Rp." << beli.jumlah << ",00\n";
			cout << "apakan anda ingin mencetak struk anda?(Y/N)\n";
			char print;
			cin >> print;
			if (print == 'Y' || print == 'y') //print struk dalam file
			{
				ofstream file;
				file.open("receipt.txt", std::ofstream::out | std::ofstream::trunc); 
				file << "=========================================================[struk]==========================================================\n";
				file << "Banyak barang\t||Nama barang\t \t ||Harga Barang\n";
				for (int i = 0; i < 2; i++)
				{
					file << beli.b_beli[i] << "\t \t" << beli.barang[i] << "\t \t \t" << beli.hb[i] << endl;
				}
				file.close();
			}
			else
			{
			}
			
			cout << "Apakah anda ingin menghentikan program?(Y/N)" << endl; //pengulangan dengan item yang sama
			cin >> choice;
			if (choice == 'N' || choice == 'n') {
				b2 = true; system("CLS"); b = true; beli.jumlah = 0;
			}
			else if (choice == 'Y' || choice == 'y') {
				b2 = false;
			}
			
		}
		return 0;
}