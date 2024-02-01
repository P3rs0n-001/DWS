#include <gtk/gtk.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new top-level window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Discord Webhook Sender");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 400, 250);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create entry fields for webhook URL and message
    GtkWidget *webhook_entry = gtk_entry_new();
    GtkWidget *message_entry = gtk_entry_new();

    // Set placeholder text for entry fields
    gtk_entry_set_placeholder_text(GTK_ENTRY(webhook_entry), "Enter Webhook URL");
    gtk_entry_set_placeholder_text(GTK_ENTRY(message_entry), "Enter Message");

    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Send to Discord");

    // Pack entry fields and button into a vertical box
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(box), webhook_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), message_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

    // Connect button click event to callback function
    GtkWidget *entries[2] = {webhook_entry, message_entry};
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), (gpointer)entries);

    // Add the box to the window
    gtk_container_add(GTK_CONTAINER(window), box);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}
