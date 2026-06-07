# hra_c-_zaverecny_project_1c_skola_krizik
hra_c++

knihovny:
#include <string> ---- na promennou string
#include <cstdlib> ---- srand()
#include <ctime> ---- time(0)
#include <vector> ---- pole vector ---- poradil a naucil chatgpt
#include <windows.h> ---- barevny text

prace z barvama:
#ifdef _WIN32 ---- text az do nasledujiciho #endif nebo #else se prelozi jenom pokud je prekladac na windows
enum barvy ---- je to pole intu ale kazde cislo je pojemenovane
#define vychozi_barva 7 ---- nastavi vychozi barvu na 7
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color) ---- definovany ve knihovne windows.h a zmeni barvu textu
#else ---- je to aby program bezel i na opercnim systemu jinym nez na windows
enum barvy ---- mam to tam aby mohl jednoduse zmenit barvy v programu
#define vychozi_barva 0 ---- zmeni vychozi barvu

datove struktury:
struct Postava ---- soubor promenych ktere se vazi k jedne postave
struct Nepritel ---- soubor promenych ktere se vazi k nepriteli

prikazy:
cout << R"()"; ---- to R dela ze muzu s jednim cout psat na nekolik radku aby se v tom lepe vyznal
system("pause"); ---- zastavi program
vector<> ---- dynamicke pole ktere muze mit libovolny pocet prvku
neco.erase ---- vymazu prvek ve prostred seznamu
neco.begin ---- vynazu prvek na zacatku seznamu
