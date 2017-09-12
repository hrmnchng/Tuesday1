//***************************************************************************
// 12345 - Lab 1.cpp by Galal Hassan (C) 2017 All Rights Reserved.
//
// Lab 1 submission.
//
// Description:

// HErman CHUNG

// Click run to see the results.
//
//*****************************************************************************

#include <windows.h>
#include <DirectXMath.h>
#include <iostream>
#include <ctime>

using namespace std;
using namespace DirectX;

ostream& XM_CALLCONV operator << (ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << "," << dest.y << ","<<  dest.z <<"," <<dest.w << ")";
	return os;
}

ostream& XM_CALLCONV operator << (ostream& os, FXMMATRIX m)
{
	for (int x = 0; x < 4; ++x)
	{
		os << XMVectorGetX(m.r[1])<< "\t";
		os << XMVectorGetY(m.r[1]) << "\t";
		os << XMVectorGetZ(m.r[1]) << "\t";
		os << XMVectorGetW(m.r[1]);
		os << endl;
	}
	return os;
}

int main()
{

	if (!XMVerifyCPUSupport())
	{
	
	cout << "directx   not supported" << endl;
	
	}
	char q; 

	srand(time(NULL));

	

	float a = rand() % 9;
	float b = rand() % 9;
	float c = rand() % 9;
	float d = rand() % 9;
	float e = rand() % 9;
	float f = rand() % 9;
	float g = rand() % 9;
	float h = rand() % 9;
	float i = rand() % 9;
	float j = rand() % 9;
	float k = rand() % 9;
	float l = rand() % 9;
	float m = rand() % 9;
	float n = rand() % 9;
	float o = rand() % 9; 
	float p = rand() % 9;

	XMMATRIX matrix(
		a, b, c, d,
		e, f, g, h,
		i, j, k, l,
		m, n, o, p
		);

	XMMatrixIdentity();
	XMVECTOR determinate = XMMatrixDeterminant(matrix);
	XMMATRIX transpose = XMMatrixTranspose(matrix);
	XMMATRIX inverse1 = XMMatrixInverse(&determinate, matrix);

	XMMATRIX inverse2 = XMMatrixInverse(&determinate, matrix);;
	
	
	cout << "Matrix:\n" << matrix << endl;
	cout << "determinate:\n" << determinate << endl;
	cout << "transpose:\n" << transpose << endl;
	cout << "inverse1:\n" << inverse1 << endl;;
	cout << "inverse2:\n" << inverse2 << endl;;

	cin >> q;
}