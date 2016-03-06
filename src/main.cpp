#include "mbed.h"
#include "waves.h"

AnalogOut speaker(p18);
BusOut myled(LED1, LED2, LED3, LED4);
BusIn keys(p21, p22, p23, p24, p25, p26, p27, p28, p29, p30, p5, p6);
Serial pc(USBTX, USBRX); // tx, rx

void soundLoop(const signed short samples[numKeys][maxSamplesNum]) {
    int i = 0;
    // magic number stupidity.
    // loop time depends on number of clock cycles per loop
    // mbed clock speed
    // and the will of compiler optimisations (oh no)
    int clocksPerSample = 65;
    pc.printf("clocks per sample loop: %d\r\n", clocksPerSample);
    signed short next;
    while (1) {
        next = clocksPerSample;
        signed short value = 0;
        for (int j = 0; j < numKeys; j++) {
            if (keys[j]) {
                value += samples[j][i % numSamples[j]];
                next -= 10;
                if (next < 0){next=0;}
            }
        }
        //pc.printf("next %d value %d\r\n", next, value + 32768);
        speaker.write_u16(value + 32768);
        ++i;
        while (next--);
    }
}

int main() {
    soundLoop(instruments[0]);
}