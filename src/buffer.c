#include <gtk/gtk.h>
#include <ctype.h>
#include "main.h"
#define POPUP 1

/* Return text from buffer - text_buffer_FR */
guchar *get_text()
{
  GtkTextIter start, end;

  gtk_text_buffer_get_start_iter(bf.text_buffer_FR, &start);
  gtk_text_buffer_get_end_iter(bf.text_buffer_FR, &end);

  guchar *text = gtk_text_buffer_get_text(bf.text_buffer_FR,
    &start, &end, FALSE);

  return text;
}

/* Checking text buffer for correctness */
gint check_ascii(guchar *b)
{
  int status;
  for (int i = 0; b[i] != '\0'; i++) {
    if (isprint(b[i]) == 0) {
      status = POPUP;
    }
  }

  if (status == POPUP) {
    dg.dialog = gtk_dialog_new();
    gtk_window_set_transient_for(GTK_WINDOW(dg.dialog), GTK_WINDOW(window));
    gtk_window_set_title(GTK_WINDOW(dg.dialog), "Message");
    gtk_window_set_default_size(GTK_WINDOW(dg.dialog), 320, 180);
    gtk_window_set_resizable(GTK_WINDOW(dg.dialog), FALSE);
    gtk_window_set_position(GTK_WINDOW(dg.dialog), GTK_WIN_POS_CENTER_ALWAYS);

    dg.content_area = gtk_dialog_get_content_area(GTK_DIALOG(dg.dialog));
    dg.ok_button = gtk_dialog_add_button(GTK_DIALOG(dg.dialog), "Ok", GTK_RESPONSE_OK);
    dg.message = gtk_label_new("The program accepts only ASCII characters");
    gtk_container_add(GTK_CONTAINER(dg.content_area), dg.message);
    gtk_box_set_homogeneous(GTK_BOX(dg.content_area), TRUE);

    dg.box_button = gtk_widget_get_parent(dg.ok_button);
    gtk_button_box_set_layout(GTK_BUTTON_BOX(dg.box_button), GTK_BUTTONBOX_CENTER);

    gtk_widget_show_all(dg.dialog);

    int r = gtk_dialog_run(GTK_DIALOG(dg.dialog));
    if (r == GTK_RESPONSE_OK) {
      gtk_widget_destroy(dg.dialog);
    }

    return 1;
  }

  return 0;
}
