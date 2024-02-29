#include "src/one.c"

CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;
int  main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("a.json");


    xpath.set_str(t,"aaaaaaaaa","['a','c']");
    //xpath.set_str(t,"aaaaaaaaa","['a','d','$append']");


    xpath.dump_to_file(t,"result.json",true);


    CxpathJson_free(t);
}