#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "some.h"

GdkPixbuf *
load_data()
{
    GdkPixbuf *bmp;
    GdkColorspace rgb = GDK_COLORSPACE_RGB;

    bmp = gdk_pixbuf_new_from_data(SOME_BMP_PIXEL_DATA, rgb, FALSE, 8,
                                   SOME_BMP_WIDTH, SOME_BMP_HEIGHT, SOME_BMP_ROWSTRIDE,
                                   NULL, NULL
    );

    return bmp;
}

int main (int argc, char *argv[])
{
    GtkWidget *win = NULL;
    GtkWidget *vbox = NULL;

    /* Initialize GTK+ */
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
    gtk_init (&argc, &argv);
    g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

    /* Create the main window */
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (win), 8);
    gtk_window_set_title (GTK_WINDOW (win), "Hello, Pix!");
    gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
    gtk_widget_realize (win);
    g_signal_connect (win, "destroy", gtk_main_quit, NULL);

    /* Create a vertical box with buttons */
    vbox = gtk_vbox_new (TRUE, 6);
    gtk_container_add (GTK_CONTAINER (win), vbox);


    GdkPixbuf *pixbuf;
    pixbuf = load_data();

    GtkWidget *image;
    image = gtk_image_new_from_pixbuf(pixbuf);
    gtk_box_pack_start (GTK_BOX (vbox), image, TRUE, TRUE, 0);

    /* Enter the main loop */
    gtk_widget_show_all (win);
    gtk_main ();
    return 0;
}
