#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#define MAX 15

class Color {
public:
    static std::string violet;
    static std::string red;
    static std::string cyan;
    static std::string green;
    static std::string yellow;
    static std::string fucsia;
    static std::string gray;
    static std::string reset;
};

std::string Color::violet = "\033[35m";
std::string Color::red = "\u001b[31m";
std::string Color::cyan = "\u001b[36m";
std::string Color::green = "\u001b[32m";
std::string Color::yellow = "\u001b[33m";
std::string Color::fucsia = "\u001b[35;1m";
std::string Color::gray = "\033[90m";
std::string Color::reset = "\u001b[0m";

void cls() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//-----STARTUP PHRASES------
void getStart(std::string phrases[][MAX]) {
    phrases[0][0] = Color::red + " >> " + Color::reset;
    phrases[0][1] = Color::violet + " -->  " + Color::reset;
    // language
    phrases[0][2] = Color::yellow + "Select your language\n" + Color::reset + "1. ENGLISH\n" + "2. ITALIAN\n";
    // name
    phrases[1][0] = Color::yellow + "Write the name (lowercase)\n" + Color::reset;
    phrases[1][1] = Color::yellow + "Scrivi il nome (minuscolo)\n" + Color::reset;
    // surname
    phrases[2][0] = Color::yellow + "Write the surname (lowercase)\n" + Color::reset;
    phrases[2][1] = Color::yellow + "Scrivi il cognome (minuscolo)\n" + Color::reset;
    // birth date
    phrases[3][0] = Color::yellow + "Write the birth year (DDMMYYYY)\n" + Color::reset;
    phrases[3][1] = Color::yellow + "Scrivi la data di nascita (GGMMAAAA)\n" + Color::reset;
    // dati corretti
    phrases[4][0] = Color::cyan + "         NAME" + Color::reset;
    phrases[4][1] = Color::cyan + "             NOME" + Color::reset;
    phrases[5][0] = Color::cyan + "      SURNAME" + Color::reset;
    phrases[5][1] = Color::cyan + "          COGNOME" + Color::reset;
    phrases[6][0] = Color::cyan + "   BIRTH DATE" + Color::reset;
    phrases[6][1] = Color::cyan + "  DATA DI NASCITA" + Color::reset;
    phrases[7][0] = "Are you sure? (y / n)\n" + Color::reset;
    phrases[7][1] = "Sei sicuro? (y / n)\n" + Color::reset;
    // name file
    phrases[8][0] = Color::yellow + "Give a name to the file to generate (without .txt)\n" + Color::reset;
    phrases[8][1] = "Dai un nome al file da generare (senza .txt)\n" + Color::reset;
    phrases[9][0] = Color::cyan + "         FILE" + Color::reset;
    phrases[10][0] = Color::gray + ".txt" + Color::reset;
    // has been created
    phrases[11][0] = "The file   has been created!";
    phrases[11][1] = "Il file   e' stato creato!";
}

void code(std::vector<std::string> data, std::vector<std::string> uppercase,
    std::string file) {

    for (int i = 0; i < uppercase.size(); ++i) {
        data.push_back(uppercase[i]);
    }

    std::ofstream f(file);
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.size(); j++) {
            for (int k = 0; k < data.size(); k++) {
                if (i < 6 && i != j && j != k && i != k) {
                    f << data[i] + data[j] + data[k] + "\n";
                }
            }
        }
    }

    for (int i = 0; i < data.size(); i++) {
        if (i > 5)
            continue;
        for (int j = 0; j < data.size(); j++) {
            if (i == j)
                continue;
            for (int k = 0; k < data.size(); k++) {
                if (i == k || j == k)
                    continue;
                for (int l = 0; l < data.size(); l++) {
                    if (i == l || j == l || k == l)
                        continue;
                    f << data[i] + data[j] + data[k] + data[l] + "\n";
                }
            }
        }
    }
    f.close();
}

