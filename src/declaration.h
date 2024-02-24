#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef cJSON__h
#include "dependencies/cJSON.h"
#undef cJSON__h
#endif 
typedef cJSON cjson_path;

#include "io/io.h"