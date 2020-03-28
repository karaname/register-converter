#include <gtk/gtk.h>
#include "main.h"

static void make_buttons_grid(GtkWidget *grid_buttns)
{
	gtk_grid_insert_row(GTK_GRID(gr.grid_buttns), 1);
	gtk_grid_insert_column(GTK_GRID(gr.grid_buttns), 4);

	gtk_grid_set_column_spacing(GTK_GRID(gr.grid_buttns), 40);
	gtk_grid_set_column_homogeneous(GTK_GRID(gr.grid_buttns), TRUE);
  gtk_widget_set_valign(GTK_WIDGET(gr.grid_buttns), GTK_ALIGN_CENTER);
}

static void make_initial_grid(GtkWidget *grid_main)
{
	gtk_grid_insert_row(GTK_GRID(gr.grid_main), 3);
	gtk_grid_insert_column(GTK_GRID(gr.grid_main), 2);

	gtk_grid_set_row_spacing(GTK_GRID(gr.grid_main), 20);
	gtk_grid_set_column_spacing(GTK_GRID(gr.grid_main), 20);
	gtk_grid_set_row_homogeneous(GTK_GRID(gr.grid_main), TRUE);
	gtk_grid_set_column_homogeneous(GTK_GRID(gr.grid_main), TRUE);
	gtk_container_set_border_width(GTK_CONTAINER(gr.grid_main), 20);
}

static void make_tree_view(GtkListStore *list_store,
GtkWidget *tree_view, GtkCellRenderer *renderer)
{
	gtk_tree_view_set_search_column(GTK_TREE_VIEW(tv.tree_view), -1);
	gtk_tree_view_set_show_expanders(GTK_TREE_VIEW(tv.tree_view), FALSE);
	gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(tv.tree_view), FALSE);

	tv.selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tv.tree_view));
	gtk_tree_selection_set_mode(GTK_TREE_SELECTION(tv.selection), GTK_SELECTION_NONE);

	gtk_list_store_append(GTK_LIST_STORE(tv.list_store), &tv.iter);

	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), 0, "Total", tv.renderer, "text", 0, NULL);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), 1, "Letter", tv.renderer, "text", 1, NULL);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), 2, "Special", tv.renderer, "text", 2, NULL);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), 3, "Space", tv.renderer, "text", 3, NULL);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), 4, "Number", tv.renderer, "text", 4, NULL);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), 5, "Even", tv.renderer, "text", 5, NULL);
	gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(tv.tree_view), 6, "Odd", tv.renderer, "text", 6, NULL);
}

static void make_scroll_window(GtkWidget *scrolled_window,
GtkTextBuffer *text_buffer, GtkWidget *text_view, gboolean value)
{
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);

  if (value == 1)
	  gtk_text_buffer_set_text(GTK_TEXT_BUFFER(text_buffer), "Enter the text and click on any button you like ...", -1);

	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD_CHAR);
	gtk_text_view_set_monospace(GTK_TEXT_VIEW(text_view), TRUE);
	gtk_text_view_set_left_margin(GTK_TEXT_VIEW(text_view), 5);
	gtk_text_view_set_right_margin(GTK_TEXT_VIEW(text_view), 8);
	gtk_text_view_set_top_margin(GTK_TEXT_VIEW(text_view), 5);
	gtk_text_view_set_bottom_margin(GTK_TEXT_VIEW(text_view), 5);
	gtk_text_view_set_pixels_above_lines(GTK_TEXT_VIEW(text_view), 3);
	gtk_text_view_set_pixels_below_lines(GTK_TEXT_VIEW(text_view), 3);
	gtk_text_view_set_pixels_inside_wrap(GTK_TEXT_VIEW(text_view), 2);

	gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);
}

static GtkWidget *
make_generic(GtkWidget *grid_main)
{
	frw.scrolled_window_FR = gtk_scrolled_window_new(NULL, NULL);
	bf.text_buffer_FR = gtk_text_buffer_new(NULL);
	frw.text_view_FR = gtk_text_view_new_with_buffer(GTK_TEXT_BUFFER(bf.text_buffer_FR));

  bt.clear_buttn = gtk_button_new_with_label("Clear");
	gtk_container_set_border_width(GTK_CONTAINER(bt.clear_buttn), 60);

	tv.list_store = gtk_list_store_new(7, G_TYPE_INT,
		G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,
		G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

	tv.tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(tv.list_store));
	tv.renderer = gtk_cell_renderer_text_new();

	srw.scrolled_window_SR = gtk_scrolled_window_new(NULL, NULL);
	bf.text_buffer_SR = gtk_text_buffer_new(NULL);
	srw.text_view_SR = gtk_text_view_new_with_buffer(GTK_TEXT_BUFFER(bf.text_buffer_SR));

  gr.grid_buttns = gtk_grid_new();
  bt.lower_buttn = gtk_button_new_with_label("Lower");
  bt.upper_buttn = gtk_button_new_with_label("Upper");
  bt.title_buttn = gtk_button_new_with_label("Title");
  bt.rev_buttn = gtk_button_new_with_label("Reverse");


  make_initial_grid(gr.grid_main);
  make_scroll_window(frw.scrolled_window_FR, bf.text_buffer_FR, frw.text_view_FR, 1);
  make_tree_view(tv.list_store, tv.tree_view, tv.renderer);
  make_scroll_window(srw.scrolled_window_SR, bf.text_buffer_SR, srw.text_view_SR, 0);
  make_buttons_grid(gr.grid_buttns);


	gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(frw.scrolled_window_FR), 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(bt.clear_buttn), 1, 0, 1, 1);

	gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(tv.tree_view), 0, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(srw.scrolled_window_SR), 1, 1, 1, 1);

	gtk_grid_attach(GTK_GRID(gr.grid_main), GTK_WIDGET(gr.grid_buttns), 0, 2, 2, 1);
	gtk_grid_attach(GTK_GRID(gr.grid_buttns), GTK_WIDGET(bt.lower_buttn), 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(gr.grid_buttns), GTK_WIDGET(bt.upper_buttn), 1, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(gr.grid_buttns), GTK_WIDGET(bt.title_buttn), 2, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(gr.grid_buttns), GTK_WIDGET(bt.rev_buttn), 3, 0, 1, 1);

  return GTK_WIDGET (grid_main);
}

int main(int argc, char *argv[])
{
  GtkWidget *window;

  gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Register Converter");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

	gr.grid_main = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), make_generic(gr.grid_main));
	gtk_widget_show_all(window);

	g_signal_connect(G_OBJECT(window), "destroy", gtk_main_quit, NULL);
	g_signal_connect(G_OBJECT(bt.lower_buttn), "clicked", G_CALLBACK(on_lower_button_clicked), &bf);
	g_signal_connect(G_OBJECT(bt.upper_buttn), "clicked", G_CALLBACK(on_upper_button_clicked), &bf);
	g_signal_connect(G_OBJECT(bt.title_buttn), "clicked", G_CALLBACK(on_title_button_clicked), &bf);
	g_signal_connect(G_OBJECT(bt.rev_buttn), "clicked", G_CALLBACK(on_reverse_button_clicked), &bf);
	g_signal_connect(G_OBJECT(bt.clear_buttn), "clicked", G_CALLBACK(on_clear_button_clicked), &bf);

  gtk_main();

  return 0;
}
