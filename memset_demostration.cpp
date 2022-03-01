// CPP Program to demonstrate that we can use memset() to
// set all values as 0 or -1 for integral data types also
#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
	int a[5];

	// all elements of A are zero
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;

	// all elements of A are -1
	memset(a, -1, sizeof(a));
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;

	// Would not work 
	memset(a, 5, sizeof(a)); // WRONG  because Ee can only assign integer 0 or -1
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
}
