// https://github.com/mborgerding/kissfft
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kiss_fft.h"

// Function to perform FFT and return the output array
kiss_fft_cpx *perform_fft(const kiss_fft_cpx *input_data, int length, int inverse)
{
    kiss_fft_cfg cfg = kiss_fft_alloc(length, inverse, NULL, NULL);
    kiss_fft_cpx *output_data = (kiss_fft_cpx *)malloc(length * sizeof(kiss_fft_cpx));

    if (!cfg)
    {
        // fprintf(stderr, "Error: Failed to allocate FFT configuration.\n");
        free(output_data);
        return NULL;
    }

    kiss_fft(cfg, input_data, output_data);
    free(cfg);

    return output_data;
}

// Helper function to initialize an array with a sinusoidal waveform
void generate_sine_wave(kiss_fft_cpx *buffer, int length, float frequency)
{
    float sample_rate = 1024.0f; // Arbitrary sample rate
    for (int i = 0; i < length; i++)
    {
        buffer[i].r = sinf(2.0f * M_PI * frequency * ((float)i / sample_rate));
        buffer[i].i = 0.0f;
    }
}

// Function to perform FFT and print the results for a given number of samples
void fft(int size)
{
    kiss_fft_cpx *input = (kiss_fft_cpx *)malloc(size * sizeof(kiss_fft_cpx));
    kiss_fft_cpx *output;

    // Generate a sine wave for testing purposes
    generate_sine_wave(input, size, 10.0f);

    // Perform FFT
    output = perform_fft(input, size, 0);

    if (output)
    {
        // printf("\nFFT Output for %d samples:\n", size);
        // for (int i = 0; i < size; i++)
        // {
        //    printf("Bin %d: Real = %f, Imag = %f\n", i, output[i].r, output[i].i);
        // }
        free(output);
    }

    free(input);
}

// int main()
// {
//     // Test with 128, 256, and 512 samples
//     fft(128);
//     fft(256);
//     fft(512);

//     return 0;
// }
