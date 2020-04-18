#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "generic.h"

#define BUFFER_SIZE 4095
gchar *text;

/* Set maximum buffer size - 4B */
void max_buffer_insert(GtkTextBuffer *text_buffer_FR, GtkTextIter *location)
{
  gint len_bf = gtk_text_buffer_get_char_count(text_buffer_FR);
  if (len_bf > BUFFER_SIZE) {
    GtkTextIter offset, end;
    gtk_text_buffer_get_iter_at_offset(text_buffer_FR, &offset, BUFFER_SIZE);
    gtk_text_buffer_get_end_iter(text_buffer_FR, &end);
    gtk_text_buffer_delete(text_buffer_FR, &offset, &end);
    gtk_text_iter_assign(location, &offset);
  }
}

/* Conversion uppercase text to lower */
void on_lower_button_clicked(GtkWidget *lower_buttn)
{
  text = get_text();
  for (int i = 0; text[i] != '\0'; i++)
    if (isupper(text[i])) *(text + i) = tolower(text[i]);

  count(text);
}

/* Conversion lowercase text to upper */
void on_upper_button_clicked(GtkWidget *upper_buttn)
{
  text = get_text();
  for (int i = 0; text[i] != '\0'; i++)
    if (islower(text[i])) *(text + i) = toupper(text[i]);

  count(text);
}

/* Conversion lowercase to title case */
void on_title_button_clicked(GtkWidget *title_buttn)
{
  text = get_text();

  if (islower(text[0])) *(text) = toupper(text[0]);
  for (int i = 0; text[i] != '\0'; i++) {
    if (isspace(text[i]) && i++) {
      if (islower(text[i])) {
        *(text + i) = toupper(text[i]);
      }
    }
  }

  count(text);
}

/* Conversion text to reverse */
void on_reverse_button_clicked(GtkWidget *rev_buttn)
{
  int c, i, j;
  text = get_text();

  for (i = 0, j = strlen(text) - 1; i < j; i++, j--)
    c = text[i], text[i] = text[j], text[j] = c;

  count(text);
}

/* Clear buffers and list store */
void on_clear_button_clicked(GtkWidget *clear_buttn)
{
  gtk_text_buffer_set_text(bf.text_buffer_FR, "", -1);
  gtk_text_buffer_set_text(bf.text_buffer_FR,
    "Enter the text and click on any button you like ...", -1);
  gtk_text_buffer_set_text(bf.text_buffer_SR, "", -1);

  for (int i = 0; i < N_COLUMNS; i++)
    gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, i, 0, -1);
}
