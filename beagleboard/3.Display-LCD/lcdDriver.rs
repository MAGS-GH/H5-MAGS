use std::fs::OpenOptions;
use std::io::prelude::*;
use std::io::{Error, ErrorKind};
use std::thread;
use std::time::Duration;

const I2C_BUS: &str = "/dev/i2c-2";
const I2C_ADDR: u16 = 0x3E;

// Control byte bits
const CO_BIT: u8 = 0x80;
const RS_BIT: u8 = 0x40;

fn lcd_send_command(i2c_fd: &mut std::fs::File, command: u8) -> Result<(), Error> {
    let buf: [u8; 2] = [CO_BIT, command];
    i2c_fd.write_all(&buf)?;

    thread::sleep(Duration::from_millis(1)); // Vent 1 ms efter kommando
    Ok(())
}

fn lcd_init(i2c_fd: &mut std::fs::File) -> Result<(), Error> {
    // Åbn I2C-enhed
    let mut file = OpenOptions::new().read(true).write(true).open(I2C_BUS)?;

    // Sæt I2C-adresse
    if let Err(e) = ioctl::set_slave_addr(&file, I2C_ADDR as i32) {
        return Err(Error::new(ErrorKind::Other, format!("Error setting I2C address: {}", e)));
    }

    // Initialiser LCD-displayet
    lcd_send_command(i2c_fd, 0x28)?; // Function set: 2 line mode, 5x8 dots
    lcd_send_command(i2c_fd, 0x0D)?; // Display on, cursor on, blink off
    lcd_send_command(i2c_fd, 0x01)?; // Clear display
    lcd_send_command(i2c_fd, 0x06)?; // Entry mode set: increment mode

    Ok(())
}

fn lcd_write_char(i2c_fd: &mut std::fs::File, data: char) -> Result<(), Error> {
    let buf: [u8; 2] = [CO_BIT | RS_BIT, data as u8];
    i2c_fd.write_all(&buf)?;

    thread::sleep(Duration::from_millis(100)); // Venter mellem hver tegn
    Ok(())
}

fn lcd_write_string(i2c_fd: &mut std::fs::File, str: &str) -> Result<(), Error> {
    for c in str.chars() {
        lcd_write_char(i2c_fd, c)?;
    }
    Ok(())
}

fn lcd_set_cursor(i2c_fd: &mut std::fs::File, line: i32, position: i32) -> Result<(), Error> {
    match line {
        1 => lcd_send_command(i2c_fd, (0x80 + position) as u8), // første linje
        2 => lcd_send_command(i2c_fd, (0xC0 + position) as u8), // anden linje
        _ => Err(Error::new(ErrorKind::Other, "Invalid line number")),
    }
}

fn main() {
    let args: Vec<String> = std::env::args().collect();
    if args.len() != 2 {
        eprintln!("Usage: {} <message>", args[0]);
        std::process::exit(1);
    }

    match OpenOptions::new().read(true).write(true).open(I2C_BUS) {
        Ok(mut i2c_fd) => {
            if let Err(e) = lcd_init(&mut i2c_fd) {
                eprintln!("Error initializing LCD: {}", e);
                std::process::exit(1);
            }

            if let Err(e) = lcd_set_cursor(&mut i2c_fd, 1, 0) {
                eprintln!("Error setting cursor: {}", e);
                std::process::exit(1);
            }
            if let Err(e) = lcd_write_string(&mut i2c_fd, &args[1]) {
                eprintln!("Error writing to LCD: {}", e);
                std::process::exit(1);
            }

            // Hvis beskeden er længere end 16 tegn, skal vi skrive på anden linje
            if args[1].len() > 16 {
                if let Err(e) = lcd_set_cursor(&mut i2c_fd, 2, 0) {
                    eprintln!("Error setting cursor: {}", e);
                    std::process::exit(1);
                }
                if let Err(e) = lcd_write_string(&mut i2c_fd, &args[1][16..]) {
                    eprintln!("Error writing to LCD: {}", e);
                    std::process::exit(1);
                }
            }
        }
        Err(e) => {
            eprintln!("Error opening I2C device: {}", e);
            std::process::exit(1);
        }
    }
}
