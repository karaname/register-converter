enum {
  COLUMN_TOTAL,
  COLUMN_LETTER,
  COLUMN_SPECIAL,
  COLUMN_SPACE,
  COLUMN_NUM,
  COLUMN_EVEN,
  COLUMN_ODD,
  N_COLUMNS
};

struct Dialog {
  GtkWidget *dialog;
  GtkWidget *content_area;
  GtkWidget *message;
  GtkWidget *box_button;
  GtkWidget *ok_button;
} dg;

struct Buttons {
  GtkWidget *lower_button;
  GtkWidget *upper_button;
  GtkWidget *title_button;
  GtkWidget *rev_button;
  GtkWidget *clear_button;
  GtkWidget *random_button;
  GtkWidget *clipboard_button;
} bt;

struct TreeView {
  GtkWidget *scrolled_tree_window;
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

struct GenPageWindow {
  GtkWidget *gen_scrolled_window;
  GtkWidget *gen_text_view;
} gpw;

struct Buffers {
  GtkTextBuffer *text_buffer_FR;
  GtkTextBuffer *text_buffer_SR;
  GtkTextBuffer *text_buffer_gen;
} bf;

struct Grids {
  GtkWidget *grid_main;
  GtkWidget *grid_buttons;
  GtkWidget *gen_grid;
  GtkWidget *gen_buttons_grid;
} gr;

struct Notebook {
  GtkWidget *notebook;
  GtkWidget *conv_page;
  GtkWidget *gen_page;
} nt;

GtkWidget *window;
