#include "TinyToonProcessor.h"
#include "TinyToonEditor.h"

TinyToonEditor::TinyToonEditor(TinyToonProcessor& p)
    : AudioProcessorEditor(&p)
{
    setSize(400, 300);

}

void TinyToonEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::whitesmoke);
}

void TinyToonEditor::resized()
{

}