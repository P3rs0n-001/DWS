#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <gtk/gtk.h>
#include <curl/curl.h>

int send_to_discord_webhook(const char *webhook_url, const char *message);
void on_button_clicked(GtkWidget *widget, gpointer data);

#endif // FUNCTIONS_H
