# Nuorodų ir žodžių išrinkimas iš duomenų failo

<b>Matas Kantautas <br>
Vilniaus universiteto duomenų mokslo programa <br>
Objektinio programavimo praktinė egzamino užduotis </b> <br>

**V1.0** <br>

Išleidžiama programa gebanti iš tekstinio duomenų failo:
1. išrinkti visas jame esančias nuorodas (pagal domenų sąrašą, esantį https://data.iana.org/TLD/tlds-alpha-by-domain.txt (2025-12-17 duomenimis, sąrašą rasite faile `nuorodu_galuniu_sarasas.txt`));
2. išrinkti visus jame esančius žodžius, kuriose eilutėse jie randami, kiek kartų jie pasikartoja duomenyse bei pagal jų dažnumą juos išrikiuoti;
3. rezultatus atspausdinti į du failus:
   * `RezultataiZodziai.txt` – gaunama lentelė su visais žodžiais, pasikartojusiais bent 2 kartus, jų vieta pagal dažnumą tarp visų rastų žodžių bei eilučių numeriais, kuriose tie žodžiai rasti;
   * `RezultataiNuorodos.txt` – gaunamos visos tekste esančios nuorodos į interneto tinklapius;
