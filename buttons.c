#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

static char *entry_value;

char *get_entry(struct MainStruct *p)
{
  const char *text_entry = gtk_entry_buffer_get_text(p -> buffer);
  char *mutcp = strdup(text_entry);
  return mutcp;
}

void lower_button_clicked(GtkWidget *lowerbutton, struct MainStruct *p)
{
  entry_value = get_entry(p);
  for (int i = 0; entry_value[i] != '\0'; i++) {
    if (entry_value[i] >= 65 && entry_value[i] <= 90)
      entry_value[i] += 32; // (A - Z) -> a -z
  }

  gtk_label_set_text(GTK_LABEL(p -> label), entry_value);
  free(entry_value);

  // test count function
  count(p);
}

void upper_button_clicked(GtkWidget *upperbutton, struct MainStruct *p)
{
  entry_value = get_entry(p);
  for (int i = 0; entry_value[i] != '\0'; i++) {
    if (entry_value[i] >= 97 && entry_value[i] <= 122)
      entry_value[i] -= 32; // (a - z) -> A - Z
  }

  gtk_label_set_text(GTK_LABEL(p -> label), entry_value);
  free(entry_value);
}

void title_button_clicked(GtkWidget *titlebutton, struct MainStruct *p)
{
  entry_value = get_entry(p);
  // first symbol - to uppercase
  if (entry_value[0] >= 97 && entry_value[0] <= 122)
    entry_value[0] -= 32;

  // other
  for (int i = 0; entry_value[i] != '\0'; i++) {
    // after space conversion to uppercase
    if (entry_value[i] == ' ' && i++)
      if (entry_value[i] >= 97 && entry_value[i] <= 122)
        entry_value[i] -= 32; // Title Conversion
  }

  gtk_label_set_text(GTK_LABEL(p -> label), entry_value);
  free(entry_value);
}

void reverse_button_clicked(GtkWidget *reversebutton, struct MainStruct *p)
{
  char reverse[50];
  int i, begin, end;
  entry_value = get_entry(p);

  // i - length
  for (i = 0; entry_value[i] != '\0'; i++);
  end = i - 1;

  for (begin = 0; begin < i; begin++) {
    reverse[begin] = entry_value[end];
    end--;
  }

  reverse[i] = '\0'; // end of array
  gtk_label_set_text(GTK_LABEL(p -> label), reverse);
  free(entry_value);
}

void clear_entry(GtkWidget *clearbutton, struct MainStruct *p)
{
  // 0 - start pos / -1 - end pos
  gtk_entry_buffer_delete_text(GTK_ENTRY_BUFFER(p -> buffer), 0, -1);
  gtk_label_set_text(GTK_LABEL(p -> label), "200 symbols");
}
