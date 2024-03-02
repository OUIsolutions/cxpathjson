# CXPathJson
CXPathJson is a library to set and get values from a json string using a path string.

# Installation 

## Single File
CXpathJson is made to be as dumb as possible and adopt the idea of single file library.
For installation, simply copy the **CXpathJson.h** into your project and compile with gcc/g++ or clang. 

[Download Link](https://github.com/OUIsolutions/cxpathjson/releases/download/v0.1/CxpathJson.h)

## full Folder 
you also can download the entire **src** project and include with **src/one.c** 

```c

#include "src/one.c"

CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t,"hello world","['a']");
    char *content = xpath.dump_to_string(t,true);
    printf("%s",content);
    free(content);
    xpath.free(t);


}
```

# Usage
In all examples, we will use the json files in the `tests/target` directory.

##  Basic hello world
<!--codeof:exemples/extra/hello_world.c-->
~~~c

#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t,"hello world","['a']");
    char *content = xpath.dump_to_string(t,true);
    printf("%s",content);
    free(content);
    xpath.free(t);


}
~~~


## Constructing a path
For loading a function from a json file  you just need to call the function
**xpath.new_from_file**  passing the json path
Example:
<!--codeof:exemples/constructors/construct_json_object_from_file.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/str.json");
    
    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("%d",code);
        printf("%s",message);
        xpath.free(t);
        return 0;
    }
    char *dumped = xpath.dump_to_string(t,true);
    printf("%s",dumped);
    xpath.free(t);
    free(dumped);
    
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

### Get
Every `get` function gets 2 parameters: the json object and the path string. The first
parameter is the json object and the second parameter is the path string. The path string is a list of keys separated by a comma. For example, the path string `"['a', 0, 'b']"` will get the value of the key `b` in the json string `{"a": [ {"b": 1} ]}`.

<!--codeof:exemples/get/get_all.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;

    CxpathJson *t = xpath.new_from_file("tests/target/all.json");
    char *name = xpath.get_str(t,"['name']");
    int age =xpath.get_int(t,"['age']");
    bool maried = xpath.get_bool(t,"['maried']");
    double height = xpath.get_double(t,"['height']");

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("code: %d\n",code);
        printf("message: %s\n",message);
        xpath.free(t);
        return 0;
    }
    printf("name: %s\n",name);
    printf("age: %d\n",age);
    printf("height: %lf\n",height);
    printf("maried: %s\n", maried ? "true": "false");
    xpath.free(t);

}
~~~

#### Getting a sub object
<!--codeof:exemples/get/get_object.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/str.json");
    CxpathJson *a = xpath.get_object(t, "['a']");
    char *a1 = xpath.get_str(a,"['b']");
    
    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("code: %d\n",code);
        printf("message: %s\n",message);
        xpath.free(t);
        return 0;
    }

    printf("%s",a1);
    xpath.free(t);

}
~~~

#### Getting a sub array
<!--codeof:exemples/get/get_array.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/array.json");
    CxpathJson *a = xpath.get_array(t, "['a','b']");
    char  *a1 =xpath.get_str(a,"[0]");

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("code: %d\n",code);
        printf("message: %s\n",message);
        xpath.free(t);
        return 0;
    }
    printf("%s\n",a1);
    xpath.free(t);

}
~~~

#### Getting size 
- `size` to get the size of an array.
<!--codeof:exemples/get/get_size.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/array.json");
    int content = xpath.size(t,"['a','b']");

    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("code: %d\n",code);
        printf("message: %s\n",message);
        xpath.free(t);
        return 0;
    }
    printf("%d",content);
    xpath.free(t);

}
~~~

### Types 
you also can get type information about the current element 
<!--codeof:exemples/extra/retriving_type.c-->
~~~c

#include "CxpathJson.h"



CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.new_from_file("tests/target/str.json");


    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("code: %d\n",code);
        printf("message: %s\n",message);
        xpath.free(t);
        return 0;
    }
    printf("exist :%d\n" , xpath.types.exist(t,"['a','b']"));
    printf("type code:%d\n" , xpath.types.type(t,"['a','b']"));
    printf("type str:%s\n" , xpath.types.type_str(t,"['a','b']"));

    xpath.free(t);

}
~~~




### Set
Every `set` function gets 3 parameters: the json object, the value to set and the path string.
To set a value in the json object, you can use a range of functions. The functions are:

<!--codeof:exemples/set/set_all.c-->
~~~c

#include "CxpathJson.h"


CxpathJsonNamespace xpath;
CxpathJsonErrorNamespace errors;


int main(){
    xpath = newCxpathJsonNamespace();
    errors = xpath.errors;
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t, "Mateus","['a', 'name']");
    xpath.set_int(t, 27,"['a', 'age']");
    xpath.set_double(t, 1.80,"['a', 'height']");
    xpath.set_bool(t,true,"['a', 'maried']");

    char *result = xpath.dump_to_string(t, false);
    printf("%s",result);
    xpath.free(t);
    free(result);



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
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t,"test","['a']['b']");
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
    CxpathJson *t = xpath.newJsonObject();
    xpath.set_str(t,"teste","['a']['b']");
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
    CxpathJson *t = xpath.new_from_file("tests/target/str.json");
    char  *content = xpath.get_str(t,"['c', 1, 'd']");
    if(errors.has_errors(t)){
        char *message =errors.get_error_message(t);
        int code = errors.get_error_code(t);
        printf("code: %d\n",code);
        printf("message: %s\n",message);
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





