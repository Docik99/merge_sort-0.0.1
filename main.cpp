#include <iostream>
#include <sstream>

using namespace std;

bool read(int *a, int s)
{
    string str;
    getline(cin, str);
    istringstream stream(str);
    for (unsigned int i = 0; i < s; ++i)
    {
        if (!(stream >> a[i]))
        {
            return false;
        }
    }
    return true;
}

void merge(int *a, int min, int mid, int max)
{
    int *b = new int[max + 1 - min];
    int h = min, i = 0, j = mid + 1, k;

    while ((h <= mid) && (j <= max))
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
    }

    if (h > mid)
    {
        for (k = j; k <= max; k++)

        {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i++;
        }
    }

    for (k = 0; k <= max - min; k++)
    {
        a[k + min] = b[k];
    }
    delete[] b;
}

void mergesort(int *a, int min, int max)
{
    int mid;
    if (min < max)
    {
        mid = (min + max) / 2;
        mergesort(a, min, mid);
        mergesort(a, mid + 1, max);
        merge(a, min, mid, max);
    }
}

int main()
{
    int s = 0, i;
    if ((cin >> s) && (s > 1))
    {
        string line;
        getline(cin, line);
        istringstream stream(line);
        int * a = new int[s];
        if (read(a, s))
        {
            mergesort(a, 0, s-1);
            for ( i = 0; i < s; ++i)
            {
                cout << a[i] << " ";
            }
        }
        else cout << "An error has occured while reading input data." << endl;
        delete[] a;
    }
    else cout << "An error has occured while reading input data." << endl;
    return 0;
}