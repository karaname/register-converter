#include <gtk/gtk.h>
#include "handlers.h"
#include "main.h"

struct Dialog dg;
struct Buttons bt;
struct TreeView tv;
struct SecondRowWindow srw;
struct FirstRowWindow frw;
struct GenPageWindow gpw;
struct Buffers bf;
struct Grids gr;
struct Notebook nt;
GtkWidget *window;

static void
make_gen_buttons_grid()
{
  gtk_grid_insert_row(GTK_GRID(gr.gen_buttons_grid), 1);
  gtk_grid_insert_column(GTK_GRID(gr.gen_buttons_grid), 2);
  gtk_grid_set_column_spacing(GTK_GRID(gr.gen_buttons_grid), 120);
  gtk_grid_set_column_homogeneous(GTK_GRID(gr.gen_buttons_grid), TRUE);
  gtk_widget_set_valign(GTK_WIDGET(gr.gen_buttons_grid), GTK_ALIGN_END);
}

static void
make_gen_grid()
{
  gtk_grid_insert_row(GTK_GRID(gr.gen_grid), 2);
  gtk_grid_insert_column(GTK_GRID(gr.gen_grid), 1);
  gtk_grid_set_row_homogeneous(GTK_GRID(gr.gen_grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(gr.gen_grid), TRUE);
  gtk_container_set_border_width(GTK_CONTAINER(gr.gen_grid), 50);
}

static void
make_buttons_grid()
{
  gtk_grid_insert_row(GTK_GRID(gr.grid_buttons), 1);
  gtk_grid_insert_column(GTK_GRID(gr.grid_buttons), 4);
  gtk_grid_set_column_spacing(GTK_GRID(gr.grid_buttons), 80);
  gtk_grid_set_column_homogeneous(GTK_GRID(gr.grid_buttons), TRUE);
  gtk_widget_set_valign(GTK_WIDGET(gr.grid_buttons), GTK_ALIGN_END);
}

static void
make_main_grid()
{
  gtk_grid_insert_row(GTK_GRID(gr.grid_main), 3);
  gtk_grid_insert_column(GTK_GRID(gr.grid_main), 2);
  gtk_grid_set_row_spacing(GTK_GRID(gr.grid_main), 60);
  gtk_grid_set_column_spacing(GTK_GRID(gr.grid_main), 60);
  gtk_grid_set_row_homogeneous(GTK_GRID(gr.grid_main), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(gr.grid_main), TRUE);
  gtk_container_set_border_width(GTK_CONTAINER(gr.grid_main), 50);
}

static void
make_tree_view()
{
  gtk_tree_view_set_search_column(GTK_TREE_VIEW(tv.tree_view), -1);
  gtk_tree_view_set_show_expanders(GTK_TREE_VIEW(tv.tree_view), FALSE);
  gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(tv.tree_view), FALSE);

  tv.selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tv.tree_view));
  gtk_tree_selection_set_mode(GTK_TREE_SELECTION(tv.selection), GTK_SELECTION_NONE);

  gtk_list_store_append(GTK_LIST_STORE(tv.list_store), &tv.iter);

  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), COLUMN_TOTAL, "Total",
     tv.renderer, "text", COLUMN_TOTAL, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), COLUMN_LETTER, "Letter",
    tv.renderer, "text", COLUMN_LETTER, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), COLUMN_SPECIAL, "Special",
    tv.renderer, "text", COLUMN_SPECIAL, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), COLUMN_SPACE, "Space",
    tv.renderer, "text", COLUMN_SPACE, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), COLUMN_NUM, "Number",
    tv.renderer, "text", COLUMN_NUM, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), COLUMN_EVEN, "Even",
    tv.renderer, "text", COLUMN_EVEN, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), COLUMN_ODD, "Odd",
    tv.renderer, "text", COLUMN_ODD, NULL);

  gtk_container_add(GTK_CONTAINER(tv.scrolled_tree_window), tv.tree_view);
}

static void
make_scrolled_window(GtkWidget *scrolled_window,
GtkTextBuffer *text_buffer, GtkWidget *text_view,
gboolean value)
{
  gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolled_window), GTK_SHADOW_IN);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
    GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);

  if (value) {
    gtk_text_buffer_set_text(text_buffer,
      "Enter the text and click on any button you like ...", -1);
  }

  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD_CHAR);
  gtk_text_view_set_monospace(GTK_TEXT_VIEW(text_view), TRUE);

  /* MARGINS */
  gtk_text_view_set_left_margin(GTK_TEXT_VIEW(text_view), 5);
  gtk_text_view_set_right_margin(GTK_TEXT_VIEW(text_view), 8);
  gtk_text_view_set_top_margin(GTK_TEXT_VIEW(text_view), 5);
  gtk_text_view_set_bottom_margin(GTK_TEXT_VIEW(text_view), 5);

  /* PIXELS */
  gtk_text_view_set_pixels_above_lines(GTK_TEXT_VIEW(text_view), 3);
  gtk_text_view_set_pixels_below_lines(GTK_TEXT_VIEW(text_view), 3);
  gtk_text_view_set_pixels_inside_wrap(GTK_TEXT_VIEW(text_view), 2);

  gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
}

