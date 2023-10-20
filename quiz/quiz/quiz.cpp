#include <iostream>
#include <fstream>
#include <string>
#include <vector>


//prosim o ignoraci obcasnych komentaru, kde si neco vysvetluji pro budouci pouziti :)



using namespace std;

struct Dotaznik {
    string otazka;
    string odpoved;
    char pismeno;
};

int main() {
    ifstream inputFile("otazky.txt");
    vector<Dotaznik> otazky;
    string line;
	// rozdeleni na otazky, odpovedi, spravne odpovedi
    while (getline(inputFile, line)) {
        size_t text1 = line.find(';');
        size_t text2 = line.find(';', text1 + 1); //najde ;, pokracuje od text1
        if (text1 != string::npos && text2 != string::npos) {
            Dotaznik q;
			q.otazka = line.substr(0, text1); //cutne string od 0 do lokace text1 pro vyber specificke casti
            q.odpoved = line.substr(text1 + 1, text2 - text1 - 1);
            q.pismeno = line[text2 + 1];
            otazky.push_back(q);
        }
    }
    inputFile.close();

    int score = 0;
// dotazovani
    for (const Dotaznik& q : otazky) {
        cout << q.otazka << endl;
        string user;
        cout << "Odpoved: ";
        cin >> user;

        if (user[0] == q.pismeno) {
            cout << "Spravne :)" << endl;
            score++;
        }
        else {
            cout << "Spatne :/" << endl;
        }
    }
    // vysledek :)
    cout << "Score: " << score << " z " << otazky.size() << endl;

    return 0;
}
