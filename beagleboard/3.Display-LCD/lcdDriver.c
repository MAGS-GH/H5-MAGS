#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <string.h>

#define I2C_BUS "/dev/i2c-2" // Afhængigt af dit system
#define I2C_ADDR 0x3E

// Control byte bits
#define CO_BIT 0x80
#define RS_BIT 0x40

int i2c_fd;

void lcd_send_command(unsigned char command) {
    unsigned char buf[2];
    buf[0] = CO_BIT; // Control byte
    buf[1] = command;
    if (write(i2c_fd, buf, 2) != 2) {
        perror("Error writing to I2C device");
        exit(1);
    }
    usleep(1000); // Vent 1 ms efter kommando
}

void lcd_init() {
    // Åbn I2C-enhed
    if ((i2c_fd = open(I2C_BUS, O_RDWR)) < 0) {
        perror("Error opening I2C device");
        exit(1);
    }

    // Sæt I2C-adresse
    if (ioctl(i2c_fd, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Error setting I2C address");
        exit(1);
    }

    // Initialiser LCD-displayet
    lcd_send_command(0x28); // Function set: 2 line mode, 5x8 dots
    lcd_send_command(0x0D); // Display on, cursor on, blink off
    lcd_send_command(0x01); // Clear display
    lcd_send_command(0x06); // Entry mode set: increment mode
}

void lcd_write_char(char data) {
    unsigned char buf[2];
    buf[0] = CO_BIT | RS_BIT; // Control byte + RS bit
    buf[1] = data;
    if (write(i2c_fd, buf, 2) != 2) {
        perror("Error writing to I2C device");
        exit(1);
    }
    usleep(100); // Venter mellem hver tegn
}

void lcd_write_string(const char *str) {
    while (*str) {
        lcd_write_char(*str++);
    }
}

void lcd_set_cursor(int line, int position) {
    if (line == 1)
        lcd_send_command(0x80 + position); // første linje
    else if (line == 2)
        lcd_send_command(0xC0 + position); // anden linje
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    lcd_init();
    lcd_set_cursor(1, 0); // Gå til starten af første linje
    lcd_write_string(argv[1]); // Skriv besked på første linje

    // Hvis beskeden er længere end 16 tegn, skal vi skrive på anden linje
    if (strlen(argv[1]) > 16) {
        lcd_set_cursor(2, 0); // Gå til starten af anden linje
        lcd_write_string(argv[1] + 16); // Skriv resten af beskeden på anden linje
    }

    close(i2c_fd);
    return 0;
}
