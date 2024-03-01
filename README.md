# CXPathJson
CXPathJson is a library to set and get values from a json string using a path string.

# Installation 

## Single File
CXpathJson is made to be as dumb as possible and adopt the idea of single file library.
For installation, simply copy the **CXpathJson.h** into your project and compile with gcc/g++ or clang. 

[Download Link](https://github.com/OUIsolutions/cxpathjson/releases/download/v0.1/CxpathJson.h)

# Usage
In all examples, we will use the json files in the `tests/target` directory.

## example
<!--codeof:exemples/get/get_int.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    int content = xpath.get_int(t,"['a','b']");
    printf("%d",content);
    xpath.free(t);

}
~~~

The code above is a simple example of how to get an integer from a json string using a path string. The path string is a string that represents the path to the value in the json string. The path string is a list of keys separated by a comma. For example, the path string `"['a', 'b', 'c']"` will get the value of the key `c` in the json string `{"a": {"b": {"c": 1}}}`.


## Constructing a path
The first step is to construct a path. You can do it by calling the `newCxpathJsonNamespace` as shown below.

<!--codeof:exemples/constructors/construct_xpath.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    printf("OK");

}
~~~

Your next step is to create an error object and a json object. The error object will be used to store the error messages if the json string is invalid. The json object will be used to store the json string and you have 4 options to create a json object:
- `new_from_file` to read the json string from a file. This function receives 1 parameter: the file path.
Example:
<!--codeof:exemples/constructors/construct_json_object_from_file.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    xpath.free(t);
    printf("OK");
}
~~~

- `new_from_string` to read the json string from a string. This function receives 1 parameter: the json string.
Example:
<!--codeof:exemples/constructors/construct_json_object_from_string.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_string("{\"a\":1}");
    xpath.free(t);
    printf("OK");
}
~~~

- `newJsonArray` to create an empty json array.
Example:
<!--codeof:exemples/constructors/construct_json_object_array.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonArray();
    xpath.free(t);
    printf("OK");
}
~~~

- `newJsonObject` to create an empty json object.
Example:
<!--codeof:exemples/constructors/construct_json_object_object.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.free(t);
    printf("OK");
}
~~~

**Important**: Note that every example already create the errors object. Every example also has a `free` function to free the memory allocated by the json object.

## Get & Set
From the json object, you can get and set values using the path string.

### Get
Every `get` function gets 2 parameters: the json object and the path string. The first
parameter is the json object and the second parameter is the path string. The path string is a list of keys separated by a comma. For example, the path string `"['a', 0, 'b']"` will get the value of the key `b` in the json string `{"a": [ {"b": 1} ]}`.

To get a value from the json object, you can use a range of functions. The functions are:
- `get_int` to get an integer.
<!--codeof:exemples/get/get_int.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    int content = xpath.get_int(t,"['a','b']");
    printf("%d",content);
    xpath.free(t);

}
~~~

- `get_double` to get a double.
<!--codeof:exemples/get/get_double.c-->
~~~c

#include "CxpathJson.h"



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
~~~

- `get_str` to get a string.
<!--codeof:exemples/get/get_str.c-->
~~~c

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
~~~

- `get_bool` to get a boolean.
<!--codeof:exemples/get/get_bool.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    bool content = xpath.get_bool(t,"['f', 'g']");
    printf("%d",content);
    xpath.free(t);

}
~~~


- `get_array` to get an array.
<!--codeof:exemples/get/get_array.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    CxpathJson *a = xpath.get_array(t, "['o']");
    char  *a1 =xpath.get_str(a,"[0]");
    printf("%s\n",a1);
    xpath.free(t);

}
~~~

- `get_object` to get an json object.
<!--codeof:exemples/get/get_object.c-->
~~~c

#include "CxpathJson.h"



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
~~~

- `get_array` to get an array.
<!--codeof:exemples/get/get_array.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    CxpathJson *a = xpath.get_array(t, "['o']");
    char  *a1 =xpath.get_str(a,"[0]");
    printf("%s\n",a1);
    xpath.free(t);

}
~~~

- `size` to get the size of an array.
<!--codeof:exemples/get/get_size.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    int content = xpath.size(t,"['c']");
    printf("%d",content);
    xpath.free(t);

}
~~~


### Set
Every `set` function gets 3 parameters: the json object, the value to set and the path string.
To set a value in the json object, you can use a range of functions. The functions are:

- `set_int` to set an integer.
<!--codeof:exemples/set/set_int.c-->
~~~c

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
~~~

- `set_double` to set a double.
<!--codeof:exemples/set/set_double.c-->
~~~c

#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    bool content = xpath.get_bool(t,"['f', 'g']");
    
    xpath.set_bool(t,true ,"['f', 'g']");

    xpath.dump_to_file(t,"tests/target/b.json", true);

    CxpathJson *t2 = xpath.new_from_file("tests/target/b.json");
    bool content2 = xpath.get_bool(t2,"['f', 'g']");


    if (content2 != content)
    {
        printf("diff");
    }else {
        printf("identical");
    }
    xpath.free(t);
    xpath.free(t2);

}
~~~

- `set_str` to set a string.
<!--codeof:exemples/set/set_str.c-->
~~~c

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
~~~

- `set_bool` to set a boolean.
<!--codeof:exemples/set/set_bool.c-->
~~~c

#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    bool content = xpath.get_bool(t,"['f', 'g']");
    
    xpath.set_bool(t,true ,"['f', 'g']");

    xpath.dump_to_file(t,"tests/target/b.json", true);

    CxpathJson *t2 = xpath.new_from_file("tests/target/b.json");
    bool content2 = xpath.get_bool(t2,"['f', 'g']");

    if (content2 != content)
    {
        printf("diff");
    }else {
        printf("identical");
    }
    xpath.free(t);
    xpath.free(t2);

}
~~~


## Dumps
You can dump the json object to a file using `dump_to_file` or to a string using `dump_to_string`.

- `dump_to_file` to dump the json object to a file. The code below will dump the json object to create a file called `b.json`. This function receives 3 parameters: the json object, the file path and and boolean to indicate if the file should be idented.
<!--codeof:exemples/dumps/dump_to_file.c-->
~~~c
#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    xpath.dump_to_file(t,"side_effect/b.json", true);
    xpath.free(t);
    printf("OK");

}
~~~

- `dump_to_string` to dump the json object to a string. This function receives 2 parameters: the json object and a boolean to indicate if the string should be idented.
<!--codeof:exemples/dumps/dump_to_string.c-->
~~~c
#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    char *content = xpath.dump_to_string(t, false);
    printf("%s", content);
    xpath.free(t);
    free(content);
    

}
~~~


## Error Handling
The library has a built-in error handling system. You can use the `error` object to get the error message if the json string is invalid. The error message will be stored in the `error` object. You can use the `error` object to get the error message as shown below.
<!--codeof:exemples/errors/raise_element_not_exists.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/a.json");
    char  *content = xpath.get_str(t,"['c', 1, 'd']");
    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("%d",code);
        printf("-%s",message);
        xpath.free(t);
        return 0;
    }

}
~~~

The code above will print the following error message:
```
5-Element not exist
```
where `5` is the code of the error and `Element not exist` is the message of the error.





