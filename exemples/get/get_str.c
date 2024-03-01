
#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    char  *content = xpath.get_str(t,"['c', 1, 'e']");
    printf("%s",content);
    xpath.free(t);

}