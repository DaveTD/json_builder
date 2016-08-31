#include <stdint.h>

typedef struct JSONObject
{
  struct SingleValueJSON* single_values;
  struct SingleObjectJSON* single_objects;
  struct ArrayValueJSON** array_values;
  struct ArrayObjectJSON** array_objects;
} JSONObject;

typedef struct SingleValueJSON
{
  char* name;
  char* value;
} SingleValueJSON;

typedef struct SingleObjectJSON
{
  char* name;
  JSONObject* value;
} SingleObjectJSON;

typedef struct ArrayValueJSON
{
  char* name;
  char** value_array;
} ArrayValueJSON;

typedef struct ArrayObjectJSON
{
  char* name;
  JSONObject** value_array;
} ArrayObjectJSON;

char* generate_json_for_row(char** row_mapping, char* row);
uint64_t hash_from_array(char** row_mapping, char* row);
char* read_value(char depth_start, char is_first, char* mapped_value);
char* append(const char *input, const char c);
