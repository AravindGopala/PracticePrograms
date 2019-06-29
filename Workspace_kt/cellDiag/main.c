#include <stdio.h>
#include<stdarg.h>

/*
 * @brief the cell event subtypes
 */
typedef enum {
    CELL_SUBTYPE_UNKNOWN=0,
    CELL_SUBTYPE_NET_UPDATE,
    CELL_SUBTYPE_NUM
} CellSubType_e;


/**
 * @brief cell diag subtype string mapping
 */
static const char * CellDiagSubTypeStr[CELL_SUBTYPE_NUM + 1] = {
    [CELL_SUBTYPE_UNKNOWN]       = "?",          /*Cell Diag SubType is Unknown*/
    [CELL_SUBTYPE_NET_UPDATE]    = "net-update", /*Cell Diag SubType is net-update*/
    [CELL_SUBTYPE_NUM]           = "INVAL"
};


static void CreateCellDiagMsg(CellSubType_e pSubTypeStr, const char * pFormat, ...)
{
  va_list v_args;

  /// NULL pointer checks
  if (pFormat == NULL)
  {
      printf("%s: No information added for Subtype %s",
                       __func__,
                       CellDiagSubTypeStr[pSubTypeStr]);
      return;
  }
  char filename[100]="Sample.txt";


  // Create diag
  FILE *f = fopen(filename, "w+");
  if (f == NULL)
  {
      printf("%s: No information added for Subtype %s",
                       __func__,
                       CellDiagSubTypeStr[pSubTypeStr]);
      return;
  }


  // Always start with the subtype
  fprintf(f, "{\"subtype\":\"%s,\"", CellDiagSubTypeStr[pSubTypeStr]);

  // Add variable args
  va_start(v_args, pFormat);
  int Res = vfprintf(f, pFormat, v_args);
  if(Res<=0)
  {
        printf("%s: No information added for Subtype %s",
                         __func__,
                         CellDiagSubTypeStr[pSubTypeStr]);
  }
  va_end(v_args);

  fprintf(f, "%c", '}');

  fclose(f);
  f = fopen(filename, "r");

  // Open file
 char c;
  // Read contents from file
  c = fgetc(f);
  while (c != EOF)
  {
      printf ("%c", c);
      c = fgetc(f);
  }

  fclose(f);


}

int main()
{
    CreateCellDiagMsg(CELL_SUBTYPE_NET_UPDATE,
                "\"cgpaddr\":\"%s\",",
                "Aravind Datla");
    printf("Hello World!\n");
    return 0;
}
