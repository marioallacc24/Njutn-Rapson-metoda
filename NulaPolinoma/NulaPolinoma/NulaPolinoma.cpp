//Newton-Raphson Method
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double f(double x);
double f(double x)
{
	double a = pow(x, 3.0) - x - 11.0;    //Ovde napisati kubnu funkciju
	return a;
}
double fprime(double x);
double fprime(double x)
{
	double b = 3 * pow(x, 2.0) - 1.0;        //Prvi izvod funkcije
	return b;
}
int main()
{
	double x, x1, e, fx, fx1;
	cout.precision(4);        //podesavanje preciznosti
	cout.setf(ios::fixed);
	cout << "Pretpostavljna vrednost: ";    //Uneti predpostavljnu vrednost nule
	cin >> x1;
	cout << "Unestie preciznost u obliku .001: ";    //Unos preciznosti
	cin >> e;
	fx = f(x);
	fx1 = fprime(x);
	cout << "x{i}" << "    " << "x{i+1}" << "        " << "|x{i+1}-x{i}|" << endl;

	do
	{
		x = x1;                //podešavanje x na poslednju izračunatu vrednost xl
		fx = f(x);            //u fx upisujemo pojednostavljenju verziju funkcije
		fx1 = fprime(x);            //u fxl upisujemo pojednostavljenu verziju prvog izvoda
		x1 = x - (fx / fx1);            // računarmo xl - nulu
		cout << x << "     " << x1 << "           " << abs(x1 - x) << endl; //posle svakog prolaza ispusjjemo stanje za taj prolaz
	} while (fabs(x1 - x) >= e);            //sve dok je izraz veći od preciznosti petlja se vrti
	cout << "Nula funkcije je: " << x1 << endl; //ispisujemo krajnje rešenje
	return 0;
}
