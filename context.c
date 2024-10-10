#include <gtk/gtk.h>
#include <glib/gstdio.h>

static void print_hello (GtkWidget *widget, gpointer data)
{
    g_print("Hello");
}

static void quit_cb (GtkWindow *window)
{
    gtk_window_close (window);
}

static void activate (GtkApplication* app, gpointer user_data)
{
    GtkBuilder *builder = gtk_builder_new ();
    gtk_builder_add_from_file (builder, "builder.ui", NULL); // Load UI description

    // Connect signal handler to widget
    GObject *window = gtk_builder_get_object (builder, "window"); 
    gtk_window_set_application (GTK_WINDOW (window), app);

    GObject *button = gtk_builder_get_object (builder, "submit");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

    gtk_widget_set_visible (GTK_WIDGET (window), TRUE);
    g_object_unref (builder);
}


int main (int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.context", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}