#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to send a message to Discord webhook
int send_to_discord_webhook(const char *webhook_url, const char *message) {
    CURL *curl;
    CURLcode res;

    // Construct the JSON string with the dynamic message content
    char content[256];  // Adjust the size based on your message length
    snprintf(content, sizeof(content), "{\"content\":\"%s\"}", message);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, webhook_url);

        // Set the method to POST
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // Set the message content
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, content);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
            curl_global_cleanup();
            return 0; // Failure
        }

        // Cleanup
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    curl_global_cleanup();
    return 1; // Success
}

// Callback function to handle button click
void on_button_clicked(GtkWidget *widget, gpointer data) {
    // Get the entry texts
    GtkWidget **entries = (GtkWidget **)data;
    const gchar *webhook_url = gtk_entry_get_text(GTK_ENTRY(entries[0]));
    const gchar *message = gtk_entry_get_text(GTK_ENTRY(entries[1]));

    // Send the message to Discord webhook and display status
    int result = send_to_discord_webhook(webhook_url, message);

    // Display a dialog box with the result
    GtkWidget *dialog;
    if (result) {
        dialog = gtk_message_dialog_new(NULL,
                                       GTK_DIALOG_DESTROY_WITH_PARENT,
                                       GTK_MESSAGE_INFO,
                                       GTK_BUTTONS_OK,
                                       "Message sent successfully!");
    } else {
        dialog = gtk_message_dialog_new(NULL,
                                       GTK_DIALOG_DESTROY_WITH_PARENT,
                                       GTK_MESSAGE_ERROR,
                                       GTK_BUTTONS_OK,
                                       "Failed to send message. Check console for details.");
    }

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    g_print("After webhook\n");
}
