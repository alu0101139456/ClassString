#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "string.hpp"



int main() { 

  

  char palabra[20] = "Hola que tal bombon";

  // char* puntero = &palabra[0];
  
 
  String test(4 , 'a');
  String A("ObjetoA");
  
  test.push_back('b');
  A.push_back('C');

  String prueba("Replace prueba de que no estoy inspirada oioioi"); 

  // prueba.replace(7, 6, A); 

  prueba.substr(8);

  prueba.split(); 

  test += A;


}