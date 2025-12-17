#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <locale>
#include <windows.h>

using std::unordered_map;
using std::string;
using std::wstring;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::wofstream;
using std::getline;
using std::stringstream;
using std::wstringstream;
using std::regex;
using std::cout;
using std::smatch;
using std::sregex_iterator;
using std::distance;
using std::tolower;
using std::sort;
using std::pair;
using std::setw;
using std::left;
using std::to_string;

void duomenu_nuskaitymas(stringstream& buf, stringstream& nuor);
void nuorodu_galuniu_isgavimas(stringstream& buf, vector <string>& nuor_galai);
void nuorodu_paieska(stringstream& buf, stringstream& be_nuor_duom, vector <string>& nuorodos, const vector <string>& nuor_galai);
void zodziu_paieska(stringstream& buf, unordered_map<string, pair<int, vector<int>>>& zodziu_sk_vt);
void zodziu_rikiavimas(vector < pair <string, pair<int, vector<int>>> >& zodziu_sk_vt_vec, const unordered_map<string, pair<int, vector<int>>>& zodziu_sk_vt);
void zodziu_filtravimas(vector < pair <string, pair<int, vector<int>>>>& zodziu_sk_vt_vec, int& riba);
void spausdinimas_zodziai(const vector < pair <string, pair<int, vector<int>>>>& zodziu_sk_vt_vec);
void spausdinimas_nuorodos(const vector <string>& nuorodos);