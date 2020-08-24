#include "string.hpp"



String::String() {
  sz_ = 0;
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
  cadena_ = str.cadena_;

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
  return cadena_[pos]; //DUDA
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
  
  std::cout << cadena_ << std::endl;
}

// //pop_back
void String::clear() {
  char* temp = new char[sz_];
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
  std::cout << cadena_ << std::endl;
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
  std::cout << cadena_ << std::endl;
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
}
// Coordenadas String::find(const String& str){

// String& String::replace(const String &subStr, const String &newStr2) {
  
// }


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

String String::makeString(int inicio, int fin) {
  int sz = fin - inicio;
  std::cout << "Tamaño de nuevo string: " << sz << std::endl;
  String aux;
  aux.cadena_ = new char[sz];
  // char *temp = new char[sz];

  for (int i = 0; i < sz; i++) {
    aux.cadena_[i] = cadena_[inicio];
    inicio++;
  }
  std::cout << "MakeString creo:" << aux.cadena_ << std::endl;

  return aux;
}

std::vector<String>& String::split(char delimit) {
  
  std::vector<String> vString;
  int ini = 0;
  int fin = -1;  
  bool firstIt = true;
  // std::cout << "Tamaño de la cadena = " << sz_ << std::endl;
  for (int i = 0; i < sz_; i++) {
    // std::cout << "Inicio: " << ini << " Fin: " << fin << std::endl;
    if( cadena_[i] == delimit) {
      fin = i;
      std::cout << "Inicio: " << ini << " Fin: " << fin << std::endl;
      
      String temp = makeString(ini, fin);
      // vString.push_back(temp);
      if(firstIt) {
        ini = i; 
        firstIt = false; 
      }
      ini = i + 1;
      // std::cout << "Termina bucle" << std::endl;
    }
  }
  String temp = makeString(fin+1, sz_);

  for(int i = 0; i < vString.size(); i++){
    std::cout << vString[i].cadena_ << std::endl; 
  }
  return vString; 
}

// String String::join(std::vector<String> &vStr, char joint = ' ') {

// }
//   //String join(std::vector<String> &vStr, String joint);

//   //trim -> Coge los espacios o tabuladores por los extremos y los quita


void String::resize(int length) {
  char* temp = new char[length];
  for (int i = 0; i < sz_; i++) {
    temp[i] = cadena_[i];
  }
  this->cadena_ = temp;
  sz_ = length;
  
}