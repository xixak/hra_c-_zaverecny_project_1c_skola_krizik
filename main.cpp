#include <iostream>
#include <string>
#include <cstdlib> //srand()
#include <ctime> //time(0)

using namespace std;
// promeny k postave
struct Postava {
    string jmeno;
    string rasa;
    int maxZivoty;
    int maxMana;
    int zivoty;
    int utok;
    int mana;
    int zlato;
    int level;
    int exp;
};
// promene k nepriteli
struct Nepritel {
    string jmeno;
    int zivoty_n;
    int utok_n;
    int odmena;
};
// Funkce na vypis statu postavy
void vypisStaty(Postava p) {
    cout << "\n===== HRAC =====\n";
    cout << "Jmeno: " << p.jmeno << endl;
    cout << "rasa: " << p.rasa << endl;
    cout << "Zivoty: " << p.zivoty << "/" << p.maxZivoty << endl;
    cout << "Mana: " << p.mana << "/" << p.maxMana << endl;
    cout << "Zlato: " << p.zlato << endl;
    cout << "Level: " << p.level << endl;
    cout << "EXP: " << p.exp << endl;
    cout << "Utok: " << p.utok << endl;
}
// Funkce na level up hrace
void levelUp(Postava &p) {
    int potreba = p.level * 10;

    if (p.exp >= potreba) {
        p.level++;
        p.exp = 0;
        p.maxZivoty += 5;
        p.utok += 2;
        p.maxMana += 3;
        p.zivoty = p.maxZivoty;
        p.mana = p.maxMana;

        cout << "\n*** LEVEL UP! Mas level " << p.level << " ***\n";
    }
}
// vesnice
void vesnice(Postava &p, int cislo) {
    int volba;

    do {
        cout << "\n---- VESNICE " << cislo << " ----\n";
        cout << "1. Doplnit zivoty (5 zlata)\n";
        cout << "2. Zvysit max zivoty (+5) (15 zlata)\n";
        cout << "3. Zvysit utok (+2) (20 zlata)\n";
        cout << "4. Odejit\n";
        cin >> volba;

        switch (volba) {
        case 1:
            if (p.zlato >= 5) {
                p.zlato -= 5;
                p.zivoty = p.maxZivoty;
                cout << "Zivoty doplneny.\n";
            }
            break;
        case 2:
            if (p.zlato >= 15) {
                p.zlato -= 15;
                p.maxZivoty += 5;
                p.zivoty = p.maxZivoty;
                cout << "Max zivoty zvyseno.\n";
            }
            break;
        case 3:
            if (p.zlato >= 20) {
                p.zlato -= 20;
                p.utok += 2;
                cout << "Utok zvysen.\n";
            }
            break;
        }
    } while (volba != 4);
}

