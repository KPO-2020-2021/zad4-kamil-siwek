#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector.hh"
#include "matrix.hh"
#include "Prism.hh"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.


TEST_CASE("test wektora kostruktor")
{
    Vector<3> tmp; 
    CHECK(tmp[0]== 0);
    CHECK(tmp[1]== 0); 
}

TEST_CASE("test wektora kostruktor parametycznego")
{
    double wek[]={2,3,5};
    Vector<3> tmp(wek);
    CHECK(tmp[0]== 2); 
    CHECK(tmp[1]== 3); 
} 

TEST_CASE("test wektora +")
{
    double wek[]={2,3,5}; 
    Vector<3> tmp(wek); 
    Vector<3> tmp2(wek); 
    tmp2 = tmp2 + tmp; 
    CHECK(tmp2[0]== 4); 
    CHECK(tmp2[1]== 6); 
}

TEST_CASE("sprawdzenie []") 
{
    double wek[]={2,3,5}; 
    Vector<3> tmp(wek); 
    WARN_THROWS(tmp[10]); 
}

TEST_CASE("wektor - wyswietlanie standard") 
{
    double wek[]={2,3,5}; 
    Vector<3> tmp(wek); 
    std::ostringstream out; 
    out <<tmp; 
    CHECK( "2 3 5 " == out.str() ); 
}

TEST_CASE("wektor - wczytywanie standard") 
{ 
    Vector<3> tmp;
    std::istringstream in("3 4"); 
    in >> tmp; 
    std::ostringstream out; 
    out <<tmp;
    CHECK( "3 4 0 " == out.str() ); 
} 

TEST_CASE("test wektora ==") 
{ 
    Vector<3> tmp,tmp2; 
    CHECK( tmp==tmp2 );
}




TEST_CASE("test macierzy kostruktor")
{ 
    Matrix<3> tmp;
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(i==j)
    CHECK(tmp(i,j)== 1);
    else 
     CHECK(tmp(i,j)== 0); 
}



TEST_CASE("test wektora *")
{
    Matrix<3> tmp;
    double wek[]={2,3,5};
    Vector<3> tmp2(wek);
    tmp2 = tmp * tmp2;
    CHECK(tmp2[0]== 2.0);
    CHECK(tmp2[1]== 3.0);
    CHECK(tmp2[2]== 5.0);
} 

TEST_CASE("sprawdzenie ()")
{
    Matrix<3> tmp;
    WARN_THROWS(tmp(12,31));
}





TEST_CASE("test prostokata kostruktor parametycznego")
{
    double wek[]={0,0};
    Prism tmp(Vector<3>(wek),10,10,10);
    CHECK(tmp[0][0]== 0);
    CHECK(tmp[0][1]== 0);
}

TEST_CASE("prostokata - wyswietlanie standard") 
{
    double wek[]={0,0};
    Prism tmp(Vector<3>(wek),10,10,10);
    std::ostringstream out;
    out <<tmp; 
    CHECK( "0 0 0 \n10 0 0 \n\n0 10 0 \n10 10 0 \n\n0 10 10 \n10 10 10 \n\n0 0 10 \n10 0 10 \n\n" == out.str() ); 
}

TEST_CASE("test prostokata kostruktor parametycznego")
{
    double wek[]={0,0};
    Prism tmp(Vector<3>(wek),10,10,10);
    double wek2[]={10,10};
    tmp.move(Vector<3>(wek2));
    CHECK(tmp[0][0]== 10);
    CHECK(tmp[0][1]== 10); 
}

TEST_CASE("test prostokata kostruktor parametycznego")
{
    Matrix<3> tmpM3;
    double wek[]={0,0};
    Prism tmp(Vector<3>(wek),10,10,10);
    
    CHECK(tmp[0][0]== 0);
    CHECK(tmp[0][1]== 0);
} 