static GtkWidget *
make_common()
{
  nt.notebook = gtk_notebook_new();
  nt.conv_page = gtk_label_new("Conversion");
  nt.gen_page = gtk_label_new("Generator");

  gr.grid_main = gtk_grid_new();
  gr.grid_buttons = gtk_grid_new();
  gr.gen_grid = gtk_grid_new();
  gr.gen_buttons_grid = gtk_grid_new();

  frw.scrolled_window_FR = gtk_scrolled_window_new(NULL, NULL);
  bf.text_buffer_FR = gtk_text_buffer_new(NULL);
  frw.text_view_FR = gtk_text_view_new_with_buffer(bf.text_buffer_FR);

  bt.clear_button = gtk_button_new_with_label("Clear");
  gtk_widget_set_valign(GTK_WIDGET(bt.clear_button), GTK_ALIGN_CENTER);
  gtk_container_set_border_width(GTK_CONTAINER(bt.clear_button), 30);

  tv.list_store = gtk_list_store_new(N_COLUMNS, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

  tv.scrolled_tree_window = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(tv.scrolled_tree_window),
    GTK_POLICY_NEVER, GTK_POLICY_NEVER);
  gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(tv.scrolled_tree_window), GTK_SHADOW_IN);

  tv.tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(tv.list_store));
  tv.renderer = gtk_cell_renderer_text_new();

  srw.scrolled_window_SR = gtk_scrolled_window_new(NULL, NULL);
  bf.text_buffer_SR = gtk_text_buffer_new(NULL);
  srw.text_view_SR = gtk_text_view_new_with_buffer(bf.text_buffer_SR);

  bt.lower_button = gtk_button_new_with_label("Lower");
  bt.upper_button = gtk_button_new_with_label("Upper");
  bt.title_button = gtk_button_new_with_label("Title");
  bt.rev_button = gtk_button_new_with_label("Reverse");
  bt.random_button = gtk_button_new_with_label("Random");
  bt.clipboard_button = gtk_button_new_with_label("Clipboard");

  gpw.gen_scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  bf.text_buffer_gen = gtk_text_buffer_new(NULL);
  gpw.gen_text_view = gtk_text_view_new_with_buffer(bf.text_buffer_gen);

  make_scrolled_window(frw.scrolled_window_FR, bf.text_buffer_FR, frw.text_view_FR, 1);
  make_tree_view();
  make_scrolled_window(srw.scrolled_window_SR, bf.text_buffer_SR, srw.text_view_SR, 0);
  make_scrolled_window(gpw.gen_scrolled_window, bf.text_buffer_gen, gpw.gen_text_view, 0);

  make_buttons_grid();
  make_main_grid();

  make_gen_buttons_grid();
  make_gen_grid();

  /* tooltips */
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.clear_button), "Clear all buffers in this page");
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.lower_button), "Text conversion to lower");
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.upper_button), "Text conversion to upper");
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.title_button), "Text conversion to title");
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.rev_button), "Text conversion to reverse");
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.random_button), "Generate random text");
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.clipboard_button), "Set text in clipboard");


  /* ATTACH BUTTONS TO GRID_BUTTNS */
  gtk_grid_attach(GTK_GRID(gr.grid_buttons), GTK_WIDGET(bt.lower_button), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_buttons), GTK_WIDGET(bt.upper_button), 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_buttons), GTK_WIDGET(bt.title_button), 2, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_buttons), GTK_WIDGET(bt.rev_button), 3, 0, 1, 1);

  /* ATTACH WIDGETS TO GRID_MAIN */
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(frw.scrolled_window_FR), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(bt.clear_button), 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(tv.scrolled_tree_window), 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(srw.scrolled_window_SR), 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(gr.grid_buttons), 0, 2, 2, 1);
  /* left, top, width, height */

  /* ATTACH BUTTONS TO GEN_BUTTONS_GRID */
  gtk_grid_attach(GTK_GRID(gr.gen_buttons_grid), GTK_WIDGET(bt.random_button), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.gen_buttons_grid), GTK_WIDGET(bt.clipboard_button), 1, 0, 1, 1);

  /* ATTACH WIDGETS TO GEN_GRID */
  gtk_grid_attach(GTK_GRID(gr.gen_grid), GTK_WIDGET(gpw.gen_scrolled_window), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.gen_grid), GTK_WIDGET(gr.gen_buttons_grid), 0, 1, 1, 1);


  /* notebook */
  gtk_notebook_set_tab_pos(GTK_NOTEBOOK(nt.notebook), GTK_POS_TOP);
  gtk_notebook_append_page(GTK_NOTEBOOK(nt.notebook), gr.grid_main, nt.conv_page);
  gtk_notebook_append_page(GTK_NOTEBOOK(nt.notebook), gr.gen_grid, nt.gen_page);

  return GTK_WIDGET(nt.notebook);
}

int main(int argc, char **argv)
{
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Text Manipulation - ASCII");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_window_maximize(GTK_WINDOW(window));

  gtk_container_add(GTK_CONTAINER(window), make_common());
  gtk_widget_show_all(window);

  g_signal_connect(G_OBJECT(window), "destroy", gtk_main_quit, NULL);
  g_signal_connect(G_OBJECT(bf.text_buffer_FR), "insert-text", G_CALLBACK(max_buffer_insert), NULL);
  g_signal_connect(G_OBJECT(bt.lower_button), "clicked", G_CALLBACK(on_lower_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.upper_button), "clicked", G_CALLBACK(on_upper_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.title_button), "clicked", G_CALLBACK(on_title_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.rev_button), "clicked", G_CALLBACK(on_reverse_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.clear_button), "clicked", G_CALLBACK(on_clear_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.random_button), "clicked", G_CALLBACK(on_random_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.clipboard_button), "clicked", G_CALLBACK(on_clipboard_button_clicked), NULL);

  gtk_main();

  return 0;
}
