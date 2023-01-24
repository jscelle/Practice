#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

struct tree {
	int data;
	tree* left;
	tree* right;
};

struct tree* addnd(int x, int y, tree* tr) {
	tr = new tree; // Ô‡ÏˇÚ¸ ÔÓ‰ ÛÁÂÎ
	tr->data = x;   // ÔÓÎÂ ‰‡ÌÌ˚ı
	tr->left = new tree;
	tr->left->left = NULL;
	tr->left->right = NULL;
	tr->left->data = y;
	tr->right = NULL; // ‚ÂÚ‚Ë ËÌËˆË‡ÎËÁËÛÂÏ ÔÛÒÚÓÚÓÈ
	return(tr);
}

struct tree* addnode(int x, int y, tree* tr) {
	if (tr != NULL)
	{
		if (x == tr->data)
		{
			if (tr->left == NULL)
			{
				tr->left = new tree;
				tr->left->data = y;
				tr->left->left = NULL;
				tr->left->right = NULL;
			}
			else
			{
				tr->right = new tree;
				tr->right->data = y;
				tr->right->left = NULL;
				tr->right->right = NULL;
			}
		}
		else
		{
			if (tr->left)
				addnode(x, y, tr->left);
			if (tr->right)
				addnode(x, y, tr->right);
		}
	}
	return(tr);
}


void printLevel(tree* t, int level, int prbl) {
	if (t == nullptr) {
		// ≈ÒÎË ‰ÂÂ‚Ó ÔÛÒÚÓÂ, ÚÓ ÓÚÓ·‡Ê‡Ú¸ ÌÂ˜Â„Ó, ‚˚ıÓ‰ËÏ
		return;
	}
	else {
		printLevel(t->left, level - 1, (prbl / 2));  // — ÔÓÏÓ˘¸˛ ÂÍÛÒËË ÔÓÒÂ˘‡ÂÏ ÎÂ‚ÓÂ ÔÓ‰‰ÂÂ‚Ó
		if (level == 0) {
			// level ·Û‰ÂÚ ‡‚ÂÌ ÌÛÎ˛ Ì‡ ÌÛÊÌÓÈ „ÎÛ·ËÌÂ, Ú‡Í Í‡Í ÔË Í‡Ê‰ÓÏ ÂÍÛÒË‚ÌÓÏ ‚˚ÁÓ‚Â ÁÌ‡˜ÂÌËÂ level ÛÏÂÌ¸¯‡ÂÚÒˇ Ì‡ Ó‰ËÌ
			for (int o = 0; o < prbl - 1; o++)
				cout << " ";
			cout << t->data << " ";  // œÓÍ‡Á˚‚‡ÂÏ ˝ÎÂÏÂÌÚ, ÂÒÎË ÓÌ Ì‡ ÌÛÊÌÓÏ Ì‡Ï ÛÓ‚ÌÂ
			for (int o = 0; o < prbl - 1; o++)
				cout << " ";
		}
		printLevel(t->right, level - 1, (prbl / 2));  // — ÔÓÏÓ˘¸˛ ÂÍÛÒËË ÔÓÒÂ˘‡ÂÏ Ô‡‚ÓÂ ÔÓ‰‰ÂÂ‚Ó
	}
}

bool proverka(tree* t) {
	bool ae = true, ae1 = true, ae2 = true;
	if (t->left->data > t->right->data)
	{
		ae = false;
	}
	else
	{
		if (t->left->left && t->left->right) ae1 = proverka(t->left);
		if (t->right->left && t->right->right) ae2 = proverka(t->right);
		ae = ae1 && ae2;
	}
	return ae;
}

int poisk(tree* t, int sm, int pp, bool* a)
{
	pp = pp * 10 + t->data;
	if (sm == t->data)
	{
		*a = true;
	}
	else if ((sm < t->data) && (t->left != NULL))
	{
		pp = poisk(t->left, sm, pp, a);
	}
	if ((sm > t->data) && (t->left != NULL))
	{
		pp = poisk(t->right, sm, pp, a);
	}
	return pp;
}

int main()
{
	int N, a, b, ct = 1, lim = 1, prbl, psk, o, pp = 0;
	string put;
	struct tree* derevo;
	derevo = NULL;
	bool prvvrk = false;
	cout << "Enter N\n";
	cin >> N;
	cout << "Enter info about tree\n";
	cin >> a >> b;
	derevo = addnd(a, b, derevo);
	for (int i = 0; i < N - 2; i++)
	{
		cin >> a >> b;
		derevo = addnode(a, b, derevo);
	};
	while (lim < N)
	{
		ct++;
		lim *= 2;
	}
	//	demonstration(derevo, ct);
	cout << endl;
	prbl = (pow(2, (ct - 1))) / 2;
	for (int p = 0; p < ct; p++)
	{
		printLevel(derevo, p, prbl);
		cout << endl;
	}
	cout << endl;
	if (proverka(derevo))
		cout << "True tree";
	else
		cout << "False tree";
	cout << endl;
	cin >> o;
	pp = poisk(derevo, o, pp, &prvvrk);
	if (prvvrk)
		cout << pp;
	else
		cout << "Element not found";
}

