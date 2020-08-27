#include <iostream>

using namespace std;

int main()
{
    int  preciores = 80, preciocerdo = 60, grasares = 20, grasacerdo = 32;
    float cantlibras=0, cantres=0, cantcerdo=0 ,preciototal=0, precioplibra =0;

    cout << "Digite la canditdad de libras que desea ligar para el albondigon : ";
    cin >> cantlibras;
    cout << endl;

    cantcerdo = (0.05*cantlibras) / 0.12;
    cantres = cantlibras - cantcerdo;
    precioplibra = preciores * (cantres/cantlibras) + preciocerdo * (cantcerdo/cantlibras);
    preciototal = preciores * cantres + preciocerdo * cantcerdo;
    cout << "Cantidad de libras de Res es: " << cantres << endl;
    cout << "Cantidad de libras de Cerdo es: " << cantcerdo << endl;
    cout << "Cantidad de libra de Res en % " << (cantres/cantlibras)*100 << endl;
    cout << "Cantidad de libra de Cerdo en % " << (cantcerdo/cantlibras)*100 << endl;
    cout << "El precio total a pagar es: " << preciototal << endl;
    cout << "El precio por libra a pagar es: " << precioplibra;
    cout << endl;

}
