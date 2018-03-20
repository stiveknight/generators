#include <iostream> 
#include <fstream> 
#include <vector> 
#include <deque> 
#include <string> 
#include <bitset> 
#include <cmath>
#include <map>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int gen_int(int a, int b) {
	srand(time(0));
	return a + rand() % b;
}
long long gen_long(long long a, long long b) {
	srand(time(0));
	return a + rand() % b;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

vector <long long> lc(map <string, string> params) {
	int x0;
	long long a, c, m, n;
	if (params.find("x0")!= params.end())
		x0 = stoi(params["x0"]);
	else x0 = gen_int(1, 20);
	while (x0 > 50 && x0 < 0) {
		cout << "Выберете меньшее x0" << endl;
		cout << "x0 = "; cin >> x0; cout << endl;
	}
	if (params.find("a") != params.end())
		a = stoi(params["a"]);
	else a = gen_long(1000, 5000);

	if (params.find("c") != params.end())
		c = stoi(params["c"]);
	else c = gen_long(10000, 100000);

	if (params.find("m") != params.end())
		m = stoi(params["m"]);
	else m = gen_long(10000, 900000);

	if (params.find("n") != params.end())
		n = stoi(params["n"]);
	else n = 10000;

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

vector <long long> add(map <string, string> params) {
	int k, j;
	long long m, n;
	if (params.find("k") != params.end())
		k = stoi(params["k"]);
	else k = gen_int(1, 2000);
	if (params.find("j") != params.end())
		j = stoi(params["j"]);
	else j = gen_int(k+1, 6000);
	
	while (k >= j) {
		cout << "Неверно заданы k, j (k должно быть меньше j)" << endl;
		cout << "k = "; cin >> k; cout << endl;
		cout << "j = "; cin >> j; cout << endl;
	}

	if (params.find("m") != params.end())
		m = stoi(params["m"]);
	else m = gen_long(1000, 15000);

	if (params.find("n") != params.end())
		n = stoi(params["n"]);
	else n = 10000;

	vector <long long> kk;
	for (int i = 0; i < j; i++) 
		kk.push_back(gen_long(1, 1000000));
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

vector <long long> five_p(map <string, string> params) {
	int p, q1, q2, q3, w;
	long long k, n;
	if (params.find("p") != params.end())
		p = stoi(params["p"]);
	else p = gen_int(20, 60);

	if (params.find("q1") != params.end())
		q1 = stoi(params["q1"]);
	else q1 = gen_int(1, p - 3);

	if (params.find("q2") != params.end())
		q2 = stoi(params["q2"]);
	else q2 = gen_int(q1, p - 2);

	if (params.find("q3") != params.end())
		q3 = stoi(params["q3"]);
	else q3 = gen_int(q2, p - 1);

	if (params.find("w") != params.end())
		w = stoi(params["w"]);
	else w = gen_int(q1, p - 3);

	while (!(q1 < q2 && q2 < q3 && q3 < p)) {
		cout << "Неверно заданы p, q1, q2, q3 (q1<q2<q3<p)" << endl;
		cout << "p = "; cin >> p; cout << endl;
		cout << "q1 = "; cin >> q1; cout << endl;
		cout << "q2 = "; cin >> q2; cout << endl;
		cout << "q3 = "; cin >> q3; cout << endl;
	}

	if (params.find("k") != params.end())
		k = stoi(params["k"]);
	else k = 11675432246;

	if (params.find("n") != params.end())
		n = stoi(params["n"]);
	else n = 10000;

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

//lfsr(40, 45841782953, 48387843145, 11, 1000);
//int p, long long x, long long a, int w, int n
vector <long long> lfsr(map <string, string> params) {
	int p, w;
	long long x, a, n;
	if (params.find("p") != params.end())
		p = stoi(params["p"]);
	else p = gen_int(10, 60);

	if (params.find("x") != params.end())
		x = stoi(params["x"]);
	else x = gen_long(9000000000, 80000000000);

	if (params.find("a") != params.end())
		a = stoi(params["a"]);
	else a = gen_long(9000000000, 80000000000);

	while (x < 5000000000) {
		cout << "Недостаточно большой x" << endl;
		cout << "x = "; cin >> x; cout << endl;
	}

	while (a < 5000000000) {
		cout << "Недостаточно большая a" << endl;
		cout << "a = "; cin >> a; cout << endl;
	}

	if (params.find("w") != params.end())
		w = stoi(params["w"]);
	else w = gen_int(7, p);

	if (params.find("n") != params.end())
		n = stoi(params["n"]);
	else n = 10000;

	deque <int> bin_p = bin(x, p);
	deque <int> bin_a = bin(a, p);
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

//nfsr(31, 4862922, 3675643, 79, 3535938, 5322133, 23, 589327, 88733, 11, 1000)
//int l1, long long x1, long long a1, int l2, long long x2, long long a2, int l3, long long x3, long long a3, int w, int n

vector <long long> nfsr(map <string, string> params) {
	//l1 l2 l3 должны быть взаимно простыми
	int l1, l2, l3, w;
	long long x1, x2, x3, a1, a2, a3, n;

	if (params.find("l1") != params.end())
		l1 = stoi(params["l1"]);
	else l1 = gen_int(5, 100);

	if (params.find("l2") != params.end())
		l2 = stoi(params["l2"]);
	else l2 = gen_int(5, 100);

	if (params.find("l3") != params.end())
		l3 = stoi(params["l3"]);
	else {
		l3 = 11;
		while (!(gcd(l1, l2) == 1 || gcd(l1, l3) == 1 || (l2, l3) == 1))
			l3 = gen_int(5, 100);
	}

	while (!(gcd(l1, l2) == 1 || gcd(l1, l3) == 1 || (l2, l3) == 1)) {
		cout << "l1, l2 и l3 должны быть взаимно простыми!" << endl;
		cout << "l1 = "; cin >> l1; cout << endl;
		cout << "l2 = "; cin >> l2; cout << endl;
		cout << "l3 = "; cin >> l3; cout << endl;
	}

	if (params.find("w") != params.end())
		w = stoi(params["w"]);
	else w = gen_int(7, 15);

	if (params.find("x1") != params.end())
		x1 = stoi(params["x1"]);
	else x1 = gen_long(1000000, 100000000);

	if (params.find("x2") != params.end())
		x2 = stoi(params["x2"]);
	else x2 = gen_long(1000000, 100000000);

	if (params.find("x3") != params.end())
		x3 = stoi(params["x3"]);
	else x3 = gen_long(1000000, 100000000);

	if (params.find("a1") != params.end())
		a1 = stoi(params["a1"]);
	else a1 = gen_long(1000000, 100000000);

	if (params.find("a2") != params.end())
		a2 = stoi(params["a2"]);
	else a2 = gen_long(1000000, 100000000);

	if (params.find("a3") != params.end())
		a3 = stoi(params["a3"]);
	else a3 = gen_long(1000000, 100000000);

	if (params.find("n") != params.end())
		n = stoi(params["n"]);
	else n = 10000;

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

//mt(15, 7, 20, 19, 36563143, 25345624, 4825411, 12, 5, 2, 7, 432556433, 25345324, 1000);
//int w, int r, int p, int q, long long x, long long a, long long f, int u, int s, int t, int l, long long b, long long c, int n
vector <long long> mt(map <string, string> params) {
	//q<p
	//w>r

	int w, r, p, q, u, s, t, l;
	long long x, a, f, b, c, n;

	if (params.find("n") != params.end())
		n = stoi(params["n"]);
	else n = 10000;

	if (params.find("w") != params.end())
		w = stoi(params["w"]);
	else w = gen_int(7, 15);

	if (params.find("r") != params.end())
		r = stoi(params["r"]);
	else r = gen_int(4, w-1);

	if (params.find("p") != params.end())
		p = stoi(params["p"]);
	else p = gen_int(10, 60);

	if (params.find("q") != params.end())
		q = stoi(params["q"]);
	else q = gen_int(7, p-1);

	while (!(q < p)) {
		cout << "Неверно заданы q, p (q<p)" << endl;
		cout << "p = "; cin >> p; cout << endl;
		cout << "q = "; cin >> q; cout << endl;
	}

	while (!(r < w)) {
		cout << "Неверно заданы r, w (r<w)" << endl;
		cout << "p = "; cin >> p; cout << endl;
		cout << "q = "; cin >> q; cout << endl;
	}

	if (params.find("u") != params.end())
		u = stoi(params["u"]);
	else u = gen_int(1, w - 1);

	if (params.find("s") != params.end())
		s = stoi(params["s"]);
	else s = gen_int(1, w - 1);

	if (params.find("t") != params.end())
		t = stoi(params["t"]);
	else t = gen_int(1, w - 1);

	if (params.find("l") != params.end())
		l = stoi(params["l"]);
	else l = gen_int(1, w - 1);


	if (params.find("x") != params.end())
		x = stoi(params["x"]);
	else x = gen_long(1000000, 100000000);

	if (params.find("a") != params.end())
		a = stoi(params["a"]);
	else a = gen_long(1000000, 100000000);

	if (params.find("f") != params.end())
		f = stoi(params["f"]);
	else f = gen_long(1000000, 100000000);

	if (params.find("b") != params.end())
		b = stoi(params["b"]);
	else b = gen_long(1000000, 100000000);

	if (params.find("c") != params.end())
		c = stoi(params["c"]);
	else c = gen_long(1000000, 100000000);

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

//rc4(475744824463622, 1000);
//long long k, int n
vector <long long> rc4(map <string, string> params) {
	long long k, n;

	if (params.find("n") != params.end())
		n = stoi(params["n"]);
	else n = 10000;

	if (params.find("k") != params.end())
		k = stoi(params["k"]);
	else k = gen_long(100000000000, 90000000000000);

	while (k < 50000000000) {
		cout << "Недостаточно большой k" << endl;
		cout << "k = "; cin >> k; cout << endl;
	}

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


long long powModN(long long x, int y, long long n) {
	long long result = 1;
	for (int i = 0; i < y; i++) {
		result = (result * x) % n;
	}
	return result;
}

vector <long long> test_ferma() {
	vector <long long> simple;
	for (int p = 500; p < 5000; p++) {
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

bool is_simple(long long q, vector <long long> &simple) {
	auto it = lower_bound(simple.begin(),  simple.end(), q);
	if (*it == q)
		return true;
	else
		return false;
}


//rsa(1583, 1847, 11, 1000);
//long long p, long long q, int w, int n
vector <long long> rsa(map <string, string> params) {
	int w;
	long long p, q, n;

	if (params.find("n") != params.end())
		n = stoi(params["n"]);
	else n = 10000;

	vector <long long> simple = test_ferma();

	if (params.find("w") != params.end())
		w = stoi(params["w"]);
	else w = gen_int(7, 15);

	if (params.find("p") != params.end())
		p = stoi(params["p"]);
	else {
		int tmp = gen_int(1, simple.size()-1);
		p = simple[tmp];
	}

	if (params.find("q") != params.end())
		q = stoi(params["q"]);
	else q = simple[0];

	while (!(is_simple(q, simple) && is_simple(p, simple))) {
		cout << "Неверно заданы q, p (q и p должны быть простыми > 500)" << endl;
		cout << "p = "; cin >> p; cout << endl;
		cout << "q = "; cin >> q; cout << endl;
	}

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

void setparam(string s, map <string, string> &params) {
	//string str1 = "", str2="";
	int pos = s.find(":");
	string str1 = s.substr(1, pos);
	string str2 = s.substr(pos + 1);
	params[str1] = str2;	
	return;
	}


int main(char *argv[]) {
	setlocale(LC_ALL, "Russian");
	map <string, string> params;
	for (int i = 1; i < argv.size(); i++)
		setparam(argv[i], params);



	//string str = "";

	//char a='0';
	//while (a != '\n') {
	//	cin >> a;
	//	str += a;
	//}
	////cin >> str;
	//cout << str << endl;
	//vector <long long> ans;
	//for (int i = 0; i < str.size(); i++) {
	//	if (str[i] == '/' && str[i + 1] == 'g' && str[i + 2] == ':') {
	//		if (str[i + 3] == 'l') {
	//			if (str[i+4]=='c') ans = lc(1, 1277, 24749, 117128, 10000); 
	//			if (str[i+4]=='f') ans = lfsr(40, 45841782953, 48387843145, 11, 1000);
	//		}
	//		if (str[i + 3] == 'a') ans = add(38, 89, 3243, 10000);
	//		if (str[i + 3] == '5') ans = five_p(40, 8, 11, 30, 15, 11675432246, 1000);
	//		if (str[i + 3] == 'n') ans = nfsr(31, 4862922, 3675643, 79, 3535938, 5322133, 23, 589327, 88733, 11, 1000);
	//		if (str[i + 3] == 'm') ans = mt(15, 7, 20, 19, 36563143, 25345624, 4825411, 12, 5, 2, 7, 432556433, 25345324, 1000);
	//		if (str[i + 3] == 'r') {
	//			if (str[i + 4] == 'c') ans = rc4(475744824463622, 1000);
	//			if (str[i + 4] == 's') ans = rsa(1583, 1847, 11, 1000);
	//		}
	//		if (str[i + 3] == 'b') ans = bbs(11, 1000);
	//	}
	//}

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