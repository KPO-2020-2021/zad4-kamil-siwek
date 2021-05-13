// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "Matrix4x4.hh"
#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "Prism.hh"
#include "lacze_do_gnuplota.hh"

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */

#define DL_KROTKI_BOK 50
#define DL_DLUGI_BOK 70
#define DL_SREDNI_BOK 60
/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia(std::ostream &StrmWy,
                                             double Przesuniecie)
{
  //---------------------------------------------------------------
  // To tylko przyklad !!!
  // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych
  // zmiennych do reprezentowania wspolrzednych!
  //
  double x1, y1, x2, y2, x3, y3, x4, y4;

  x1 = y1 = 10;
  x2 = x1 + DL_DLUGI_BOK;
  y2 = y1;
  x3 = x2;
  y3 = y2 + DL_KROTKI_BOK;
  x4 = x3 - DL_DLUGI_BOK;
  y4 = y3;

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x1 + Przesuniecie
         << std::setw(16) << std::fixed << std::setprecision(10) << y1 + Przesuniecie << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x2 + Przesuniecie
         << std::setw(16) << std::fixed << std::setprecision(10) << y2 + Przesuniecie << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x3 + Przesuniecie
         << std::setw(16) << std::fixed << std::setprecision(10) << y3 + Przesuniecie << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x4 + Przesuniecie
         << std::setw(16) << std::fixed << std::setprecision(10) << y4 + Przesuniecie << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x1 + Przesuniecie
         << std::setw(16) << std::fixed << std::setprecision(10) << y1 + Przesuniecie << std::endl;
  // Jeszcze raz zapisujemy pierwszy punkt,
  // aby gnuplot narysowal zamkniętą linię.
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku(const char *sNazwaPliku, Prism rec)
{
  std::ofstream StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())
  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
              << ":(  nie powiodla sie." << std::endl;
    return false;
  }
  std::cout << rec;
  StrmPlikowy << rec;
  StrmPlikowy << rec[0] << std::endl;
  StrmPlikowy << rec[1] << std::endl;
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

int main()
{
  std::cout << "C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK
            << std::endl;
  std::system("cat ../LICENSE");

  PzG::LaczeDoGNUPlota Lacze;
  //-------------------------------------------------------
  //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
  //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
  //  na dwa sposoby:
  //   1. Rysowane jako linia ciagl o grubosci 2 piksele
  //
  Lacze.DodajNazwePliku("../datasets/Prostopadloscian.dat", PzG::RR_Ciagly, 2);
  //
  //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
  //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
  //  jako wspolrzedne punktow podajemy x,y,z.
  //
  Lacze.ZmienTrybRys(PzG::TR_3D);

  // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-155, 155);
  Lacze.UstawZakresX(-155, 155);
  Lacze.UstawZakresZ(-155, 155);

  double wec3[] = {20, 20, 30};
  Vector<3> argumentsV(wec3);
  funkcja(10,30,40,argumentsV);
  Prism rec(argumentsV, DL_KROTKI_BOK, DL_DLUGI_BOK, DL_SREDNI_BOK);
  char opcja;
  Matrix<3> mac_powtorzenia;
  double kat;
  char os;
  double wek[2];
  std::cout << "\n\n" << std::endl;
  std::cout << "o - obrot bryly o zadana sekwencje katow" << std::endl;
  std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
  std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
  std::cout << "m - wyswietl menu" << std::endl;
  std::cout << "k - koniec dzialania programu\n" << std::endl;

  while (opcja != 'k')
  {
    if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Prostopadloscian.dat", rec))
      return 1;
    Lacze.Rysuj();
    std::cin >> opcja;
    switch (opcja)
    {
    case 'o':
    {
      Matrix<3> mac;
      while (1)
      {
        std::cout << "os" << std::endl;
        std::cin >> os;
        if (os == '.')
          break;
        std::cout << "jaki kat" << std::endl;
        std::cin >> kat;
        if (os == 'x')
          mac = mac * obr_x(kat);
        if (os == 'y')
          mac = mac * obr_y(kat);
        if (os == 'z')
          mac = mac * obr_z(kat);
      }
      mac_powtorzenia = mac;
      rec.rotacion(mac);
    }
    break;
    case 't':
    {
      rec.rotacion(mac_powtorzenia);
    }
    break;
    case 'p':
    {
      double x, y, z;
      std::cin >> x >> y >> z;
      wek[0] = x;
      wek[1] = y;
      wek[2] = z;
      Vector<3> tmpV1(wek);
      rec.move(tmpV1);
    }
    break;
    case 'w':
    {
      std::cout << rec;
    }
    break;
    case 'm':
    {
      std::cout << "\n\n" << std::endl;
      std::cout << "o - obrot bryly o zadana sekwencje katow" << std::endl;
      std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
      std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
      std::cout << "m - wyswietl menu" << std::endl;
      std::cout << "k - koniec dzialania programu\n" << std::endl;
    }
    break;
    }
    //kod rysujacy w gnuplocie
  }
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
