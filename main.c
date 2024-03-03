
#include "src/one.c"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t =  xpath.newJsonObject();
    xpath.set_default_str(t,"naaa","['a','%s']","naaa");
    xpath.free(t);

}