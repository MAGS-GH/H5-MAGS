# Læs tempratur opgave 

    debian@beaglebone:~/h5-mags/beagleboard/readtemp$ gcc readtemp.c -o readtemp2 -li2c
    debian@beaglebone:~/h5-mags/beagleboard/readtemp$ ./readtemp2
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