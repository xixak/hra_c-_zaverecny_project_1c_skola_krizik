#include <iostream>
#include <string>
#include <cstdlib> //srand()
#include <ctime> //time(0)
#include <vector> // vector = dynamicke pole 

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
// souboj
bool souboj(Postava &p, vector<Nepritel> nepratele, bool boss = false) { // vektor = dynamicke pole ktere muze mit libovolny pocet prvku
    cout << "\n===== Zacina SOUBOJ =====\n";

    int infekce = 0;
    int bezLeceni = 0;

      while (p.zivoty > 0 && !nepratele.empty()) {

        // Infekce
        if (boss && infekce > 0) {
            int damage = (rand() % 3 + 1) * infekce;
            p.zivoty -= damage;
            cout << "Infekce dava " << damage << " damage! (stacky: " << infekce << ")\n";
        }

        cout << "\nzivoty: " << p.zivoty << "/" << p.maxZivoty << endl;
        cout << "1. Utok\n2. Leceni (5 many)\n";
        int akce;
        cin >> akce;

        if (akce == 2 && p.mana >= 5) {
        p.mana -= 5;
        p.zivoty += 10;
            if (p.zivoty > p.maxZivoty) p.zivoty = p.maxZivoty;
           
                cout << "Vylecil ses!\n";
            if (infekce > 0) infekce--;
            bezLeceni = 0;
        } else {
            bezLeceni++;

            cout << "\nNepratele:\n";
            for (int i = 0; i < nepratele.size(); i++) {
                cout << i + 1 << ". " << nepratele[i].jmeno
                     << " Zivoty: " << nepratele[i].zivoty_n << endl;
            }
             int cil;
            cin >> cil;
            cil--;
             if (cil >= 0 && cil < nepratele.size()) {
                nepratele[cil].zivoty_n -= p.utok;
                cout << "Utok za " << p.utok << endl;

                if (nepratele[cil].zivoty_n <= 0) {
                    cout << nepratele[cil].jmeno << " zemrel!\n";
                    p.zlato += nepratele[cil].odmena;
                    p.exp += 5;
                    nepratele.erase(nepratele.begin() + cil); // .erase vymazu prvek uprostred 
                }
            }
        }
   // utok nepratel
        for (auto &n : nepratele) {
            p.zivoty -= n.utok_n;
            cout << n.jmeno << " utoci za " << n.utok_n << endl;

            if (boss) {
                infekce = min(infekce + 1, 5); // min vraci mensi prvek
            }
        }
 // bonus utok
        if (boss && bezLeceni >= 3 && !nepratele.empty()) {
            cout << "BOSS dava bonusovy utok!\n";
            p.zivoty -= nepratele[0].utok_n;
        }
    }
    if (p.zivoty <= 0) {
        cout << "\nProhral jsi!\n";
        return false;
    }

    cout << "\nVyhral jsi!\n";
    levelUp(p);
    return true;
}
// ===== VYBER CLASSY =====
Postava vyberrasy() {
    Postava p;
    cout << "Zadej jmeno: ";
    cin >> p.jmeno;

       int volba;
    do {
        cout << "\nVyber Rasu/povolani:\n";
        cout << "1. Valecnik\n2. Lucistnik\n3. Carodej\n4. Tank\n";
        cin >> volba;

        switch (volba) {
        case 1:
            p.rasa = "Valecnik";
            p.maxZivoty = 30;
            p.maxMana = 10;
            p.utok = 7;
            break;
        case 2:
            p.rasa = "Lucistnik";
            p.maxZivoty = 25;
            p.maxMana = 15;
            p.utok = 8;
            break;
        case 3:
            p.rasa = "Carodej";
            p.maxZivoty = 20;
            p.maxMana = 30;
            p.utok = 10;
            break;
        case 4:
            p.rasa = "Tank";
            p.maxZivoty = 40;
            p.maxMana = 5;
            p.utok = 5;
            break;
        }
    } while (volba < 1 || volba > 4);

    p.zivoty = p.maxZivoty;
    p.mana = p.maxMana;
    p.zlato = 20;
    p.level = 1;
    p.exp = 0;

    return p;
}
    // ===== MAIN =====
int main() {
    srand(time(0));

    Postava postava = vyberrasy();

    vector<vector<Nepritel>> mapa = {
        {{"Goblin", 10, 3, 5}},
        {{"Vlk", 10, 3, 5}, {"Netopyr", 8, 2, 4}},
        {{"Kostlivec", 12, 4, 6}, {"Zombie", 12, 4, 6}, {"Krysa", 8, 2, 3}},
        {{"MiniBoss Obr", 25, 6, 20}},
        {{"Ork", 15, 5, 8}},
        {{"Bandita", 14, 5, 8}, {"Pavouk", 10, 3, 5}},
        {{"MiniBoss Rytir", 30, 7, 25}},
        {{"Plaguevile", 60, 12, 150}} // HLAVNI BOSS
    };
}
