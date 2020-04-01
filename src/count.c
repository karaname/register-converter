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
    if (text[i] >= 48 && text[i] <= 57) {
      anum++; // numbers
      // even - odd
      (text[i] % 2 == 0) ? even++ : odd++;
    } else if ((text[i] >= 65 && text[i] <= 90) ||
      (text[i] >= 97 && text[i] <= 122)) {
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

  gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, 0, achar, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, 1, aletter, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, 2, asymb, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, 3, aspace, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, 4, anum, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, 5, even, -1);
  gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, 6, odd, -1);
}
