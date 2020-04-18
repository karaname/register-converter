#include <gtk/gtk.h>
#include <ctype.h>
#include "main.h"

/* Return text from buffer - text_buffer_FR */
guchar *get_text()
{
  GtkTextIter start, end;

  gtk_text_buffer_get_start_iter(bf.text_buffer_FR, &start);
  gtk_text_buffer_get_end_iter(bf.text_buffer_FR, &end);

  guchar *text = gtk_text_buffer_get_text(bf.text_buffer_FR,
    &start, &end, FALSE);

  for (int i = 0; text[i] != '\0'; i++) {
    if (isprint(text[i]) == 0) {
      /* popup here */
    }
  }

  return text;
}
