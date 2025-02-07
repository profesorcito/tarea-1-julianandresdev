#include <iostream>

using namespace std;

// TODO: Implementar función para calcular la suma de los dígitos de un número
bool sumaDigitos(int numero) {
    int primerDigito = numero / 10;  // Extraer primer digito
    int segundoDigito = numero % 10; // Extraer segundo digito

    int resultadoSumaDigitos = primerDigito + segundoDigito;

    if (resultadoSumaDigitos % 3 == 0) {
        return true;
    } else {
        return false;
    }
}

// TODO: Implementar la lógica para calcular la tarifa
double calcularTarifa(int horas, int dia) {
    const double TARIFA_PRIMERA_HORA = 6.00;
    const double TARIFA_1_A_3 = 4.00;
    const double TARIFA_3_A_5 = 3.00;
    const double TARIFA_FIJA = 22.00;
    const int LIMITE_HORAS = 24;
    const double INCREMENTO_FIN_SEMANA = 1.15;
    const double DESCUENTO_DIGITOS = 0.95;

    // Validar límite de horas
    if (horas > LIMITE_HORAS) {
        return -1;
    }

    double totalPagar = 0.0;
    //double totalTarifa = 0.0;
    // TODO: Implementar la lógica para calcular la tarifa base
    if (horas <= 1) {
        totalPagar = 6;
    } else if (horas > 1 && horas <= 3) {
        totalPagar = 6 + ((horas-1) * 4);
    } else if (horas > 3 && horas <= 5) {
        totalPagar = 6 + (2 * 4) + ((horas - 3) * 3);
    } else {
        totalPagar = TARIFA_FIJA;
    }

    // TODO: Aplicar incremento si es fin de semana
    if (dia == 6 || dia == 7) {
        totalPagar *= INCREMENTO_FIN_SEMANA;
    }
    int totalPagarInt = totalPagar;
    // TODO: Aplicar descuento si la suma de los dígitos es múltiplo de 3
    bool aplicadescuentoDigitos = sumaDigitos(horas);
    if (aplicadescuentoDigitos) {
        totalPagar *= DESCUENTO_DIGITOS;
    }

    return totalPagar;
}

int main() {
    int horas, dia;

    // Leer los valores de entrada
    cin >> horas >> dia;

    double resultado = calcularTarifa(horas, dia);

    if (resultado == -1) {
        cout << "ERROR" << endl;
    } else {
        printf("%.2f\n", resultado);
    }

    return 0;
}