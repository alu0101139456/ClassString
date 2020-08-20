#include "string.hpp"



String::String() {

}

String::String(const char *cadena){
  
}
String::String(const String &str) {

}
String::String(const String &str, int pos, int sz = npos_){

}
String::String(int sz, char crtr){

}

String::~String(){

}

int String::length() const{
  
}
const char* String::c_str() const{
  
}

char String::at(int pos) const{

}

char& String::at(int pos){

}

char String::front() const{

}
char& String::front(){

}
char String::back() const{

}
char& String::back(){

}

void String::push_back(char ch){

}
//pop_back
void String::clear() {

}

//append

char& String::operator[](int pos){

}
char String::operator[](int pos) const{

}

String& String::operator=(const String &str){

}
String& String::operator=(const char &chr){

}

String& String::operator+=(const String &str){

}
String& String::operator+=(const char &chr){ //fijarse si hasce falta dejarlo como referencia

}

String& String::replace(int pos, int sz, const String &str) {

}
String& String::replace(const String &subStr, const String &newStr2) {

}
String& String::replace_all(const String &subStr, const String &newStr2) {

}

String& String::substr(int pos, int length = npos_) {

}

std::vector<String>& String::split(char delimit = ' ') {

}

String String::join(std::vector<String> &vStr, char joint = ' ') {

}
  //String join(std::vector<String> &vStr, String joint);

  //trim -> Coge los espacios o tabuladores por los extremos y los quita


void String::resize(int length) {

}