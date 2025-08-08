int binary_to_int(int binary_digits[], int number_of_digits) {
    int value = 0;
    for (int i = 0; i < number_of_digits; i++) {
        value = value * 2 + binary_digits[i];

    }
    return value;
}
