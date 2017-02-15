// Example usage for NeoRingDsp library by Alik <aliktab@gmail.com>.

#include "NeoRingDsp.h"

// Initialize objects from the lib
NeoRingDsp neoRingDsp;

void setup() {
    // Call functions on initialized library objects that require hardware
    neoRingDsp.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    neoRingDsp.process();
}
