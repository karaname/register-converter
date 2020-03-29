#include <gtk/gtk.h>
#include "main.h"

gchar *get_text()
{
  GtkTextIter start, end;
  gtk_text_buffer_get_start_iter(bf.text_buffer_FR, &start);
  gtk_text_buffer_get_end_iter(bf.text_buffer_FR, &end);

  gchar *text = gtk_text_buffer_get_text(bf.text_buffer_FR,
    &start, &end, FALSE);

  return text;
}
