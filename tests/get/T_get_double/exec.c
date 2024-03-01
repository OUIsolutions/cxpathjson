
#include "../../../CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    double content = xpath.get_double(t,"['h', 0]");
    printf("%.10lf",content);
    xpath.free(t);

}