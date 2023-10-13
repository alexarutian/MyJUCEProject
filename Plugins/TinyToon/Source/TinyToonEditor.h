#pragma once

#include "TinyToonProcessor.h"

class TinyToonEditor : public juce::AudioProcessorEditor
{
public:
    explicit TinyToonEditor(TinyToonProcessor&) ;

private:
    void paint(juce::Graphics&) override;
    void resized() override;

};
