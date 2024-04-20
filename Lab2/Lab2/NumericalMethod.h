#pragma once
#include "math.h"
#include "malloc.h"
namespace NumericalMethod {
	extern double* solution;
	extern int sX;
	extern int sY;
	extern int sT;
	extern int x0;
	extern int X;
	extern int y0;
	extern int Y;
	extern int t0;
	extern int T;

	extern double h;
	extern double tau;
	void ThreadAlternatingDirectionMethod(int* matrix, int h, int t);
	double* SplitLine(int a, int b, double h);
	void ExecuteScheme();
	double f(double x, double y, double t);
	double g1();
	double g2(double y, double t);
	double g3();
	double g4(double y, double t);
	double v(double x, double y);
}
