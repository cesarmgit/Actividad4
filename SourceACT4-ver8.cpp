#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL,"es_ES.UTF-8");

    int numArticulo , diaVenta , cantidadArtVendido;
    float precioCosto , precioVenta;
    int ventasPrimeraQuincena , ventasSegundaQuincena , ventasPrimeraSemana , cantidadTotalVentas , ventasArt5Dia16;
    float ganancia , gananciaMaxima;
    int numArticuloActivo , articuloMaximaGanancia;
    float porcentajePrimeraSemana;

    ventasPrimeraQuincena = 0;
    ventasSegundaQuincena = 0;
    ventasPrimeraSemana = 0;
    cantidadTotalVentas = 0;
    ventasArt5Dia16 = 0;
    gananciaMaxima = 0;

    cout << "Ingrese las ventas del mes:" << endl << endl;
    cout << "Número de artículo (1 a 10, 0 para finalizar): ";
    cin >> numArticulo;

    while (numArticulo != 0) {

        numArticuloActivo = numArticulo;

        while (numArticulo == numArticuloActivo) {

        cout << "Día de venta (1 a 31): ";
        cin >> diaVenta;
        cout << "Cantidad de artículos vendidos: ";
        cin >> cantidadArtVendido;
        cout << "Precio de costo: ";
        cin >> precioCosto;
        cout << "Precio de venta: ";
        cin >> precioVenta;
        cout << endl;

        cantidadTotalVentas++;

        ganancia = (precioVenta - precioCosto) * cantidadArtVendido;

            if (ganancia > gananciaMaxima) {
                gananciaMaxima = ganancia;
                articuloMaximaGanancia = numArticulo;
            }

            if (diaVenta < 16) {
                ventasPrimeraQuincena += cantidadArtVendido;
            } else {
                ventasSegundaQuincena += cantidadArtVendido;
            }

            if (diaVenta < 8) {
                ventasPrimeraSemana++;
            }

            if (numArticulo == 5 && diaVenta == 16) {
                ventasArt5Dia16 += cantidadArtVendido;
            }
        cout << "Número de artículo (1 a 10, 0 para finalizar): ";
        cin >> numArticulo;
        }
    }

    porcentajePrimeraSemana = (float)ventasPrimeraSemana / cantidadTotalVentas * 100;

    cout << endl;
    cout << "-------------------------------------------------------------------------" << endl << endl;
    cout << "Resultados:" << endl;
    cout << "Artículo con mayor ganancia: " << articuloMaximaGanancia << endl;
    cout << "Total de artículos vendidos en la primera quincena: " << ventasPrimeraQuincena << endl;
    cout << "Total de artículos vendidos en la segunda quincena: " << ventasSegundaQuincena << endl;
    cout << "Porcentaje de ventas en la primera semana: " << porcentajePrimeraSemana << "%" << endl;

    if (ventasArt5Dia16 > 0) {
        cout << "Cantidad de ventas del artículo 5 el día 16: " << ventasArt5Dia16 << endl;
    } else {
        cout << "No se registraron ventas del artículo 5 el día 16." << endl;
    }

    cout << endl;
    cout << "-------------------------------------------------------------------------" << endl << endl;

    return 0;
}
