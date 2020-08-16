/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 220);
    addAndMakeVisible(dial1);
    addAndMakeVisible(dial2);
    addAndMakeVisible(labelDial1);
    addAndMakeVisible(labelDial2);
    dial1.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial1.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    dial1.setLookAndFeel(&otherLookAndFeel);
     
    labelDial1.setFont(juce::Font(16.0f, juce::Font::bold));
    labelDial1.setColour(juce::Label::textColourId, juce::Colours::saddlebrown);
    labelDial1.setJustificationType(juce::Justification::centred);
    labelDial1.setText("High Pass", juce::dontSendNotification);
    labelDial1.attachToComponent(&dial1, false);

    dial2.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dial2.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    dial2.setLookAndFeel(&otherLookAndFeel);

    labelDial2.setFont(juce::Font(16.0f, juce::Font::bold));
    labelDial2.setColour(juce::Label::textColourId, juce::Colours::saddlebrown);
    labelDial2.setJustificationType(juce::Justification::centred);
    labelDial2.setText("Low Pass", juce::dontSendNotification);
    labelDial2.attachToComponent(&dial2, false);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::blanchedalmond);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    juce::Rectangle <int> dial1area = getLocalBounds().removeFromBottom(200);
    juce::Rectangle <int> dial2area = dial1area.removeFromLeft(dial1area.getWidth() / 2);
    dial1.setBounds(dial1area);
    dial2.setBounds(dial2area);

}
