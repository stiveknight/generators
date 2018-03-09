#include <iostream> 
#include <fstream> 
#include <vector> 
#include <deque> 
#include <string> 
#include <bitset> 
#include <cmath>

using namespace std;

vector <long long> lc(int x0, long long a, long long c, long long m, long long n) {
	vector <long long> ans;
	ans.push_back(x0);
	int xn = x0;
	for (int i = 0; i < n; i++) {
		long long x = (a*xn + c) % m;
		ans.push_back(x);
		xn = x;
	}
	return ans;
}

vector <long long> add(int k, int j, int m, int n) {
	vector <long long> kk = lc(1, 1277, 24749, 117128, j);
	vector <long long> ans;
	int tmp = j;
	for (int i = 0; i < n; i++) {
		int x = (kk[j + i - k] + kk[i]) % m;
		kk.push_back(x);
		ans.push_back(x);
	}
	return ans;
}

deque <int> bin(long long k, int p) {
	deque <int> ans;
	while (k != 0 && ans.size()<p) {
		ans.push_front(k % 2);
		k = k / 2;
	}
	if (ans.size() < p)
		while (ans.size()!=p)
			ans.push_front(0);
	return ans;
}

//deque <int> bin2(long long a1, long long a2, int b1, int b2) {
//	deque <int> d1 = bin(a1, b1);
//	deque <int> d2 = bin(a2, b2);
//	//cout << d1.size() << endl << d2.size();
//	deque <int> ans = d1;
//	for (int i = 0; i < d2.size(); i++)
//		ans.push_back(d2[i]);
//	return ans;
//}

long long ten(vector <int> duo) {
	string str ="";
	for (int i = 0; i < duo.size(); i++) {
		str += duo[i] + '0';
	}
	long long ans = bitset<32>(str).to_ulong();
	return ans;
}

long long ten2(deque <int> duo) {
	string str = "";
	for (int i = 0; i < duo.size(); i++) {
		str += duo[i] + '0';
	}
	long long ans = bitset<32>(str).to_ulong();
	return ans;
}

vector <long long> five_p(int p, int q1, int q2, int q3, int w, long long k, int n) {
	deque <int> bin_p = bin(k, p);
	vector <long long> ans;
	for (int i = 0; i < n; i++) {
		vector <int> tmp;
		for (int j = 0; j < w; j++) {
			tmp.push_back(bin_p.back());
			int b = bin_p[q1] ^ bin_p[q2] ^ bin_p[q3] ^ bin_p[0];
			bin_p.pop_back();
			bin_p.push_front(b);
		}
		ans.push_back(ten(tmp));
	}
	return ans;
}

vector <long long> lfsr(int p, long long x, long long a, int w, int n) {
	deque <int> bin_p = bin(x, p);
	//for (int i = 0; i < bin_p.size(); i++)
	//	cout << bin_p[i];
	//cout << endl;
	deque <int> bin_a = bin(a, p);
	//for (int i = 0; i < bin_a.size(); i++)
	//	cout << bin_a[i];
	vector <long long> ans;
	for (int i = 0; i < n; i++) {
		vector <int> tmp;
		for (int j = 0; j < w; j++) {
			tmp.push_back(bin_p.back());
			int b = bin_p[p - 1] * bin_a[p - 1];
			for (int k = p - 2; k >= 0; k--)
				b = b ^ (bin_p[k] * bin_a[k]);
			bin_p.pop_back();
			bin_p.push_front(b);
		}
		ans.push_back(ten(tmp));
	}
	return ans;
}

int bit(int p, deque <int> &bin_p, deque <int> &bin_a) {
	int b = bin_p[p - 1] * bin_a[p - 1];
	for (int k = p - 2; k >= 0; k--)
		b = b ^ (bin_p[k] * bin_a[k]);
	bin_p.pop_back();
	bin_p.push_front(b);
	return b;
}


