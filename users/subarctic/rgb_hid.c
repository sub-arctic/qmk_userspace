uint8_t red = 255;  // Default some values
uint8_t green = 0;
uint8_t blue = 0;
bool received = false;

// This function gets triggered when Raw HID data is received
void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Update the global RGB variables with new values from the host
    red = data[0];
    green = data[1];
    blue = data[2];

    // Print received values for debugging
    uprintf("Received RGB Values -> R: %d, G: %d, B: %d\n", red, green, blue);

    // Set the "received" flag so the indicator callback activates
    received = true;
}

// This callback runs on every LED frame, allowing persistent color application
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // If new RGB data has been received and the values are different from the last
    if (received) {
        // Set the color of all LEDs to the received RGB value
        rgb_matrix_set_color_all(red, green, blue);
    }

    return false;  // Returning false continues to allow other QMK matrix functions to run.
}

// Initialize the keyboard and set a default mode
void keyboard_post_init_user(void) {
    // Set the RGB color mode manually to SOLID_COLOR (ignoring EEPROM settings)
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);  // Set initial matrix mode to solid color
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}


