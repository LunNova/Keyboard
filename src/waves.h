#define maxSamplesNum 5000
// Each sample should have 20 waves
#define maxInstruments 2
#define numKeys 12

const short numSamples[numKeys] = {
#include "freqdata.h"
};

const signed short instruments[maxInstruments][numKeys][maxSamplesNum] = {
    /* Violin
    {
        // C 523Hz
        {
            0x7ff, 0x7ff // TODO - add samples  
        }
    },*/
#include "wavedata.h"
};