void intro(bool time) {
    cls();
    if (time)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << Color::green;
    std::cout << "   _____                             _  \n";
    std::cout << "  |  _  |___ ___ ___ _ _ _ ___ ___ _| | \n";
    std::cout << "  |   __| .'|_ -|_ -| | | | . |  _| . | \n";
    std::cout << "  |__|  |__,|___|___|_____|___|_| |___| \n \n";
    if (time)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "     _____               _ _          \n";
    std::cout << "    |     |___ _____ ___|_| |___ ___  \n";
    std::cout << "    |   --| . |     | . | | | -_|  _| \n";
    std::cout << "    |_____|___|_|_|_|  _|_|_|___|_|   \n";
    std::cout << "                    |_|               \n \n";
    if (time)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << Color::violet << "\n  by alfanowski & lorex   " << Color::reset
        << "version: 2.2\n";
    if (time)
        getchar();
    else
        std::cout << "\n";
    std::cout << Color::red << "------------------------------------------\n\n"
        << Color::reset;
    time = false;
}

int main() {
    std::string frasi[MAX][MAX];
    bool time = true;
    int language;
    char correct, sel;
    std::string file, nome, cognome, nascita, maiuscnome, maiuscognome,
        abbrevanno, giorno, mese, anno;

    // startup phrases
    getStart(frasi);

    do {
        if (time) {
            intro(time);
            time = false;
        }
        else
            intro(time = false);
        std::cout << frasi[0][2] << frasi[0][0];
        std::cin >> sel;
    } while (sel != '1' and sel != '2');

    language = sel - '0';
    language--;

    do {
        intro(time = false);
        // nome
        std::cout << frasi[1][language] << frasi[0][0];
        std::cin >> nome;
        // cognome
        std::cout << "\n" << frasi[2][language] << frasi[0][0];
        std::cin >> cognome;
        do {
            // data di nascita
            std::cout << "\n" << frasi[3][language] << frasi[0][0];
            std::cin >> nascita;
        } while (nascita.length() != 8);

        do {
            intro(time = false);
            // dati corretti
            std::cout << frasi[4][language] << frasi[0][1] << nome << "\n";
            std::cout << frasi[5][language] << frasi[0][1] << cognome << "\n";
            std::cout << frasi[6][language] << frasi[0][1]
                << nascita.at(0) << nascita.at(1)
                << "/" << nascita.at(2) << nascita.at(3) << "/" << nascita.at(4)
                << nascita.at(5) << nascita.at(6) << nascita.at(7) << "\n \n";
            std::cout << frasi[7][language] << frasi[0][0];
            std::cin >> correct;
        } while (correct != 'y' and correct != 'n' and correct != 'Y' and
            correct != 'N' and correct != 'S' and correct != 's');
    } while (correct != 'y' and correct != 'Y' and correct != 'S' and
        correct != 's');

    giorno = nascita.substr(0, 2);
    mese = nascita.substr(2, 2);
    anno = nascita.substr(4, 4);
    abbrevanno = nascita.substr(6, 2);

    // file
    do {
        intro(time = false);
        std::cout << frasi[8][language] << frasi[0][0];
        std::cin >> file;    
        do {
            intro(time = false);
            std::cout << frasi[9][0] << frasi[0][1] << file << frasi[10][0] << "\n \n";
            std::cout << frasi[7][language] << frasi[0][0];
            std::cin >> correct;
        } while (correct != 'y' and correct != 'n' and correct != 'Y' and
            correct != 'N' and correct != 'S' and correct != 's');  
    } while (correct != 'y' and correct != 'Y' and correct != 'S' and
        correct != 's');

    file += ".txt";

    std::string nome1 = nome;
    std::vector<std::string> upcase;
    for (int i = 0; i < nome.size(); ++i) {
        nome1[i] = toupper(nome1[i]);
        upcase.push_back(nome1);
        nome1 = nome;
    }

    maiuscnome = nome;
    maiuscnome[0] = toupper(maiuscnome[0]);
    code({nome, cognome, giorno, mese, anno, abbrevanno, maiuscnome, ".", "@", "_", "-", "!",}, upcase, file);

    intro(time = false);
    // file generato
    int indicerestart = frasi[11][language].find("le ", 0) + 3;
    std::cout << frasi[11][language].substr(0, indicerestart) << Color::green
        << file << Color::reset
        << frasi[11][language].substr(indicerestart + 1);

    getchar();
    getchar();
    cls();

    return 0;
}
