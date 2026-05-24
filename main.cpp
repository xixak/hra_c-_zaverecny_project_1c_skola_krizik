#include <iostream>
#include <string>
#include <cstdlib> //srand()
#include <ctime> //time(0)
#include <vector> // vector = dynamicke pole

using namespace std;

#ifdef _WIN32 // kdyz jses ve windows
#include <windows.h> // barevny text
// ------------ BARVY ------------ 
enum barvy : int { cerna, modra, zelena, tyrkysova, cervena, fialova, zlutohneda, svetle_seda, tmave_seda, svetle_modra, svetle_zelena, svetle_tyrkysova, ruzova, svetle_fialova, zluta, bila };
#define vychozi_barva 7
void barva(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#else //linux
enum barvy : int { cerna = 30, cervena, zelena, zluta, modra, fialova, tyrkysova, bila };
enum svetle_barvy : int { tmave_seda = 90, ruzova, svetle_zelena, hneda, svetle_modra, svetle_fialova, svetle_tyrkysova };
#define vychozi_barva 0
void barva(int color) {
    cout << "\033[" << color << "m";
}
#endif

// ------------ promeny k postave ------------ 
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
// ------------ promene k nepriteli ------------ 
struct Nepritel {
    string jmeno;
    int zivoty_n;
    int utok_n;
    int odmena;
};
// ------------ oddelovac ------------
void oddelovac() {
    barva(tmave_seda);
    cout << "\n=====================================\n";
    barva(vychozi_barva);
}
// ------------ pausa ------------
void pauseGame() {
    cout << "\n";
    system("pause");
}
// ------------ COMBAT TEXT ------------
void combatText(string text, int color = vychozi_barva) {
    barva(color);
    cout << "\n>> " << text << endl;
    barva(vychozi_barva);
}
// ------------ HP BAR ------------
void hpBar(int hp, int maxHp) {

    int pocet = (hp * 20) / maxHp;

    cout << "HP: [";

    for (int i = 0; i < 20; i++) {

        if (i < pocet){
            barva(cervena);
            cout << "& ";
        }else{
            barva(tmave_seda);
            cout << "-";
        }
    }
    barva(vychozi_barva);
    cout << "] " << hp << "/" << maxHp << endl;
}
// ------------ LOKACE ------------
void lokace(string nazev) {

    oddelovac();

    barva(svetle_tyrkysova);
    cout << " LOKACE: " << nazev << endl;

    barva(vychozi_barva);

    oddelovac();
}
// ------------ logo hry ------------
void logoHry() {
    barva(svetle_tyrkysova);
    cout << R"(

███████╗██╗     ██████╗  ██████╗ ██████╗
██╔════╝██║     ██╔══██╗██╔═══██╗██╔══██╗
█████╗  ██║     ██║  ██║██║   ██║██████╔╝
██╔══╝  ██║     ██║  ██║██║   ██║██╔══██╗
███████╗███████╗██████╔╝╚██████╔╝██║  ██║
╚══════╝╚══════╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝

)";
   barva(vychozi_barva);
}

