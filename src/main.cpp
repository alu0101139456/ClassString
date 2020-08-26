#include <iostream>
#include <vector>
#include <algorithm>
#include "string.hpp"


int main() { 

  std::cout << "Creamos un string a partir de una cadena de char." << std::endl;
  String test("Texto de prueba de una cadena de caracteres.");
  std::cout << "Objeto string creado: " << test << std::endl;
  String copyTest(test);
  std::cout << "Se crea objeto copyTest usando contructor de copia." << std::endl;
  std::cout << "Cadena copiada: " << copyTest << std::endl;
  String subTest( copyTest, 0, 15);
  std::cout << "Se crea substring por constructor." << std::endl;
  std::cout << "Resultado: " << subTest << std::endl;
  String charTest(10, 'a');
  std::cout << "Constructor que rellena con 10 aes. Resultado: " << charTest << std::endl;
  std::cout << "Tamaño del SubString: " << subTest.length() << std::endl;
  std::cout << "Primer caracter del SubString (front) : " << subTest.front() << std::endl;
  std::cout << "Último caracter del SubString (back) : " << subTest.back() << std::endl;
  charTest.push_back('B');
  std::cout << "Hacemos un push_back de una B despues de las 10 aes: " << charTest << std::endl;
  std::cout << "Hacemos un clear sobre el string anterior. " << std::endl;
  charTest.clear();
  std::cout << "Contenido del string anterio: " << charTest << std::endl;
  std::cout << "---> " << test << std::endl;
  std::cout << "Reemplazamos \"cadena\" por \"REEMPLAZADA\"" << std::endl;
  test.replace(22, 6, "REEMPLAZADA");
  std::cout << "---> " << test << std::endl;

  // String temp = test.substr(9,6);
  // std::cout << temp << std::endl;

  
  // std::cout << "Reemplazamos \"REEMPLAZADA de caracteres\" por \"clase\"" << std::endl;
  // test.replace("REEMPLAZADA de caracteres", "clase");
  // std::cout << "---> " << test << std::endl;

  std::cout << "Prueba de split con test: " << test << std::endl;
  std::vector<String> vString = test.split();
  for (int i = 0; i < vString.size(); i++) {
    std::cout << "  [" << i << "]" << vString[i];
  }



  
  std::cout << "\nPrueba de join con vString: " << std::endl;
  std::cout << "Resultado: " < << std::endl;



  // std::cout << aux << std::endl;
  // // std::cout << "Creamos un subString \"prueba\" usando substr de test" << std::endl;
  // test.substr(9,6);




  return 0;
}