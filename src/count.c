#include <gtk/gtk.h>
#include <ctype.h>
#include "main.h"

/*
Count different symbols from text_buffer_FR
Update list store and text_buffer_SR
*/
void count(guchar *s)
{
  int anum, even, odd;
  int achar, asymb, aspace, aletter;

  anum = even = odd = 0;
  achar = asymb = aspace = aletter = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    if (isprint(s[i])) achar++;

    if (isdigit(s[i])) {
      anum++;
      (s[i] % 2 == 0) ? even++ : odd++;
    } else if (isalpha(s[i])) {
      aletter++;
    } else if (isspace(s[i])) {
      aspace++;
    } else {
      asymb++;
    }
  }

  /* Set counting values */
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

  /* Set transformed text */
  gtk_text_buffer_set_text(bf.text_buffer_SR, s, -1);
  g_free(s);
}
