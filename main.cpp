#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 20;

void copia();

class PagedArray {
private:
    int arr[SIZE];

public:
    PagedArray() {
        ifstream file("archivo_resultado.txt");
        string data = "";
        register int i;
        for(i = 0; i < SIZE; i++) {
            getline(file, data,',');
            arr[i] = atoi(data.c_str());;
        }
        file.close();
        ;   }

        int &operator[](int i) {
        if( i > SIZE ) {
            cout << "Index out of bounds" <<endl;
            // return first element.
            return arr[0];
        }

        return arr[i];
    }
};


void copia(){

    const string nfichero = "archivo.txt";
    const string nfsalida = "archivo_resultado.txt";
    char letra;
    ifstream fichero;
    ofstream salida;
    fichero.open(nfichero.c_str());
    salida.open(nfsalida.c_str());
    if(!fichero.fail()){
        fichero.get(letra);
        while(!fichero.eof()){
            salida << letra;
            fichero.get(letra);
        }
        fichero.close();
        salida.close();
    }

}

int main() {
    PagedArray A;

    copia();

    cout << "Value of A[2] : " << A[2] <<endl;
    cout << "Value of A[5] : " << A[5]<<endl;
    cout << "Value of A[12] : " << A[12]<<endl;

    return 0;
}
