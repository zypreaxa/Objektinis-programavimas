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

  
