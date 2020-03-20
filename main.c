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

  struct VBoxStruct {
    GtkWidget *vbox1;
    GtkWidget *vbox2;
    GtkWidget *vbox3;
  } vb;

  GtkWidget *hbox;
  GtkWidget *window;

  /*
    Если мы инициализируме указатель на структуру
    struct ButtonsStruct *pointer = &bt;
    То тогда обращение к элементам происходит как pointer -> lowerbutton
    Потому что указатель на структуру

    Если мы инициализируем переменную посредника
    struct ButtonsStruct bt;
    То тогда обращение к элементам структуры происходит как bt.lowerbutton
  */

  /*
    Если определить структуру с помощью:
    typedef struct {
      int x;
    } Name;

    И затем struct Name *p;
    Обращение к элементам происходит через p -> label;
    Нужно понять разницу между struct Name {}; и typedef struct {} Name;
  */

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

  vb.vbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
  vb.vbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
  vb.vbox3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
  hbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);

  gtk_box_pack_start(GTK_BOX(vb.vbox1), leb.entry, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(vb.vbox1), bt.clearbutton, TRUE, TRUE, 10);

  gtk_box_pack_start(GTK_BOX(vb.vbox2), leb.label, TRUE, TRUE, 10);

  gtk_box_pack_start(GTK_BOX(vb.vbox3), bt.lowerbutton, TRUE, TRUE, 20);
  gtk_box_pack_start(GTK_BOX(vb.vbox3), bt.upperbutton, TRUE, TRUE, 20);
  gtk_box_pack_start(GTK_BOX(vb.vbox3), bt.titlebutton, TRUE, TRUE, 20);
  gtk_box_pack_start(GTK_BOX(vb.vbox3), bt.reversebutton, TRUE, TRUE, 20);

  gtk_box_pack_start(GTK_BOX(hbox), vb.vbox1, TRUE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(hbox), vb.vbox2, TRUE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(hbox), vb.vbox3, TRUE, FALSE, 10);
  gtk_container_add(GTK_CONTAINER(window), hbox);

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
