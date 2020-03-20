#include <gtk/gtk.h>
#include "headers.h"

void count(struct MainStruct *c)
{
  const char *tl = gtk_label_get_text(GTK_LABEL(c -> label));
  const char *te = gtk_entry_buffer_get_text(c -> buffer);

  int i, anumber, even, odd;
  int achar, asymb, aspace, aletter;

  anumber = even = odd = 0;
  achar = asymb = aspace = aletter = 0;

  for (i = 0; te[i] != '\0'; i++ ) {
    // all chars
    if (te[i] >= 32 && te[i] <= 126) achar++;

    // other
    if (te[i] >= 48 && te[i] <= 57) {
      anumber++;
      // even / odd
      (te[i] % 2 == 0) ? even++ : odd++;
    } else if ((te[i] >= 65 && te[i] <= 90)|| (te[i] >= 97 && te[i] <= 122)) {
      // letters
      aletter++;
    } else if (te[i] == ' ') {
      // spaces
      aspace++;
    } else {
      // special symbols
      asymb++;
    }
  }

  printf("-------------------------------------------------------");
  printf("\n total chars     - %-5d / letters - %d\n", achar, aletter);
  printf(" special symbols - %-5d / spaces  - %d\n", asymb, aspace);
  printf(" numbers         - %-5d / even    - %-5d / odd - %d\n", anumber, even, odd);

  gchar *a;
  a = g_strdup_printf("%d", achar);

  /*
    НУЖНО СДЕЛАТЬ ИНКЛУД ПЕРЕМЕННЫХ ВЫШЕ В ВИДЖЕТ LABEL (ИЛИ ИНОЙ ДРУГОЙ < НАДО ПОДУМАТЬ)
    ЕСЛИ КЛАСТЬ ПЕРЕМЕННУЮ ACHAR В ФУНКЦИЮ НИЖЕ КОМПИЛЯТОР НАЧИНАЕТ РУГАТЬСЯ, ТАК
    КАК МЫ ПЫТАЕМСЯ ПОЛОЖИТЬ INT, А ФУНКЦИЯ ПРИНИМАЕТ CONST GCHAR *STR;
    ПОЭТОМУ ВОЗНИКАЕТ ОШИБКА, НУЖНО ПОДУМАТЬ НАСЧЕТ TREEVIEW
    МБ СТОИТ КЛАСТЬ ВСЕ ЭТИ ДАННЫЕ / ПЕРЕМЕННЫЕ, КАК - ТО КРАСИВО ПО ПОЛОЧКАМ?
    А НЕ КИДАТЬ ИХ В LABEL КОЕ - КАК, ЕСЛИ ЧТО У НАС 7 ПЕРЕМЕННЫХ :)
  */

  gtk_label_set_text(GTK_LABEL(c -> label), a);
}
