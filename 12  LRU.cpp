#include <iostream>
using namespace std;

int main()
{
	int nopages, noframes, page[20], i, count = 0;
	cout << "\n\t Enter no of pages for which you want to calculate page faults:>";
	cin >> nopages;
	cout << "\n\t Enter the Reference String:";
	for (i = 0; i < nopages; i++)
	{
		cout << "\t";
		cin >> page[i];
	}
	cout << "\n\t Enter the Numer of frames:";
	cin >> noframes;
	int frame[noframes], fcount[noframes];
	for (i = 0; i < noframes; i++)
	{
		frame[i] = -1;
		fcount[i] = 0;
	}
	i = 0;
	while (i < nopages)
	{
		int j = 0, flag = 0;
		while (j < noframes)
		{
			if (page[i] == frame[j])
			{
				flag = 1;
				fcount[j] = i + 1;
			}
			j++;
		}
		j = 0;
		cout << "\n\t***\n";
		cout << "\t" << page[i] << "-->";
		if (flag == 0)
		{
			int min = 0, k = 0;
			while (k < noframes - 1)
			{
				if (fcount[min] > fcount[k + 1])
					min = k + 1;
				k++;
			}
			frame[min] = page[i];
			fcount[min] = i + 1;
			count++;
			while (j < noframes)
			{
				cout << "\t|" << frame[j] << "|";
				j++;
			}
		}
		i++;
	}
	cout << "\n\t***\n";
	cout << "\n\t Page Fault:" << count << "\n";
	return 0;
}
// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
