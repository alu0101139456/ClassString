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
  

}