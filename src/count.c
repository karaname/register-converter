#include <gtk/gtk.h>
#include "main.h"
#include "get_buffer.h"

/* Count different symbols from text_buffer_FR */
void count()
{
  int anum, even, odd;
  int achar, asymb, aspace, aletter;

  anum = even = odd = 0;
  achar = asymb = aspace = aletter = 0;
  gchar *text = get_text();

  for (int i = 0; text[i] != '\0'; i++) {
    // all chars
    if (text[i] >= 32 && text[i] <= 126) achar++;

    // others
    if (text[i] >= '0' && text[i] <= '9') {
      anum++; // numbers
      // even - odd
      (text[i] % 2 == 0) ? even++ : odd++;
    } else if ((text[i] >= 'A' && text[i] <= 'Z') ||
      (text[i] >= 'a' && text[i] <= 'z')) {
      // letters
      aletter++;
    } else if (text[i] == ' ') {
      // spaces
      aspace++;
    } else {
      // special symbols
      asymb++;
    }
  }

  gtk_list_store_set(GTK_LIST_STORE(tv.list_store),
    &tv.iter, COLUMN_TOTAL, achar, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store),
    &tv.iter, COLUMN_LETTER, aletter, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store),
    &tv.iter, COLUMN_SPECIAL, asymb, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store),
    &tv.iter, COLUMN_SPACE, aspace, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store),
    &tv.iter, COLUMN_NUM, anum, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store),
    &tv.iter, COLUMN_EVEN, even, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store),
    &tv.iter, COLUMN_ODD, odd, -1);
}
