#pragma once

#include <iostream>
#include <vector>

class String {

 private:
  static const int npos_ = -1;
  char *cadena_;
  int sz_;

 public:
  String();
  String(const char* cadena);
  String(const String& str);
  String(const String& str, int pos, int sz=npos_);
  String(int sz, char crtr);

  ~String();

  int length() const;
  const char* c_str() const;
  
  char at(int pos) const;
  char& at(int pos);

  char front() const;
  char& front();
  char back() const;
  char& back();

  void push_back(char ch);
  //pop_back
  void clear();

  //append

  char& operator[](int pos);
  char operator[](int pos) const;

  String& operator=(const String &str);
  String& operator=(const char &chr);

  String& operator+=(const String &str);
  String& operator+=(const char &chr); //fijarse si hasce falta dejarlo como referencia

  String& replace(int pos, int sz, const String &str);
  String& replace(const String &subStr, const String &newStr2);
  String& replace_all(const String &subStr, const String &newStr2);

  String& substr(int pos, int length=npos_);

  std::vector<String>& split(char delimit=' ');

  String join(std::vector<String> &vStr, char joint=' ');
  //String join(std::vector<String> &vStr, String joint);

  //trim -> Coge los espacios o tabuladores por los extremos y los quita

 private:

  void resize(int length);
  

};

String operator+(const String &str1, const String &str2);
std::ostream& operator<<(std::ostream& os, const String &str);
std::istream& operator>>(std::istream& is, const String &str);

bool operator==(const String &str1, const String &str2);
bool operator!=(const String &str1, const String &str2);