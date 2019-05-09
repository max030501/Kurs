#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    while(true)
    {
        cout << "Vvedite chislo: ";
        cin >> n;
        if(!cin)
        {
            cout << "ne verno vveli, povtorite vvod\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else break;
    }

    cout << n << endl;

    system("pause");
    return 0;
}