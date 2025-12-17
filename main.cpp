#include "mylib.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int riba = 1;
    vector <string> nuorodos, nuor_galai;
    unordered_map<string, pair<int, vector<int>>> zodziu_sk_vt;
    vector <pair <string, pair<int, vector<int>>>> zodziu_sk_vt_vec;
    stringstream prad_duom, be_nuor_duom, nuor;
    cout << "Nuskaitomi duomenys...\n";
    duomenu_nuskaitymas(prad_duom, nuor);
    nuorodu_galuniu_isgavimas(nuor, nuor_galai);
    cout << "Ieškoma nuorodų...\n";
    nuorodu_paieska(prad_duom, be_nuor_duom, nuorodos, nuor_galai);
    cout << "Ieškoma žodžių...\n";
    zodziu_paieska(be_nuor_duom, zodziu_sk_vt);
    cout << "Vykdomas žodžių rikiavimas...\n";
    zodziu_rikiavimas(zodziu_sk_vt_vec, zodziu_sk_vt);
    cout << "Vykdomas žodžių filtravimas...\n";    
    zodziu_filtravimas(zodziu_sk_vt_vec, riba);
    cout << "Duomenys spausdinami...\n";    
    spausdinimas_zodziai(zodziu_sk_vt_vec);
    spausdinimas_nuorodos(nuorodos);
    cout << "Baigta!\n";
}