
#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    double content = xpath.get_int(t,"['h', 0]");
    xpath.set_int(t,543,"['h', 0]");

    xpath.dump_to_file(t,"tests/target/b.json", true);

    CxpathJson *t2 = xpath.new_from_file("tests/target/b.json");
    int content2 = xpath.get_int(t2,"['a', 'b']");

    if (content2 != content)
    {
        printf("diff");
    }else {
        printf("identical");
    }
    xpath.free(t);
    xpath.free(t2);

}