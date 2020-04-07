#include <gtk/gtk.h>
#include <string.h>
#include "main.h"
#include "count.h"
#include "get_buffer.h"
#define BUFFER_SIZE 4095

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
  gchar *text = get_text();
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z')
      text[i] += 32;
  }

  gtk_text_buffer_set_text(bf.text_buffer_SR, text, -1);
  g_free(text);
  count();
}

/* Conversion lowercase text to upper */
void on_upper_button_clicked(GtkWidget *upper_buttn)
{
  gchar *text = get_text();
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'a' && text[i] <= 'z')
      text[i] -= 32;
  }

  gtk_text_buffer_set_text(bf.text_buffer_SR, text, -1);
  g_free(text);
  count();
}

/* Conversion lowercase to title case */
void on_title_button_clicked(GtkWidget *title_buttn)
{
  gchar *text = get_text();
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[0] >= 'a' && text[0] <= 'z')
      text[0] -= 32;

    if (text[i] == ' ' && i++) {
      if (text[i] >= 'a' && text[i] <= 'z')
        text[i] -= 32;
    }
  }

  gtk_text_buffer_set_text(bf.text_buffer_SR, text, -1);
  g_free(text);
  count();
}

/* Conversion text to reverse */
void on_reverse_button_clicked(GtkWidget *rev_buttn)
{
  int c, i, j;
  gchar *text = get_text();

  for (i = 0, j = strlen(text) - 1; i < j; i++, j--)
    c = text[i], text[i] = text[j], text[j] = c;

  gtk_text_buffer_set_text(bf.text_buffer_SR, text, -1);
  g_free(text);
  count();
}

/* Clear buffers / list store from data */
void on_clear_button_clicked(GtkWidget *clear_buttn)
{
  gtk_text_buffer_set_text(bf.text_buffer_FR, "", -1);
  gtk_text_buffer_set_text(bf.text_buffer_FR,
    "Enter the text and click on any button you like ...", -1);

  gtk_text_buffer_set_text(bf.text_buffer_SR, "", -1);

  for (int i = 0; i < N_COLUMNS; i++)
    gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, i, 0, -1);
}
