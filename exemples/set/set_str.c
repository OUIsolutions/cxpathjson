
#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    char *content = xpath.get_str(t,"['c', 1, 'e']");
    xpath.set_str(t,"new_value3" ,"['c', 1, 'e']");
    xpath.dump_to_file(t,"tests/target/b.json", true);

    CxpathJson *t2 = xpath.new_from_file("tests/target/b.json");
    char *content2 = xpath.get_str(t2,"['c', 1, 'e']");


    if (content2 != content)
    {
        printf("diff");
    }else {
        printf("identical");
    }
    xpath.free(t);
    xpath.free(t2);

}