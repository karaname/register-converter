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

extern struct Dialog {
  GtkWidget *dialog;
  GtkWidget *content_area;
  GtkWidget *message;
  GtkWidget *box_button;
  GtkWidget *ok_button;
} dg;

extern struct Buttons {
  GtkWidget *lower_button;
  GtkWidget *upper_button;
  GtkWidget *title_button;
  GtkWidget *rev_button;
  GtkWidget *clear_button;
  GtkWidget *random_button;
  GtkWidget *clipboard_button;
} bt;

extern struct TreeView {
  GtkWidget *scrolled_tree_window;
  GtkListStore *list_store;
  GtkWidget *tree_view;
  GtkTreeSelection *selection;
  GtkTreeIter iter;
  GtkCellRenderer *renderer;
} tv;

extern struct SecondRowWindow {
  GtkWidget *scrolled_window_SR;
  GtkWidget *text_view_SR;
} srw;

extern struct FirstRowWindow {
  GtkWidget *scrolled_window_FR;
  GtkWidget *text_view_FR;
} frw;

extern struct GenPageWindow {
  GtkWidget *gen_scrolled_window;
  GtkWidget *gen_text_view;
} gpw;

extern struct Buffers {
  GtkTextBuffer *text_buffer_FR;
  GtkTextBuffer *text_buffer_SR;
  GtkTextBuffer *text_buffer_gen;
} bf;

extern struct Grids {
  GtkWidget *grid_main;
  GtkWidget *grid_buttons;
  GtkWidget *gen_grid;
  GtkWidget *gen_buttons_grid;
} gr;

extern struct Notebook {
  GtkWidget *notebook;
  GtkWidget *conv_page;
  GtkWidget *gen_page;
} nt;

extern GtkWidget *window;
