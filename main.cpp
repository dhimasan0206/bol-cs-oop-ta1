#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Pelanggan {
    private:
        int nomor;
        string nama;
        string alamat;
        int penggunaan;
        
    public:
        Pelanggan(int n1, string n2, string a, int p) {
            nomor = n1;
            nama = n2;
            alamat = a;
            penggunaan = p;
        }
        
        void setNomor(int n) {
            nomor = n;
        }
        
        int getNomor() {
            return nomor;
        }
        
        void setNama(string n) {
            nama = n;
        }
        
        string getNama() {
            return nama;
        }
        
        void setAlamat(string a) {
            alamat = a;
        }
        
        string getAlamat() {
            return alamat;
        }
        
        void setPenggunaan(int p) {
            penggunaan = p;
        }
        
        int getPenggunaan() {
            return penggunaan;
        }
        
        float getBiaya() {
            if (penggunaan <= 60) {
                // cout << penggunaan << " * $2.00 = $";
                return penggunaan * 2.00;
            } else {
                // cout << "(60 * $1.75) + (" << (penggunaan-60) << " * $1.50) = $";
                return (60 * 1.75) + ((penggunaan - 60) * 1.50);
            }
        }
};

int main() {
    // Create a text string, which is used to output the text file
    string myText;
    
    // Read from the text file
    ifstream MyReadFile("pelanggan.csv");

    vector<vector<string>> content;
	vector<string> row;
	string line, word;
    
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, line)) {
        row.clear();

        stringstream str(line);

        while (getline (str, word, ',')) {
            row.push_back(word);
        }
        
        content.push_back(row);
    }

    // Close the file
    MyReadFile.close();

    int totalPelanggan;
    float totalTerhutang;

    for(int i=1;i<content.size();i++)
	{
		int nomor;
        int penggunaan;

        stringstream ss1;
        ss1 << content[i][0];
        ss1 >> nomor;

        stringstream ss2;
        ss2 << content[i][3];
        ss2 >> penggunaan;

        Pelanggan pelanggan (nomor, content[i][1], content[i][2], penggunaan);
        cout << pelanggan.getNomor() << " " << pelanggan.getNama() << " " << pelanggan.getAlamat() << " " << pelanggan.getPenggunaan() << " $" << pelanggan.getBiaya() << "\n";
        totalPelanggan = totalPelanggan + 1;
        totalTerhutang = totalTerhutang + pelanggan.getBiaya();
        cout << "$" << totalTerhutang << "\n";
	}

    cout<<"Total pelanggan = " << totalPelanggan << "\n";
    cout<<"Total yang terhutang = $" << totalTerhutang << "\n";
}