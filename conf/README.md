# CXPathJson
CXPathJson is a library to set and get values from a json string using a path string.

# Installation 

## Single File
CXpathJson is made to be as dumb as possible and adopt the idea of single file library.
For installation, simply copy the **CXpathJson.h** into your project and compile with gcc/g++ or clang. 

[Download Link]()

# Usage
In all examples, we will use the json files in the `tests/target` directory.

## example
<!-- tests/get/get_int.c -->

The code above is a simple example of how to get an integer from a json string using a path string. The path string is a string that represents the path to the value in the json string. The path string is a list of keys separated by a comma. For example, the path string `"['a', 'b', 'c']"` will get the value of the key `c` in the json string `{"a": {"b": {"c": 1}}}`.


## Constructing a path
The first step is to construct a path. You can do it by calling the `newCxpathJsonNamespace` as shown below.

<!-- tests/constructors/construct_xpath.c -->

Your next step is to create an error object and a json object. The error object will be used to store the error messages if the json string is invalid. The json object will be used to store the json string and you have 4 options to create a json object:
- `new_from_file` to read the json string from a file. This function receives 1 parameter: the file path.
Example:
<!-- tests/constructors/construct_json_object_from_file.c -->

- `new_from_string` to read the json string from a string. This function receives 1 parameter: the json string.
Example:
<!-- tests/constructors/construct_json_object_from_string.c -->

- `newJsonArray` to create an empty json array.
Example:
<!-- tests/constructors/construct_json_object_array.c -->

- `newJsonObject` to create an empty json object.
Example:
<!-- tests/constructors/construct_json_object_object.c -->

**Important**: Note that every example already create the errors object. Every example also has a `free` function to free the memory allocated by the json object.

## Get & Set
From the json object, you can get and set values using the path string.

### Get
Every `get` function gets 2 parameters: the json object and the path string. The first
parameter is the json object and the second parameter is the path string. The path string is a list of keys separated by a comma. For example, the path string `"['a', 0, 'b']"` will get the value of the key `b` in the json string `{"a": [ {"b": 1} ]}`.

To get a value from the json object, you can use a range of functions. The functions are:
- `get_int` to get an integer.
<!-- tests/get/get_int.c -->

- `get_double` to get a double.
<!-- tests/get/get_double.c -->

- `get_str` to get a string.
<!-- tests/get/get_str.c -->

- `get_bool` to get a boolean.
<!-- tests/get/get_bool.c -->

- `get_array` to get an array.
<!-- tests/get/get_array.c -->

- `get_object` to get an json object.
<!-- tests/get/get_object.c -->

- `get_array` to get an array.
<!-- tests/get/get_array.c -->

- `size` to get the size of an array.
<!-- tests/get/get_array_size.c -->


### Set
Every `set` function gets 3 parameters: the json object, the value to set and the path string.
To set a value in the json object, you can use a range of functions. The functions are:

- `set_long` to set an integer.
<!-- tests/set/set_long.c -->

- `set_double` to set a double.
<!-- tests/set/set_double.c -->

- `set_str` to set a string.
<!-- tests/set/set_str.c -->

- `set_bool` to set a boolean.
<!-- tests/set/set_bool.c -->


## Dumps
You can dump the json object to a file using `dump_to_file` or to a string using `dump_to_string`.

- `dump_to_file` to dump the json object to a file. The code below will dump the json object to create a file called `b.json`. This function receives 3 parameters: the json object, the file path and and boolean to indicate if the file should be idented.
<!-- tests/dumps/dump_to_file.c -->

- `dump_to_string` to dump the json object to a string. This function receives 2 parameters: the json object and a boolean to indicate if the string should be idented.
<!-- tests/dumps/dump_to_string.c -->


## Error Handling
The library has a built-in error handling system. You can use the `error` object to get the error message if the json string is invalid. The error message will be stored in the `error` object. You can use the `error` object to get the error message as shown below.
<!-- tests/errors/raise_element_not_exists.c -->

The code above will print the following error message:
```
5-Element not exist
```
where `5` is the code of the error and `Element not exist` is the message of the error.





