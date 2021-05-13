#pragma once

#include "matrix.hh"

typedef Matrix<4> Matrix4x4;


void funkcja(double alfa, double beta, double gamma , Vector<3> translacja)
{
    alfa=alfa*M_PI/180;
      beta=beta*M_PI/180;
        gamma=gamma*M_PI/180;
    Matrix4x4 wynik;
      wynik(0, 0) = cos(alfa)*cos(beta);
    wynik(0, 1) = cos(alfa)*sin(beta)*sin(gamma)-sin(alfa)*cos(gamma);
    wynik(0, 2) =sin(alfa)*sin(beta)*cos(gamma)+sin(alfa)*sin(gamma);
 wynik(0, 3) = translacja[0];

    wynik(1, 0) = sin(alfa)*cos(beta);
    wynik(1, 1) =  sin(alfa)*sin(beta)*sin(gamma)+cos(alfa)*cos(gamma);
    wynik(1, 2) = sin(alfa)*sin(beta)*cos(gamma)-cos(alfa)*sin(gamma);
 wynik(1, 3) =translacja[1];

    wynik(2, 0) = -sin(beta);
    wynik(2, 1) = cos(beta)*sin(gamma);
    wynik(2, 2) = cos(beta)*cos(gamma);
     wynik(2, 3) = translacja[2];

         wynik(3, 0) = 0;
    wynik(3, 1) = 0;
    wynik(3, 2) = 0;
     wynik(3, 3) = 1;
     std::cout<<wynik;
}