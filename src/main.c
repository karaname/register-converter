#include <gtk/gtk.h>
#include "main.h"
#include "handlers.h"

static void
make_buttons_grid()
{
  gtk_grid_insert_row(GTK_GRID(gr.grid_buttns), 1);
  gtk_grid_insert_column(GTK_GRID(gr.grid_buttns), 4);
  gtk_grid_set_column_spacing(GTK_GRID(gr.grid_buttns), 50);
  gtk_grid_set_column_homogeneous(GTK_GRID(gr.grid_buttns), TRUE);
  gtk_widget_set_valign(GTK_WIDGET(gr.grid_buttns), GTK_ALIGN_CENTER);
}

static void
make_initial_grid()
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
}

static void
make_scrolled_window(GtkWidget *scrolled_window,
GtkTextBuffer *text_buffer, GtkWidget *text_view,
gboolean value)
{
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
  /* new objects */
  nt.notebook = gtk_notebook_new();
  nt.label = gtk_label_new("???");

  nt.conv_page = gtk_label_new("Conversion");
  nt.gen_page = gtk_label_new("Generator");

  gr.grid_main = gtk_grid_new();
  gr.grid_buttns = gtk_grid_new();

  frw.scrolled_window_FR = gtk_scrolled_window_new(NULL, NULL);
  bf.text_buffer_FR = gtk_text_buffer_new(NULL);
  frw.text_view_FR = gtk_text_view_new_with_buffer(bf.text_buffer_FR);

  bt.clear_buttn = gtk_button_new_with_label("Clear");

  tv.list_store = gtk_list_store_new(N_COLUMNS, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,
    G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

  tv.tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(tv.list_store));
  tv.renderer = gtk_cell_renderer_text_new();

  srw.scrolled_window_SR = gtk_scrolled_window_new(NULL, NULL);
  bf.text_buffer_SR = gtk_text_buffer_new(NULL);
  srw.text_view_SR = gtk_text_view_new_with_buffer(bf.text_buffer_SR);

  bt.lower_buttn = gtk_button_new_with_label("Lower");
  bt.upper_buttn = gtk_button_new_with_label("Upper");
  bt.title_buttn = gtk_button_new_with_label("Title");
  bt.rev_buttn = gtk_button_new_with_label("Reverse");


  /* scrolled window first row */
  make_scrolled_window(frw.scrolled_window_FR, bf.text_buffer_FR, frw.text_view_FR, 1);

  /* clear button */
  gtk_container_set_border_width(GTK_CONTAINER(bt.clear_buttn), 40);
  gtk_widget_set_valign(GTK_WIDGET(bt.clear_buttn), GTK_ALIGN_CENTER);
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.clear_buttn), "Clear all buffers in this page");

  /* tree view */
  make_tree_view();

  /* scrolled window second row */
  make_scrolled_window(srw.scrolled_window_SR, bf.text_buffer_SR, srw.text_view_SR, 0);

  /* cases buttons */
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.lower_buttn), "Text conversion to lower");
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.upper_buttn), "Text conversion to upper");
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.title_buttn), "Text conversion to title");
  gtk_widget_set_tooltip_text(GTK_WIDGET(bt.rev_buttn), "Text conversion to reverse");

  /* grids */
  make_buttons_grid();
  make_initial_grid();


  /* ATTACH WIDGETS TO GRID_MAIN */
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(frw.scrolled_window_FR), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(bt.clear_buttn), 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(tv.tree_view), 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(srw.scrolled_window_SR), 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(gr.grid_buttns), 0, 2, 2, 1);
  /* left, top, width, height */

  /* ATTACH BUTTONS TO GRID_BUTTNS */
  gtk_grid_attach(GTK_GRID(gr.grid_buttns), GTK_WIDGET(bt.lower_buttn), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_buttns), GTK_WIDGET(bt.upper_buttn), 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_buttns), GTK_WIDGET(bt.title_buttn), 2, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(gr.grid_buttns), GTK_WIDGET(bt.rev_buttn), 3, 0, 1, 1);

  /* notebook */
  gtk_notebook_set_tab_pos(GTK_NOTEBOOK(nt.notebook), GTK_POS_TOP);
  gtk_notebook_append_page(GTK_NOTEBOOK(nt.notebook), gr.grid_main, nt.conv_page);
  gtk_notebook_append_page(GTK_NOTEBOOK(nt.notebook), nt.label, nt.gen_page);

  /* background problem */
  css_provider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(css_provider, "css/theme.css", NULL);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
    GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  gtk_style_context_add_class(gtk_widget_get_style_context(frw.text_view_FR), "views_bg");
  gtk_style_context_add_class(gtk_widget_get_style_context(srw.text_view_SR), "views_bg");

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
  g_signal_connect(G_OBJECT(bt.lower_buttn), "clicked", G_CALLBACK(on_lower_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.upper_buttn), "clicked", G_CALLBACK(on_upper_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.title_buttn), "clicked", G_CALLBACK(on_title_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.rev_buttn), "clicked", G_CALLBACK(on_reverse_button_clicked), NULL);
  g_signal_connect(G_OBJECT(bt.clear_buttn), "clicked", G_CALLBACK(on_clear_button_clicked), NULL);

  gtk_main();

  return 0;
}
