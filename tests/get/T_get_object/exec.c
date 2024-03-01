
#include "../../../CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    CxpathJson *a = xpath.get_object(t, "['m']");
    char *a1 = xpath.get_str(a,"['n']");
    printf("%s",a1);
    xpath.free(t);

}