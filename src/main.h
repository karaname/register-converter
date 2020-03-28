struct Buttons {
	GtkWidget *lower_buttn;
	GtkWidget *upper_buttn;
	GtkWidget *title_buttn;
	GtkWidget *rev_buttn;
	GtkWidget *clear_buttn;
} bt;

struct TreeView {
	GtkListStore *list_store;
	GtkWidget *tree_view;
	GtkTreeSelection *selection;
	GtkTreeIter iter;
	GtkCellRenderer *renderer;
} tv;

struct SecondRowWindow {
	GtkWidget *scrolled_window_SR;
	GtkWidget *text_view_SR;
} srw;

struct FirstRowWindow {
	GtkWidget *scrolled_window_FR;
	GtkWidget *text_view_FR;
} frw;

struct Buffers {
	GtkTextBuffer *text_buffer_FR;
	GtkTextBuffer *text_buffer_SR;
} bf;

struct Grids {
	GtkWidget *grid_main;
	GtkWidget *grid_buttns;
} gr;

void on_lower_button_clicked(GtkWidget *lower_buttn, struct Buffers *p);
void on_upper_button_clicked(GtkWidget *upper_buttn, struct Buffers *p);
void on_title_button_clicked(GtkWidget *title_buttn, struct Buffers *p);
void on_reverse_button_clicked(GtkWidget *rev_buttn, struct Buffers *p);
void on_clear_button_clicked(GtkWidget *clear_buttn, struct Buffers *p);
