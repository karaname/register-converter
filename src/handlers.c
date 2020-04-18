#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "generic.h"

#define BUFFER_SIZE 4095
guchar *buffer;

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

/* Conversion uppercase text to lower */
void on_lower_button_clicked(GtkWidget *lower_buttn)
{
  buffer = get_text();

  if (!check_ascii(buffer)) {
    for (int i = 0; buffer[i] != '\0'; i++)
      if (isupper(buffer[i])) *(buffer + i) = tolower(buffer[i]);

    count(buffer);
  } else {
    on_clear_button_clicked(bt.clear_buttn);
  }
}

/* Conversion lowercase text to upper */
void on_upper_button_clicked(GtkWidget *upper_buttn)
{
  buffer = get_text();

  if (!check_ascii(buffer)) {
    for (int i = 0; buffer[i] != '\0'; i++)
      if (islower(buffer[i])) *(buffer + i) = toupper(buffer[i]);

    count(buffer);
  } else {
    on_clear_button_clicked(bt.clear_buttn);
  }
}

/* Conversion lowercase to title case */
void on_title_button_clicked(GtkWidget *title_buttn)
{
  buffer = get_text();

  if (!check_ascii(buffer)) {
    if (islower(buffer[0])) *(buffer) = toupper(buffer[0]);
    for (int i = 0; buffer[i] != '\0'; i++) {
      if (isspace(buffer[i]) && i++) {
        if (islower(buffer[i])) {
          *(buffer + i) = toupper(buffer[i]);
        }
      }
    }
    count(buffer);
  } else {
    on_clear_button_clicked(bt.clear_buttn);
  }
}

/* Conversion text to reverse */
void on_reverse_button_clicked(GtkWidget *rev_buttn)
{
  buffer = get_text();

  if (!check_ascii(buffer)) {
    int c, i, j;

    for (i = 0, j = strlen(buffer) - 1; i < j; i++, j--)
      c = buffer[i], buffer[i] = buffer[j], buffer[j] = c;

    count(buffer);
  } else {
    on_clear_button_clicked(bt.clear_buttn);
  }
}
