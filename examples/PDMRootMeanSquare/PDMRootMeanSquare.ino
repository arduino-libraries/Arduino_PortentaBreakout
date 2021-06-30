/*
  This example reads audio data from the connected PDM microphone, and prints
  out the RMS value of the samples to the Serial console. The Serial Plotter 
  built into the Arduino IDE can be used to plot the audio data (Tools -> 
  Serial Plotter)

  Circuit:
  - Portenta Breakout

  This example code is in the public domain.
*/

#include <Arduino_PortentaBreakout.h>

// default number of output channels
static const char channels = 1;

// default PCM output frequency
static const int frequency = 16000;

// Buffer to read samples into, each sample is 16-bits.
// Size in bytes must be a power of 2, grater or equal than PDM buffer size.
short sampleBuffer[2048];

// Number of audio samples read
volatile int samplesRead;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Configure the data receive callback
  Breakout.PDM.onReceive(onPDMdata);

  // Configure BufferSize to 4096 bytes
  Breakout.PDM.setBufferSize(4096);
  
  // Optionally set the gain, default value is 24
  Breakout.PDM.setGain(24);

  // Initialize PDM with:
  // - one channel (mono mode)
  // - a 16 kHz sample rate
  if (!Breakout.PDM.begin(channels, frequency)) {
    Serial.println("Failed to start PDM!");
    while (1);
  }
}

void loop() {
  // Wait for samples to be read
  if (samplesRead == 2048) {

    // Compute RMS value
    double rms = RMS(sampleBuffer, samplesRead);

    Serial.println(rms);
    
    // Clear the read count
    samplesRead = 0;
  }
}

/**
 * Callback function to process the data from the PDM microphone.
 * NOTE: This callback is executed as part of an ISR.
 * Therefore using `Serial` to print messages inside this function isn't supported.
 * */
void onPDMdata() {
  // Query the number of available bytes
  int bytesAvailable = Breakout.PDM.available();

  if(samplesRead < 2048) {
    // Read into the sample buffer
    Breakout.PDM.read(sampleBuffer, bytesAvailable);

    // 16-bit, 2 bytes per sample
    samplesRead = bytesAvailable / 2;
  }
}

/**
 * Compute RMS value of the input samples block
 */
double RMS(short Samples[], int Length) {
  double sum = 0;
  int i;
  for(i = 0; i < Length; i++) {
    sum += Samples[i] * Samples[i];
  }
  return sqrt(sum / Length);
}
