# Læs tempratur opgave 

Temperatur sensor
I skal kunne udskrive temperaturen på skærmen som for eksempel: "Temperaturen er 16.04375 grader celsious"

Ekstra opgave: (Vi har ikke talt om dette endnu)

1. Lav et C-source modul med nødvendige funtioner til at anvende temperatur sensoren

2. Lav en header fil (.h-fil) der kan inkluderes i et andet projekt    

Link til [Mars-Grove_I2C_High_Accuracy_Temerature_Sensor](https://mars.merhot.dk/w/index.php/Grove_I2C_High_Accuracy_Temerature_Sensor_-_Seeed)

## Kode og kommandoer

    debian@beaglebone:~/h5-mags/beagleboard/2.TemperaturSensor$ gcc readtemp.c -o readtemp2 -li2c
    debian@beaglebone:~/h5-mags/beagleboard/TemperaturSensor$ ./readtemp2
    All good :-)
    Temperaturen er 22.62 grader celsious


```c
float read_temperature(int file) {
    // Vi bruger en int16 for at læse den "rå" tempratur fra enheden
    uint16_t raw_temperature;

    //Vi bruger float til at opbevare værdien som skal vises til brugeren
    float temperature;

    //Vi læser temperaturen fra enheden
    raw_temperature = i2c_smbus_read_word_data(file, TA_REG);
    if (raw_temperature < 0) { // Hvis den ikke findes "<0"
        fprintf(stderr, "ERROR: Read failed on i2c bus register %d - %s\n", TA_REG, strerror(errno));
        exit(1);
    }

    // Vi laver bitswap da vi har en lil-engine CPU og så det bliver læst omvendt!
    raw_temperature = bswap_16(raw_temperature); // bite swap
    temperature = (float)((raw_temperature & 0x0FFF) / 16.0);
    //Laver vores int16 til float

    return temperature;
}
```