#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Configures terminal to read characters instantly and non-blockingly
void set_non_blocking_mode(struct termios *old_settings) {
    struct termios new_settings;
    
    // Get current terminal settings
    tcgetattr(STDIN_FILENO, old_settings);
    new_settings = *old_settings;
    
    // Disable canonical mode (line buffering) and local echo
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    
    // Set stdin file descriptor to non-blocking mode
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

// Restores the original terminal state
void reset_terminal_mode(struct termios *old_settings) {
    tcsetattr(STDIN_FILENO, TCSANOW, old_settings);
}

int main() {
    struct termios old_settings;
    set_non_blocking_mode(&old_settings);

    printf("Press keys on your keyboard. Press 'q' to quit.\n");

    while (1) {
        char ch;
        // Attempt to read 1 byte from stdin
        int bytes_read = read(STDIN_FILENO, &ch, 1);

        if (bytes_read > 0) {
            printf("\nYou pressed: %c\n", ch);
            if (ch == 'q' || ch == 'Q') {
                break;
            }
        }

        // Program keeps running other tasks
        printf(".");
        fflush(stdout);
        usleep(200000); // Sleep 200ms to save CPU cycles
    }

    // Crucial: always restore settings before exiting
    reset_terminal_mode(&old_settings);
    printf("\nProgram exited.\n");
    return 0;
}

