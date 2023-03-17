# Objektinis-programavimas
<sub>1 kurso objektinio programavimo modulio darbų repozitorija.</sub>

# v0.1
Pirmoji versija turi du variantus:

- Kodas, kuriame naudojami C masyvai.
- Kodas, kuriame naudojami vektoriai.

**Abu failai naudoja universalią asmeninę biblioteką.**

# v0.2
## Kas naujo?
Kodas papildytas taip, kad galėtų nuskaityti pasirinktą tekstinį failą ir išvesti jo duomenis konsolėje pagal pasirinktą rikiavimą.
Tą pasiekti reikėjo:

- Atnaujinti asmeninę biblioteką.
  - įtrauktos dažnai naudojamos bibliotekos, skirtos failo nuskaitymui (ifstream, stringstream).

- Pridėti funkcijas, kurių tikslas nuskaityti pasirinktą .txt failą.
  - element_count() - eilutės elementų skaičiavimas. 
  - counter() - eilučių skaičiavimas. Abi funkcijos naudojamos atpažinti failo dydį ir pagal tai priskirti nuskaitytus duomenis studento struktūrai.

- Pridėti papildomą funkciją, kuri išrūšiuotų studento sąrašą *vector<Studentas> sarasas* pagal pirmąją vardo raidę.

*Nuo šios versijos buvo pradėtas vesti ***README.md*** failas*
# v0.3
## Kas naujo?
Kadangi projektas buvo sukeltas į vieną bloką, teko jį išskaidyti į kelis skirtingus dokumentus.
Jis buvo išskaidytas į:

- *fun.h* failą.
  - į šį failą perkelta *Studentas* struktūra ir jos deklaracijos, taip pat deklaruotos visos projekte naudojamos funkcijos (išskyrus *main()*).

- Source failus, kuriuose sudėtos tam tikro tipo funkcijos:
  - rankinės įvesties funkcijos.
  - failo nuskaitymo funkcijos.
  - spausdinimo funkcijos.
  
Taip pat buvo pridėtas *try/catch*, taigi jei yra įvedamas neegzistuojantis failo pavadinimas, programa jo neatpažįsta ir negrąžina tuščios išvesties.
  
# v0.4
## Kas naujo?
Visas projektas buvo šiek tiek pakoreguotas siekiant optimizuoti programos veikimo laiką ir išmatuoti jos spartą. 
- Pridėtas *windows.h* failas, kurį naudoja _showloadingindicator_ funkcija. Ji naudojama parodyti vartotojui, kad programa iš tiesų veikia.
- Visas I/O perkeltas į atskirą failą dėl patogumo. Taip main programa atrodo daug švaresnė.
- Pakeista kaip atrodo user interface. Vartotojui duodama žymiai daugiau pasirinkimų, pridėti *try/catch* ten, kur jų labai reikėjo. *Input* pasirinkimai intuityvesni.

Pagal užduoties reikalavimus buvo pridėti/pakeisti šie programos komponentai:
- Pakeista:
  - *read_file()* funkcija. Dabar naudojamas *istringstream* bufferis.
  - Visoms reikalingoms funkcijoms pagal užduoties reikalavimus buvo pridėtos laiko matavimo priemonės.
  - Pakeistas projekto /Ox flag. Tai turėtų pagreitinti programos veikimą.
- Pridėta:
  - *generate()* funkcija, kuri generuoja norimą failą. Priklausomai nuo to, kaip funkcija yra naudojama, galima sukurti norimą įrašų failą.
  - *requirement_generate()* funkcija, kuri pasitelkia *generate()* ir sukuria failus pagal užduoties reikalavimus.
  - Studentų suskirstymo, išrūšiavimo ir išvedimo funkcijos, kurios atskiria protingus ir ne tokius protingus studentus.
  - Pridėtas loading indikatorius, kuris leidžia vartotojui suprasti kad programa vykdo nurodymus.
  
Padaryta programos trukmės duomenų lentelė:
| Stud. skaičius | Generavimo trukmė (s) | Nuskaitymo trukmė (s) | Rūšiavimo trukmė (s) | Išvedimas į du failus |
|----------------|-----------------------|-----------------------|----------------------|-----------------------|
| 1000           | 0,26                  | 0,26                  | 0,26                 | 0,26                  |
| 10000          | 0,26                  | 0,26                  | 0,26                 | 0,26                  |
| 100000         | 0,50                  | 4,07                  | 0,26                 | 2,06                  |
| 1000000        | 5,40                  | 40,34                 | 2,34                 | 31,33                 |
| 10000000       | 50,04                 | 410,02                | 20,03                | 152,07                |
  
** Visos programos veikimo laiką išmatuoti įmanoma bet beprasmiška, nes labai dažnai reikalaujama vartotojo įvesčių. Kiekvieną kartą atidarius programą gaunamas vis kitoks laikas, nes vartotojas ne visada pasirenka ką nori daryti per tą patį laiko tarpsnį. **
  
  

  
