#pragma once

#include <iostream>
#include <vector>

class String
{

private:
  static const int npos_ = -1;
  // char *cadena_;
  char *cadena_ = nullptr;
  int sz_;

public:
  /**
   * @brief Constructor por defecto. (sz_ = 0 y char *cadena = nullptr)
   **/
  String();

  /**
   * @brief Constructor from char to string 
   * @param cadena Puntero de tipo char 
   **/ 
  String(const char *cadena);

  /**
   * @brief Constructor de copia
   * @param str Referencia de un string que se quiere copiar 
   **/ 
  String(const String &str);

  /**
   * @brief Constructor que convierte un string a un substring 
   * @param str Referencia del string que se quiere cambiar 
   * @param pos Posición que se quiere empezar a cambiar 
   * @param sz Hasta donde se quiere cambiar el string 
   **/
  String(const String &str, int pos, int sz = npos_);

  /** 
   * @brief Constructor que rellena con un caracter
   * @param sz Tamaño que se quiere rellenar 
   * @param crtr Caracter con el que se quiere rellenar 
   **/ 
  String(int sz, char crtr);

  /** 
   * @brief Destructor que limpia la memoria dinámica con el delete
   **/ 
  ~String();

  /** 
   * @return Devuelve el tamaño del string
   **/ 
  int length() const;

  /**
   * @return Devuelve el string
   **/ 
  const char *c_str() const;

  /**
   * @param pos Posición que se quiere acceder
   * @return Devuelve lo que hay en la posición del parámetro
   **/ 
  char at(int pos) const;
  char &at(int pos);

  /**
   * @return Devuelve el caracter de la primera posición del string
   **/
  char front() const;
  char &front();

  /**
   * @return Devuelve el último caracter del string 
   **/ 
  char back() const;
  char &back();

  /**
   * @brief Pone un caracter al final de la cadena
   * @param ch Caracter que ingresa en la cadena por el final
   **/ 
  void push_back(char ch);
  //pop_back

  /**
   * @brief Lo que está apuntando el objeto temporal pasa a nuestro atributo cadena
   **/ 
  void clear();

  //append

  /**
   * @brief Operador que facilita el acceso al string 
   **/ 
  char &operator[](int pos);
  char operator[](int pos) const;

  /**
   * @brief Operador que iguala dos string
   **/ 

  String &operator=(const String &str);
  String &operator=(const char &chr);

  /**
   * @brief Operador que suma dos string 
   **/

  String &operator+=(const String &str);
  String &operator+=(const char &chr); //fijarse si hasce falta dejarlo como referencia

  /**
   * @brief Método que reemplaza la cadena desde una determinada posición
   * @param pos Posición desde la que se quiere reemplazar
   * @param sz Longitud que se quiere reemplazar
   * @param str Palabra que se quiere reemplazar
   * @return Devuelve una nueva string 
   **/

  String &replace(int pos, int sz, const String &str);

  /**
   * @brief Método que reemplaza una palabra por otra dentro de la cadena
   * @param subStr Palabra que se quiere reemplazar
   * @param newStr2 Palabra que se quiere poner en la cadena
   * @return Devuelve una nueva string 
   **/
  String &replace(const String &subStr, const String &newStr2);
  String &replace_all(const String &subStr, const String &newStr2);

  /** 
   * @brief Proporciona un substring desde la poscición hasta el tamaño deseado
   * @param pos Posición desde la que se quiere el substring
   * @param lenght Tamaño que se quiere del substring
   * @return Devuelve una referencia del substring 
   **/ 
  // String &substr(int pos, int length = npos_);

  String substr(int pos, int length = npos_);

  /**
   * @brief Separa las palabras de una cadena y las mete en un vector de string
   * @param demilit Delimitador para separar las palabras
   * @return Devuelve un vector de string
   **/

  std::vector<String> split(char delimit = ' ');

  /**
   * @brief Une las palabras del vector de string en una cadena
   * @param str Vector de string que contiene las string que se quieren juntar
   * @param joint Va a unirlas por espacios por defecto. 
   * @return Devuelve la string con las palabras del vector unidas
   **/ 

  String join(std::vector<String> &vStr, char joint = ' ');
  //String join(std::vector<String> &vStr, String joint);

  //trim -> Coge los espacios o tabuladores por los extremos y los quita

private:
  void resize(int length);
};

  /**
   * @brief Operador que suma dos string 
   * @param str1 String que se quiere sumar
   * @param str2 String que se quiere sumar
   * @return Devuelve una nueva string
   **/
String operator+(const String &str1, const String &str2);

  /**
   * @brief Operador de salida 
   **/

std::ostream &operator<<(std::ostream &os, const String &str);

  /**
   * @brief Operador de entrada 
   **/
std::istream &operator>>(std::istream &is, const String &str);

  /**
   * @brief Operador que comprueba si dos strig son iguales
   * @param str1 String que se quiere comparar
   * @param str2 String que se quiere comparar
   * @return Devuelve true o false  
   **/
bool operator==(const String &str1, const String &str2);

 /**
   * @brief Operador que comprueba si dos strig son diferentes
   * @param str1 String que se quiere comparar
   * @param str2 String que se quiere comparar
   * @return Devuelve true o false 
   **/
bool operator!=(const String &str1, const String &str2);