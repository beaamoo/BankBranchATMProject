/*****************************************************************
NAME: Beatrice Mossberg, Jannik Wendt, Joseph Mattouk
ORGN: BCSAI IE University
FILE: main.cpp
DATE: Nov 22nd 2022
URL Repository: https://replit.com/@BeatriceMossber/FinalBankProgram#main.cpp
*****************************************************************/
#include <fstream>
#include <iostream>
#include <limits>
#include <string.h>
#include <unistd.h>
#include "functions.h"

using namespace std;

#include <stdio.h>


int main() {
  atmUser();
  return 0;
}



/*
int main()
{
  // Open the file in read-write mode
  FILE *file = fopen("LockedCards.txt", "r+");

  // Locate the class and attribute in the file
  char line[256];
  while (fgets(line, sizeof(line), file))
  {
    if (strstr(line, "class bankBranch"))
    {
      // We found the class, now look for the attribute
      while (fgets(line, sizeof(line), file))
      {
        if (strstr(line, "file"))
        {
          // We found the attribute, now let's change its value
          fprintf(file, "  file = LockedCards.txt;\n");
          break;
        }
      }
      break;
    }
  }

  // Close the file
  fclose(file);

  return 0;
}
*/