// Victoria Levacic Tkalec
// LV10

#include <iostream>
#include <vector>
using namespace std;

int brojProlaznihIter (const vector<int>& v, int p)
{
	int b = 0;
	for (int i = 0; i < v.size();i++) {	if (v[i] >= p) b++; }
	return b;
}

int brojProlaznihRek(const vector<int>& v, int p, int n)
{
	n--;
	if (n == -1) return 0;
	if (v[n] >= p) return brojProlaznihRek(v, p, n) + 1;
	return brojProlaznihRek(v, p, n);
}

int main()
{
	int n, p, i; cin >> n >> p;
	vector<int>v;
	for (int i = 0; i < n;i++)
	{
		int broj; cin >> broj;
		v.push_back(broj);
	}
	cout << "PROLAZ int " << brojProlaznihIter(v, p) << endl;
	cout << "PROLAZ rek " << brojProlaznihRek(v, p, n) << endl;
}

// A
// Za vektor{ 42, 58, 35 } i prag p = 50: koliko elemenata zadovoljava uvjet ? 1
// Napiši što vraća rekurzivni poziv kada je indeks jednak veličini vektora : 0
// Koji se argument mijenja pri svakom sljedećem pozivu ?  indeks


// B
// Test			n, p i rezultati		Očekivano		Iter. i Rek.
// 1	  7 50 | 42 58 58 35 61 47 61		4				4
// 2		  4 70 | 70 70 70 70 			4				4
// 3		 5 80 | 10 20 30 40 50			0				0
// 4			   1 40 | 40 				1				1
// 5               1 40 | 39 				0				0
// 6 

// C
// Pitanje								Iterativno rješenje		Rekurzivno rješenje
// Koliko se elemenata obrađuje?				n						n
// Vremenska složenost O(…)?				   O(n)				       O(n)
// Dodatna memorija O(…)?					   O(1)					   O(n)
// Što se događa s vrlo velikim n?							prekoračiti veličinu steka

