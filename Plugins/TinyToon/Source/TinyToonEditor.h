#pragma once

#include "TinyToonProcessor.h"

class TinyToonEditor : public juce::AudioProcessorEditor,
                       public juce::Slider::Listener
{
public:
    explicit TinyToonEditor(TinyToonProcessor&) ;
    void sliderValueChanged(juce::Slider* slider) override;

private:
    void paint(juce::Graphics&) override;
    void resized() override;

    juce::Label titleLabel;
    juce::Slider slidey;

};

class EarthLayer : public juce::Component
{
public:
    EarthLayer(float wo, float ho, float d, float priord, juce::Colour c, double toRadiansFactor = 1);
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    float widthOffset;
    float heightOffset;
    float diameter;
    float priorLayerDiameter;
    double toRadiansRatio;
    juce::Colour color;
};
