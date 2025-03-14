#include <iostream>
#include <vector>
#include <algorithm>


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para calcular el cambio usando Algoritmo Avaro
vector<int> cambioAvaro(vector<int>& denominaciones, int cambio) {
    int n = denominaciones.size();
    vector<int> resultado(n, 0);
    
    for (int i = 0; i < n; i++) {
        while (cambio >= denominaciones[i]) {
            cambio -= denominaciones[i];
            resultado[i]++;
        }
    }
    
    return resultado;
}

int main() {
    int N;
    cout << "Ingrese el número de denominaciones disponibles: ";
    cin >> N;
    vector<int> denominaciones(N);
    
    cout << "Ingrese los valores de las denominaciones (una por línea):\n";
    for (int i = 0; i < N; i++) {
        cin >> denominaciones[i];
    }
    
    int P, Q;
    cout << "Ingrese el precio del producto: ";
    cin >> P;
    cout << "Ingrese el monto con el que se paga: ";
    cin >> Q;
    
    int cambio = Q - P;
    if (cambio < 0) {
        cout << " Falta dinero para pagar este producto" << endl;
        return 0;
    }
    
    cout << "El cambio a devolver es: " << cambio << "\n";
    
    // Ordenamos las denominaciones en orden descendente para el algoritmo avaro
    sort(denominaciones.rbegin(), denominaciones.rend());
    
    // Calcular el cambio con algoritmo avaro
    vector<int> resultadoAvaro = cambioAvaro(denominaciones, cambio);
    
    cout << "Cambio total: \n";
    for (int i = 0; i < N; i++) {
        cout << resultadoAvaro[i] << " moneda(s) de " << denominaciones[i] << endl;
    }
    
    return 0;
}
