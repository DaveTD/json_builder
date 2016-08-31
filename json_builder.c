#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "json_builder.h"

/*
* Depending on whether or not ruby can pass data in, and have that information
* continue to be held in C or not, this will either by called by ruby or C
*/
char* generate_json_for_row(char* row_mapping, char* row)
{

}

uint64_t hash_from_array(char* row_mapping, char* row)
{
  //Split out numbers to figure out the structure of the json

  //1s, 2s are sent to the hash for the row's value

  //return the hash value
  return 2;
}

char* read_value(char depth_start, char is_first, char* mapped_value)
{
  char* return_string;
  char starting_character = 0;
  char depth_counter = 0;
  if (depth_start > 0)
  {
    while (depth_counter < depth_start)
    {
      if (starting_character > strlen(mapped_value))
      {
        // Returns 0 if the mapped value doesn't go deep enough
        return 0;
      }
      else if (mapped_value[starting_character] == '-')
      {
        depth_counter++;
      }
      starting_character++;
    }
  }

  if (is_first == 0)
  {
    starting_character += 2;
    while(starting_character < strlen(mapped_value) 
      && mapped_value[starting_character] != '.')
    {
      return_string = append(return_string, mapped_value[starting_character]);
    }
  }
  else
  {
    return_string = malloc(sizeof(char));
    return_string[0] = mapped_value[++starting_character];
  }

  return return_string;
}

char *append(const char *input, const char c)
{
  size_t len = strlen(input);
  char *new_string = malloc(len + 1 + 1 );
  strcpy(new_string, input);
  new_string[len] = c;
  new_string[len + 1] = '\0';

  return new_string;
}

int main()
{
  // Test some string stuff
  char* test_string;
  char* test_substring = "";
  char depth_checked = 0;
  test_string = "This is a test string. Cut me off before the first period.";

  while (depth_checked < strlen(test_string) 
    && test_string[depth_checked] != '.')
  {
    test_substring = append(test_substring, test_string[depth_checked]);
    depth_checked++;
  }
  printf("%s\n", test_substring);
  return 1;
}