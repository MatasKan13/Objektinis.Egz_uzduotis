#include "mylib.h"

void duomenu_nuskaitymas(stringstream& buf, stringstream& nuor) {
    ifstream in("Kaunas.txt");
    buf << in.rdbuf();
    in.close();

    ifstream in2("nuorodu_sarasas.txt");
    nuor << in2.rdbuf();
    in2.close();
}

void nuorodu_galuniu_isgavimas(stringstream& buf, vector <string>& nuor_galai) {
    string temp;
    while(!buf.eof()) {
        getline(buf,temp);
        std::transform(temp.begin(), temp.end(), temp.begin(),
        [](char c){return tolower(c);});
        nuor_galai.push_back(temp);
    }
}

void nuorodu_paieska(stringstream& buf, stringstream& be_nuor_duom, vector <string>& nuorodos, const vector <string>& nuor_galai)
{
    string galai = "(";
    for (string galas : nuor_galai) {
        galai += galas + "|";
    }
    galai.pop_back();
    galai+= ")";
    string sablono_tekstas = R"(((http(s)?://)?(www\.)?([\w-]+\.)+)" + galai + R"(\b[^ \[\)\(\s\r\n\t\f]*))";
    regex sablonas(sablono_tekstas, regex::icase);
    int i = 1;
    while(!buf.eof()){
        string eil;
        vector <string> rasti_zodziai;
        getline(buf, eil);
        auto rasti_pr = sregex_iterator(eil.begin(), eil.end(), sablonas);
        auto rasti_pb = sregex_iterator();
        string nauja_eilute = regex_replace(eil, sablonas, " ");
        for (sregex_iterator k = rasti_pr; k != rasti_pb; ++k) {
            smatch zodis_obj = *k;
            string zodis = zodis_obj.str();
            nuorodos.push_back(zodis);
        }
        be_nuor_duom << nauja_eilute << "\n";
        i++;
    }
}

void zodziu_paieska(stringstream& buf, unordered_map<string, pair<int, vector<int>>>& zodziu_sk_vt)
{
    regex sablonas(R"([a-zA-ZąĄčČęĘėĖįĮšŠųŲūŪžŽ]+)");
    int i = 1;
    while(!buf.eof()){
        string eil;
        vector <string> rasti_zodziai;
        getline(buf, eil);
        auto rasti_pr = sregex_iterator(eil.begin(), eil.end(), sablonas);
        auto rasti_pb = sregex_iterator();

        for (sregex_iterator k = rasti_pr; k != rasti_pb; ++k) {
            smatch zodis_obj = *k;
            string zodis = zodis_obj.str();
            auto it = zodziu_sk_vt.find(zodis);
            if (it == zodziu_sk_vt.end()) {
                zodziu_sk_vt.insert({zodis, {1, {i}}});
            }
            else {
                zodziu_sk_vt[zodis].first++;
                bool yra = false;
                for (const int& eil : zodziu_sk_vt[zodis].second)
                {
                    if (i == eil) yra = true;
                }
                if(!yra) zodziu_sk_vt[zodis].second.push_back(i);
            }
        }
        i++;
    }
}

void zodziu_rikiavimas(vector < pair <string, pair<int, vector<int>>> >& zodziu_sk_vt_vec, const unordered_map<string, pair<int, vector<int>>>& zodziu_sk_vt) {
    for (const pair <string, pair<int, vector<int>>>& pora : zodziu_sk_vt){
        zodziu_sk_vt_vec.push_back(pora);
    }
    sort(zodziu_sk_vt_vec.begin(), zodziu_sk_vt_vec.end(), 
    [](pair <string, pair<int, vector<int>>>& a, pair <string, pair<int, vector<int>>>& b) {
        if(a.second.first > b.second.first) return true;
        else if(a.second.first == b.second.first && a.first < b.first) return true;
        else return false;});
}

void zodziu_filtravimas(vector < pair <string, pair<int, vector<int>>>>& zodziu_sk_vt_vec, int& riba) {
    for (auto it = zodziu_sk_vt_vec.begin(); it != zodziu_sk_vt_vec.end(); ++it) {
        if(it->second.first == riba) {
            zodziu_sk_vt_vec.erase(it, zodziu_sk_vt_vec.end());
            break;
        }
    }
}

void spausdinimas_zodziai(const vector < pair <string, pair<int, vector<int>>>>& zodziu_sk_vt_vec) {
    stringstream ss;
    int i = 1;
    ss << left << setw(7) << "Vieta" << left << setw(20) << "Žodis" << left << setw(20) << "Pasikartojimų sk." << left << setw(50) << "Eilutės, kuriose rastas šis žodis" << "\n";
    for (const pair <string, pair<int, vector<int>>>& pora : zodziu_sk_vt_vec) {
        int lauk_pl = 7 - to_string(i).size();
        string ltraides = "ąčęėįšųūž";
        int k = 0;
        for (char raide : pora.first) {
            for (char ltraide : ltraides) {
                if (raide == ltraide) {
                    k++;
                    break;
                }
            }
        }
        ss << left << i++ << left << setw(lauk_pl) << "." << left << setw(19+k-k/2) << pora.first << left << setw(19) << pora.second.first << left;
        for (const int& eil : pora.second.second) {
            ss << left << eil << left << "; ";
        }
        ss << "\n";
    }
    ofstream out ("RezultataiZodziai.txt");
    out << ss.str();
    out.close();
}

void spausdinimas_nuorodos(const vector <string>& nuorodos) {
    ofstream out("RezultataiNuorodos.txt");
    for (const string& nuoroda : nuorodos) {
        out << nuoroda << "\n";
    }
}