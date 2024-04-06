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
    usleep(100); // Vent 100 us efter hvert tegn
}

void lcd_write_string(const char *str) {
    while (*str) {
        lcd_write_char(*str++);
    }
}

void lcd_set_backlight(int brightness) {
    if (brightness < 0 || brightness > 255) {
        printf("Error: Invalid brightness value. Value must be between 0 and 255.\n");
        return;
    }
    unsigned char buf[2];
    buf[0] = 0x00; // Dette kan variere afhængigt af dit LCD-modul
    buf[1] = brightness; // PWM-værdi
    if (write(i2c_fd, buf, 2) != 2) {
        perror("Error writing to I2C device");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <message> [brightness]\n", argv[0]);
        return 1;
    }

    lcd_init();
    lcd_write_string(argv[1]);

    // Hvis der blev angivet en lysstyrkeværdi som argument
    if (argc == 3) {
        int brightness = atoi(argv[2]);
        lcd_set_backlight(brightness);
    }

    close(i2c_fd);
    return 0;
}
