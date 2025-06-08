#include "Menu.h"
using namespace std;

//Key codes for arrow keys and Enter
enum {
    Up = 72,
    Down = 80,
    Left = 75,
    Right = 77,
    Enter = 13
};


int showMenu(const vector<string>& options, const string& prompt) {
    int selected = 0;
    while (true) {
        system("cls");
		// Clear the console and display the menu
        cout << prompt << "\n";
        for (int i = 0; i < options.size(); ++i) {
            if (i == selected)
                cout << " > " << options[i] << " <\n";
            else
                cout << "   " << options[i] << "\n";
        }
        int ch = _getch();
        if (ch == 224) {// 224 means "extended key follows"
            ch = _getch();//ch is Up, Down, Left, or Right
            if (ch == Up && selected > 0)
                --selected;
            else if (ch == Down && selected < options.size() - 1)
                ++selected;
        }
        else if (ch == Enter) {
            return selected;
        }
    }
}