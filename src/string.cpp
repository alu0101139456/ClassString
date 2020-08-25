#include "string.hpp"

String::String() {
  sz_ = 0;
  cadena_ = new char[sz_];
}

String::String(const char *cadena){
  int count = 0; 
  while ( cadena[count] != '\0') {
    count++;
  }
  sz_ = count;
  cadena_ = new char[count];

  for (int i = 0; i < sz_; i++) {
    cadena_[i] = cadena[i];
  }
    
}


String::String(const String &str) {
  sz_ = str.sz_;
  cadena_ = new char[sz_];

  for (int i = 0; i < sz_; i++) {
    cadena_[i] = str.cadena_[i];
  }
  
}


String::String(const String &str, int pos, int sz){
  
  int newSize = str.sz_ - pos;
  int i=0;  
  if( sz == npos_) {
    cadena_ = new char[newSize];
    while (str.cadena_[pos] != '\0' || i < newSize)
    {
      cadena_[i] = str.cadena_[pos];
      pos++;   
      i++;
    }
    
  }
  else {
    cadena_ = new char[sz];
    int aux=0;
    while (aux < sz)
    {
      cadena_[i] = str.cadena_[pos];
      pos++;   
      aux++;
      i++;
    }
  }
      
}

String::String(int sz, char crtr){
  cadena_ = new char[sz];
  for(int i = 0; i < sz; i++) {
    cadena_[i] = crtr;
  }
  sz_ = sz;
  std::cout << cadena_ << std::endl;
}

String::~String(){
  sz_ = -1;
  delete[] cadena_;
  
}


int String::length() const{
  return sz_;
}

const char* String::c_str() const{
  return cadena_; //DUDA
}

char String::at(int pos) const{
  return cadena_[pos];
}

char& String::at(int pos){
  return cadena_[pos]; 
}

char String::front() const{
  return cadena_[0];
}
char& String::front(){
  return cadena_[0]; 
}
char String::back() const{
   return cadena_[sz_ - 1];
}
char& String::back() {
   return cadena_[sz_ - 1];
}

void String::push_back(char ch){
  resize(sz_ + 1);
  cadena_[sz_ - 1] = ch;
  
  // std::cout << cadena_ << std::endl;

}

// //pop_back
void String::clear() {
  char* temp = new char[sz_];
  delete[] cadena_;
  this->cadena_ = temp;
}

// //append

char& String::operator[](int pos){
  return at(pos);
}
char String::operator[](int pos) const{
  return at(pos);
}

String& String::operator=(const String &str){
  sz_ = str.sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++) {
    cadena_[i] = str.cadena_[i];
  }
  //hay que devolver la referencia de un objeto 
  return *this;
  
}
String& String::operator=(const char &chr){
  resize(1);
  cadena_[0] = chr;
  // std::cout << cadena_ << std::endl;
  return *this;
}

String& String::operator+=(const String &str){
  int since = sz_;
  int nSize = sz_ + str.sz_;
  resize(nSize);
  int j=0;
  for (int i = since; i < nSize; i++) {
    cadena_[i] = str.cadena_[j];
    j++;
  }
  std::cout << cadena_ << std::endl;
  return *this;
}

String& String::operator+=(const char &chr){ //fijarse si hasce falta dejarlo como referencia
  resize(sz_ + 1);
  cadena_[sz_ - 1] = chr;
  // std::cout << cadena_ << std::endl;
  return *this;
}

String& String::replace(int pos, int sz, const String &str) {
  int nSize = sz_ + str.sz_ - sz;
  char* temp = new char[nSize];
  int ii=0;
  while ( ii <= pos) {
    temp[ii] = cadena_[ii];
    ii++;
  }
  int i = ii;
  int j=0;
  while ( j < str.sz_) {
    temp[i] = str.cadena_[j];
    i++; 
    j++;
  }
  //int k = pos + str.sz_; 
  ii += sz; 
  while ( ii < nSize){
    temp[i] = cadena_[ii]; 
    i++;
    ii++; 
  }

  std::cout << "Resultado: " << temp << std::endl; 
  return *this;
}

String& String::replace(const String &subStr, const String &newStr2) {
  
  for (int i = 0; i < sz_; i++) {
    String temp = substr(i, subStr.length());
    if(temp == subStr) {
      replace(i, subStr.length(), newStr2);
    }
  }
}


// String& String::replace_all(const String &subStr, const String &newStr2) {


// }


String& String::substr(int pos, int length) {
  
  int newSize = sz_ - pos;
  int i=0;  
  if( length == npos_) {
    char *temp = new char[newSize]; 
    while (cadena_[i] != '\0')
    {
      temp[i] = cadena_[pos];
      pos++;   
      i++;
    }
    this->cadena_ = temp;
  }
  else {
    char *temp = new char[length];
    int aux=0;
    while (aux < length)
    {
      temp[aux] = cadena_[pos];
      pos++;   
      aux++;
    }
    this->cadena_ = temp;
  }
   std::cout << "Resultado: " << cadena_ << std::endl; 
  return *this;
 
}

std::vector<String> String::split(char delimit) {
  std::vector<String> vString;
  
  String temp;
  this->push_back(delimit);  
  for (int i = 0; i < sz_; i++) {
    if (at(i) != delimit) {
      temp += at(i);
    } else {
      vString.push_back(temp);
      std::cout << vString.back() << std::endl; 
      temp = "";
    }
  }

  return vString;
}


String join(std::vector<String> &vStr, char joint){
  std::cout << "Entrando a join" << std::endl; 
  String temp; 
  // std:: cout << temp << std::endl; 
  for(int i = 0 ; i < vStr.size(); i++){
    temp += vStr[i]; 
    if(i < vStr.size() - 1){
      temp += joint; 
      std::cout << temp << std::endl; 
    }
  }
  return temp; 
}

void String::resize(int length) {
  char* temp = new char[length];
  for (int i = 0; i < sz_; i++) {
    temp[i] = cadena_[i];
  }
  this->cadena_ = temp;
  sz_ = length;
  
}

std::ostream& operator<<(std::ostream &os, const String &str) {
  for (int i = 0; i < str.length(); i++) {
    os << str[i];
  }
  
  return os;
}

std::istream &operator>>(std::istream &is, const String &str){
  is >> str.c_str(); 
  return is; 
}

String operator+(const String &str1, const String &str2) {
  String temp;
  temp += str1;
  temp += str2;
  return temp;
}

bool operator==(const String &str1, const String &str2) {
  int count=0;
  bool temp;
  if(str1.length() == str2.length()) {
    for (int i = 0; i < str1.length(); i++) {
      if(str1[i] == str2[i]) count++;
    }      
  }
  return (count == str1.length())? true : false;
}

bool operator!=(const String &str1, const String &str2) {
  return !(str1 == str2);
}