//#include<iostream>
//using namespace std;
//
//
//int fact(int n) {
//
//	if (n == 1 || n == 0)return 1;
//	else
//	{
//		return(n * fact(n - 1));
//	}
//
//}
//
//int prim(int v, int i = 2) {
//	int y = 2;
//	if (v <= 2) return false;
//	if (v % i == 0) return false;
//	if (i * i > v) return true;
//
//	return prim(v, i + 1);
//
//
//}
//
//int fibonnaci(int y) {
//	if ((y == 1) || (y == 0)) {
//		return(y);
//	}
//	else {
//		return(fibonnaci(y - 1) + fibonnaci(y - 2));
//	}
//}
//
//int powt(int p, int n) {
//
//	if (n != 0)return(p * powt(p, n - 1));
//
//}
//
//
//int main() {
//
//	//int a;
//	//cin >> a;
//	//cout << fact(a) << endl;
//	//------------------------------------
//
//
//	int a;
//	cin >> a;
//	if (prim(a)) {
//		cout << "prim" << endl;
//	}
//	else cout << "inte prime" << endl;
//	//------------------------------------
//		//int y, i = 0;
//		//cout << "Enter the number of terms of series : ";
//		//cin >> y;
//		//cout << "\nFibonnaci Series : ";
//		//while (i < y) {
//		//	cout << " " << fibonnaci(i);
//		//	i++;
//		//}
//	//------------------------------------
//
//
//		//int a, b, c;
//		//cin >> a >> b;
//		//c = powt(a, b);
//		//cout << c << endl;
//
//	//------------------------------------
//
//	return 0;
//}
//
