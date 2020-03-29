#include <gtk/gtk.h>

#include "main.h"
#include "count.h"
#include "get_buffer.h"

void on_lower_button_clicked(GtkWidget *lower_buttn)
{
  gchar *text = get_text();
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 65 && text[i] <= 90)
      text[i] += 32; // (A - Z) -> a -z
  }

  gtk_text_buffer_set_text(bf.text_buffer_SR, text, -1);
  g_free(text);

  count();
}

void on_upper_button_clicked(GtkWidget *upper_buttn)
{
  gchar *text = get_text();
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 97 && text[i] <= 122)
      text[i] -= 32; // (a - z) -> A - Z
  }

  gtk_text_buffer_set_text(bf.text_buffer_SR, text, -1);
  g_free(text);

  count();
}

void on_title_button_clicked(GtkWidget *title_buttn)
{
  gchar *text = get_text();
  // first symbol - to uppercase
  if (text[0] >= 97 && text[0] <= 122)
    text[0] -= 32;

  // other
  for (int i = 0; text[i] != '\0'; i++) {
    // after space conversion to uppercase
    if (text[i] == ' ' && i++)
      if (text[i] >= 97 && text[i] <= 122)
        text[i] -= 32; // Title Conversion
  }

  gtk_text_buffer_set_text(bf.text_buffer_SR, text, -1);
  g_free(text);

  count();
}

void on_reverse_button_clicked(GtkWidget *rev_buttn)
{
  char reverse[50];
  int i, start, end;
  gchar *text = get_text();

  // i - length
  for (i = 0; text[i] != '\0'; i++);
  end = i - 1;

  for (start = 0; start < i; start++) {
    reverse[start] = text[end];
    end--;
  }

  reverse[i] = '\0'; // end of array
  gtk_text_buffer_set_text(bf.text_buffer_SR, reverse, -1);
  g_free(text);

  count();
}

void on_clear_button_clicked(GtkWidget *clear_buttn)
{
  gtk_text_buffer_set_text(bf.text_buffer_FR, "", -1);
  gtk_text_buffer_set_text(bf.text_buffer_FR,
    "Enter the text and click on any button you like ...", -1);

  gtk_text_buffer_set_text(bf.text_buffer_SR, "", -1);

  for (int i = 0; i < 7; i++)
    gtk_list_store_set(GTK_LIST_STORE(tv.list_store), &tv.iter, i, 0, -1);
}
