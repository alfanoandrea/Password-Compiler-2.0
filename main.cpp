#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#define MAX 200


//-----STARTUP PHRASES------
void getStart(std::string phrases[][MAX]){
  //name
  phrases[0][0] = "\u001b[33mWrite the name (lowercase)\u001b[0m";
  phrases[0][1] = "\u001b[33mScrivi il nome (minuscolo)\u001b[0m";
  //surname
  phrases[1][0] = "\u001b[33mWrite the surname (lowercase)\u001b[0m";
  phrases[1][1] = "\u001b[33mScrivi il cognome (minuscolo)\u001b[0m";
  //birth date
  phrases[2][0] = "\u001b[33mWrite the birth year (DDMMYYYY)\u001b[0m";
  phrases[2][1] = "\u001b[33mScrivi la data di nascita (GGMMAAAA)\u001b[0m";
  //dati corretti
  phrases[3][0] = "\u001b[36m         NAME \u001b[35m-->  \u001b[0m";
  phrases[3][1] = "\u001b[36m             NOME \u001b[35m-->  \u001b[0m";
  phrases[4][0] = "\u001b[36m      SURNAME \u001b[35m-->  \u001b[0m";
  phrases[4][1] = "\u001b[36m          COGNOME \u001b[35m-->  \u001b[0m";
  phrases[5][0] = "\u001b[36m   BIRTH DATE \u001b[35m-->  \u001b[0m";
  phrases[5][1] = "\u001b[36m  DATA DI NASCITA \u001b[35m-->  \u001b[0m";
  phrases[6][0] = "Are you sure? (y / n) -->  ";
  phrases[6][1] = "Sei sicuro? (y / n) -->  ";
  //name file
  phrases[7][0] = "\u001b[33mGive a name to the file to generate: \u001b[37m\n  --> ";
  phrases[7][1] = "\u001b[33mDai un nome al file da generare: \u001b[37m\n  --> ";
  //has been created
  phrases[8][0] = "The file \u001b[32;1m \u001b[0m has been created!"; //half at -> 21 from 0
  phrases[8][1] = "Il file \u001b[32;1m \u001b[0m e' stato creato!"; // -> 20 from 0 
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
  system("clear");
  if (time == true)
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "\u001b[32m";
  std::cout << "  _____                             _  \n";
  std::cout << " |  _  |___ ___ ___ _ _ _ ___ ___ _| | \n";
  std::cout << " |   __| .'|_ -|_ -| | | | . |  _| . | \n";
  std::cout << " |__|  |__,|___|___|_____|___|_| |___| \n \n";
  if (time == true)
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "    _____               _ _          \n";
  std::cout << "   |     |___ _____ ___|_| |___ ___  \n";
  std::cout << "   |   --| . |     | . | | | -_|  _| \n";
  std::cout << "   |_____|___|_|_|_|  _|_|_|___|_|   \n";
  std::cout << "                   |_|               \n \n";
  if (time == true)
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "\n  \u001b[35m       by alfanowski & lorex \n \n";
  std::cout << "\u001b[0m";
  if (time == true)
    getchar();
  std::cout
      << "\u001b[31m----------------------------------------\u001b[0m\n\n";
  time = false;
}

int main() {
  //startup phrases
  
  std::string frasi[MAX][MAX];
  getStart(frasi);
  
  int language;
  bool time = true;
  char correct;
  std::string file, nome, cognome, nascita, maiuscnome, maiuscognome,
      abbrevanno, giorno, mese, anno;

  do {
    if (time == true) {
      intro(time);
      time = false;
    } else
      intro(time = false);
    std::cout << "\u001b[33mSelect your language\u001b[0m \n"
              << "1. ENGLISH \n"
              << "2. ITALIAN \n";             
    std::cin >> language;
  } while (language != 1 and language != 2);
  
  language--;

    do {
      intro(time = false);
      std::cout << frasi[0][language] << "\n";
      std::cin >> nome;
      std::cout << "\n" << frasi[1][language] << "\n";
      std::cin >> cognome;
      do {
        std::cout << "\n" << frasi[2][language] << "\n";
        std::cin >> nascita;
      } while (nascita.length() != 8);

      do {
        intro(time = false);
        std::cout << frasi[3][language] << nome << '\n'
                  << frasi[4][language] << cognome << '\n'
                  << frasi[5][language] << nascita.at(0) << nascita.at(1) << "/" << nascita.at(2)
                  << nascita.at(3) << "/" << nascita.at(4) << nascita.at(5)
                  << nascita.at(6) << nascita.at(7)
                  << "\n \n" << frasi[6][language];
        std::cin >> correct;
      } while (correct != 'y' and correct != 'n' and correct != 'Y' and
               correct != 'N');
    } while (correct != 'y' and correct != 'Y');

  giorno = nascita.substr(0, 2);
  mese = nascita.substr(2, 2);
  anno = nascita.substr(4, 4);
  abbrevanno = nascita.substr(6, 2);

  intro(time = false);

    std::cout
        << frasi[7][language];
    std::cin >> file;

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
  code({nome, cognome, giorno, mese, anno, abbrevanno, maiuscnome, ".", "@", "_", "-", "!", },
    upcase, file);

  intro(time = false);

    int indicerestart =frasi[8][language].find("1m", 0)+2;
    std::cout << frasi[8][language].substr(0, indicerestart) << file
              << frasi[8][language].substr(indicerestart+1);
  
  getchar();

  return 0;
}