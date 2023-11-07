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
    titleLabel.setBounds(10, 10, 300, 50);
    titleLabel.setFont(myFont);
    titleLabel.setText("here is my label", juce::dontSendNotification);
    titleLabel.setColour(juce::Label::textColourId, juce::Colours::lightgreen);
    titleLabel.setJustificationType(juce::Justification::centred);

    // add and configure the slider
    addAndMakeVisible(slidey);
    slidey.setRange(0, 1);
    slidey.setSliderStyle(juce::Slider::LinearVertical);
    slidey.setBounds(190, 100, 20, 300);
    // our editor is now a listener bc we changed its inheritance in the .h file
    slidey.addListener(this);
}

void TinyToonEditor::paint(juce::Graphics& g)
{
    const auto sliderValue = slidey.getValue();
    const float widthOffset = 200;
    const float heightOffset = 400;

    // fill background of plugin
    g.fillAll(juce::Colour(28, 28, 28));

    // AA QUESTION: assuming this repaints them every single time the parent's paint method is called?

    // make the yellow molten core of the earth
    EarthLayer(widthOffset, heightOffset, 75, 0, juce::Colour(237, 228, 92)).paint(g);

    // level 2 core
    EarthLayer(widthOffset, heightOffset, 175, 75, juce::Colour(226, 153, 77)).paint(g);

    // level 3 core
    EarthLayer(widthOffset, heightOffset, 275, 175, juce::Colour(240, 190, 76)).paint(g);

    // level 4 core (red)
    EarthLayer(widthOffset, heightOffset, 375, 275, juce::Colour(191, 52, 47)).paint(g);

    // level 5 core (brown)
    EarthLayer(widthOffset, heightOffset, 455, 375, juce::Colour(155, 89, 46)).paint(g);

    // level 6 core (dark brown)
    EarthLayer(widthOffset, heightOffset, 475, 455, juce::Colour(84, 26, 17), 1-sliderValue).paint(g);

    // level 7 ocean (blue)
    EarthLayer(widthOffset, heightOffset, 530, 475, juce::Colour(88, 131, 191), 1-sliderValue).paint(g);

    // level 8 greenery (light green)
    EarthLayer(widthOffset, heightOffset, 555, 530, juce::Colour(179, 207, 98), 0.4*(1-sliderValue)).paint(g);

    // level 9 greenery (darker green)
    EarthLayer(widthOffset, heightOffset, 571, 555, juce::Colour(135, 177, 83), 0.25*(1-sliderValue)).paint(g);
}

void TinyToonEditor::resized()
{

}

void TinyToonEditor::sliderValueChanged(juce::Slider *slider)
{

titleLabel.setText(juce::String(slider->getValue()), juce::dontSendNotification);
repaint();

}

EarthLayer::EarthLayer(float wo, float ho, float d, float priord, juce::Colour c, double trf)
{
    // save all variables down to the class
    widthOffset = wo;
    heightOffset = ho;
    diameter = d;
    priorLayerDiameter = priord;
    color = c;
    toRadiansRatio = trf;

}

void EarthLayer::paint(juce::Graphics& g)
{
    using jconst = juce::MathConstants<float>;

    juce::Path p;

    p.addPieSegment(widthOffset-diameter/2, heightOffset-diameter/2, diameter, diameter, -jconst::halfPi, jconst::halfPi * toRadiansRatio, priorLayerDiameter/diameter);
    g.setColour(color);
    g.fillPath(p);
    p.clear();
}

void EarthLayer::resized()
{

}