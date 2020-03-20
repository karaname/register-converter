struct MainStruct {
  GtkEntryBuffer *buffer;
  GtkWidget *entry;
  GtkWidget *label;
};

void count(struct MainStruct *c);
void lower_button_clicked(GtkWidget *lowerbutton, struct MainStruct *p);
void upper_button_clicked(GtkWidget *upperbutton, struct MainStruct *p);
void title_button_clicked(GtkWidget *titlebutton, struct MainStruct *p);
void reverse_button_clicked(GtkWidget *reversebutton, struct MainStruct *p);
void clear_entry(GtkWidget *clearbutton, struct MainStruct *p);
