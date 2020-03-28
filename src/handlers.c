#include <gtk/gtk.h>
#include "main.h"

/* COUNT - SOON */

static gchar *text;
gchar *get_text(struct Buffers *p)
{
  GtkTextIter start, end;
  gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(p -> text_buffer_FR), &start);
  gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(p -> text_buffer_FR), &end);

  text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(p -> text_buffer_FR), &start, &end, FALSE);

  return text;
}

void on_lower_button_clicked(GtkWidget *lower_buttn, struct Buffers *p)
{
  text = get_text(p);
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 65 && text[i] <= 90)
      text[i] += 32; // (A - Z) -> a -z
  }

  gtk_text_buffer_set_text(GTK_TEXT_BUFFER(p -> text_buffer_SR), text, -1);
  g_free(text);
}

void on_upper_button_clicked(GtkWidget *upper_buttn, struct Buffers *p)
{
  text = get_text(p);
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 97 && text[i] <= 122)
      text[i] -= 32; // (a - z) -> A - Z
  }

  gtk_text_buffer_set_text(GTK_TEXT_BUFFER(p -> text_buffer_SR), text, -1);
  g_free(text);
}

void on_title_button_clicked(GtkWidget *title_buttn, struct Buffers *p)
{
  text = get_text(p);
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

  gtk_text_buffer_set_text(GTK_TEXT_BUFFER(p -> text_buffer_SR), text, -1);
  g_free(text);
}

void on_reverse_button_clicked(GtkWidget *rev_buttn, struct Buffers *p)
{
  char reverse[50];
  int i, start, end;
  text = get_text(p);

  // i - length
  for (i = 0; text[i] != '\0'; i++);
  end = i - 1;

  for (start = 0; start < i; start++) {
    reverse[start] = text[end];
    end--;
  }

  reverse[i] = '\0'; // end of array
  gtk_text_buffer_set_text(GTK_TEXT_BUFFER(p -> text_buffer_SR), reverse, -1);
  g_free(text);
}

void on_clear_button_clicked(GtkWidget *clear_buttn, struct Buffers *p)
{
  gtk_text_buffer_set_text(GTK_TEXT_BUFFER(p -> text_buffer_FR), "", -1);
  gtk_text_buffer_set_text(GTK_TEXT_BUFFER(p -> text_buffer_SR), "", -1);
}
