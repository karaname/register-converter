#include <gtk/gtk.h>
#include "headers.h"

int main(int argc, char *argv[])
{
  struct MainStruct leb;

  struct ButtonsStruct {
    GtkWidget *lowerbutton;
    GtkWidget *upperbutton;
    GtkWidget *titlebutton;
    GtkWidget *reversebutton;
    GtkWidget *clearbutton;
  } bt;

  struct BoxStruct {
    GtkWidget *hbox1;
    GtkWidget *hbox2;
    GtkWidget *hbox3;
    GtkWidget *vbox;
  } vb;

  GtkWidget *window;

  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Title");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  bt.lowerbutton = gtk_button_new_with_label("Lowercase");
  bt.upperbutton = gtk_button_new_with_label("Uppercase");
  bt.titlebutton = gtk_button_new_with_label("Title");
  bt.reversebutton = gtk_button_new_with_label("Reverse");
  bt.clearbutton = gtk_button_new_with_label("Clear");

  leb.buffer = gtk_entry_buffer_new(NULL, -1);
  leb.entry = gtk_entry_new_with_buffer(GTK_ENTRY_BUFFER(leb.buffer));
  gtk_entry_buffer_set_max_length(GTK_ENTRY_BUFFER(leb.buffer), 200);

  leb.label = gtk_label_new("200 symbols");

  vb.hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
  vb.hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
  vb.hbox3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
  vb.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);

  gtk_box_pack_start(GTK_BOX(vb.hbox1), leb.entry, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(vb.hbox1), bt.clearbutton, TRUE, TRUE, 10);

  gtk_box_pack_start(GTK_BOX(vb.hbox2), leb.label, TRUE, TRUE, 10);

  gtk_box_pack_start(GTK_BOX(vb.hbox3), bt.lowerbutton, TRUE, TRUE, 20);
  gtk_box_pack_start(GTK_BOX(vb.hbox3), bt.upperbutton, TRUE, TRUE, 20);
  gtk_box_pack_start(GTK_BOX(vb.hbox3), bt.titlebutton, TRUE, TRUE, 20);
  gtk_box_pack_start(GTK_BOX(vb.hbox3), bt.reversebutton, TRUE, TRUE, 20);

  gtk_box_pack_start(GTK_BOX(vb.vbox), vb.hbox1, TRUE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(vb.vbox), vb.hbox2, TRUE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(vb.vbox), vb.hbox3, TRUE, FALSE, 10);
  gtk_container_add(GTK_CONTAINER(window), vb.vbox);

  g_signal_connect(G_OBJECT(bt.lowerbutton), "clicked", G_CALLBACK(lower_button_clicked), &leb);
  g_signal_connect(G_OBJECT(bt.upperbutton), "clicked", G_CALLBACK(upper_button_clicked), &leb);
  g_signal_connect(G_OBJECT(bt.titlebutton), "clicked", G_CALLBACK(title_button_clicked), &leb);
  g_signal_connect(G_OBJECT(bt.reversebutton), "clicked", G_CALLBACK(reverse_button_clicked), &leb);
  g_signal_connect(G_OBJECT(bt.clearbutton), "clicked", G_CALLBACK(clear_entry), &leb);
  g_signal_connect(G_OBJECT(window), "destroy", gtk_main_quit, NULL);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
