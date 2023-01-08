#include <iostream>

using namespace std;

string judulBuku[11]={"satu", "dua", "tiga", "empat", "lima", "enam", "tuju", "delapan", "sembilan", "sepuluh","sebelas"};
int panjangArray=sizeof(judulBuku)/sizeof(judulBuku[0]);
int arraykodeBuku[11]={6, 3, 4, 2, 7, 1, 5, 9, 8, 10, 11};

struct tree{
    int kodeB;
    string namaB;
    tree *kiri;
    tree *kanan;
};

tree *akar;

tree* BuatKeyBaru(int i){
    tree *newkey;
    
    newkey = new tree();
    // Pada C++ boleh menggunakan perintah new, namun untuk syntax malloc yang sebenarnya seperti berikut
    // newkey = (struct tree*)malloc(sizeof(struct tree));
    
    newkey->namaB=judulBuku[i];
    newkey->kodeB=arraykodeBuku[i];
    newkey->kiri=NULL;
    newkey->kanan=NULL;
    return newkey;
}

void MasukkanKeyBaru(int i, tree *tempcon){
    if(akar==NULL){
        tree *newnode;
        newnode = new tree();
        newnode = BuatKeyBaru(i);
        akar = newnode;
        cout<<"data sukses diinput!\n\n";
    }
    else{
 if(arraykodeBuku[i]<tempcon->kodeB){
            if(tempcon->kiri!=NULL){
                tempcon=tempcon->kiri;
                MasukkanKeyBaru(i, tempcon);
            }else{
                tree *newleaf;
                newleaf = new tree();
                newleaf = BuatKeyBaru(i);
                tempcon->kiri = newleaf;
            }
        }else if(arraykodeBuku[i]>=tempcon->kodeB){
            if(tempcon->kanan!=NULL){
                tempcon=tempcon->kanan;
                MasukkanKeyBaru(i, tempcon);
            }else{
                tree *newleaf;
                newleaf = new tree();
                newleaf = BuatKeyBaru(i);
                tempcon->kanan = newleaf;
            }
        }
    }
}

void TampilkanTreeBiasa(tree *control){
    cout<<"Judul :"<<control->namaB<<"\t";
    cout<<"Kode: "<<control->kodeB;
    cout<<"\n";
    if(control->kiri!=NULL){
        TampilkanTreeBiasa(control->kiri);
    }
    if(control->kanan!=NULL){
        TampilkanTreeBiasa(control->kanan);
    }
}

void TampilkanTreeAscending(tree *control){
    if(control->kiri!=NULL){
        TampilkanTreeAscending(control->kiri);
    }
    
    cout<<"Nama buku: "<<control->namaB<<" \n";
    cout<<"Kode buku: "<<control->kodeB<<" \n\n";
    
    if(control->kanan!=NULL){
        TampilkanTreeAscending(control->kanan);
}
}

int main()
{
    int pilih1;
    int data;
    int pencarian;
    int cari;
    
    menuutama:
    cout<<"\nMenu Utama\n";
    cout<<"1.Input data\n";
    cout<<"2.Tampilkan data buku tanpa diurut\n";
    cout<<"3.Tampilkan data buku diurut dari nilai terkecil\n";
    cout<<"Pilihan: ";
    cin>>pilih1;
    
    switch(pilih1){
        
        case 1:
        for(int i=0; i<panjangArray; i++){
            MasukkanKeyBaru(i, akar);
        }
        goto menuutama;
        break;
        
        case 2:
        cout<<"Data buku: \n";
        if(akar==NULL){
            cout<<"penyimpanan kosong, belum ada data\n";
        }
        else{
            TampilkanTreeBiasa(akar);
        }
        goto menuutama;
        break;
        
        case 3:
        cout<<"Data buku: \n";
        if(akar==NULL){
            cout<<"penyimpanan kosong, belum ada data\n";
        }
        else{
            TampilkanTreeAscending(akar);
        }
goto menuutama;
        break;
        
        default:
        cout<<"\nFormat anda tidak sesuai";
        return 0;
    }

    return 0;
}
