#include "TinyToonProcessor.h"
#include "TinyToonEditor.h"
#include "BinaryData.h"

TinyToonEditor::TinyToonEditor(TinyToonProcessor& p)
    : AudioProcessorEditor(&p)
{
    setSize(400, 400);

    // load a custom font
    auto tface = juce::Typeface::createSystemTypefaceFor(BinaryData::myfont_ttf, BinaryData::myfont_ttfSize);
    juce::String tfaceName = tface->getName();
    juce::Font myFont(tface);
    myFont.setHeight(20.0f);

    // add the titleLabel to this component, and set all its attributes
    addAndMakeVisible(titleLabel);
    titleLabel.setBounds(100, 100, 300, 50);
    titleLabel.setFont(myFont);
    titleLabel.setText("here is my label", juce::dontSendNotification);
    titleLabel.setColour(juce::Label::textColourId, juce::Colours::lightgreen);
    titleLabel.setJustificationType(juce::Justification::centred);
}

void TinyToonEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(28, 28, 28));
    g.setColour(juce::Colours::orange);
    g.fillRect(10, 10, 40, 40);
    g.setColour(juce::Colours::red);
    g.drawEllipse(50, 50, 100, 100, 1);
}

void TinyToonEditor::resized()
{

}