// ------------ BOSS INTRO ------------
void bossIntro() {
    barva(cervena);
    cout << R"(

             .-.
            (o.o)
             |=|
            __|__
          //.=|=.\\
         // .=|=. \\
         \\\\ .=|=. //
          \\\\(_=_)//
           (:| |:)
            || ||
            () ()
            || ||
            || ||
           ==' '==

        PLAGUEVILE

)";
    barva(vychozi_barva);
}
// ------------ PRIBEH ------------
void uvod() {
    oddelovac();
    barva(zluta);
    cout << "        KRALOVSTVI ELDOR\n";
    barva(vychozi_barva);
    oddelovac();

    cout << "Kdysi bylo kralovstvi Eldor mistem miru.\n";
    cout << "Lide zili bezpecne a magie slouzila dobru.\n\n";

    cout << "Jednoho dne se ale na severu objevila\n";
    cout << "temna nemoc zvana Morova nakaza.\n\n";

    cout << "Lesy umiraly, lide mizeli a mrtvi\n";
    cout << "vstavali znovu jako nestvury.\n\n";

    cout << "Za vse muze pradavna bytost:\n";
    barva(cervena);
    cout << "PLAGUEVILE.\n\n";
    barva(vychozi_barva);
    cout << "Mnoho hrdinu se pokusilo zastavit\n";
    cout << "temnotu, ale nikdo se nevratil.\n\n";

    cout << "Ted prichazis TY.\n";
    cout << "Osud kralovstvi je ve tvych rukou.\n\n";
    pauseGame();
}
// ------------ PRIBEH SOUBOJU ------------
void pribehSouboje(int i) {
    switch (i) {

    case 0:
        lokace("Temny les");
        cout << "Vstupujes do stareho lesa.\n";
        cout << "Mlha je husta a vzduch chladny.\n";
        cout << "Najednou pred tebou vyskoci Goblin.\n";
    break;

    case 1:
        lokace("Loviste bestii");
        cout << "Slysis vytí mezi stromy.\n";
        cout << "Vlk a Netopyr se pripravuji k utoku.\n";
    break;

    case 2:
        lokace("Prokleta cesta");
        cout << "Na zemi lezi stare kosti.\n";
        cout << "Mrtvi znovu povstali.\n";
    break;

    case 3:
        lokace("Most strazce");
        cout << "Obrovsky Obr blokuje most.\n";
        cout << "\"Nikdo neprojde!\"\n";
    break;

    case 4:
        lokace("Vez temne magie");
        cout << "Ve stinech stoji Temny Mag.\n";
        cout << "Jeho oci zari fialovou energii.\n";
    break;

    case 5:
        lokace("Jedovate močaly");
        cout << "Z vody se plazi Jedovaty Had.\n";
        cout << "Hovno kouka a smrdi.\n";
    break;

    case 6:
        lokace("Spalena vesnice");
        cout << "Domy jsou znicene.\n";
        cout << "Rozzuřeny Ork jde proti tobe.\n";
     break;

     case 7:
        lokace("Ledove hory");
        cout << "Obrovsky Ledovy Golem blokuje cestu.\n";
    break;
    
     case 8:
        lokace("Jedovate jeskyne");
        cout << "Ze tmy se ozve smich Bandity.\n";
        cout << "Vedle nej se plazi obrovsky Pavouk.\n";
    break;

    case 9:
        lokace("Zakazane ruiny");
        cout << "Nemrtvy Carodej sesila temna kouzla.\n";
        cout << "Kouzelna hulka se na tebe blbe smeje.\n";
    break;
    
    case 10:
        lokace("Pekelna brana");
        cout << "Z ohně vystupuje mocny Demon.\n";
    break;

    case 11:
        lokace("Peklo Padly rytir");
        cout << "Pred tebou stoji nemrtvy rytir.\n";
        cout << "\"Osvobod me...\"\n";
    break;

    case 12:
        lokace("Peklo Draci vrchol");
        cout << "Oblohu zakryla kridla obrovskeho Draka.\n";
    break;

    case 13:
        lokace("Temna pevnost");
        cout << "Dorazil jsi na konec sve cesty.\n";
        cout << "Na trunu sedi PLAGUEVILE.\n";
    bossIntro();
    break;
    }
    pauseGame();
}
// ------------ Funkce na vypis statu postavy ------------ 
void vypisStaty(Postava p) {
    oddelovac();
    barva(svetle_tyrkysova);
    cout << "\n===== HRAC =====\n";
    barva(vychozi_barva);
    cout << "Jmeno: " << p.jmeno << endl;
    cout << "rasa: " << p.rasa << endl;
    hpBar(p.zivoty, p.maxZivoty);
    cout << "Mana: " << p.mana << "/" << p.maxMana << endl;
    cout << "Zlato: " << p.zlato << endl;
    cout << "Level: " << p.level << endl;
    cout << "EXP: " << p.exp << endl;
    cout << "Utok: " << p.utok << endl;
}
// ------------ Funkce na level up hrace ------------
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
        barva(svetle_zelena);

        cout << "\n*** LEVEL UP! Mas level " << p.level << " ***\n";
        barva(vychozi_barva);
    }
}
// ------------ vesnice ------------
void vesnice(Postava &p, int cislo) {
    cout << "\nDorazil jsi do vesnice.\n";
    cout << "Mistni obyvatel ti nabizi pomoc.\n";
    int volba;

    do {
        oddelovac();
        barva(zluta);
        cout << "\n---- VESNICE " << cislo << " ----\n";
        barva(vychozi_barva);
        oddelovac();
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
                combatText("Byl jsi vylecen.", svetle_zelena);
            }else {
                combatText("Nemas dost penez.", ruzova);
            }
        break;

        case 2:
            if (p.zlato >= 15) {
                p.zlato -= 15;
                p.maxZivoty += 5;
                p.zivoty = p.maxZivoty;
                combatText("Tvoje odolnost vzrostla.", svetle_zelena);
            }else {
                combatText("Nemas dost penez.", ruzova);
            }
        break;

        case 3:
            if (p.zlato >= 20) {
                p.zlato -= 20;
                p.utok += 2;
                combatText("Tvoje sila je vetsi.", svetle_zelena);
            }else {
                combatText("Nemas dost penez.", ruzova);
            }
        break;
        }
    } while (volba != 4);
}
// ------------ souboj ------------
bool souboj(Postava &p, vector<Nepritel> nepratele, bool boss = false) { // vektor = dynamicke pole ktere muze mit libovolny pocet prvku
    oddelovac();
    barva(ruzova);
    cout << "\n===== Zacina SOUBOJ =====\n";
    barva(vychozi_barva);
    oddelovac();

    int infekce = 0;
    int bezLeceni = 0;

    while (p.zivoty > 0 && !nepratele.empty()) {

// ------------ Infekce ------------
if (boss && infekce > 0) {
    int damage = (rand() % 3 + 1) * infekce;
    p.zivoty -= damage;
    combatText("Infekce " + to_string(damage) + " damage!", svetle_fialova);
    if (p.zivoty <= 0) break;
}
    oddelovac();
    cout << "Tvuj tah\n";
    hpBar(p.zivoty, p.maxZivoty);
    if(p.zivoty <= 10){
        barva(ruzova);
        cout << "!!! Jsi tezce zraneny !!!\n";
        barva(vychozi_barva);
    }
    cout << "Mana: " << p.mana << "/" << p.maxMana << endl;
    cout << "\nAKCE:\n";
    cout << "1. Utok\n";
    cout << "2. Leceni (5 many)\n";
    int akce;
    cin >> akce;
// ------------ LECENI ------------
        if (akce == 2 && p.mana >= 5) {
        p.mana -= 5;
        p.zivoty += 10;
            if (p.zivoty > p.maxZivoty)
                p.zivoty = p.maxZivoty;
            combatText("vylecil ses!", svetle_zelena);
            if (infekce > 0)
            infekce--;
            bezLeceni = 0;
        
// ------------ UTOK ------------
        } else {
            bezLeceni++;

            cout << "\n----Nepratele:----\n";
            for (int i = 0; i < nepratele.size(); i++) {
                cout << "[" << i + 1 << "] " << nepratele[i].jmeno << " | HP: " << nepratele[i].zivoty_n << endl;
            }
             int cil;
             cout << "\nvyber cil: ";
            cin >> cil;
            cil--;
             if (cil >= 0 && cil < nepratele.size()) {
                nepratele[cil].zivoty_n -= p.utok;
                combatText("Zasahl jsi " + nepratele[cil].jmeno + " za " + to_string(p.utok) + " damage!", svetle_zelena);

                if (nepratele[cil].zivoty_n <= 0) {
                    combatText(nepratele[cil].jmeno + " byl porazen!", zluta);
                    p.zlato += nepratele[cil].odmena;
                    p.exp += 10;
                    nepratele.erase(nepratele.begin() + cil); // .erase vymazu prvek uprostred
                }
            }
        }
// ------------ utok nepratel ------------
        for (auto &n : nepratele) {
            p.zivoty -= n.utok_n;
            combatText(n.jmeno + " utoci za " + to_string(n.utok_n) + " damage!", ruzova);
// ------------ boss infekce ------------
            if (boss) {
                infekce = min(infekce + 1, 5); // min vraci mensi prvek
                combatText("Byl jsi nakazen!", svetle_fialova);
            }
        }
 // ------------ bonus utok bosse ------------ 
        if (boss && bezLeceni >= 3 && !nepratele.empty()) {
            combatText("PLAGUEVILE pouziva bonusovy utok!", cervena);
            p.zivoty -= nepratele[0].utok_n;
        }
    }
// ------------ prohra ------------
    if (p.zivoty <= 0) {
        oddelovac();
        barva(cervena);
        cout << " Prohral jsi!\n";
        cout << " Eldor padl do temnoty...\n";
        barva(vychozi_barva);
        oddelovac();
        return false;
    }
// ------------ vyhra ------------ 
    combatText("Vyhral jsi boj!", svetle_zelena);
    levelUp(p);
    pauseGame();
    return true;
}
// ------------ VYBER CLASSY ------------
Postava vyberrasy() {
    Postava p;
    cout << "Zadej jmeno: ";
    cin >> p.jmeno;
     int volba;
    do {
        oddelovac();
        cout << "Vyber Rasu/povolani:\n\n";
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
    // ------------ MAIN ------------
int main() {
    srand(time(0));
    logoHry();
    uvod();
    Postava postava = vyberrasy();
    vector<vector<Nepritel>> mapa = {
        {{"Goblin", 10, 3, 5}},
        {{"Vlk", 10, 3, 5}, {"Netopyr", 8, 2, 4}},
        {{"Kostlivec", 12, 4, 8}, {"Zombie", 12, 4, 8}, {"Krysa", 8, 2, 7}},
        {{"MiniBoss Obr", 25, 6, 20}},
        {{"Temny Mag", 18, 6, 15}},
        {{"Jedovaty Had", 16, 5, 12},{"hovno", 20, 5, 15}},
        {{"Ork", 15, 5, 10}},
        {{"MiniBossLedovy Golem", 35, 8, 40}},
        {{"Bandita", 14, 5, 8}, {"Pavouk", 10, 3, 10}},
        {{"MiniBoss Kouzelna hulka", 30, 7, 40}, {"Nemrtvy Carodej", 20, 9, 20}},
        {{"Demon", 40, 10, 35}},
        {{"MiniBoss Rytir", 30, 7, 30}},
        {{"Drak", 80, 8, 100}},
        {{"Plaguevile", 100, 12, 150}} // HLAVNI BOSS
    };
// ------------ prubeh hry ------------
for (int i = 0; i < mapa.size();i++){
    vypisStaty(postava);
    if (i == 3)
        vesnice(postava, 1);
    if (i == 6)
        vesnice(postava, 2);
    if (i == 9)
        vesnice(postava, 3);
    if (i == 11)
        vesnice(postava, 4);
    if (i == 13)
        vesnice(postava, 5);
    pribehSouboje(i);
    bool vysledek;
// ------------ boss boj ------------
    if (i == mapa.size() - 1)
        vysledek = souboj(postava, mapa[i], true);
    else
        vysledek = souboj(postava, mapa[i], false);
    if (!vysledek)
    return 0;
}
// ------------ konec ------------
    oddelovac();
    barva(svetle_zelena);
    cout << R"(

██╗   ██╗██╗   ██╗██╗  ██╗██████╗  █████╗
██║   ██║╚██╗ ██╔╝██║  ██║██╔══██╗██╔══██╗
██║   ██║ ╚████╔╝ ███████║██████╔╝███████║
╚██╗ ██╔╝  ╚██╔╝  ██╔══██║██╔══██╗██╔══██║
 ╚████╔╝    ██║   ██║  ██║██║  ██║██║  ██║
  ╚═══╝     ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝

)";
    barva(vychozi_barva);
    cout << "PLAGUEVILE padl na zem.\n";
    cout << "Temna magie mizí.\n";
    cout << "Eldor byl zachranen.\n\n";

    cout << "Lide oslavují tve jmeno.\n";
    cout << "Stal ses legendou kralovstvi.\n";

    oddelovac();

    system("pause");

    return 0;
}