vector <long long> nfsr(int l1, long long x1, long long a1, int l2, long long x2, long long a2, int l3, long long x3, long long a3, int w, int n) {
	//l1 l2 l3 должны быть взаимно простыми
	deque <int> bin_p1 = bin(x1, l1);
	deque <int> bin_a1 = bin(a1, l1);
	deque <int> bin_p2 = bin(x2, l2);
	deque <int> bin_a2 = bin(a2, l2);
	deque <int> bin_p3 = bin(x3, l3);
	deque <int> bin_a3 = bin(a3, l3);
	vector <long long> ans;
	for (int i = 0; i < n; i++) {
		vector <int> tmp;
		for (int j = 0; j < w; j++) {
			int xx1 = bit(l1, bin_p1, bin_a1);
			int xx2 = bit(l2, bin_p2, bin_a2);
			int xx3 = bit(l3, bin_p3, bin_a3);
			int b = (xx1*xx2) ^ (xx2*xx3) ^ xx3;
			tmp.push_back(b);
		}
		ans.push_back(ten(tmp));
	}
	return ans;
}

deque <int> left(deque <int> a, int k) {
	for (int i = 0; i < k; i++) {
		a.pop_front();
		a.push_back(0);
	}
	return a;
}

deque <int> rigth(deque <int> a, int k) {
	for (int i = 0; i < k; i++) {
		a.pop_back();
		a.push_front(0);
	}
	return a;
}
vector <long long> mt(int w, int r, int p, int q, long long x, long long a, long long f, int u, int s, int t, int l, long long b, long long c, int n) {
	//q<p
	//w>r
	vector <deque<int>> X;
	vector <deque<int>> Z;
	deque <int> tmp = bin(x, w);
	X.push_back(tmp);
	deque <int> A = bin(a, w);
	deque <int> F = bin(f, w);
	deque <int> B = bin(b, w);
	deque <int> C = bin(c, w);

	for (int i = 0; i < p; i++) { //генерация p штук X
		tmp.clear();
		for (int j = 0; j < w; j++) {
			int t = (X[i][j] * F[j]) ^ X[i][(j+2)%w];
			tmp.push_back(t);
		}
		X.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		//конкатенация
		deque <int> y;
		for (int j = 0; j < w - r; j++)
			y.push_back(X[i][j]);
		for (int j = w - r; j < X[i + 1].size(); j++)
			y.push_back(X[i + 1][j]);

		y = rigth(y, 1);
		for (int j = 0; j < w; j++)
			y[j] = X[q][j] ^ y[j];
		if (y.back() == 1)
			for (int j = 0; j < w; j++)
				y[j] = y[j] ^ A[j];
		X.push_back(y);

		//вычисление Z
		deque <int> y1 = rigth(y, u);
		for (int j = 0; j < w; j++)
			y[j] = y[j] ^ y1[j];
		y1 = left(y, s);
		for (int j = 0; j < w; j++) 
			y[j] = y[j] ^ (y1[j] * B[j]);
		y1 = left(y, t);
		for (int j = 0; j < w; j++)
			y[j] = y[j] ^ (y1[j] * C[j]);
		y1 = rigth(y, l);
		for (int j = 0; j < w; j++)
			y[j] = y[j] ^ y1[j];
		Z.push_back(y);
	}

	vector <long long> ans;
	for (int i = 0; i < Z.size(); i++) 
		ans.push_back(ten2(Z[i]));

	return ans;
}

int kk(deque <int> K, int k) {
	deque <int> tmp = rigth(K, (k * 8));
	for (int i = 0; i < tmp.size() - 8; i++)
		tmp[i] = 0;
	return ten2(tmp);
}

