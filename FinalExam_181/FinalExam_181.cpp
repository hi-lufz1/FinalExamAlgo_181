#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string nama;
	int jumlah;
	string tipe;
	Node* next;

	Node(string nama, int jumlah, string tipe) {
		this->nama = nama;
		this->jumlah = jumlah;
		this->tipe = tipe;
		next = NULL;
	}
};

class ManajemenProduk {
private:
	Node* head;

public:
	ManajemenProduk() {
		head = NULL;
	}

	void tambahProduk() {
		string nama;
		int jumlah;
		string tipe;
		cout << "========== TAMBAH PRODUK ==========" << endl;
		cout << "Nama Produk : ";
		getline(cin, nama);
		cout << "Jumlah Produk : ";
		cin >> jumlah;
		cin.ignore(); // Membersihkan buffer input
		cout << "Tipe Produk : ";
		getline(cin, tipe);
		Node* newNode = new Node(nama, jumlah, tipe);
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newNode;
		}

		cout << "Produk berhasil ditambahkan!" << endl;
	}

	void tampilkanSemuaProduk() {
		cout << "========== SEMUA DATA PRODUK ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			Node* current = head;
			while (current != NULL) {
				cout << "Nama Produk : " << current->nama << endl;
				cout << "Jumlah Produk : " << current->jumlah << endl;
				cout << "Tipe Produk : " << current->tipe << endl;
				cout << endl;
				current = current->next;
			}
		}
	}
	void cariProdukByNama() {
		cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			string targetNama;
			cout << "Nama Produk yang dicari: ";
			getline(cin, targetNama);
			Node* current = head;
			int posisi = 0;
			while (current != NULL) {
				posisi++;
				// lINEAR SEARCH
				if (current->nama == targetNama) {
					cout << "Produk " << targetNama << "DITEMUKAN pada posisi" << posisi << endl;
					cout << "Nama Produk : " << current->nama << endl;
					cout << "Jumlah Produk : " << current->jumlah << endl;
					cout << "Tipe Produk : " << current->tipe << endl;
					cout << endl;
					return;
				}

				current = current->next;
			}
			if (current == NULL) {
				cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" <<
					endl;
			}
		}
	}
	
	void algorithmaSortByJumlahProduk() {
		if (head == NULL || head->next == NULL) {
			return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
		}
		Node* current;
		Node* last = NULL;
		current = head;
		
		bool  swapp;
		
	//bubble sort
		do {
			swapp = false;
			current = head;

			while (current->next != last) {
				if (current->jumlah > current->next->jumlah) {
					
					string tempnama = current->nama;
					int tempjumlah = current->jumlah;
					string temptipe = current->tipe;

					current->nama = current->next->nama;
					current->jumlah = current->next->jumlah;
					current->tipe = current->next->tipe;

					current->next->nama = tempnama;
					current->next->jumlah = tempjumlah;
					current->next->tipe = temptipe;
					swapp = true;
				}
				current = current->next;
			}
			last = current;

		} while (swapp);

		cout << "Produk berhasil diurutkan berdasarkan jumlah!" << endl;
		cout << "========== DATA PRODUK BERDASARKAN JUMLAH ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			Node* current = head;
			while (current != NULL) {
				cout << "Nama Produk : " << current->nama << endl;
				cout << "Jumlah Produk : " << current->jumlah << endl;
				cout << "Tipe Produk : " << current->tipe << endl;
				cout << endl;
				current = current->next;
			}
		}
	}

	
	
};
int main() {
	ManajemenProduk manajemenProduk;
	int pilihan;
	do {
		cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
		cout << "1. Tambah Produk" << endl;
		cout << "2. Tampilkan Semua Produk" << endl;
		cout << "3. Cari Produk berdasarkan Nama" << endl;
		cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan:";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			manajemenProduk.tambahProduk();
			break;
		case 2:
			manajemenProduk.tampilkanSemuaProduk();
			break;
		case 3:
			manajemenProduk.cariProdukByNama();
			break;
		case 4:
			manajemenProduk.algorithmaSortByJumlahProduk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}


// 2. linear search dan bubble sort dengan single link list
// 3 Jika REAR sudah sampai index terakhir maka referensikan FRONT ke index 0 (menjadi bentuk circular)
// 4. saat perlu menggunakan sesuatu yang terakhir dimasukan(input) maka itu juga yang akan pertama kali dilakukan contoh undo dan redo pada ms word
// last in first out
//5. a. 5
//b pre order :
//1. baca root
//2. baca subtree paling kiri
//3. baca subtree paling kanan
//50,48,30,20,15,25,32,31,35, 70, 65, 67,66,69,90,98,94,99 
	
