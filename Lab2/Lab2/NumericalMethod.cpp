#include "NumericalMethod.h"
#include "math.h"
namespace NumericalMethod
{
	double* solution = NULL;
	int sX = 0;
	int lX = 0;
	int sY = 0;
	int lY = 0;
	int lT = 0;
	int sT = 0;

	int x0 = 0;
	int X = 0;
	int y0 = 0;
	int Y = 0;
	int t0 = 0;
	int T = 0;

	double h = 0;
	double tau = 0;

	double C1 = 0;
	double C2 = 0;

	double const Eiler = 2.7182818284;
	double const Pi = 2.71828182845904;
	void ThreadAlternatingDirectionMethod(int* matrix, int h, int t)
	{
		int mX = (int)((X - x0) / h);
		int mY = (int)((Y - y0) / h);
		int mT = 2;

		double* bed = (double*)calloc(mX * mY * mT,sizeof(double));



	}

	double* SplitLine(int a, int b, double h, int &size)
	{
		int arrCount = (int)((b - a) / h);
		size = arrCount;
		double* arr = new double[arrCount];

		for (int i = 0; i < arrCount; i++)
		{
			arr[i] = i * h;
		}
		  
		return arr;
	}

	void ExecuteScheme()
	{
		double *sX = SplitLine(x0, X, h, lX);
		double *sY = SplitLine(y0, Y, h, lY);
		double *sT = SplitLine(t0, T, tau, lT);

		//сделать указатель на массив как ссылку
		solution = (double*)calloc(lX * lY * lT, sizeof(double));
		for (int i = 0; i < lX; i++)
			for (int j = 0; j < lY; j++)
				*(solution + lX * i + j) = v(sX[i], sY[j]);

		for (int i = 0; i < lT; i++)
		{
			for (int j = 0; j < lX; j++)
			{
				*(solution + i*lX*lY +j) = g1();
				*(solution + i * (lX-1)*lY + j) = g3();

			}
		}

		for (int i = 0; i < lY; i++)
			for (int j = 0; j < lT; j++)
			{
				*(solution + j * lX) = g2(sY[i],sT[j]);
				*(solution + i * (lX-1)*lY + j * lX) = g4(sY[i], sT[j]);
			}
	}

	double L(double* m, int i, int j, int k)
	{
		return 0;
	}

	double L1(double* m, int i, int j, int k)
	{
		return 0;
	}

	double L2(double *m, int i, int j, int k)
	{
		return *(m + i);
	}
	
	double f(double x, double y, double t)
	{
		return C1 * t * pow(Eiler, -(pow(x - (7 / 8) * X, 2) + pow(y - (3 / 8) * Y, 2)));
	}

	double g2(double y, double t)
	{
		return C2 * t * cos(Pi * y / Y);
	}

	double g4(double y, double t)
	{
		return C2 * t * cos(Pi * y / Y);
	}

	double g1()
	{
		return 0;
	}

	double g3()
	{
		return 0;
	}

	double v(double x, double y)
	{
		return 0;
	}

}