vector <long long> rc4(long long k, int n) {
	deque <int> K = bin(k, 256);
	vector <long long> s;
	for (int i = 0; i < 256; i++)
		s.push_back(i);
	int j = 0;
	for (int i = 0; i < 256; i++) {
		j = (j + s[j] + kk(K, i)) % 256;
		swap(s[i], s[j]);
	}
	vector <long long> ans;
	int i = 0; j = 0;
	for (int e = 0; e < n; e++) {
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;
		swap(s[i], s[j]);
		int t = (s[i] + s[j]) % 256;
		
		ans.push_back(s[t]);
	}
	return ans;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

long long powModN(long long x, int y, long long n) {
	long long result = 1;
	for (int i = 0; i < y; i++) {
		result = (result * x) % n;
	}
	return result;
}

vector <long long> rsa(long long p, long long q, int w, int n) {
	long long N = p*q;
	long long f = (p - 1)*(q - 1);
	int e = 1;
	for (int i = 2; i < f; i++) {
		if (gcd(f, i) == 1) {
			e = i;
			break;
		}
	}
	long long x0 = N/2+3;
	vector <deque<int>> Z;
	for (int i = 0; i < n; i++) {
		deque <int> tmp;
		for (int j = 0; j < w; j++) {

			x0 = powModN(x0, e, N) % N;

			deque<int> X0 = bin(x0, w);
			tmp.push_back(X0.back());
		}
		Z.push_back(tmp);
	}

	vector <long long> ans;
	for (int i = 0; i < Z.size(); i++)
		ans.push_back(ten2(Z[i]));

	return ans;
}

vector <long long> test_ferma() {
	vector <long long> simple;
	for (int p = 500; p < 2000; p++) {
		for (int a = 1; a < p; a++) {
			if (gcd(a, p) == 1) {
				if (!((powModN(a, p - 1, p)) % p == 1))
					break;
			}
		}
		simple.push_back(p);
	}
	return simple;
}

vector <long long> bbs(int w, int n) {
	//p q простые сравнимые с 3 по модулю 4
	//(p-3)%4==0 (q-3)%4==0 
	vector <long long> simple = test_ferma();
	long long p, q;
	for (int i = 0; i < simple.size(); i++) {
		if ((simple[i] - 3) % 4 == 0) {
			p = simple[i];
			for (int j = i + 1; j < simple.size(); j++)
				if ((simple[j] - 3) % 4 == 0) {
					q = simple[j];
					break;
				}
			break;
		}
	}

	long long N = p*q;
	long long x = 1;
	for (long long i = 10; i < N * 2; i++) {
		if (gcd(N, i) == 1) {
			x = i;
			break;
		}
	}
	long long x0= powModN(x, 2, N) % N;
	vector <deque<int>> Z;
	for (int i = 0; i < n; i++) {
		deque <int> tmp;
		for (int j = 0; j < w; j++) {
			x0= powModN(x0, 2, N) % N;
			deque<int> X0 = bin(x0, w);
			tmp.push_back(X0.back());
		}
		Z.push_back(tmp);
	}
	vector <long long> ans;
	for (int i = 0; i < Z.size(); i++)
		ans.push_back(ten2(Z[i]));

	return ans;
}


int main() {
	//vector <long long> ans = lc(1, 1277, 24749, 117128, 10000);
	//vector <long long> ans = add(38, 89, 3243, 10000);
	//vector <long long> ans = five_p(40, 8, 11, 30, 15, 11675432246, 1000);
	//vector <long long> ans = lfsr(40, 45841782953, 48387843145, 11, 1000);
	//vector <long long> ans = nfsr(31, 4862922, 3675643, 79, 3535938, 5322133, 23, 589327, 88733, 11, 1000);
	//vector <long long> ans = mt(15, 7, 20, 19, 36563143, 25345624, 4825411, 12, 5, 2, 7, 432556433, 25345324, 1000);
	//vector <long long> ans = rc4(475744824463622, 1000);
	//vector <long long> ans = rsa(1583, 1847, 11, 1000);
	vector <long long> ans = bbs(11, 1000);
	for (int i = 0; i < ans.size(); i++) {
		//if (ans[i]<100)
		cout << ans[i] << ' ';
	}
	//lc(7, 8, 9, 10, 100);
	system("pause");
	return 0;
}