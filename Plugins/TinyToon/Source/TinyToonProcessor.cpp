#include "TinyToonProcessor.h"
#include "TinyToonEditor.h"


TinyToonProcessor::TinyToonProcessor()
{
    //constructor stuff
}

void TinyToonProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                      juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(midiMessages);
    buffer.clear();
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TinyToonProcessor();
}

// NEW always gives pointer = its your job to clean up after yourself
juce::AudioProcessorEditor* TinyToonProcessor::createEditor() {
    // dereferencing the pointer
    return new TinyToonEditor(*this);
}
