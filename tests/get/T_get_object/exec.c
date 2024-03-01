
#include "../../../CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/str.json");
    CxpathJson *a = xpath.get_object(t, "['a']");
    char *a1 = xpath.get_str(a,"['b']");
    printf("%s",a1);
    xpath.free(t);

}